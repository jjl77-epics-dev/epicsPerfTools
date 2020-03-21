/**
 * 
 * perfToolsUtil.h
 * 
 * Internal utils used by perfTools
 * 
 */ 
#pragma once

#include <epicsStdlib.h>
#include <epicsAssert.h>

template<class T, int N = 1000>
class perfToolsFreeList
{
private:
	struct freeBucket_t
	{
		T* v;
		freeBucket_t* pnext;
	};

	/* Head of the free list */
	freeBucket_t* pfreehead;
	
	/* Head of the used list */
	freeBucket_t* pusedhead;

	/* Slab of T */
	T ptslab[N];
public:
	perfToolsFreeList()
	{
		/* For the default constructor, we'll allocate a large slab of memory based on the N parameter */
		freeBucket_t* pnewblock = static_cast<freeBucket_t*>(calloc(N, sizeof(freeBucket_t*)));

		pfreehead = pnewblock;
		
		/* Loop through each block now and set the pointers */
		for(int i = 0; i < N-1; i++)
		{
			pfreehead[i].pnext = &pfreehead[i+1];
			pfreehead[i].v = &ptslab[i];
		}
	}

	~perfToolsFreeList()
	{

	}

	bool isFull() const
	{
		return pfreehead == nullptr;
	}

	T* alloc()
	{
		freeBucket_t* pbucket = pfreehead;
		if(!pbucket) return nullptr;

		/* reset the freehead */
		pfreehead = pbucket->pnext;
		
		/* this bucket now sits at the head of pusedhead */
		pbucket->next = pusedhead;
		pusedhead = pbucket;

		/* We no longer own the value in pusedhead, so set it to null and return the last */
		T* ret = pusedhead->v;
		pusedhead->v = nullptr;
		return ret;
	}

	/* Alias of alloc */
	T* malloc()
	{
		return this->alloc();
	}

	void free(T* ptr)
	{
		/* well, this is awkward... */
		if(!pusedhead)
			assert(pusedhead != NULL);
		
		/* grab the bucket from the used list */
		freeBucket_t* pbucket = pusedhead;

		/* effectively remove this guy from the used list */
		pusedhead = pbucket->next;

		/* add this back to the free list */
		pbucket->v = ptr;
		pbucket->next = pfreehead;
		pfreehead = pbucket;
	}


};
TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE

# Build an IOC support library
LIBRARY_IOC += epicsPerfToolsSupport

DBD += epicsPerfTools.dbd
DBD += epicsPerfToolsInclude.dbd

USR_CXXFLAGS += -g 

# Used for code improvement purposes
#USR_CXXFLAGS += -Wunused -Wall -Wextra -Wpedantic

# Records/Device support sources
epicsPerfToolsSupport_SRCS += perfTools.cpp

epicsPerfToolsSupport_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE


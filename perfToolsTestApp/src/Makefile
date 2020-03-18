TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = perfToolsTest

DBD += perfToolsTest.dbd

perfToolsTest_DBD += base.dbd
perfToolsTest_DBD += epicsPerfTools.dbd

# Add all the support libraries needed by this IOC
perfToolsTest_LIBS += epicsPerfToolsSupport
perfToolsTest_SRCS += perfToolsTest_registerRecordDeviceDriver.cpp


# Build the main IOC entry point on workstation OSs.
perfToolsTest_SRCS_DEFAULT += perfToolsTestMain.cpp
perfToolsTest_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#ek9000Test_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
perfToolsTest_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


# Name of component under test
COMPONENT_NAME = mock_sensor

# Dynamically generate absolute paths
# From https://matheusmbar.com/bugfree-robot/2019/04/05/makefile-first-test.html
MAKEFILE_DIR = $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
PROJECT_DIR = $(realpath $(MAKEFILE_DIR)../..)
SRC_DIR = $(PROJECT_DIR)/src
TEST_DIR = $(PROJECT_DIR)/tests

# Location of CppUTest (if not already set)
CPPUTEST_HOME ?= $(PROJECT_DIR)/cpputest

# Include and source files for component under test
INCLUDE_DIRS = $(SRC_DIR)
SRC_DIRS = $(SRC_DIR)


# Includes CppUTest header files
INCLUDE_DIRS += $(CPPUTEST_HOME)/include

# Directories containing the unit tests
TEST_SRC_DIRS = $(TEST_DIR)/$(COMPONENT_NAME)

CPPUTEST_LDFLAGS += -L$(CPPUTEST_HOME)/lib
CPPUTEST_LDFLAGS += -lCppUTest -lCppUTestExt

# Run MakefileWorker.mk with the variables set in this Makefile
include $(CPPUTEST_HOME)/build/MakefileWorker.mk

.PHONY: echo
echo:
	@echo 'Hello mock_sensor'
	@echo 'TEST_SRC_DIRS= $(TEST_SRC_DIRS)'
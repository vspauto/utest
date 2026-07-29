#
# TARGETS := test
# SRCS := rcar-vin.c
# OBJS = $(patsubst %.c, %.o, $(SRCS))
#
# CFLAGS := -g -I $(SDKTARGETSYSROOT)/usr/include/libdrm
# CFLAGS += `pkg-config --cflags gstreamer-1.0 gstreamer-base-1.0 gstreamer-app-1.0`
# LDFLAGS := -L $(SDKTARGETSYSROOT)/usr/lib -ldrm -ludev -ljpeg -lpng -lpthread
# LDFLAGS += `pkg-config --libs gstreamer-1.0 gstreamer-base-1.0 gstreamer-app-1.0`
#
# $(TARGETS) : $(OBJS)
#	$(CC) $(LDFLAGS) -o $@ $^
#
# %.o:%.c
#	$(CC) $(CFLAGS) -c -o $@ $<
#
# all: $(TARGETS)
#
# clean:
#	-rm -f *.o
#	-rm -f $(TARGETS)
#

# Settings
SRC_DIR = ./src
TEST_DIR = ./utests
BUILD_DIR = .
TARGET = app

C_SRCS = $(SRC_DIR)/main.c
C_SRCS += $(wildcard $(SRC_DIR)/average/*.c)
C_OBJS = $(patsubst %.c, %.o, $(C_SRCS))

CFLAGS += -Wall
CFLAGS += -I$(SRC_DIR)/average
LDFLAGS += 

# Default rule: build application
.PHONY: all
all: $(TARGET)

# Build Components
$(C_OBJS) : %.o : %.c
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Build Target application
.PHONY: $(TARGET)
$(TARGET) : $(C_OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Echo for debug
.PHONY: echo
echo:
	@echo 'C_SRCS= $(C_SRCS)'
	@echo 'TEST_DIR= $(TEST_DIR)'

.PHONY: clean
clean:
	rm -f $(C_OBJS) $(TARGET)

#--------------------------------------
# Unit Test
.PHONY: utest
utest:
	make –C $(TEST_DIR)

.PHONY: utest_clean
utest_clean:
	make –C $(TEST_DIR) clean

.PHONY: utest_echo
utest_echo:
	@echo 'TEST_DIR= $(TEST_DIR)'
	make –C $(TEST_DIR) echo
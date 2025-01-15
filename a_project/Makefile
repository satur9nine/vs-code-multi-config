# Clear implicit rules to prevent Make from using the wrong compiler and commands
.SUFFIXES :

# Pre-compiler and Compiler flags
C_FLAGS := -std=c11 -g3 -DA_PROJECT
PRE_FLAGS := -MMD -MP

# Project directory structure
SRC := src ../common/src
INC := inc ../common/inc
LIB := lib

# Build directories and output
BUILD := build
TARGET := $(BUILD)/main

# Library search directories and flags
EXT_LIB :=
LDFLAGS :=
LDPATHS := # $(addprefix -L,$(LIB) $(EXT_LIB)) disabled, no libraries

# Include directories
INC_DIRS := $(INC)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Custom mapping of source to object file to handle the common code in the parent directory
SRC_TO_OBJ_MAPPER = $(addprefix build/,$(subst ../,,$(addsuffix .o,$(basename $(1)))))

# Construct build output and dependency filenames
SRCS := $(shell find $(SRC) -name *.c)
OBJS := $(call SRC_TO_OBJ_MAPPER,$(SRCS))
DEPS := $(OBJS:.o=.d)

# Main task
all: $(TARGET)

# Build task
build: all

# Task producing target from object files
$(TARGET): $(OBJS)
	@echo "🛠️ Linking..."
	@mkdir -p $(dir $@)
	$(CC) $(OBJS) -o $@ $(LDPATHS) $(LDFLAGS)
	@echo

# Template to create rules using two parameters: object and source
define OBJ_RULE
$(1): $(2)
	@mkdir -p $(dir $1)
	$(CC) $(C_FLAGS) $(PRE_FLAGS) $(INC_FLAGS) -c -o $1 $2 $(LDPATHS) $(LDFLAGS)
endef

# Generate object build rules using the template, necessary because of the custom mapping
$(foreach _src,$(SRCS),$(eval $(call OBJ_RULE,$(call SRC_TO_OBJ_MAPPER, $(_src)),$(_src))))

# Clean task
.PHONY: clean
clean:
	@echo "🧹 Clearing..."
	rm -rf build

# Include all dependencies
-include $(DEPS)
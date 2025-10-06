# sqlite - A rebuild of sqlite core features
# Copyright (C) 2025 Yixiang Qiu
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#

# variables for paths
CUR_DIR         :=          .
SRC_PATH 		:= 			$(CUR_DIR)/src
INCLUDE_PATH 	:= 			$(CUR_DIR)/include
TEST_PATH 		:= 			$(CUR_DIR)/test
CONFIG_PATH 	:= 			$(CUR_DIR)/config
BUILD_PATH 		:= 			$(CUR_DIR)/build
OBJ_PATH 		:= 			$(BUILD_PATH)/obj
DEP_PATH 		:= 			$(BUILD_PATH)/dep
LIB_PATH 		:= 			$(CUR_DIR)/lib


# file list
SRCS 			:= 			$(shell find $(SRC_PATH) -name "*.c")
OBJS 			:= 			$(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRCS))
DEPS 			:= 			$(patsubst $(SRC_PATH)/%.c, $(DEP_PATH)/%.d, $(SRCS))

# variables for compiler
CC             	:=          gcc
CXX             :=          g++

# flags for compiler
CC_FLAGS        :=          -Wall -Wextra -Werror -Wshadow
CC_FLAGS       	+=          -Wno-unused-parameter -Wno-unused-function
CC_FLAGS       	+=          -std=c99
CC_FLAGS        +=          -O2
CC_FLAGS       	+=          -I$(INCLUDE_PATH)
CC_DEPS_FLAGS   :=          -MMD -MP -MF


# general rules for all objects
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CC_FLAGS) $(CC_DEPS_FLAGS) $(DEP_PATH)/$(notdir $(@F:.o=.d)) -c $< -o $@
	@echo " + CC\t$@"

.PHONY: all clean
.DEFAULT_GOAL := help

-include $(DEPS)

# all targets
all: $(OBJS)
	@$(CC) $(OBJS) -o $(BUILD_PATH)/sqlite
	@echo " + LD\t$(notdir $(BUILD_PATH))/sqlite"

# clean targets
clean:
	@rm -rf $(BUILD_PATH)

# help targets
help:
	@echo "Build system for sqlite core"
	@echo "USAGE:"
	@echo "\tmake all\t- build the project"
	@echo "\tmake clean\t- clean the build directory"
	@echo "\tmake help\t- show this help message"
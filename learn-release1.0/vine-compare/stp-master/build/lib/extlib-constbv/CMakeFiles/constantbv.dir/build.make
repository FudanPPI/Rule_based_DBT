# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ppi/dbt/pattern-dbt/vine-compare/stp-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build

# Include any dependencies generated for this target.
include lib/extlib-constbv/CMakeFiles/constantbv.dir/depend.make

# Include the progress variables for this target.
include lib/extlib-constbv/CMakeFiles/constantbv.dir/progress.make

# Include the compile flags for this target's objects.
include lib/extlib-constbv/CMakeFiles/constantbv.dir/flags.make

lib/extlib-constbv/CMakeFiles/constantbv.dir/constantbv.cpp.o: lib/extlib-constbv/CMakeFiles/constantbv.dir/flags.make
lib/extlib-constbv/CMakeFiles/constantbv.dir/constantbv.cpp.o: ../lib/extlib-constbv/constantbv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/extlib-constbv/CMakeFiles/constantbv.dir/constantbv.cpp.o"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/extlib-constbv && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/constantbv.dir/constantbv.cpp.o -c /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/extlib-constbv/constantbv.cpp

lib/extlib-constbv/CMakeFiles/constantbv.dir/constantbv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/constantbv.dir/constantbv.cpp.i"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/extlib-constbv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/extlib-constbv/constantbv.cpp > CMakeFiles/constantbv.dir/constantbv.cpp.i

lib/extlib-constbv/CMakeFiles/constantbv.dir/constantbv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/constantbv.dir/constantbv.cpp.s"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/extlib-constbv && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/extlib-constbv/constantbv.cpp -o CMakeFiles/constantbv.dir/constantbv.cpp.s

constantbv: lib/extlib-constbv/CMakeFiles/constantbv.dir/constantbv.cpp.o
constantbv: lib/extlib-constbv/CMakeFiles/constantbv.dir/build.make

.PHONY : constantbv

# Rule to build all files generated by this target.
lib/extlib-constbv/CMakeFiles/constantbv.dir/build: constantbv

.PHONY : lib/extlib-constbv/CMakeFiles/constantbv.dir/build

lib/extlib-constbv/CMakeFiles/constantbv.dir/clean:
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/extlib-constbv && $(CMAKE_COMMAND) -P CMakeFiles/constantbv.dir/cmake_clean.cmake
.PHONY : lib/extlib-constbv/CMakeFiles/constantbv.dir/clean

lib/extlib-constbv/CMakeFiles/constantbv.dir/depend:
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ppi/dbt/pattern-dbt/vine-compare/stp-master /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/extlib-constbv /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/extlib-constbv /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/extlib-constbv/CMakeFiles/constantbv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/extlib-constbv/CMakeFiles/constantbv.dir/depend


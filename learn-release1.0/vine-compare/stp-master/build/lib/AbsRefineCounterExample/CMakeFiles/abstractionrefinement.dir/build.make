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
include lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/depend.make

# Include the progress variables for this target.
include lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/progress.make

# Include the compile flags for this target's objects.
include lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/flags.make

lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/AbstractionRefinement.cpp.o: lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/flags.make
lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/AbstractionRefinement.cpp.o: ../lib/AbsRefineCounterExample/AbstractionRefinement.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/AbstractionRefinement.cpp.o"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/AbsRefineCounterExample && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abstractionrefinement.dir/AbstractionRefinement.cpp.o -c /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/AbsRefineCounterExample/AbstractionRefinement.cpp

lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/AbstractionRefinement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abstractionrefinement.dir/AbstractionRefinement.cpp.i"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/AbsRefineCounterExample && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/AbsRefineCounterExample/AbstractionRefinement.cpp > CMakeFiles/abstractionrefinement.dir/AbstractionRefinement.cpp.i

lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/AbstractionRefinement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abstractionrefinement.dir/AbstractionRefinement.cpp.s"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/AbsRefineCounterExample && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/AbsRefineCounterExample/AbstractionRefinement.cpp -o CMakeFiles/abstractionrefinement.dir/AbstractionRefinement.cpp.s

lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/CounterExample.cpp.o: lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/flags.make
lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/CounterExample.cpp.o: ../lib/AbsRefineCounterExample/CounterExample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/CounterExample.cpp.o"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/AbsRefineCounterExample && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abstractionrefinement.dir/CounterExample.cpp.o -c /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/AbsRefineCounterExample/CounterExample.cpp

lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/CounterExample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abstractionrefinement.dir/CounterExample.cpp.i"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/AbsRefineCounterExample && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/AbsRefineCounterExample/CounterExample.cpp > CMakeFiles/abstractionrefinement.dir/CounterExample.cpp.i

lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/CounterExample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abstractionrefinement.dir/CounterExample.cpp.s"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/AbsRefineCounterExample && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/AbsRefineCounterExample/CounterExample.cpp -o CMakeFiles/abstractionrefinement.dir/CounterExample.cpp.s

abstractionrefinement: lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/AbstractionRefinement.cpp.o
abstractionrefinement: lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/CounterExample.cpp.o
abstractionrefinement: lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/build.make

.PHONY : abstractionrefinement

# Rule to build all files generated by this target.
lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/build: abstractionrefinement

.PHONY : lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/build

lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/clean:
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/AbsRefineCounterExample && $(CMAKE_COMMAND) -P CMakeFiles/abstractionrefinement.dir/cmake_clean.cmake
.PHONY : lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/clean

lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/depend:
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ppi/dbt/pattern-dbt/vine-compare/stp-master /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/AbsRefineCounterExample /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/AbsRefineCounterExample /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/AbsRefineCounterExample/CMakeFiles/abstractionrefinement.dir/depend

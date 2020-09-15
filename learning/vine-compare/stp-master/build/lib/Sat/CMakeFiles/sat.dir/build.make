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
include lib/Sat/CMakeFiles/sat.dir/depend.make

# Include the progress variables for this target.
include lib/Sat/CMakeFiles/sat.dir/progress.make

# Include the compile flags for this target's objects.
include lib/Sat/CMakeFiles/sat.dir/flags.make

lib/Sat/CMakeFiles/sat.dir/CryptoMinisat.cpp.o: lib/Sat/CMakeFiles/sat.dir/flags.make
lib/Sat/CMakeFiles/sat.dir/CryptoMinisat.cpp.o: ../lib/Sat/CryptoMinisat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/Sat/CMakeFiles/sat.dir/CryptoMinisat.cpp.o"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sat.dir/CryptoMinisat.cpp.o -c /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/Sat/CryptoMinisat.cpp

lib/Sat/CMakeFiles/sat.dir/CryptoMinisat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sat.dir/CryptoMinisat.cpp.i"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/Sat/CryptoMinisat.cpp > CMakeFiles/sat.dir/CryptoMinisat.cpp.i

lib/Sat/CMakeFiles/sat.dir/CryptoMinisat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sat.dir/CryptoMinisat.cpp.s"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/Sat/CryptoMinisat.cpp -o CMakeFiles/sat.dir/CryptoMinisat.cpp.s

lib/Sat/CMakeFiles/sat.dir/MinisatCore.cpp.o: lib/Sat/CMakeFiles/sat.dir/flags.make
lib/Sat/CMakeFiles/sat.dir/MinisatCore.cpp.o: ../lib/Sat/MinisatCore.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/Sat/CMakeFiles/sat.dir/MinisatCore.cpp.o"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sat.dir/MinisatCore.cpp.o -c /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/Sat/MinisatCore.cpp

lib/Sat/CMakeFiles/sat.dir/MinisatCore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sat.dir/MinisatCore.cpp.i"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/Sat/MinisatCore.cpp > CMakeFiles/sat.dir/MinisatCore.cpp.i

lib/Sat/CMakeFiles/sat.dir/MinisatCore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sat.dir/MinisatCore.cpp.s"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/Sat/MinisatCore.cpp -o CMakeFiles/sat.dir/MinisatCore.cpp.s

lib/Sat/CMakeFiles/sat.dir/MinisatCore_prop.cpp.o: lib/Sat/CMakeFiles/sat.dir/flags.make
lib/Sat/CMakeFiles/sat.dir/MinisatCore_prop.cpp.o: ../lib/Sat/MinisatCore_prop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object lib/Sat/CMakeFiles/sat.dir/MinisatCore_prop.cpp.o"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sat.dir/MinisatCore_prop.cpp.o -c /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/Sat/MinisatCore_prop.cpp

lib/Sat/CMakeFiles/sat.dir/MinisatCore_prop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sat.dir/MinisatCore_prop.cpp.i"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/Sat/MinisatCore_prop.cpp > CMakeFiles/sat.dir/MinisatCore_prop.cpp.i

lib/Sat/CMakeFiles/sat.dir/MinisatCore_prop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sat.dir/MinisatCore_prop.cpp.s"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/Sat/MinisatCore_prop.cpp -o CMakeFiles/sat.dir/MinisatCore_prop.cpp.s

lib/Sat/CMakeFiles/sat.dir/SimplifyingMinisat.cpp.o: lib/Sat/CMakeFiles/sat.dir/flags.make
lib/Sat/CMakeFiles/sat.dir/SimplifyingMinisat.cpp.o: ../lib/Sat/SimplifyingMinisat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object lib/Sat/CMakeFiles/sat.dir/SimplifyingMinisat.cpp.o"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sat.dir/SimplifyingMinisat.cpp.o -c /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/Sat/SimplifyingMinisat.cpp

lib/Sat/CMakeFiles/sat.dir/SimplifyingMinisat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sat.dir/SimplifyingMinisat.cpp.i"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/Sat/SimplifyingMinisat.cpp > CMakeFiles/sat.dir/SimplifyingMinisat.cpp.i

lib/Sat/CMakeFiles/sat.dir/SimplifyingMinisat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sat.dir/SimplifyingMinisat.cpp.s"
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/Sat/SimplifyingMinisat.cpp -o CMakeFiles/sat.dir/SimplifyingMinisat.cpp.s

sat: lib/Sat/CMakeFiles/sat.dir/CryptoMinisat.cpp.o
sat: lib/Sat/CMakeFiles/sat.dir/MinisatCore.cpp.o
sat: lib/Sat/CMakeFiles/sat.dir/MinisatCore_prop.cpp.o
sat: lib/Sat/CMakeFiles/sat.dir/SimplifyingMinisat.cpp.o
sat: lib/Sat/CMakeFiles/sat.dir/build.make

.PHONY : sat

# Rule to build all files generated by this target.
lib/Sat/CMakeFiles/sat.dir/build: sat

.PHONY : lib/Sat/CMakeFiles/sat.dir/build

lib/Sat/CMakeFiles/sat.dir/clean:
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat && $(CMAKE_COMMAND) -P CMakeFiles/sat.dir/cmake_clean.cmake
.PHONY : lib/Sat/CMakeFiles/sat.dir/clean

lib/Sat/CMakeFiles/sat.dir/depend:
	cd /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ppi/dbt/pattern-dbt/vine-compare/stp-master /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/lib/Sat /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat /home/ppi/dbt/pattern-dbt/vine-compare/stp-master/build/lib/Sat/CMakeFiles/sat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/Sat/CMakeFiles/sat.dir/depend

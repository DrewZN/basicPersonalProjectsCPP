# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/drewzn/Stuff/Programming/C++/Projects/Personal/basicLoginSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/drewzn/Stuff/Programming/C++/Projects/Personal/basicLoginSystem/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/basicLoginSystem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/basicLoginSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/basicLoginSystem.dir/flags.make

CMakeFiles/basicLoginSystem.dir/main.cpp.o: CMakeFiles/basicLoginSystem.dir/flags.make
CMakeFiles/basicLoginSystem.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/drewzn/Stuff/Programming/C++/Projects/Personal/basicLoginSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/basicLoginSystem.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basicLoginSystem.dir/main.cpp.o -c /home/drewzn/Stuff/Programming/C++/Projects/Personal/basicLoginSystem/main.cpp

CMakeFiles/basicLoginSystem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basicLoginSystem.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/drewzn/Stuff/Programming/C++/Projects/Personal/basicLoginSystem/main.cpp > CMakeFiles/basicLoginSystem.dir/main.cpp.i

CMakeFiles/basicLoginSystem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basicLoginSystem.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/drewzn/Stuff/Programming/C++/Projects/Personal/basicLoginSystem/main.cpp -o CMakeFiles/basicLoginSystem.dir/main.cpp.s

# Object files for target basicLoginSystem
basicLoginSystem_OBJECTS = \
"CMakeFiles/basicLoginSystem.dir/main.cpp.o"

# External object files for target basicLoginSystem
basicLoginSystem_EXTERNAL_OBJECTS =

basicLoginSystem: CMakeFiles/basicLoginSystem.dir/main.cpp.o
basicLoginSystem: CMakeFiles/basicLoginSystem.dir/build.make
basicLoginSystem: CMakeFiles/basicLoginSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/drewzn/Stuff/Programming/C++/Projects/Personal/basicLoginSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable basicLoginSystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/basicLoginSystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/basicLoginSystem.dir/build: basicLoginSystem

.PHONY : CMakeFiles/basicLoginSystem.dir/build

CMakeFiles/basicLoginSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/basicLoginSystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/basicLoginSystem.dir/clean

CMakeFiles/basicLoginSystem.dir/depend:
	cd /home/drewzn/Stuff/Programming/C++/Projects/Personal/basicLoginSystem/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/drewzn/Stuff/Programming/C++/Projects/Personal/basicLoginSystem /home/drewzn/Stuff/Programming/C++/Projects/Personal/basicLoginSystem /home/drewzn/Stuff/Programming/C++/Projects/Personal/basicLoginSystem/cmake-build-debug /home/drewzn/Stuff/Programming/C++/Projects/Personal/basicLoginSystem/cmake-build-debug /home/drewzn/Stuff/Programming/C++/Projects/Personal/basicLoginSystem/cmake-build-debug/CMakeFiles/basicLoginSystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/basicLoginSystem.dir/depend


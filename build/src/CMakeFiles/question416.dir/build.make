# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/heyjude/workspace/projects/leetcode_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/heyjude/workspace/projects/leetcode_cpp/build

# Include any dependencies generated for this target.
include src/CMakeFiles/question416.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/question416.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/question416.dir/flags.make

src/CMakeFiles/question416.dir/question416.cpp.o: src/CMakeFiles/question416.dir/flags.make
src/CMakeFiles/question416.dir/question416.cpp.o: ../src/question416.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heyjude/workspace/projects/leetcode_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/question416.dir/question416.cpp.o"
	cd /home/heyjude/workspace/projects/leetcode_cpp/build/src && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/question416.dir/question416.cpp.o -c /home/heyjude/workspace/projects/leetcode_cpp/src/question416.cpp

src/CMakeFiles/question416.dir/question416.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/question416.dir/question416.cpp.i"
	cd /home/heyjude/workspace/projects/leetcode_cpp/build/src && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/heyjude/workspace/projects/leetcode_cpp/src/question416.cpp > CMakeFiles/question416.dir/question416.cpp.i

src/CMakeFiles/question416.dir/question416.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/question416.dir/question416.cpp.s"
	cd /home/heyjude/workspace/projects/leetcode_cpp/build/src && /usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/heyjude/workspace/projects/leetcode_cpp/src/question416.cpp -o CMakeFiles/question416.dir/question416.cpp.s

src/CMakeFiles/question416.dir/question416.cpp.o.requires:

.PHONY : src/CMakeFiles/question416.dir/question416.cpp.o.requires

src/CMakeFiles/question416.dir/question416.cpp.o.provides: src/CMakeFiles/question416.dir/question416.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/question416.dir/build.make src/CMakeFiles/question416.dir/question416.cpp.o.provides.build
.PHONY : src/CMakeFiles/question416.dir/question416.cpp.o.provides

src/CMakeFiles/question416.dir/question416.cpp.o.provides.build: src/CMakeFiles/question416.dir/question416.cpp.o


# Object files for target question416
question416_OBJECTS = \
"CMakeFiles/question416.dir/question416.cpp.o"

# External object files for target question416
question416_EXTERNAL_OBJECTS =

src/question416: src/CMakeFiles/question416.dir/question416.cpp.o
src/question416: src/CMakeFiles/question416.dir/build.make
src/question416: src/CMakeFiles/question416.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/heyjude/workspace/projects/leetcode_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable question416"
	cd /home/heyjude/workspace/projects/leetcode_cpp/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/question416.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/question416.dir/build: src/question416

.PHONY : src/CMakeFiles/question416.dir/build

src/CMakeFiles/question416.dir/requires: src/CMakeFiles/question416.dir/question416.cpp.o.requires

.PHONY : src/CMakeFiles/question416.dir/requires

src/CMakeFiles/question416.dir/clean:
	cd /home/heyjude/workspace/projects/leetcode_cpp/build/src && $(CMAKE_COMMAND) -P CMakeFiles/question416.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/question416.dir/clean

src/CMakeFiles/question416.dir/depend:
	cd /home/heyjude/workspace/projects/leetcode_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/heyjude/workspace/projects/leetcode_cpp /home/heyjude/workspace/projects/leetcode_cpp/src /home/heyjude/workspace/projects/leetcode_cpp/build /home/heyjude/workspace/projects/leetcode_cpp/build/src /home/heyjude/workspace/projects/leetcode_cpp/build/src/CMakeFiles/question416.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/question416.dir/depend


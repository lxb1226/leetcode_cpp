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
include src/CMakeFiles/question394.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/question394.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/question394.dir/flags.make

src/CMakeFiles/question394.dir/question394.cpp.o: src/CMakeFiles/question394.dir/flags.make
src/CMakeFiles/question394.dir/question394.cpp.o: ../src/question394.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heyjude/workspace/projects/leetcode_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/question394.dir/question394.cpp.o"
	cd /home/heyjude/workspace/projects/leetcode_cpp/build/src && /usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/question394.dir/question394.cpp.o -c /home/heyjude/workspace/projects/leetcode_cpp/src/question394.cpp

src/CMakeFiles/question394.dir/question394.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/question394.dir/question394.cpp.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_PREPROCESSED_SOURCE

src/CMakeFiles/question394.dir/question394.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/question394.dir/question394.cpp.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_ASSEMBLY_SOURCE

src/CMakeFiles/question394.dir/question394.cpp.o.requires:

.PHONY : src/CMakeFiles/question394.dir/question394.cpp.o.requires

src/CMakeFiles/question394.dir/question394.cpp.o.provides: src/CMakeFiles/question394.dir/question394.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/question394.dir/build.make src/CMakeFiles/question394.dir/question394.cpp.o.provides.build
.PHONY : src/CMakeFiles/question394.dir/question394.cpp.o.provides

src/CMakeFiles/question394.dir/question394.cpp.o.provides.build: src/CMakeFiles/question394.dir/question394.cpp.o


# Object files for target question394
question394_OBJECTS = \
"CMakeFiles/question394.dir/question394.cpp.o"

# External object files for target question394
question394_EXTERNAL_OBJECTS =

src/question394: src/CMakeFiles/question394.dir/question394.cpp.o
src/question394: src/CMakeFiles/question394.dir/build.make
src/question394: src/CMakeFiles/question394.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/heyjude/workspace/projects/leetcode_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable question394"
	cd /home/heyjude/workspace/projects/leetcode_cpp/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/question394.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/question394.dir/build: src/question394

.PHONY : src/CMakeFiles/question394.dir/build

src/CMakeFiles/question394.dir/requires: src/CMakeFiles/question394.dir/question394.cpp.o.requires

.PHONY : src/CMakeFiles/question394.dir/requires

src/CMakeFiles/question394.dir/clean:
	cd /home/heyjude/workspace/projects/leetcode_cpp/build/src && $(CMAKE_COMMAND) -P CMakeFiles/question394.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/question394.dir/clean

src/CMakeFiles/question394.dir/depend:
	cd /home/heyjude/workspace/projects/leetcode_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/heyjude/workspace/projects/leetcode_cpp /home/heyjude/workspace/projects/leetcode_cpp/src /home/heyjude/workspace/projects/leetcode_cpp/build /home/heyjude/workspace/projects/leetcode_cpp/build/src /home/heyjude/workspace/projects/leetcode_cpp/build/src/CMakeFiles/question394.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/question394.dir/depend


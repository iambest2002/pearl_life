# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /root/liupeng/pearl_house/pearl_house

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/liupeng/pearl_house/pearl_house/build

# Include any dependencies generated for this target.
include base_algorithm/example/caller/CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include base_algorithm/example/caller/CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include base_algorithm/example/caller/CMakeFiles/client.dir/flags.make

base_algorithm/example/caller/CMakeFiles/client.dir/caller.cpp.o: base_algorithm/example/caller/CMakeFiles/client.dir/flags.make
base_algorithm/example/caller/CMakeFiles/client.dir/caller.cpp.o: ../base_algorithm/example/caller/caller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/liupeng/pearl_house/pearl_house/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object base_algorithm/example/caller/CMakeFiles/client.dir/caller.cpp.o"
	cd /root/liupeng/pearl_house/pearl_house/build/base_algorithm/example/caller && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/caller.cpp.o -c /root/liupeng/pearl_house/pearl_house/base_algorithm/example/caller/caller.cpp

base_algorithm/example/caller/CMakeFiles/client.dir/caller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/caller.cpp.i"
	cd /root/liupeng/pearl_house/pearl_house/build/base_algorithm/example/caller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/liupeng/pearl_house/pearl_house/base_algorithm/example/caller/caller.cpp > CMakeFiles/client.dir/caller.cpp.i

base_algorithm/example/caller/CMakeFiles/client.dir/caller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/caller.cpp.s"
	cd /root/liupeng/pearl_house/pearl_house/build/base_algorithm/example/caller && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/liupeng/pearl_house/pearl_house/base_algorithm/example/caller/caller.cpp -o CMakeFiles/client.dir/caller.cpp.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/caller.cpp.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

../bin/client: base_algorithm/example/caller/CMakeFiles/client.dir/caller.cpp.o
../bin/client: base_algorithm/example/caller/CMakeFiles/client.dir/build.make
../bin/client: ../lib/libbase_algorithm.a
../bin/client: base_algorithm/example/caller/CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/liupeng/pearl_house/pearl_house/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../bin/client"
	cd /root/liupeng/pearl_house/pearl_house/build/base_algorithm/example/caller && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
base_algorithm/example/caller/CMakeFiles/client.dir/build: ../bin/client

.PHONY : base_algorithm/example/caller/CMakeFiles/client.dir/build

base_algorithm/example/caller/CMakeFiles/client.dir/clean:
	cd /root/liupeng/pearl_house/pearl_house/build/base_algorithm/example/caller && $(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : base_algorithm/example/caller/CMakeFiles/client.dir/clean

base_algorithm/example/caller/CMakeFiles/client.dir/depend:
	cd /root/liupeng/pearl_house/pearl_house/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/liupeng/pearl_house/pearl_house /root/liupeng/pearl_house/pearl_house/base_algorithm/example/caller /root/liupeng/pearl_house/pearl_house/build /root/liupeng/pearl_house/pearl_house/build/base_algorithm/example/caller /root/liupeng/pearl_house/pearl_house/build/base_algorithm/example/caller/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : base_algorithm/example/caller/CMakeFiles/client.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gaoyun/zxj_chatserver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gaoyun/zxj_chatserver

# Include any dependencies generated for this target.
include testmuduo/CMakeFiles/testserver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include testmuduo/CMakeFiles/testserver.dir/compiler_depend.make

# Include the progress variables for this target.
include testmuduo/CMakeFiles/testserver.dir/progress.make

# Include the compile flags for this target's objects.
include testmuduo/CMakeFiles/testserver.dir/flags.make

testmuduo/CMakeFiles/testserver.dir/testmuduo.cpp.o: testmuduo/CMakeFiles/testserver.dir/flags.make
testmuduo/CMakeFiles/testserver.dir/testmuduo.cpp.o: testmuduo/testmuduo.cpp
testmuduo/CMakeFiles/testserver.dir/testmuduo.cpp.o: testmuduo/CMakeFiles/testserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gaoyun/zxj_chatserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object testmuduo/CMakeFiles/testserver.dir/testmuduo.cpp.o"
	cd /home/gaoyun/zxj_chatserver/testmuduo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT testmuduo/CMakeFiles/testserver.dir/testmuduo.cpp.o -MF CMakeFiles/testserver.dir/testmuduo.cpp.o.d -o CMakeFiles/testserver.dir/testmuduo.cpp.o -c /home/gaoyun/zxj_chatserver/testmuduo/testmuduo.cpp

testmuduo/CMakeFiles/testserver.dir/testmuduo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/testserver.dir/testmuduo.cpp.i"
	cd /home/gaoyun/zxj_chatserver/testmuduo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gaoyun/zxj_chatserver/testmuduo/testmuduo.cpp > CMakeFiles/testserver.dir/testmuduo.cpp.i

testmuduo/CMakeFiles/testserver.dir/testmuduo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/testserver.dir/testmuduo.cpp.s"
	cd /home/gaoyun/zxj_chatserver/testmuduo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gaoyun/zxj_chatserver/testmuduo/testmuduo.cpp -o CMakeFiles/testserver.dir/testmuduo.cpp.s

# Object files for target testserver
testserver_OBJECTS = \
"CMakeFiles/testserver.dir/testmuduo.cpp.o"

# External object files for target testserver
testserver_EXTERNAL_OBJECTS =

bin/testserver: testmuduo/CMakeFiles/testserver.dir/testmuduo.cpp.o
bin/testserver: testmuduo/CMakeFiles/testserver.dir/build.make
bin/testserver: testmuduo/CMakeFiles/testserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/gaoyun/zxj_chatserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/testserver"
	cd /home/gaoyun/zxj_chatserver/testmuduo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
testmuduo/CMakeFiles/testserver.dir/build: bin/testserver
.PHONY : testmuduo/CMakeFiles/testserver.dir/build

testmuduo/CMakeFiles/testserver.dir/clean:
	cd /home/gaoyun/zxj_chatserver/testmuduo && $(CMAKE_COMMAND) -P CMakeFiles/testserver.dir/cmake_clean.cmake
.PHONY : testmuduo/CMakeFiles/testserver.dir/clean

testmuduo/CMakeFiles/testserver.dir/depend:
	cd /home/gaoyun/zxj_chatserver && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gaoyun/zxj_chatserver /home/gaoyun/zxj_chatserver/testmuduo /home/gaoyun/zxj_chatserver /home/gaoyun/zxj_chatserver/testmuduo /home/gaoyun/zxj_chatserver/testmuduo/CMakeFiles/testserver.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : testmuduo/CMakeFiles/testserver.dir/depend


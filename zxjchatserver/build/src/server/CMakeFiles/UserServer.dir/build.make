# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhao/tmpdir/chatserver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhao/tmpdir/chatserver/build

# Include any dependencies generated for this target.
include src/server/CMakeFiles/UserServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/server/CMakeFiles/UserServer.dir/compiler_depend.make

# Include the progress variables for this target.
include src/server/CMakeFiles/UserServer.dir/progress.make

# Include the compile flags for this target's objects.
include src/server/CMakeFiles/UserServer.dir/flags.make

src/server/CMakeFiles/UserServer.dir/chat.pb.cc.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/chat.pb.cc.o: ../src/server/chat.pb.cc
src/server/CMakeFiles/UserServer.dir/chat.pb.cc.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/server/CMakeFiles/UserServer.dir/chat.pb.cc.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/chat.pb.cc.o -MF CMakeFiles/UserServer.dir/chat.pb.cc.o.d -o CMakeFiles/UserServer.dir/chat.pb.cc.o -c /home/zhao/tmpdir/chatserver/src/server/chat.pb.cc

src/server/CMakeFiles/UserServer.dir/chat.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/chat.pb.cc.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/chat.pb.cc > CMakeFiles/UserServer.dir/chat.pb.cc.i

src/server/CMakeFiles/UserServer.dir/chat.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/chat.pb.cc.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/chat.pb.cc -o CMakeFiles/UserServer.dir/chat.pb.cc.s

src/server/CMakeFiles/UserServer.dir/chatserver.cpp.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/chatserver.cpp.o: ../src/server/chatserver.cpp
src/server/CMakeFiles/UserServer.dir/chatserver.cpp.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/server/CMakeFiles/UserServer.dir/chatserver.cpp.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/chatserver.cpp.o -MF CMakeFiles/UserServer.dir/chatserver.cpp.o.d -o CMakeFiles/UserServer.dir/chatserver.cpp.o -c /home/zhao/tmpdir/chatserver/src/server/chatserver.cpp

src/server/CMakeFiles/UserServer.dir/chatserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/chatserver.cpp.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/chatserver.cpp > CMakeFiles/UserServer.dir/chatserver.cpp.i

src/server/CMakeFiles/UserServer.dir/chatserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/chatserver.cpp.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/chatserver.cpp -o CMakeFiles/UserServer.dir/chatserver.cpp.s

src/server/CMakeFiles/UserServer.dir/chatservice.cpp.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/chatservice.cpp.o: ../src/server/chatservice.cpp
src/server/CMakeFiles/UserServer.dir/chatservice.cpp.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/server/CMakeFiles/UserServer.dir/chatservice.cpp.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/chatservice.cpp.o -MF CMakeFiles/UserServer.dir/chatservice.cpp.o.d -o CMakeFiles/UserServer.dir/chatservice.cpp.o -c /home/zhao/tmpdir/chatserver/src/server/chatservice.cpp

src/server/CMakeFiles/UserServer.dir/chatservice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/chatservice.cpp.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/chatservice.cpp > CMakeFiles/UserServer.dir/chatservice.cpp.i

src/server/CMakeFiles/UserServer.dir/chatservice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/chatservice.cpp.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/chatservice.cpp -o CMakeFiles/UserServer.dir/chatservice.cpp.s

src/server/CMakeFiles/UserServer.dir/main.cpp.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/main.cpp.o: ../src/server/main.cpp
src/server/CMakeFiles/UserServer.dir/main.cpp.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/server/CMakeFiles/UserServer.dir/main.cpp.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/main.cpp.o -MF CMakeFiles/UserServer.dir/main.cpp.o.d -o CMakeFiles/UserServer.dir/main.cpp.o -c /home/zhao/tmpdir/chatserver/src/server/main.cpp

src/server/CMakeFiles/UserServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/main.cpp.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/main.cpp > CMakeFiles/UserServer.dir/main.cpp.i

src/server/CMakeFiles/UserServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/main.cpp.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/main.cpp -o CMakeFiles/UserServer.dir/main.cpp.s

src/server/CMakeFiles/UserServer.dir/userserver.cc.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/userserver.cc.o: ../src/server/userserver.cc
src/server/CMakeFiles/UserServer.dir/userserver.cc.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/server/CMakeFiles/UserServer.dir/userserver.cc.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/userserver.cc.o -MF CMakeFiles/UserServer.dir/userserver.cc.o.d -o CMakeFiles/UserServer.dir/userserver.cc.o -c /home/zhao/tmpdir/chatserver/src/server/userserver.cc

src/server/CMakeFiles/UserServer.dir/userserver.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/userserver.cc.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/userserver.cc > CMakeFiles/UserServer.dir/userserver.cc.i

src/server/CMakeFiles/UserServer.dir/userserver.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/userserver.cc.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/userserver.cc -o CMakeFiles/UserServer.dir/userserver.cc.s

src/server/CMakeFiles/UserServer.dir/userservice.cc.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/userservice.cc.o: ../src/server/userservice.cc
src/server/CMakeFiles/UserServer.dir/userservice.cc.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/server/CMakeFiles/UserServer.dir/userservice.cc.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/userservice.cc.o -MF CMakeFiles/UserServer.dir/userservice.cc.o.d -o CMakeFiles/UserServer.dir/userservice.cc.o -c /home/zhao/tmpdir/chatserver/src/server/userservice.cc

src/server/CMakeFiles/UserServer.dir/userservice.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/userservice.cc.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/userservice.cc > CMakeFiles/UserServer.dir/userservice.cc.i

src/server/CMakeFiles/UserServer.dir/userservice.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/userservice.cc.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/userservice.cc -o CMakeFiles/UserServer.dir/userservice.cc.s

src/server/CMakeFiles/UserServer.dir/db/db.cpp.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/db/db.cpp.o: ../src/server/db/db.cpp
src/server/CMakeFiles/UserServer.dir/db/db.cpp.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/server/CMakeFiles/UserServer.dir/db/db.cpp.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/db/db.cpp.o -MF CMakeFiles/UserServer.dir/db/db.cpp.o.d -o CMakeFiles/UserServer.dir/db/db.cpp.o -c /home/zhao/tmpdir/chatserver/src/server/db/db.cpp

src/server/CMakeFiles/UserServer.dir/db/db.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/db/db.cpp.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/db/db.cpp > CMakeFiles/UserServer.dir/db/db.cpp.i

src/server/CMakeFiles/UserServer.dir/db/db.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/db/db.cpp.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/db/db.cpp -o CMakeFiles/UserServer.dir/db/db.cpp.s

src/server/CMakeFiles/UserServer.dir/model/friendmodel.cpp.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/model/friendmodel.cpp.o: ../src/server/model/friendmodel.cpp
src/server/CMakeFiles/UserServer.dir/model/friendmodel.cpp.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/server/CMakeFiles/UserServer.dir/model/friendmodel.cpp.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/model/friendmodel.cpp.o -MF CMakeFiles/UserServer.dir/model/friendmodel.cpp.o.d -o CMakeFiles/UserServer.dir/model/friendmodel.cpp.o -c /home/zhao/tmpdir/chatserver/src/server/model/friendmodel.cpp

src/server/CMakeFiles/UserServer.dir/model/friendmodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/model/friendmodel.cpp.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/model/friendmodel.cpp > CMakeFiles/UserServer.dir/model/friendmodel.cpp.i

src/server/CMakeFiles/UserServer.dir/model/friendmodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/model/friendmodel.cpp.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/model/friendmodel.cpp -o CMakeFiles/UserServer.dir/model/friendmodel.cpp.s

src/server/CMakeFiles/UserServer.dir/model/group.cpp.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/model/group.cpp.o: ../src/server/model/group.cpp
src/server/CMakeFiles/UserServer.dir/model/group.cpp.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/server/CMakeFiles/UserServer.dir/model/group.cpp.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/model/group.cpp.o -MF CMakeFiles/UserServer.dir/model/group.cpp.o.d -o CMakeFiles/UserServer.dir/model/group.cpp.o -c /home/zhao/tmpdir/chatserver/src/server/model/group.cpp

src/server/CMakeFiles/UserServer.dir/model/group.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/model/group.cpp.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/model/group.cpp > CMakeFiles/UserServer.dir/model/group.cpp.i

src/server/CMakeFiles/UserServer.dir/model/group.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/model/group.cpp.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/model/group.cpp -o CMakeFiles/UserServer.dir/model/group.cpp.s

src/server/CMakeFiles/UserServer.dir/model/groupmodel.cpp.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/model/groupmodel.cpp.o: ../src/server/model/groupmodel.cpp
src/server/CMakeFiles/UserServer.dir/model/groupmodel.cpp.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/server/CMakeFiles/UserServer.dir/model/groupmodel.cpp.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/model/groupmodel.cpp.o -MF CMakeFiles/UserServer.dir/model/groupmodel.cpp.o.d -o CMakeFiles/UserServer.dir/model/groupmodel.cpp.o -c /home/zhao/tmpdir/chatserver/src/server/model/groupmodel.cpp

src/server/CMakeFiles/UserServer.dir/model/groupmodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/model/groupmodel.cpp.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/model/groupmodel.cpp > CMakeFiles/UserServer.dir/model/groupmodel.cpp.i

src/server/CMakeFiles/UserServer.dir/model/groupmodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/model/groupmodel.cpp.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/model/groupmodel.cpp -o CMakeFiles/UserServer.dir/model/groupmodel.cpp.s

src/server/CMakeFiles/UserServer.dir/model/groupuser.cpp.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/model/groupuser.cpp.o: ../src/server/model/groupuser.cpp
src/server/CMakeFiles/UserServer.dir/model/groupuser.cpp.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/server/CMakeFiles/UserServer.dir/model/groupuser.cpp.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/model/groupuser.cpp.o -MF CMakeFiles/UserServer.dir/model/groupuser.cpp.o.d -o CMakeFiles/UserServer.dir/model/groupuser.cpp.o -c /home/zhao/tmpdir/chatserver/src/server/model/groupuser.cpp

src/server/CMakeFiles/UserServer.dir/model/groupuser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/model/groupuser.cpp.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/model/groupuser.cpp > CMakeFiles/UserServer.dir/model/groupuser.cpp.i

src/server/CMakeFiles/UserServer.dir/model/groupuser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/model/groupuser.cpp.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/model/groupuser.cpp -o CMakeFiles/UserServer.dir/model/groupuser.cpp.s

src/server/CMakeFiles/UserServer.dir/model/offlinemessage.cpp.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/model/offlinemessage.cpp.o: ../src/server/model/offlinemessage.cpp
src/server/CMakeFiles/UserServer.dir/model/offlinemessage.cpp.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/server/CMakeFiles/UserServer.dir/model/offlinemessage.cpp.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/model/offlinemessage.cpp.o -MF CMakeFiles/UserServer.dir/model/offlinemessage.cpp.o.d -o CMakeFiles/UserServer.dir/model/offlinemessage.cpp.o -c /home/zhao/tmpdir/chatserver/src/server/model/offlinemessage.cpp

src/server/CMakeFiles/UserServer.dir/model/offlinemessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/model/offlinemessage.cpp.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/model/offlinemessage.cpp > CMakeFiles/UserServer.dir/model/offlinemessage.cpp.i

src/server/CMakeFiles/UserServer.dir/model/offlinemessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/model/offlinemessage.cpp.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/model/offlinemessage.cpp -o CMakeFiles/UserServer.dir/model/offlinemessage.cpp.s

src/server/CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.o: ../src/server/model/offlinemessagemodel.cpp
src/server/CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/server/CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.o -MF CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.o.d -o CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.o -c /home/zhao/tmpdir/chatserver/src/server/model/offlinemessagemodel.cpp

src/server/CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/model/offlinemessagemodel.cpp > CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.i

src/server/CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/model/offlinemessagemodel.cpp -o CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.s

src/server/CMakeFiles/UserServer.dir/model/user.cpp.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/model/user.cpp.o: ../src/server/model/user.cpp
src/server/CMakeFiles/UserServer.dir/model/user.cpp.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/server/CMakeFiles/UserServer.dir/model/user.cpp.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/model/user.cpp.o -MF CMakeFiles/UserServer.dir/model/user.cpp.o.d -o CMakeFiles/UserServer.dir/model/user.cpp.o -c /home/zhao/tmpdir/chatserver/src/server/model/user.cpp

src/server/CMakeFiles/UserServer.dir/model/user.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/model/user.cpp.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/model/user.cpp > CMakeFiles/UserServer.dir/model/user.cpp.i

src/server/CMakeFiles/UserServer.dir/model/user.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/model/user.cpp.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/model/user.cpp -o CMakeFiles/UserServer.dir/model/user.cpp.s

src/server/CMakeFiles/UserServer.dir/model/usermodel.cpp.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/model/usermodel.cpp.o: ../src/server/model/usermodel.cpp
src/server/CMakeFiles/UserServer.dir/model/usermodel.cpp.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object src/server/CMakeFiles/UserServer.dir/model/usermodel.cpp.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/model/usermodel.cpp.o -MF CMakeFiles/UserServer.dir/model/usermodel.cpp.o.d -o CMakeFiles/UserServer.dir/model/usermodel.cpp.o -c /home/zhao/tmpdir/chatserver/src/server/model/usermodel.cpp

src/server/CMakeFiles/UserServer.dir/model/usermodel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/model/usermodel.cpp.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/model/usermodel.cpp > CMakeFiles/UserServer.dir/model/usermodel.cpp.i

src/server/CMakeFiles/UserServer.dir/model/usermodel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/model/usermodel.cpp.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/model/usermodel.cpp -o CMakeFiles/UserServer.dir/model/usermodel.cpp.s

src/server/CMakeFiles/UserServer.dir/redis/redis.cpp.o: src/server/CMakeFiles/UserServer.dir/flags.make
src/server/CMakeFiles/UserServer.dir/redis/redis.cpp.o: ../src/server/redis/redis.cpp
src/server/CMakeFiles/UserServer.dir/redis/redis.cpp.o: src/server/CMakeFiles/UserServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object src/server/CMakeFiles/UserServer.dir/redis/redis.cpp.o"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/CMakeFiles/UserServer.dir/redis/redis.cpp.o -MF CMakeFiles/UserServer.dir/redis/redis.cpp.o.d -o CMakeFiles/UserServer.dir/redis/redis.cpp.o -c /home/zhao/tmpdir/chatserver/src/server/redis/redis.cpp

src/server/CMakeFiles/UserServer.dir/redis/redis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UserServer.dir/redis/redis.cpp.i"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhao/tmpdir/chatserver/src/server/redis/redis.cpp > CMakeFiles/UserServer.dir/redis/redis.cpp.i

src/server/CMakeFiles/UserServer.dir/redis/redis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UserServer.dir/redis/redis.cpp.s"
	cd /home/zhao/tmpdir/chatserver/build/src/server && /usr/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhao/tmpdir/chatserver/src/server/redis/redis.cpp -o CMakeFiles/UserServer.dir/redis/redis.cpp.s

# Object files for target UserServer
UserServer_OBJECTS = \
"CMakeFiles/UserServer.dir/chat.pb.cc.o" \
"CMakeFiles/UserServer.dir/chatserver.cpp.o" \
"CMakeFiles/UserServer.dir/chatservice.cpp.o" \
"CMakeFiles/UserServer.dir/main.cpp.o" \
"CMakeFiles/UserServer.dir/userserver.cc.o" \
"CMakeFiles/UserServer.dir/userservice.cc.o" \
"CMakeFiles/UserServer.dir/db/db.cpp.o" \
"CMakeFiles/UserServer.dir/model/friendmodel.cpp.o" \
"CMakeFiles/UserServer.dir/model/group.cpp.o" \
"CMakeFiles/UserServer.dir/model/groupmodel.cpp.o" \
"CMakeFiles/UserServer.dir/model/groupuser.cpp.o" \
"CMakeFiles/UserServer.dir/model/offlinemessage.cpp.o" \
"CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.o" \
"CMakeFiles/UserServer.dir/model/user.cpp.o" \
"CMakeFiles/UserServer.dir/model/usermodel.cpp.o" \
"CMakeFiles/UserServer.dir/redis/redis.cpp.o"

# External object files for target UserServer
UserServer_EXTERNAL_OBJECTS =

../bin/UserServer: src/server/CMakeFiles/UserServer.dir/chat.pb.cc.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/chatserver.cpp.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/chatservice.cpp.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/main.cpp.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/userserver.cc.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/userservice.cc.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/db/db.cpp.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/model/friendmodel.cpp.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/model/group.cpp.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/model/groupmodel.cpp.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/model/groupuser.cpp.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/model/offlinemessage.cpp.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/model/offlinemessagemodel.cpp.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/model/user.cpp.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/model/usermodel.cpp.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/redis/redis.cpp.o
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/build.make
../bin/UserServer: src/server/CMakeFiles/UserServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhao/tmpdir/chatserver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable ../../../bin/UserServer"
	cd /home/zhao/tmpdir/chatserver/build/src/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UserServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/server/CMakeFiles/UserServer.dir/build: ../bin/UserServer
.PHONY : src/server/CMakeFiles/UserServer.dir/build

src/server/CMakeFiles/UserServer.dir/clean:
	cd /home/zhao/tmpdir/chatserver/build/src/server && $(CMAKE_COMMAND) -P CMakeFiles/UserServer.dir/cmake_clean.cmake
.PHONY : src/server/CMakeFiles/UserServer.dir/clean

src/server/CMakeFiles/UserServer.dir/depend:
	cd /home/zhao/tmpdir/chatserver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhao/tmpdir/chatserver /home/zhao/tmpdir/chatserver/src/server /home/zhao/tmpdir/chatserver/build /home/zhao/tmpdir/chatserver/build/src/server /home/zhao/tmpdir/chatserver/build/src/server/CMakeFiles/UserServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/server/CMakeFiles/UserServer.dir/depend

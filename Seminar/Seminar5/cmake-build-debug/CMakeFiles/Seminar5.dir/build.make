# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\231.9011.31\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\231.9011.31\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Programming\Object-Oriented-Programming\Seminar\Seminar5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Programming\Object-Oriented-Programming\Seminar\Seminar5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Seminar5.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Seminar5.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Seminar5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Seminar5.dir/flags.make

CMakeFiles/Seminar5.dir/main.cpp.obj: CMakeFiles/Seminar5.dir/flags.make
CMakeFiles/Seminar5.dir/main.cpp.obj: D:/Programming/Object-Oriented-Programming/Seminar/Seminar5/main.cpp
CMakeFiles/Seminar5.dir/main.cpp.obj: CMakeFiles/Seminar5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programming\Object-Oriented-Programming\Seminar\Seminar5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Seminar5.dir/main.cpp.obj"
	C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\231.9011.31\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Seminar5.dir/main.cpp.obj -MF CMakeFiles\Seminar5.dir\main.cpp.obj.d -o CMakeFiles\Seminar5.dir\main.cpp.obj -c D:\Programming\Object-Oriented-Programming\Seminar\Seminar5\main.cpp

CMakeFiles/Seminar5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Seminar5.dir/main.cpp.i"
	C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\231.9011.31\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programming\Object-Oriented-Programming\Seminar\Seminar5\main.cpp > CMakeFiles\Seminar5.dir\main.cpp.i

CMakeFiles/Seminar5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Seminar5.dir/main.cpp.s"
	C:\Users\boboo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\231.9011.31\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programming\Object-Oriented-Programming\Seminar\Seminar5\main.cpp -o CMakeFiles\Seminar5.dir\main.cpp.s

# Object files for target Seminar5
Seminar5_OBJECTS = \
"CMakeFiles/Seminar5.dir/main.cpp.obj"

# External object files for target Seminar5
Seminar5_EXTERNAL_OBJECTS =

Seminar5.exe: CMakeFiles/Seminar5.dir/main.cpp.obj
Seminar5.exe: CMakeFiles/Seminar5.dir/build.make
Seminar5.exe: CMakeFiles/Seminar5.dir/linkLibs.rsp
Seminar5.exe: CMakeFiles/Seminar5.dir/objects1
Seminar5.exe: CMakeFiles/Seminar5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Programming\Object-Oriented-Programming\Seminar\Seminar5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Seminar5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Seminar5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Seminar5.dir/build: Seminar5.exe
.PHONY : CMakeFiles/Seminar5.dir/build

CMakeFiles/Seminar5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Seminar5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Seminar5.dir/clean

CMakeFiles/Seminar5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Programming\Object-Oriented-Programming\Seminar\Seminar5 D:\Programming\Object-Oriented-Programming\Seminar\Seminar5 D:\Programming\Object-Oriented-Programming\Seminar\Seminar5\cmake-build-debug D:\Programming\Object-Oriented-Programming\Seminar\Seminar5\cmake-build-debug D:\Programming\Object-Oriented-Programming\Seminar\Seminar5\cmake-build-debug\CMakeFiles\Seminar5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Seminar5.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\nguye\Desktop\New project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\nguye\Desktop\New project\build"

# Include any dependencies generated for this target.
include CMakeFiles/newproject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/newproject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/newproject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/newproject.dir/flags.make

CMakeFiles/newproject.dir/main.cpp.obj: CMakeFiles/newproject.dir/flags.make
CMakeFiles/newproject.dir/main.cpp.obj: C:/Users/nguye/Desktop/New\ project/main.cpp
CMakeFiles/newproject.dir/main.cpp.obj: CMakeFiles/newproject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\nguye\Desktop\New project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/newproject.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/newproject.dir/main.cpp.obj -MF CMakeFiles\newproject.dir\main.cpp.obj.d -o CMakeFiles\newproject.dir\main.cpp.obj -c "C:\Users\nguye\Desktop\New project\main.cpp"

CMakeFiles/newproject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/newproject.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\nguye\Desktop\New project\main.cpp" > CMakeFiles\newproject.dir\main.cpp.i

CMakeFiles/newproject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/newproject.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\nguye\Desktop\New project\main.cpp" -o CMakeFiles\newproject.dir\main.cpp.s

# Object files for target newproject
newproject_OBJECTS = \
"CMakeFiles/newproject.dir/main.cpp.obj"

# External object files for target newproject
newproject_EXTERNAL_OBJECTS =

newproject.exe: CMakeFiles/newproject.dir/main.cpp.obj
newproject.exe: CMakeFiles/newproject.dir/build.make
newproject.exe: CMakeFiles/newproject.dir/linkLibs.rsp
newproject.exe: CMakeFiles/newproject.dir/objects1.rsp
newproject.exe: CMakeFiles/newproject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\nguye\Desktop\New project\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable newproject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\newproject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/newproject.dir/build: newproject.exe
.PHONY : CMakeFiles/newproject.dir/build

CMakeFiles/newproject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\newproject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/newproject.dir/clean

CMakeFiles/newproject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\nguye\Desktop\New project" "C:\Users\nguye\Desktop\New project" "C:\Users\nguye\Desktop\New project\build" "C:\Users\nguye\Desktop\New project\build" "C:\Users\nguye\Desktop\New project\build\CMakeFiles\newproject.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/newproject.dir/depend


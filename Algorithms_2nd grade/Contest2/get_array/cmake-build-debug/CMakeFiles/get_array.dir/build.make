# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\User\Contests_2nd grade\Contest2\get_array"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\User\Contests_2nd grade\Contest2\get_array\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/get_array.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/get_array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/get_array.dir/flags.make

CMakeFiles/get_array.dir/get_array.cpp.obj: CMakeFiles/get_array.dir/flags.make
CMakeFiles/get_array.dir/get_array.cpp.obj: ../get_array.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Contests_2nd grade\Contest2\get_array\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/get_array.dir/get_array.cpp.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\get_array.dir\get_array.cpp.obj -c "C:\Users\User\Contests_2nd grade\Contest2\get_array\get_array.cpp"

CMakeFiles/get_array.dir/get_array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/get_array.dir/get_array.cpp.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Contests_2nd grade\Contest2\get_array\get_array.cpp" > CMakeFiles\get_array.dir\get_array.cpp.i

CMakeFiles/get_array.dir/get_array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/get_array.dir/get_array.cpp.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Contests_2nd grade\Contest2\get_array\get_array.cpp" -o CMakeFiles\get_array.dir\get_array.cpp.s

# Object files for target get_array
get_array_OBJECTS = \
"CMakeFiles/get_array.dir/get_array.cpp.obj"

# External object files for target get_array
get_array_EXTERNAL_OBJECTS =

get_array.exe: CMakeFiles/get_array.dir/get_array.cpp.obj
get_array.exe: CMakeFiles/get_array.dir/build.make
get_array.exe: CMakeFiles/get_array.dir/linklibs.rsp
get_array.exe: CMakeFiles/get_array.dir/objects1.rsp
get_array.exe: CMakeFiles/get_array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\User\Contests_2nd grade\Contest2\get_array\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable get_array.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\get_array.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/get_array.dir/build: get_array.exe
.PHONY : CMakeFiles/get_array.dir/build

CMakeFiles/get_array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\get_array.dir\cmake_clean.cmake
.PHONY : CMakeFiles/get_array.dir/clean

CMakeFiles/get_array.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\Contests_2nd grade\Contest2\get_array" "C:\Users\User\Contests_2nd grade\Contest2\get_array" "C:\Users\User\Contests_2nd grade\Contest2\get_array\cmake-build-debug" "C:\Users\User\Contests_2nd grade\Contest2\get_array\cmake-build-debug" "C:\Users\User\Contests_2nd grade\Contest2\get_array\cmake-build-debug\CMakeFiles\get_array.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/get_array.dir/depend


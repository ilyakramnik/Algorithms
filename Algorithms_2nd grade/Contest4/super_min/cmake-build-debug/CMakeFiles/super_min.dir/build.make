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
CMAKE_SOURCE_DIR = "C:\Users\User\Contests_2nd grade\Contest4\super_min"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\User\Contests_2nd grade\Contest4\super_min\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/super_min.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/super_min.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/super_min.dir/flags.make

CMakeFiles/super_min.dir/main.cpp.obj: CMakeFiles/super_min.dir/flags.make
CMakeFiles/super_min.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Contests_2nd grade\Contest4\super_min\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/super_min.dir/main.cpp.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\super_min.dir\main.cpp.obj -c "C:\Users\User\Contests_2nd grade\Contest4\super_min\main.cpp"

CMakeFiles/super_min.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/super_min.dir/main.cpp.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Contests_2nd grade\Contest4\super_min\main.cpp" > CMakeFiles\super_min.dir\main.cpp.i

CMakeFiles/super_min.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/super_min.dir/main.cpp.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Contests_2nd grade\Contest4\super_min\main.cpp" -o CMakeFiles\super_min.dir\main.cpp.s

# Object files for target super_min
super_min_OBJECTS = \
"CMakeFiles/super_min.dir/main.cpp.obj"

# External object files for target super_min
super_min_EXTERNAL_OBJECTS =

super_min.exe: CMakeFiles/super_min.dir/main.cpp.obj
super_min.exe: CMakeFiles/super_min.dir/build.make
super_min.exe: CMakeFiles/super_min.dir/linklibs.rsp
super_min.exe: CMakeFiles/super_min.dir/objects1.rsp
super_min.exe: CMakeFiles/super_min.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\User\Contests_2nd grade\Contest4\super_min\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable super_min.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\super_min.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/super_min.dir/build: super_min.exe
.PHONY : CMakeFiles/super_min.dir/build

CMakeFiles/super_min.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\super_min.dir\cmake_clean.cmake
.PHONY : CMakeFiles/super_min.dir/clean

CMakeFiles/super_min.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\Contests_2nd grade\Contest4\super_min" "C:\Users\User\Contests_2nd grade\Contest4\super_min" "C:\Users\User\Contests_2nd grade\Contest4\super_min\cmake-build-debug" "C:\Users\User\Contests_2nd grade\Contest4\super_min\cmake-build-debug" "C:\Users\User\Contests_2nd grade\Contest4\super_min\cmake-build-debug\CMakeFiles\super_min.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/super_min.dir/depend


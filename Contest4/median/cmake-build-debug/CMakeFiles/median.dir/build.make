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
CMAKE_SOURCE_DIR = "C:\Users\User\Contests_2nd grade\Contest4\median"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\User\Contests_2nd grade\Contest4\median\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/median.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/median.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/median.dir/flags.make

CMakeFiles/median.dir/main.cpp.obj: CMakeFiles/median.dir/flags.make
CMakeFiles/median.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Contests_2nd grade\Contest4\median\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/median.dir/main.cpp.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\median.dir\main.cpp.obj -c "C:\Users\User\Contests_2nd grade\Contest4\median\main.cpp"

CMakeFiles/median.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/median.dir/main.cpp.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Contests_2nd grade\Contest4\median\main.cpp" > CMakeFiles\median.dir\main.cpp.i

CMakeFiles/median.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/median.dir/main.cpp.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Contests_2nd grade\Contest4\median\main.cpp" -o CMakeFiles\median.dir\main.cpp.s

# Object files for target median
median_OBJECTS = \
"CMakeFiles/median.dir/main.cpp.obj"

# External object files for target median
median_EXTERNAL_OBJECTS =

median.exe: CMakeFiles/median.dir/main.cpp.obj
median.exe: CMakeFiles/median.dir/build.make
median.exe: CMakeFiles/median.dir/linklibs.rsp
median.exe: CMakeFiles/median.dir/objects1.rsp
median.exe: CMakeFiles/median.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\User\Contests_2nd grade\Contest4\median\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable median.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\median.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/median.dir/build: median.exe
.PHONY : CMakeFiles/median.dir/build

CMakeFiles/median.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\median.dir\cmake_clean.cmake
.PHONY : CMakeFiles/median.dir/clean

CMakeFiles/median.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\Contests_2nd grade\Contest4\median" "C:\Users\User\Contests_2nd grade\Contest4\median" "C:\Users\User\Contests_2nd grade\Contest4\median\cmake-build-debug" "C:\Users\User\Contests_2nd grade\Contest4\median\cmake-build-debug" "C:\Users\User\Contests_2nd grade\Contest4\median\cmake-build-debug\CMakeFiles\median.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/median.dir/depend


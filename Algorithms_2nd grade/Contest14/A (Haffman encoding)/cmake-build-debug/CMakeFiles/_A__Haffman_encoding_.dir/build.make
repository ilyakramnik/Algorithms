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
CMAKE_SOURCE_DIR = "C:\Users\User\Algorithms\Algorithms_2nd grade\Contest14\A (Haffman encoding)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\User\Algorithms\Algorithms_2nd grade\Contest14\A (Haffman encoding)\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/_A__Haffman_encoding_.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/_A__Haffman_encoding_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_A__Haffman_encoding_.dir/flags.make

CMakeFiles/_A__Haffman_encoding_.dir/main.cpp.obj: CMakeFiles/_A__Haffman_encoding_.dir/flags.make
CMakeFiles/_A__Haffman_encoding_.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Algorithms\Algorithms_2nd grade\Contest14\A (Haffman encoding)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/_A__Haffman_encoding_.dir/main.cpp.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\_A__Haffman_encoding_.dir\main.cpp.obj -c "C:\Users\User\Algorithms\Algorithms_2nd grade\Contest14\A (Haffman encoding)\main.cpp"

CMakeFiles/_A__Haffman_encoding_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_A__Haffman_encoding_.dir/main.cpp.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Algorithms\Algorithms_2nd grade\Contest14\A (Haffman encoding)\main.cpp" > CMakeFiles\_A__Haffman_encoding_.dir\main.cpp.i

CMakeFiles/_A__Haffman_encoding_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_A__Haffman_encoding_.dir/main.cpp.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Algorithms\Algorithms_2nd grade\Contest14\A (Haffman encoding)\main.cpp" -o CMakeFiles\_A__Haffman_encoding_.dir\main.cpp.s

# Object files for target _A__Haffman_encoding_
_A__Haffman_encoding__OBJECTS = \
"CMakeFiles/_A__Haffman_encoding_.dir/main.cpp.obj"

# External object files for target _A__Haffman_encoding_
_A__Haffman_encoding__EXTERNAL_OBJECTS =

_A__Haffman_encoding_.exe: CMakeFiles/_A__Haffman_encoding_.dir/main.cpp.obj
_A__Haffman_encoding_.exe: CMakeFiles/_A__Haffman_encoding_.dir/build.make
_A__Haffman_encoding_.exe: CMakeFiles/_A__Haffman_encoding_.dir/linklibs.rsp
_A__Haffman_encoding_.exe: CMakeFiles/_A__Haffman_encoding_.dir/objects1.rsp
_A__Haffman_encoding_.exe: CMakeFiles/_A__Haffman_encoding_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\User\Algorithms\Algorithms_2nd grade\Contest14\A (Haffman encoding)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable _A__Haffman_encoding_.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\_A__Haffman_encoding_.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_A__Haffman_encoding_.dir/build: _A__Haffman_encoding_.exe
.PHONY : CMakeFiles/_A__Haffman_encoding_.dir/build

CMakeFiles/_A__Haffman_encoding_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\_A__Haffman_encoding_.dir\cmake_clean.cmake
.PHONY : CMakeFiles/_A__Haffman_encoding_.dir/clean

CMakeFiles/_A__Haffman_encoding_.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\Algorithms\Algorithms_2nd grade\Contest14\A (Haffman encoding)" "C:\Users\User\Algorithms\Algorithms_2nd grade\Contest14\A (Haffman encoding)" "C:\Users\User\Algorithms\Algorithms_2nd grade\Contest14\A (Haffman encoding)\cmake-build-debug" "C:\Users\User\Algorithms\Algorithms_2nd grade\Contest14\A (Haffman encoding)\cmake-build-debug" "C:\Users\User\Algorithms\Algorithms_2nd grade\Contest14\A (Haffman encoding)\cmake-build-debug\CMakeFiles\_A__Haffman_encoding_.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/_A__Haffman_encoding_.dir/depend

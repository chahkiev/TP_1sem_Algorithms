# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Desktop\Alg1_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Desktop\Alg1_3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Alg1_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Alg1_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Alg1_3.dir/flags.make

CMakeFiles/Alg1_3.dir/main.cpp.obj: CMakeFiles/Alg1_3.dir/flags.make
CMakeFiles/Alg1_3.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Desktop\Alg1_3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Alg1_3.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Alg1_3.dir\main.cpp.obj -c D:\Desktop\Alg1_3\main.cpp

CMakeFiles/Alg1_3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alg1_3.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Desktop\Alg1_3\main.cpp > CMakeFiles\Alg1_3.dir\main.cpp.i

CMakeFiles/Alg1_3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alg1_3.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Desktop\Alg1_3\main.cpp -o CMakeFiles\Alg1_3.dir\main.cpp.s

# Object files for target Alg1_3
Alg1_3_OBJECTS = \
"CMakeFiles/Alg1_3.dir/main.cpp.obj"

# External object files for target Alg1_3
Alg1_3_EXTERNAL_OBJECTS =

Alg1_3.exe: CMakeFiles/Alg1_3.dir/main.cpp.obj
Alg1_3.exe: CMakeFiles/Alg1_3.dir/build.make
Alg1_3.exe: CMakeFiles/Alg1_3.dir/linklibs.rsp
Alg1_3.exe: CMakeFiles/Alg1_3.dir/objects1.rsp
Alg1_3.exe: CMakeFiles/Alg1_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Desktop\Alg1_3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Alg1_3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Alg1_3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Alg1_3.dir/build: Alg1_3.exe

.PHONY : CMakeFiles/Alg1_3.dir/build

CMakeFiles/Alg1_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Alg1_3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Alg1_3.dir/clean

CMakeFiles/Alg1_3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Desktop\Alg1_3 D:\Desktop\Alg1_3 D:\Desktop\Alg1_3\cmake-build-debug D:\Desktop\Alg1_3\cmake-build-debug D:\Desktop\Alg1_3\cmake-build-debug\CMakeFiles\Alg1_3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Alg1_3.dir/depend


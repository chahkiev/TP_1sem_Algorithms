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
CMAKE_SOURCE_DIR = D:\Desktop\Alg_2_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Desktop\Alg_2_3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Alg_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Alg_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Alg_2.dir/flags.make

CMakeFiles/Alg_2.dir/main.cpp.obj: CMakeFiles/Alg_2.dir/flags.make
CMakeFiles/Alg_2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Desktop\Alg_2_3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Alg_2.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Alg_2.dir\main.cpp.obj -c D:\Desktop\Alg_2_3\main.cpp

CMakeFiles/Alg_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Alg_2.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Desktop\Alg_2_3\main.cpp > CMakeFiles\Alg_2.dir\main.cpp.i

CMakeFiles/Alg_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Alg_2.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Desktop\Alg_2_3\main.cpp -o CMakeFiles\Alg_2.dir\main.cpp.s

# Object files for target Alg_2
Alg_2_OBJECTS = \
"CMakeFiles/Alg_2.dir/main.cpp.obj"

# External object files for target Alg_2
Alg_2_EXTERNAL_OBJECTS =

Alg_2.exe: CMakeFiles/Alg_2.dir/main.cpp.obj
Alg_2.exe: CMakeFiles/Alg_2.dir/build.make
Alg_2.exe: CMakeFiles/Alg_2.dir/linklibs.rsp
Alg_2.exe: CMakeFiles/Alg_2.dir/objects1.rsp
Alg_2.exe: CMakeFiles/Alg_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Desktop\Alg_2_3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Alg_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Alg_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Alg_2.dir/build: Alg_2.exe

.PHONY : CMakeFiles/Alg_2.dir/build

CMakeFiles/Alg_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Alg_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Alg_2.dir/clean

CMakeFiles/Alg_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Desktop\Alg_2_3 D:\Desktop\Alg_2_3 D:\Desktop\Alg_2_3\cmake-build-debug D:\Desktop\Alg_2_3\cmake-build-debug D:\Desktop\Alg_2_3\cmake-build-debug\CMakeFiles\Alg_2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Alg_2.dir/depend


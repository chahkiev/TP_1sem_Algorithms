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
CMAKE_SOURCE_DIR = D:\Desktop\Alg_6_4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Desktop\Alg_6_4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/alg_6_4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/alg_6_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/alg_6_4.dir/flags.make

CMakeFiles/alg_6_4.dir/main.cpp.obj: CMakeFiles/alg_6_4.dir/flags.make
CMakeFiles/alg_6_4.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Desktop\Alg_6_4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/alg_6_4.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\alg_6_4.dir\main.cpp.obj -c D:\Desktop\Alg_6_4\main.cpp

CMakeFiles/alg_6_4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alg_6_4.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Desktop\Alg_6_4\main.cpp > CMakeFiles\alg_6_4.dir\main.cpp.i

CMakeFiles/alg_6_4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alg_6_4.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Desktop\Alg_6_4\main.cpp -o CMakeFiles\alg_6_4.dir\main.cpp.s

# Object files for target alg_6_4
alg_6_4_OBJECTS = \
"CMakeFiles/alg_6_4.dir/main.cpp.obj"

# External object files for target alg_6_4
alg_6_4_EXTERNAL_OBJECTS =

alg_6_4.exe: CMakeFiles/alg_6_4.dir/main.cpp.obj
alg_6_4.exe: CMakeFiles/alg_6_4.dir/build.make
alg_6_4.exe: CMakeFiles/alg_6_4.dir/linklibs.rsp
alg_6_4.exe: CMakeFiles/alg_6_4.dir/objects1.rsp
alg_6_4.exe: CMakeFiles/alg_6_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Desktop\Alg_6_4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable alg_6_4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\alg_6_4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/alg_6_4.dir/build: alg_6_4.exe

.PHONY : CMakeFiles/alg_6_4.dir/build

CMakeFiles/alg_6_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\alg_6_4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/alg_6_4.dir/clean

CMakeFiles/alg_6_4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Desktop\Alg_6_4 D:\Desktop\Alg_6_4 D:\Desktop\Alg_6_4\cmake-build-debug D:\Desktop\Alg_6_4\cmake-build-debug D:\Desktop\Alg_6_4\cmake-build-debug\CMakeFiles\alg_6_4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/alg_6_4.dir/depend


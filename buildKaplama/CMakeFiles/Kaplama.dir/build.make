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
CMAKE_SOURCE_DIR = C:\Users\ismet\OPENGLEGITIM\Kaplama

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ismet\OPENGLEGITIM\buildKaplama

# Include any dependencies generated for this target.
include CMakeFiles/Kaplama.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Kaplama.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Kaplama.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Kaplama.dir/flags.make

CMakeFiles/Kaplama.dir/src/main.cpp.obj: CMakeFiles/Kaplama.dir/flags.make
CMakeFiles/Kaplama.dir/src/main.cpp.obj: CMakeFiles/Kaplama.dir/includes_CXX.rsp
CMakeFiles/Kaplama.dir/src/main.cpp.obj: C:/Users/ismet/OPENGLEGITIM/Kaplama/src/main.cpp
CMakeFiles/Kaplama.dir/src/main.cpp.obj: CMakeFiles/Kaplama.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ismet\OPENGLEGITIM\buildKaplama\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Kaplama.dir/src/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Kaplama.dir/src/main.cpp.obj -MF CMakeFiles\Kaplama.dir\src\main.cpp.obj.d -o CMakeFiles\Kaplama.dir\src\main.cpp.obj -c C:\Users\ismet\OPENGLEGITIM\Kaplama\src\main.cpp

CMakeFiles/Kaplama.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kaplama.dir/src/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ismet\OPENGLEGITIM\Kaplama\src\main.cpp > CMakeFiles\Kaplama.dir\src\main.cpp.i

CMakeFiles/Kaplama.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kaplama.dir/src/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ismet\OPENGLEGITIM\Kaplama\src\main.cpp -o CMakeFiles\Kaplama.dir\src\main.cpp.s

CMakeFiles/Kaplama.dir/src/glad.c.obj: CMakeFiles/Kaplama.dir/flags.make
CMakeFiles/Kaplama.dir/src/glad.c.obj: CMakeFiles/Kaplama.dir/includes_C.rsp
CMakeFiles/Kaplama.dir/src/glad.c.obj: C:/Users/ismet/OPENGLEGITIM/Kaplama/src/glad.c
CMakeFiles/Kaplama.dir/src/glad.c.obj: CMakeFiles/Kaplama.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ismet\OPENGLEGITIM\buildKaplama\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Kaplama.dir/src/glad.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Kaplama.dir/src/glad.c.obj -MF CMakeFiles\Kaplama.dir\src\glad.c.obj.d -o CMakeFiles\Kaplama.dir\src\glad.c.obj -c C:\Users\ismet\OPENGLEGITIM\Kaplama\src\glad.c

CMakeFiles/Kaplama.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Kaplama.dir/src/glad.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ismet\OPENGLEGITIM\Kaplama\src\glad.c > CMakeFiles\Kaplama.dir\src\glad.c.i

CMakeFiles/Kaplama.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Kaplama.dir/src/glad.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ismet\OPENGLEGITIM\Kaplama\src\glad.c -o CMakeFiles\Kaplama.dir\src\glad.c.s

CMakeFiles/Kaplama.dir/src/shaderprogram.cpp.obj: CMakeFiles/Kaplama.dir/flags.make
CMakeFiles/Kaplama.dir/src/shaderprogram.cpp.obj: CMakeFiles/Kaplama.dir/includes_CXX.rsp
CMakeFiles/Kaplama.dir/src/shaderprogram.cpp.obj: C:/Users/ismet/OPENGLEGITIM/Kaplama/src/shaderprogram.cpp
CMakeFiles/Kaplama.dir/src/shaderprogram.cpp.obj: CMakeFiles/Kaplama.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ismet\OPENGLEGITIM\buildKaplama\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Kaplama.dir/src/shaderprogram.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Kaplama.dir/src/shaderprogram.cpp.obj -MF CMakeFiles\Kaplama.dir\src\shaderprogram.cpp.obj.d -o CMakeFiles\Kaplama.dir\src\shaderprogram.cpp.obj -c C:\Users\ismet\OPENGLEGITIM\Kaplama\src\shaderprogram.cpp

CMakeFiles/Kaplama.dir/src/shaderprogram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kaplama.dir/src/shaderprogram.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ismet\OPENGLEGITIM\Kaplama\src\shaderprogram.cpp > CMakeFiles\Kaplama.dir\src\shaderprogram.cpp.i

CMakeFiles/Kaplama.dir/src/shaderprogram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kaplama.dir/src/shaderprogram.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ismet\OPENGLEGITIM\Kaplama\src\shaderprogram.cpp -o CMakeFiles\Kaplama.dir\src\shaderprogram.cpp.s

CMakeFiles/Kaplama.dir/src/square.cpp.obj: CMakeFiles/Kaplama.dir/flags.make
CMakeFiles/Kaplama.dir/src/square.cpp.obj: CMakeFiles/Kaplama.dir/includes_CXX.rsp
CMakeFiles/Kaplama.dir/src/square.cpp.obj: C:/Users/ismet/OPENGLEGITIM/Kaplama/src/square.cpp
CMakeFiles/Kaplama.dir/src/square.cpp.obj: CMakeFiles/Kaplama.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ismet\OPENGLEGITIM\buildKaplama\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Kaplama.dir/src/square.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Kaplama.dir/src/square.cpp.obj -MF CMakeFiles\Kaplama.dir\src\square.cpp.obj.d -o CMakeFiles\Kaplama.dir\src\square.cpp.obj -c C:\Users\ismet\OPENGLEGITIM\Kaplama\src\square.cpp

CMakeFiles/Kaplama.dir/src/square.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kaplama.dir/src/square.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ismet\OPENGLEGITIM\Kaplama\src\square.cpp > CMakeFiles\Kaplama.dir\src\square.cpp.i

CMakeFiles/Kaplama.dir/src/square.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kaplama.dir/src/square.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ismet\OPENGLEGITIM\Kaplama\src\square.cpp -o CMakeFiles\Kaplama.dir\src\square.cpp.s

CMakeFiles/Kaplama.dir/src/texturemanager.cpp.obj: CMakeFiles/Kaplama.dir/flags.make
CMakeFiles/Kaplama.dir/src/texturemanager.cpp.obj: CMakeFiles/Kaplama.dir/includes_CXX.rsp
CMakeFiles/Kaplama.dir/src/texturemanager.cpp.obj: C:/Users/ismet/OPENGLEGITIM/Kaplama/src/texturemanager.cpp
CMakeFiles/Kaplama.dir/src/texturemanager.cpp.obj: CMakeFiles/Kaplama.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ismet\OPENGLEGITIM\buildKaplama\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Kaplama.dir/src/texturemanager.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Kaplama.dir/src/texturemanager.cpp.obj -MF CMakeFiles\Kaplama.dir\src\texturemanager.cpp.obj.d -o CMakeFiles\Kaplama.dir\src\texturemanager.cpp.obj -c C:\Users\ismet\OPENGLEGITIM\Kaplama\src\texturemanager.cpp

CMakeFiles/Kaplama.dir/src/texturemanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Kaplama.dir/src/texturemanager.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ismet\OPENGLEGITIM\Kaplama\src\texturemanager.cpp > CMakeFiles\Kaplama.dir\src\texturemanager.cpp.i

CMakeFiles/Kaplama.dir/src/texturemanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Kaplama.dir/src/texturemanager.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ismet\OPENGLEGITIM\Kaplama\src\texturemanager.cpp -o CMakeFiles\Kaplama.dir\src\texturemanager.cpp.s

# Object files for target Kaplama
Kaplama_OBJECTS = \
"CMakeFiles/Kaplama.dir/src/main.cpp.obj" \
"CMakeFiles/Kaplama.dir/src/glad.c.obj" \
"CMakeFiles/Kaplama.dir/src/shaderprogram.cpp.obj" \
"CMakeFiles/Kaplama.dir/src/square.cpp.obj" \
"CMakeFiles/Kaplama.dir/src/texturemanager.cpp.obj"

# External object files for target Kaplama
Kaplama_EXTERNAL_OBJECTS =

Kaplama.exe: CMakeFiles/Kaplama.dir/src/main.cpp.obj
Kaplama.exe: CMakeFiles/Kaplama.dir/src/glad.c.obj
Kaplama.exe: CMakeFiles/Kaplama.dir/src/shaderprogram.cpp.obj
Kaplama.exe: CMakeFiles/Kaplama.dir/src/square.cpp.obj
Kaplama.exe: CMakeFiles/Kaplama.dir/src/texturemanager.cpp.obj
Kaplama.exe: CMakeFiles/Kaplama.dir/build.make
Kaplama.exe: C:/Users/ismet/OPENGLEGITIM/Dependencies/GLFW/lib/libglfw3.a
Kaplama.exe: CMakeFiles/Kaplama.dir/linkLibs.rsp
Kaplama.exe: CMakeFiles/Kaplama.dir/objects1.rsp
Kaplama.exe: CMakeFiles/Kaplama.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ismet\OPENGLEGITIM\buildKaplama\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Kaplama.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Kaplama.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Kaplama.dir/build: Kaplama.exe
.PHONY : CMakeFiles/Kaplama.dir/build

CMakeFiles/Kaplama.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Kaplama.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Kaplama.dir/clean

CMakeFiles/Kaplama.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ismet\OPENGLEGITIM\Kaplama C:\Users\ismet\OPENGLEGITIM\Kaplama C:\Users\ismet\OPENGLEGITIM\buildKaplama C:\Users\ismet\OPENGLEGITIM\buildKaplama C:\Users\ismet\OPENGLEGITIM\buildKaplama\CMakeFiles\Kaplama.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Kaplama.dir/depend


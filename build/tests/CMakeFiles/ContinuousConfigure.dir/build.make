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
CMAKE_SOURCE_DIR = D:\CODING\CPlusPlusPROGRAM\gtestVscodeEX

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CODING\CPlusPlusPROGRAM\build

# Utility rule file for ContinuousConfigure.

# Include any custom commands dependencies for this target.
include tests/CMakeFiles/ContinuousConfigure.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/ContinuousConfigure.dir/progress.make

tests/CMakeFiles/ContinuousConfigure:
	cd /d D:\CODING\CPlusPlusPROGRAM\build\tests && "C:\Program Files\CMake\bin\ctest.exe" -D ContinuousConfigure

ContinuousConfigure: tests/CMakeFiles/ContinuousConfigure
ContinuousConfigure: tests/CMakeFiles/ContinuousConfigure.dir/build.make
.PHONY : ContinuousConfigure

# Rule to build all files generated by this target.
tests/CMakeFiles/ContinuousConfigure.dir/build: ContinuousConfigure
.PHONY : tests/CMakeFiles/ContinuousConfigure.dir/build

tests/CMakeFiles/ContinuousConfigure.dir/clean:
	cd /d D:\CODING\CPlusPlusPROGRAM\build\tests && $(CMAKE_COMMAND) -P CMakeFiles\ContinuousConfigure.dir\cmake_clean.cmake
.PHONY : tests/CMakeFiles/ContinuousConfigure.dir/clean

tests/CMakeFiles/ContinuousConfigure.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CODING\CPlusPlusPROGRAM\gtestVscodeEX D:\CODING\CPlusPlusPROGRAM\gtestVscodeEX\tests D:\CODING\CPlusPlusPROGRAM\build D:\CODING\CPlusPlusPROGRAM\build\tests D:\CODING\CPlusPlusPROGRAM\build\tests\CMakeFiles\ContinuousConfigure.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/ContinuousConfigure.dir/depend


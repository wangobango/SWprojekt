# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/ramon/CLion-2018.3/clion-2018.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ramon/CLion-2018.3/clion-2018.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ramon/CLionProjects/projektSW

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ramon/CLionProjects/projektSW/cmake-build-debug

# Utility rule file for projektSW-size.

# Include the progress variables for this target.
include CMakeFiles/projektSW-size.dir/progress.make

CMakeFiles/projektSW-size: projektSW.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ramon/CLionProjects/projektSW/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Calculating projektSW image size"
	/home/ramon/CLion-2018.3/clion-2018.3/bin/cmake/linux/bin/cmake -DFIRMWARE_IMAGE=/home/ramon/CLionProjects/projektSW/cmake-build-debug/projektSW.elf -DMCU=atmega328p -DEEPROM_IMAGE=/home/ramon/CLionProjects/projektSW/cmake-build-debug/projektSW.eep -P /home/ramon/CLionProjects/projektSW/cmake-build-debug/CMakeFiles/FirmwareSize.cmake

projektSW-size: CMakeFiles/projektSW-size
projektSW-size: CMakeFiles/projektSW-size.dir/build.make

.PHONY : projektSW-size

# Rule to build all files generated by this target.
CMakeFiles/projektSW-size.dir/build: projektSW-size

.PHONY : CMakeFiles/projektSW-size.dir/build

CMakeFiles/projektSW-size.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projektSW-size.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projektSW-size.dir/clean

CMakeFiles/projektSW-size.dir/depend:
	cd /home/ramon/CLionProjects/projektSW/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ramon/CLionProjects/projektSW /home/ramon/CLionProjects/projektSW /home/ramon/CLionProjects/projektSW/cmake-build-debug /home/ramon/CLionProjects/projektSW/cmake-build-debug /home/ramon/CLionProjects/projektSW/cmake-build-debug/CMakeFiles/projektSW-size.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/projektSW-size.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/emilioag/Documents/TC2004.1/Face_Alignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emilioag/Documents/TC2004.1/Face_Alignment/src

# Include any dependencies generated for this target.
include CMakeFiles/my_project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_project.dir/flags.make

CMakeFiles/my_project.dir/mainface.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/mainface.cpp.o: mainface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilioag/Documents/TC2004.1/Face_Alignment/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_project.dir/mainface.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/mainface.cpp.o -c /home/emilioag/Documents/TC2004.1/Face_Alignment/src/mainface.cpp

CMakeFiles/my_project.dir/mainface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/mainface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emilioag/Documents/TC2004.1/Face_Alignment/src/mainface.cpp > CMakeFiles/my_project.dir/mainface.cpp.i

CMakeFiles/my_project.dir/mainface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/mainface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emilioag/Documents/TC2004.1/Face_Alignment/src/mainface.cpp -o CMakeFiles/my_project.dir/mainface.cpp.s

CMakeFiles/my_project.dir/facealignmentM2.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/facealignmentM2.cpp.o: facealignmentM2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilioag/Documents/TC2004.1/Face_Alignment/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/my_project.dir/facealignmentM2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_project.dir/facealignmentM2.cpp.o -c /home/emilioag/Documents/TC2004.1/Face_Alignment/src/facealignmentM2.cpp

CMakeFiles/my_project.dir/facealignmentM2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/facealignmentM2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emilioag/Documents/TC2004.1/Face_Alignment/src/facealignmentM2.cpp > CMakeFiles/my_project.dir/facealignmentM2.cpp.i

CMakeFiles/my_project.dir/facealignmentM2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/facealignmentM2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emilioag/Documents/TC2004.1/Face_Alignment/src/facealignmentM2.cpp -o CMakeFiles/my_project.dir/facealignmentM2.cpp.s

# Object files for target my_project
my_project_OBJECTS = \
"CMakeFiles/my_project.dir/mainface.cpp.o" \
"CMakeFiles/my_project.dir/facealignmentM2.cpp.o"

# External object files for target my_project
my_project_EXTERNAL_OBJECTS =

my_project: CMakeFiles/my_project.dir/mainface.cpp.o
my_project: CMakeFiles/my_project.dir/facealignmentM2.cpp.o
my_project: CMakeFiles/my_project.dir/build.make
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_gapi.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_stitching.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_alphamat.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_aruco.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_bgsegm.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_bioinspired.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_ccalib.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_cvv.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_dnn_objdetect.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_dnn_superres.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_dpm.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_face.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_freetype.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_fuzzy.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_hdf.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_hfs.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_img_hash.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_intensity_transform.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_line_descriptor.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_mcc.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_quality.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_rapid.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_reg.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_rgbd.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_saliency.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_sfm.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_stereo.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_structured_light.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_superres.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_surface_matching.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_tracking.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_videostab.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_xfeatures2d.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_xobjdetect.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_xphoto.so.4.5.0
my_project: dlib_build/libdlib.a
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_highgui.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_shape.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_datasets.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_plot.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_text.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_dnn.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_ml.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_phase_unwrapping.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_optflow.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_ximgproc.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_video.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_videoio.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_imgcodecs.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_objdetect.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_calib3d.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_features2d.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_flann.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_photo.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_imgproc.so.4.5.0
my_project: /home/emilioag/Desktop/installation/OpenCV-master/lib/libopencv_core.so.4.5.0
my_project: /usr/lib/x86_64-linux-gnu/libSM.so
my_project: /usr/lib/x86_64-linux-gnu/libICE.so
my_project: /usr/lib/x86_64-linux-gnu/libX11.so
my_project: /usr/lib/x86_64-linux-gnu/libXext.so
my_project: /usr/lib/x86_64-linux-gnu/libpng.so
my_project: /usr/lib/x86_64-linux-gnu/libz.so
my_project: /usr/lib/x86_64-linux-gnu/libjpeg.so
my_project: /usr/lib/x86_64-linux-gnu/libatlas.so
my_project: /usr/lib/x86_64-linux-gnu/libcblas.so
my_project: /usr/lib/x86_64-linux-gnu/liblapack.so
my_project: CMakeFiles/my_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emilioag/Documents/TC2004.1/Face_Alignment/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable my_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_project.dir/build: my_project

.PHONY : CMakeFiles/my_project.dir/build

CMakeFiles/my_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_project.dir/clean

CMakeFiles/my_project.dir/depend:
	cd /home/emilioag/Documents/TC2004.1/Face_Alignment/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emilioag/Documents/TC2004.1/Face_Alignment /home/emilioag/Documents/TC2004.1/Face_Alignment /home/emilioag/Documents/TC2004.1/Face_Alignment/src /home/emilioag/Documents/TC2004.1/Face_Alignment/src /home/emilioag/Documents/TC2004.1/Face_Alignment/src/CMakeFiles/my_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_project.dir/depend


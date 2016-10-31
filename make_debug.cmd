cmake -E make_directory build
cmake -E chdir build cmake .. -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=DEBUG
cmake --build build

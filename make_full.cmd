cmake -E make_directory build
cmake -E chdir build cmake .. -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=RELEASE
cmake --build build --target install --clean-first
cmake -E chdir build cmake .. -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=DEBUG
cmake --build build --target install --clean-first

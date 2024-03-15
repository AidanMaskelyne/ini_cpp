# INICPP

A simple C++ INI parsing library.

## How to use

Simply clone/download the repo and add the `include/` folder as an include folder in you build system.

To build the docs and or tests, do the following:

**Linux:**
```
cmake -S path/to/cppini -B path/to/build
cmake --build path/to/build
```

If you wish to run the tests, `BUILD_TESTS=ON` needs to be set when generating build files with `cmake`. `BUILD_DOCS` is `ON` by default. Simply add `--target test` or `--target docs` on the end of the `cmake --build` command.

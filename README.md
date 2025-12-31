# Advent of Code 2025
https://adventofcode.com/2025

This year, I'm trying [C](https://www.c-language.org/) (C23)

## Set Up
Install these tools:
- [task](https://taskfile.dev/docs/installation)
- LLVM (`brew install llvm`)
- [conan](https://docs.conan.io/2/installation.html)

## Running
Run `task run`  
This will install dependencies, set up the build system, build the app and run it.

There are also individual tasks that can be run separately if you need to. Run `task --list` or check [Taskfile.yml](./Taskfile.yml) to see all the available tasks

### Running tests
Run `task test`

Tests are written using [CUnit](https://cunit.sourceforge.net/)

## Linting and Formatting
Run `task lint` to lint code  
Run `task lint-fix` to automatically fix lint issues (where possible)
Run `task format` to format code

Linting is handled by [`clang-tidy`](https://releases.llvm.org/21.1.0/tools/clang/tools/extra/docs/clang-tidy/index.html)  
Formatting is handled by [`clang-format`](https://releases.llvm.org/21.1.0/tools/clang/docs/ClangFormat.html)

## References
- https://blog.quentinra.dev/tools-and-frameworks/others/testing/tools/c/cunit/index.md
- https://docs.conan.io/2/examples/tools/cmake/cmake_toolchain/build_project_cmake_presets.html

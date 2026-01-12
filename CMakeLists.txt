cmake_minimum_required(VERSION 4.2.1)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(aoc25 C)

### Main ###
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.c
        src/day1.h
        src/day1.c
        src/day2.h
        src/day2.c

        src/utils.h
        src/utils.c
        src/dynamic-array.h
        src/dynamic-array.c
)

set(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD_REQUIRED 23)

# TODO modify this based on the compiler frontend
# Disable unsafe-buffer-usage since it's not clear how to make this warning
# happy
target_compile_options(${PROJECT_NAME}
  PRIVATE
    -O2
    -Weverything
    -Wno-unsafe-buffer-usage
    -Wno-variadic-macro-arguments-omitted
    -Wno-unused-macros
)

### Tests ###
find_package(cunit REQUIRED)

add_executable(${PROJECT_NAME}test)
target_link_libraries(${PROJECT_NAME}test cunit::cunit)
target_sources(${PROJECT_NAME}test
    PRIVATE
        test/main.c
        test/day1.h
        test/day1.c
        test/day2.h
        test/day2.c

        test/CUnit.h
        test/CUnit.c

        src/day1.h
        src/day1.c
        src/day2.h
        src/day2.c

        src/utils.h
        src/utils.c
        src/dynamic-array.h
        src/dynamic-array.c
)

set(TARGET ${PROJECT_NAME}test PROPERTY C_STANDARD_REQUIRED 23)

# TODO modify this based on the compiler frontend
# Disable unsafe-buffer-usage since it's not clear how to make this warning
# happy
target_compile_options(${PROJECT_NAME}test
  PRIVATE
    -O0
    -Weverything
    -Wno-unsafe-buffer-usage
    -Wno-variadic-macro-arguments-omitted
    -Wno-unused-macros
)

# TODO re-add this if we end up using more than just cunit and want to
# coordinate them with ctest

# add_test(
#     NAME CUnitTests
#     COMMAND ${PROJECT_NAME}test
# )

# option(BUILD_TESTING "Enable testing and build tests" ON)
# if(BUILD_TESTING)
#     enable_testing()
# endif()

### Installation ###
install(TARGETS ${PROJECT_NAME}
    CONFIGURATIONS Release
    RUNTIME
        DESTINATION bin/Release
)

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}test
    CONFIGURATIONS Debug
    RUNTIME
        DESTINATION bin/Debug
)

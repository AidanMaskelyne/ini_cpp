# Testing library
FetchContent_Declare(
	catch
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG v2.13.6)
FetchContent_MakeAvailable(catch)
# Adds Catch2::Catch2

add_executable(test src/test.cpp)

target_compile_features(test PRIVATE cxx_std_17)

target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(test PRIVATE Catch2::Catch2)

add_test(NAME Test COMMAND test)

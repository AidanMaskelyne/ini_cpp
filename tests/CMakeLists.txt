include(FetchContent)

# Testing library
FetchContent_Declare(
	catch
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG v2.13.6)
FetchContent_MakeAvailable(catch)
# Adds Catch2::Catch2

add_executable(INITest src/INITest.cpp)

target_compile_features(INITest PRIVATE cxx_std_17)

target_include_directories(INITest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

message(${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(INITest PRIVATE Catch2::Catch2)

add_test(NAME Test COMMAND INITest)

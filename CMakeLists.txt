cmake_minimum_required(VERSION 3.28)

project(
	INICpp
	VERSION 0.1
	DESCRIPTION "A simple C++ INI parsing library"
	LANGUAGES CXX
)

option(BUILD_DOCS "Build the documentation" ON)
option(BUILD_TESTS "Build the tests" OFF)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

	if(BUILD_DOCS)
		find_package(Doxygen)
		if (Doxygen_FOUND)
			add_subdirectory(docs)
		else(DOXYGEN_FOUND)
			message(STATUS "Doxygen couldn't be found, not building docs")
		endif()
	endif()

	# TESTING
	if(BUILD_TESTS)
		include(CTest)
		add_subdirectory(tests)
	endif()

endif()

add_library(INICpp INTERFACE include/INICPP/INI.h)

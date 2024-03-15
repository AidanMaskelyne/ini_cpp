cmake_minimum_required(VERSION 3.28)

project(
	INICpp
	VERSION 0.1
	DESCRIPTION "A simple C++ INI parsing library"
	LANGUAGES CXX
)

option(BUILD_DOCS "Build documentation" ON)
option(BUILD_TESTS "Run the tests" OFF)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

	# DOXYGEN
	if(BUILD_DOCS)
		find_package(Doxygen)
		if (Doxygen_FOUND)
			set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.ini)
			set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

			configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
			message("Doxygen build started")

			add_custom_target( doc_doxygen ALL
				COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
				WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
				COMMENT "Generating API documentation with Doxygen"
				VERBATIM
			)
		else(DOXYGEN_FOUND)
			message("Doxygen needs to be installed to generate the documentation")
		endif()
	endif()

	# TESTING
	if(RUN_TESTS)
		include(CTest)
		add_subdirectory(tests)
	endif()

endif()

add_library(INICpp INTERFACE include/CPPINI/INI.h)

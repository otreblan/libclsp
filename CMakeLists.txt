cmake_minimum_required(VERSION 3.13.0)

project(clsp
	VERSION 0.0.0
	DESCRIPTION "A language server protocol C++ library"
	HOMEPAGE_URL "https://github.com/otreblan/clsp"
	LANGUAGES "CXX"
)

# Without this, paths are not relative in the sources list
cmake_policy(SET CMP0076 NEW)

include(GNUInstallDirs)
include(FindPkgConfig)

# The library itself
add_library(${PROJECT_NAME} SHARED)

# Version for the library symlinks
set_target_properties(${PROJECT_NAME}
	PROPERTIES
		VERSION ${PROJECT_VERSION}
		SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Headers
target_include_directories(${PROJECT_NAME}
	PRIVATE ${PROJECT_SOURCE_DIR}/include
)

# Sources list
add_subdirectory(src)

# Header installation
add_subdirectory(include)

# C++ standard
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

#target_link_libraries(${PROJECT_NAME} ${library_LIBRARIES})

install(TARGETS ${PROJECT_NAME}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

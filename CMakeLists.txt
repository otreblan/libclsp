cmake_minimum_required(VERSION 3.13.0)

project(libclsp
	VERSION 0.0.0
	DESCRIPTION "A language server protocol C++ library"
	HOMEPAGE_URL "https://github.com/otreblan/libclsp"
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
		PREFIX ""
		CXX_STANDARD 17
)

# Headers
target_include_directories(${PROJECT_NAME}
	PRIVATE ${PROJECT_SOURCE_DIR}/include
)

# Sources list
add_subdirectory(src)

# Header installation
add_subdirectory(include)

# pkg-config file
configure_file(libclsp.pc.in
	${CMAKE_BINARY_DIR}/libclsp.pc
	@ONLY
)
install(FILES
	${CMAKE_BINARY_DIR}/libclsp.pc
	DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
)

# Libraries
pkg_check_modules(RAPIDJSON REQUIRED RapidJSON)
include(FindBoost)

# Header path
target_include_directories(${PROJECT_NAME}
	PUBLIC
		${RAPIDJSON_INCLUDE_DIRS}
		${Boost_INCLUDE_DIRS}
)

# Linking
target_link_libraries(${PROJECT_NAME}
	PUBLIC
		${RAPIDJSON_LIBRARIES}
		${Boost_LIBRARIES}
)

# Other flags
target_compile_definitions(${PROJECT_NAME}
	PUBLIC
		${RAPIDJSON_CFLAGS_OTHER}
)

install(TARGETS ${PROJECT_NAME}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

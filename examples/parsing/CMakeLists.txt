cmake_minimum_required(VERSION 3.13.0)

project(parsing
	LANGUAGES "CXX"
)

include(FindPkgConfig)

# The binary itself
add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
	PRIVATE
		main.cpp
)

# Version for the library symlinks
set_target_properties(${PROJECT_NAME}
	PROPERTIES
		CXX_STANDARD 17
)


# Libraries
pkg_check_modules(LIBCLSP REQUIRED libclsp)

# Header path
target_include_directories(${PROJECT_NAME}
	PUBLIC
		${LIBCLSP_INCLUDE_DIRS}
)

# Linking
target_link_libraries(${PROJECT_NAME}
	PUBLIC
		${LIBCLSP_LIBRARIES}
)

# Other flags (without this rapidjson can't use std::string)
target_compile_definitions(${PROJECT_NAME}
	PUBLIC
		${LIBCLSP_CFLAGS_OTHER}
)

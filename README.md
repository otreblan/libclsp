# Libclsp

[![AUR version](https://img.shields.io/aur/version/libclsp?style=flat-square)](https://aur.archlinux.org/packages/libclsp/)

A C++17 library for
[language servers](https://microsoft.github.io/language-server-protocol/).

Currently this library is only objects from the 3.15.0 specification.

## TODO
* [ ] Parsing
* [ ] Writing
* [ ] The server
* [x] All lsp structs declared

## Install (Arch linux)

``` bash
yay -S libclsp
```

## Link (CMake)

``` cmake
include(FindPkgConfig)
pkg_check_modules(LIBCLSP libclsp)

add_executable(foo)

target_link_libraries(foo PUBLIC ${LIBCLSP_LIBRARIES})
target_include_directories(foo PUBLIC ${LIBCLSP_INCLUDE_DIRS})
target_compile_definitions(foo PUBLIC ${LIBCLSP_CFLAGS_OTHER})
```

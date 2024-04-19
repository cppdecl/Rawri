# Rawri Library

**Rawri** is a collection of header-only C++ helper and utility functions that I always utilize in my projects and has grown tired of copy-pasting each and every file to a new one. Maybe turning it into a library I could easily clone will make my life easier.

## Dependencies
- [CMake](https://cmake.org/)
- [Git](https://git-scm.com/)

**Note:** This project depends on a CMake buildsystem. I have no intention to support others at the moment. However, you could probably easily copy the files over to your own project as each module is header-only.

## Installation

Clone this repository using [git](https://git-scm.com/).

```bash
git clone https://github.com/cppdecl/rawri
```

## Usage

Using [CMake](https://cmake.org/), make sure add this line to your CMakeLists.txt file in order to include it to your project
```cmake
add_subdirectory(Rawri)
```
And be sure to link it as `rawri`.
```cmake
target_link_libraries(${PROJECT_NAME} PUBLIC rawri)
```

## Contributing

This library is far from perfect and is mostly for private use. If you want to contribute and improve it you can surely do as pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
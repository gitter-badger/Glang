## Glang Contribution Guidelines
If you have any interest in contributing to this project, that's great, but I expect that you follow  *all* of the following guidelines.

**Disclaimer: [Gigabyte Giant](https://github.com/Gigabyte-Giant) reserves the right to turn down any and all contributions that do not follow these guidelines.**

### General Guidelines
All contributions must be submitted in English.

### File Guidelines
#### File Extensions
All `*.c` files should have a sister `*.h` file (of the same name). Example:
```sh
file.c
file.h
```

All `*.cpp` files should have a sister `*.hpp` file (of the same name). Example:
```sh
Lexer.cpp
Lexer.hpp
```

#### File Naming
In general, the first letter in filenames should be written in lowercase, while the rest of the filename should be written using camelcase. However, if a file contains the interface or implementation for a class, the first letter in the filename should be written in uppercase. The rest of the filename should be written using camelcase. Example:
```sh
someFile.cpp # General File
SomeClass.hpp # Class Interface
SomeClass.cpp # Class Implementation
```
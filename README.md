# Directory Tree Printer

Author: Lei Mao

## Introduction

Printing directory tree is useful to present the direcotry architectures. Such directory trees could often be used in GitHub projects.

## Demo

This is the directory tree of the "Directory Tree Printer" folder.

```
.
├── tree.txt
├── tree_print
├── test_folder
│   ├── file1.txt
│   ├── file2.txt
│   └── folder_1
│       ├── file_3.txt
│       ├── file1.txt
│       ├── file2.txt
│       └── folder_2
│           ├── file1.txt
│           ├── file2.txt
│           └── folder_2
│               ├── file1.txt
│               ├── file2.txt
│               └── folder_2
├── tree_print.cpp
├── Makefile
├── demo
├── README.md
├── tree.h
└── tree.cpp
```

## Usage

The executable file "tree_print" has been compiled on Ubuntu 16.04 using g++ 5.4.0. Ubuntu users should be able to use the program directly.

```shell
find . | xargs ./tree_print
find . | xargs ./tree_print > demo.txt
```


## Building
----
### Linux
To compile the from the source code, simply run:
```shell
make
```

### Windows
```shell
cl /Zi /EHsc /std:c++17 /Fe: tree_print.exe *.cpp
```
> You may customize to add or remove args from the command

## Notes
* You need a compiler supporting C++17
* Linux has similar packages to present directory tree.

    On Ubuntu:
    ```shell
    sudo apt install tree
    ```
# Directory Tree Printer

Author: Lei Mao

Date: 1/14/2018

## Introduction

Printing directory tree is useful to present the direcotry architectures. Such directory trees could often be used in GitHub projects.

## Dependencies

[Boost C++ Library](http://www.boost.org/)

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
find . | xargs ./tree_print > demo
```

To compile the from the source code, simply run:

```shell
make
```

## Caveats

The name of folder and files should not have blanks. Because the program relies on the output from ```find``` command from Linux shell, and ```find``` could not correctly parsing the directory list to the C++ program arguments, there will be problems to present the directory structure containing blanks in the path. This might be fixed in the future if I have time.

## Notes

Linux has similar packages to present directory tree.

On Ubuntu:
```shell
sudo apt install tree
```
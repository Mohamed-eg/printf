# 🤝Custom `Printf` Function in C

Project Overview
This project aims to develop a custom `printf` function in C that mimics the functionality of the standard `printf` function but offers additional features and flexibility. This project is a collaborative effort between students at Hulperton School, with significant contributions from Maria and the project's initiator.

## Project Motivation

The standard `printf` function in C is a powerful tool for formatted output, but it can sometimes be limiting in its capabilities. This project seeks to create a custom `printf` function that extends the functionality of the original, providing more options for formatting and output control.

## Key Features

Our custom `printf` function will offer several enhancements over the standard `printf`:

Custom Formatting Flags: We will introduce additional formatting flags to control the appearance of output, such as justification, alignment, and padding.

Enhanced Data Types: We will expand the range of supported data types beyond the standard `printf`, enabling formatted output for user-defined data types and structures.

Variadic Arguments: Our custom `printf` will handle variadic arguments, allowing for flexible formatting of an arbitrary number of arguments.

Error Handling: We will incorporate error handling mechanisms to gracefully deal with invalid format specifications and unexpected input.

## Implementation Approach

The custom `printf` function will be implemented using a similar approach to the standard `printf`, utilizing a parser to interpret the format string and dynamically generate the formatted output. We will extend the parser to handle our custom formatting flags and data types.

## Expected Outcomes

Upon completion of this project, we expect to have a fully functional custom `printf` function that provides enhanced formatting capabilities, supports a wider range of data types, and handles variadic arguments effectively. This custom function will serve as a valuable tool for formatted output in C programming.

## Compilation

```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

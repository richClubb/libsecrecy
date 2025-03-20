# C++ Secrecy

A library to replicate the functionality of the secrecy crate in Rust in C++

## Objectives

The main things the secrecy crate gives us are:
* ability to hide the value of the variable and only be exposed explicitly (by calling `expose_value()`)
* zero out the memory location after the variable has been deleted

This gives the ability to audit the secrets a bit easier as you can always see where `expose_value()` is called.

## To-Do

* CI/CD pipeline
* Properly arrange make files
* Integration tests?
  * What might they be?
* Investigate virtual classes for extensibility
* Cross compile for different arch / OS
  * Currently only tested in Linux but I want this to be used in windows
* Set up release process
# libsecrecy

A library to replicate the functionality of the secrecy crate in Rust in C and C++

## Objectives

The main things the secrecy crate gives us are:
* ability to hide the value of the variable and only be exposed explicitly (by calling `expose_value()`)
* zero out the memory location after the variable has been deleted

This gives the ability to audit the secrets a bit easier as you can always see where `expose_value()` is called.

## Overview

Currently the library supports hiding secrets in both C and C++.

### C implementation 

For C the library encrypts the secret with an AES 256 bit encryption to hide the value. This is NOT designed to be a secure storage container and is purely for the purpose of storing the secret in an obfuscated way so that if someone tries to use the secret it will be hidden. I decided that encrypting the value would be better than some other very basic form of obfuscation as if the secret is leaked it will at least be harder for an attacker to decipher.

### C++

For C++ the implementation is simpler, the secret value is loaded into a private member variable and is only accessible via the `expose_secret()` method. This way it is clear when the value is being accessed.

## Examples 

There are (examples)[/examples] which will show you a basic implementation of the secret values and how they can be used, these are designed for minimal exposure of the secret.

The unit tests for both C and C++ will also provide you with examples although they may not be as 'clean' as they are intended for testing rather than minimal exposure.

## To-Do

* CI/CD pipeline
  * Different arch support
* Properly arrange make files
* Integration tests?
  * What might they be?
* Investigate virtual classes for extensibility
* Cross compile for different arch / OS
  * Currently only tested in Linux but I want this to be used in windows
* Set up release process
* Fixed memory version?
  * No malloc, suitable for embedded applications with dynamic memory constraints?
  * Might not be possible due to openssl memory allocation behaviour
# C++ Secrecy Basic Example

This is a basic example of how to use the C++ secrecy library.

In this example we take a username and password from the command line and store them in a secret container. We class the username and password as secrets but we don't care too much about the hostname that we're connecting to.

We then try to print out the username and password (essentially for logging) but we haven't exposed the secret.

The main thing is that the secrets are created and the only way to expose them is via the `expose_secret()` method. This will be easier to audit and understand the scope of the exposure when using that variable.

## Building 

This can be built from this directory with cmake

```
mkdir build
cd build
cmake ../
make
```

This also is built as part of the main build process as well.

If you build this in this directory you will need to add the library path to `LD_LIBRARY_PATH` or use it in the invocation. If you're using the devcontainer then this will work.

```
LD_LIBRARY_PATH=/workspaces/c_secrecy/build/lib ./cpp_secrecy_example [a] [b]
```

## Running

You need to supply a `username` and `password` at the commandline.

```
./cpp_secrecy_basic_example [username] [password]
```

This will print out something like

```
Logging in user : "richard" with password: "supersecretthing" to machine: "localhost"
```
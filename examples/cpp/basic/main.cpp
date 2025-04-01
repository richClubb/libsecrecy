#include <cstring>
#include <iostream>
#include <stdio.h>

#include "cpp_secrecy.h"

#define RC_SUCCESS 0
#define RC_INVALID_PARAMS 1

void log_in_to_server(SecretValue<string> *username, SecretValue<string> *password, string server)
{
    std::cout << "Logging in user: \"" << *username->expose_value() <<
      "\" with password: \"" << *password->expose_value() << 
      "\" to machine: \"" << server << "\"\n";
}


int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Incorrect number of parameters, must have 2\n");
        return RC_INVALID_PARAMS;
    }

    SecretValue<string> username(argv[1]);
    SecretValue<string> password(argv[2]);
    
    log_in_to_server(&username, &password, "localhost\0");

    return RC_SUCCESS;
}
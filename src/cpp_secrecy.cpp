#include <stdio.h>
#include <string.h>

#include "cpp_secrecy.h"

template <typename T> SecretValue<T>::SecretValue(T val)
{
    this->val = val;
    this->size = sizeof(T);
}

template <typename T> SecretValue<T>::SecretValue(T val, int size)
{
    memcpy(this->val, val, size*sizeof(T));
    this->size = size;
}

template <typename T> T* SecretValue<T>::expose_value()
{
    return &this->val;
}

// this might have to have some more specific constructors?
template <typename T> SecretValue<T>::~SecretValue()
{
    memset(&this->val, 0, this->size);
}

// this shouldn't have to be here but is required or g++ is compiling out the code WTF
int main(void)
{
    SecretValue<int> aThing(1);

    printf("Hush!!! %d\n", *aThing.expose_value());

    return 0;
}
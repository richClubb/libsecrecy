#ifndef __CPP_SECRECY__

#define __CPP_SECRECY__

// system
#include <stdlib.h>
#include <string>


#ifdef __cplusplus
    #define EXTERN extern "C"
#else
    #define EXTERN
#endif

using namespace std;

/*
    needs to be constructed and destructed

    destructor needs to have a zeroing functionality.

    Seems entirely wank that it requires it all to be here
*/
template <typename T> class SecretValue{

private:
    T* ptr;
    int size;

    public:
        // Constructor for concrete values
        SecretValue(T val);
        // Constructor for arrays / vectors
        SecretValue(T *val, int size);
        T* expose_value(void);
        ~SecretValue();
};

template <typename T> SecretValue<T>::SecretValue(T val)
{
    this->ptr = new T(val);
    this->size = sizeof(T);
}

template <typename T> SecretValue<T>::SecretValue(T *val, int size)
{
    // This currently doesn't work. We want to be able to copy the array into the location
    //this->ptr = new T(size);
    this->ptr = (T *)malloc(size*sizeof(T));

    memcpy(this->ptr, val, sizeof(val)*size);

    // this size should be in bytes?
    this->size = sizeof(T)*size;
}


template <typename T> T* SecretValue<T>::expose_value()
{
    return this->ptr;
}

template <typename T> SecretValue<T>::~SecretValue()
{
    // zero the memory location
    memset(this->ptr, 0, this->size);

    // this might not work for certain datatypes. E.g. strings

    // data should be automatically deleted so we don't have to delete the ptr
}

#endif
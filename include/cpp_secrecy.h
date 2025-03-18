#ifndef _C_SECRECY_

#define _C_SECRECY_

using namespace std;

/*
    needs to be constructed and destructed

    destructor needs to have a zeroing functionality.
*/
template <typename T> class SecretValue{

private:
    T val;
    int size;

    public:
        SecretValue(T value);
        SecretValue(T value, int size);
        T* expose_value(void);
        ~SecretValue();
};

#endif
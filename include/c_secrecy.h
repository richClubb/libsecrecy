#ifndef __C_SECRECY__

#define __C_SECRECY__

using namespace std;


/*
    needs to be constructed and destructed

    destructor needs to have a zeroing functionality.
*/
template <typename T> class SecretValue{

    private:
        T* ptr;
        int size;

    public:
        SecretValue();
        T* expose_value(void);
        ~SecretValue();
};

#endif
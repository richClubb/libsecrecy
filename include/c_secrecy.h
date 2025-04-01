#ifndef __C_SECRECY__

#define __C_SECRECY__

#ifdef __cplusplus
    #define EXTERN extern "C"
#else
    #define EXTERN
#endif

// system
#include <stdint.h>

// external includes
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>



#define SECRET_KEY_SIZE 32
#define SECRET_IV_SIZE 16

#define SUCCESS 0

EXTERN typedef struct {
    uint8_t *value;
    uint8_t key[SECRET_KEY_SIZE];
    uint8_t iv[SECRET_IV_SIZE];
    uint64_t value_len;
    uint64_t ciphertext_len;
} Secret_t;

// Uses the key to decrypt the value
EXTERN void expose_secret(Secret_t *, uint8_t *, const int);
EXTERN const uint8_t *expose_secret_inline(Secret_t *);

// Generates a key and stores the value
EXTERN Secret_t *create_secret(uint8_t *, uint64_t);

EXTERN void delete_secret(Secret_t *);

#endif
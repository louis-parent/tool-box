#ifndef __ABSTRACT_CIPHER_H__
#define __ABSTRACT_CIPHER_H__

#include <string.h>

class AbstractCipher
{
    public:
        virtual void encipher(void* data, size_t dataLength) const = 0;
        virtual void decipher(void* data, size_t dataLength) const = 0;
};

#endif

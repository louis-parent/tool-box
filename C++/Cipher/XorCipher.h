#ifndef __SIMPLE_CIPHER_H__
#define __SIMPLE_CIPHER_H__

#include "AbstractCipher.h"
#include <string>

class XorCipher : public AbstractCipher
{
    public:
        XorCipher(const std::string& key);

        void encipher(void* data, size_t dataLength) const override;
        void decipher(void* data, size_t dataLength) const override;

        void setKey(const std::string& key);
    private:
        std::string key;
};

#endif

#include "XorCipher.h"

XorCipher::XorCipher(const std::string& key) : key(key) {}

void XorCipher::encipher(void* data, size_t dataLength) const
{
    std::string tmp(this->key);
    while (tmp.size() < dataLength)
    {
        tmp.append(this->key);
    }

    char* bytes = (char*) data;
    for (size_t i = 0; i < dataLength; ++i)
    {
        bytes[i] ^= tmp[i];
    }
}

void XorCipher::decipher(void* data, size_t dataLength) const
{
    this->encipher(data, dataLength);
}

void XorCipher::setKey(const std::string& key)
{
    this->key = key;
}

#include "crypt.h"

Crypt::Crypt()
{
}

// Symmetric XOR encryption method
QByteArray Crypt::encryption()
{
    size_t keyLen = key_.length();
    for (int i = 0; i < data_.count() - 1; i++)
    {
        data_[i] =  data_[i] ^ key_[i % keyLen];
    }

    return data_;
}

// Uploading incoming data for encryption
void Crypt::load_Data(QByteArray data)
{
    data_ = data;
}

// Uploading the encryption key
void Crypt::load_Key(QByteArray key)
{
    key_ = key;
}

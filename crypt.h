#ifndef CRYPT_H
#define CRYPT_H

#include <QByteArray>
#include <QString>

/* Crypt
* The class responsible for storing and encrypting information.*/
class Crypt
{
public:
    Crypt();

    void load_Data(QByteArray);
    void load_Key(QByteArray);
    QByteArray encryption();
private:
    QByteArray data_;
    QByteArray key_;

};

#endif // CRYPT_H

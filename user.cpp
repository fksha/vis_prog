#include "user.h"
#include <QCryptographicHash>  // Для простого хэширования (по желанию, можно без него)

User::User(int id, const QString& username, const QString& password)
    : id(id), username(username), passwordHash(password)  // Пока без хэша для простоты
{
}

int User::getId() const { return id; }
QString User::getUsername() const { return username; }

void User::setPassword(const QString& password)
{
    passwordHash = password;  // Можно добавить QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5).toHex();
}

bool User::checkPassword(const QString& password) const
{
    return passwordHash == password;
}

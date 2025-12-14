#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User(int id = -1, const QString& username = "", const QString& password = "");

    int getId() const;
    QString getUsername() const;
    void setPassword(const QString& password);  // Для смены пароля в будущем

    // Проверка пароля
    bool checkPassword(const QString& password) const;

private:
    int id;
    QString username;
    QString passwordHash;  // Пока просто текст (для учебного проекта нормально)
};

#endif // USER_H

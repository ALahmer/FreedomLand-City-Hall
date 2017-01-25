#ifndef AMMINISTRATORE_MODEL_H
#define AMMINISTRATORE_MODEL_H

#include<MODEL/amministratore.h>
#include<MODEL/database.h>

class ModelAmministratore {
private:
    Utente* admin;
    UsersDatabase* UsDb;
public:
    ModelAmministratore(const QString& username, UsersDatabase* db);
    bool EmptyDB() const;
    void UpdateInfo(const QString& nome, const QString& cognome, const QDate& datadinascita, const QString& professione, const QString& mail);
    Utente* getAdmin() const;
    QString getAdminLogged() const;
    myContainer<Utente>::myIterator begin() const;
    myContainer<Utente>::myIterator end() const;
    void DeleteUser(const QString& username);
    void AddUser(const QString& nome, const QString& cognome, const QString& username, const QString& password, const QString& tipo);
    bool ExistingUser(const QString& username) const;
};

#endif // AMMINISTRATORE_MODEL_H

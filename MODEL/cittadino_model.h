#ifndef CITTADINO_MODEL_H
#define CITTADINO_MODEL_H

#include<MODEL/cittadino.h>
#include<MODEL/database.h>

class ModelCittadino {
private:
    Utente* cittadino;
    UsersDatabase* UsDb;
public:
    ModelCittadino(const QString& username, UsersDatabase* db);
    Utente* getCittadino() const;
    QString getCittadinoLogged() const;
    QString getUsername() const;
    void UpdateInfo(const QString& nome, const QString& cognome, const QDate& datadinascita, const QString& professione, const QString& mail);
};

#endif // CITTADINO_MODEL_H

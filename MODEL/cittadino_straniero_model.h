#ifndef CITTADINO_STRANIERO_MODEL_H
#define CITTADINO_STRANIERO_MODEL_H

#include<MODEL/cittadino_straniero.h>
#include<MODEL/database.h>

class ModelCittadinoStraniero {
private:
    Utente* cittadinostraniero;
    UsersDatabase* UsDb;
public:
    ModelCittadinoStraniero(const QString& username, UsersDatabase* db);
    Utente* getCittadinoStraniero() const;
    QString getCittadinoStranieroLogged() const;
    QString getUsername() const;
    void UpdateInfo(const QString& nome, const QString& cognome, const QDate& datadinascita, const QString& professione, const QString& mail);
};

#endif // CITTADINO_STRANIERO_MODEL_H

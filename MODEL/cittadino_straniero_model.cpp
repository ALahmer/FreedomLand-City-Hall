#include<MODEL/cittadino_straniero_model.h>

ModelCittadinoStraniero::ModelCittadinoStraniero(const QString& username, UsersDatabase* db) {
    UsDb = db;
    cittadinostraniero = UsDb->Find_Utente(username);
}

Utente* ModelCittadinoStraniero::getCittadinoStraniero() const {
    return UsDb->Find_Utente(cittadinostraniero->getUsername());
}

QString ModelCittadinoStraniero::getCittadinoStranieroLogged() const {
    return cittadinostraniero->getUsername();
}

QString ModelCittadinoStraniero::getUsername() const {
    return cittadinostraniero->getUsername();
}

void ModelCittadinoStraniero::UpdateInfo(const QString& nome, const QString& cognome, const QDate& datadinascita, const QString& professione, const QString& mail) {
    cittadinostraniero->setInfo(nome,cognome,datadinascita,professione,mail);
}


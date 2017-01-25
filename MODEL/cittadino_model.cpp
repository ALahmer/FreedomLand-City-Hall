#include<MODEL/cittadino_model.h>

ModelCittadino::ModelCittadino(const QString& username, UsersDatabase* db) {
    UsDb = db;
    cittadino = UsDb->Find_Utente(username);
}

Utente* ModelCittadino::getCittadino() const {
    return UsDb->Find_Utente(cittadino->getUsername());
}

QString ModelCittadino::getCittadinoLogged() const {
    return cittadino->getUsername();
}

QString ModelCittadino::getUsername() const {
    return cittadino->getUsername();
}

void ModelCittadino::UpdateInfo(const QString& nome, const QString& cognome, const QDate& datadinascita, const QString& professione, const QString& mail) {
    cittadino->setInfo(nome,cognome,datadinascita,professione,mail);
}

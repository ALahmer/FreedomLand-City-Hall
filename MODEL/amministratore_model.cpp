#include<MODEL/amministratore_model.h>

ModelAmministratore::ModelAmministratore(const QString& username, UsersDatabase* db) {
    UsDb = db;
    admin = UsDb->Find_Utente(username);
}

bool ModelAmministratore::EmptyDB() const {
    return UsDb->Empty();
}

void ModelAmministratore::UpdateInfo(const QString& nome, const QString& cognome, const QDate& datadinascita, const QString& professione, const QString& mail) {
    admin->setInfo(nome,cognome,datadinascita,professione,mail);
}

Utente* ModelAmministratore::getAdmin() const {
    return admin;
}

QString ModelAmministratore::getAdminLogged() const {
    return admin->getUsername();
}

myContainer<Utente>::myIterator ModelAmministratore::begin() const {
    return UsDb->begin();
}

myContainer<Utente>::myIterator ModelAmministratore::end() const {
    return UsDb->end();
}

void ModelAmministratore::DeleteUser(const QString& username) {
    UsDb->Delete_Utente(username);
}

void ModelAmministratore::AddUser(const QString& nome, const QString& cognome, const QString& username, const QString& password, const QString& tipo) {
    if(tipo == "Amministratore") UsDb->Add_Amministratore(username,password,nome,cognome);
    else if(tipo == "Cittadino") UsDb->Add_Cittadino(username,password,nome,cognome);
    else if(tipo == "Cittadino Straniero") UsDb->Add_CittadinoStraniero(username,password,nome,cognome);
    else if(tipo == "Impiegato Anagrafe") UsDb->Add_ImpiegatoAnagrafe(username,password,nome,cognome);
    else if(tipo == "Impiegato Biblioteca") UsDb->Add_ImpiegatoBiblioteca(username,password,nome,cognome);
}

bool ModelAmministratore::ExistingUser(const QString& username) const {
    return UsDb->UtenteEsistente(username);
}

#include<MODEL/impiegato_anagrafe_model.h>

ModelImpiegatoAnagrafe::ModelImpiegatoAnagrafe(const QString& username, UsersDatabase* db) {
    UsDb = db;
    impiegatoanagrafe = UsDb->Find_Utente(username);
}

bool ModelImpiegatoAnagrafe::EmptyDB() const {
    return UsDb->Empty();
}

void ModelImpiegatoAnagrafe::UpdateInfo(const QString& nome, const QString& cognome, const QDate& datadinascita, const QString& professione, const QString& mail) {
    impiegatoanagrafe->setInfo(nome,cognome,datadinascita,professione,mail);
}

Utente* ModelImpiegatoAnagrafe::getImpiegatoAnagrafe() const {
    return impiegatoanagrafe;
}

QString ModelImpiegatoAnagrafe::getImpiegatoAnagrafeLogged() const {
    return impiegatoanagrafe->getUsername();
}

myContainer<Utente>::myIterator ModelImpiegatoAnagrafe::begin() const {
    return UsDb->begin();
}

myContainer<Utente>::myIterator ModelImpiegatoAnagrafe::end() const {
    return UsDb->end();
}

void ModelImpiegatoAnagrafe::DeleteUser(const QString& username) {
    UsDb->Delete_Utente(username);
}

void ModelImpiegatoAnagrafe::AddUser(const QString& nome, const QString& cognome, const QString& username, const QString& password, const QString& tipo) {
    if(tipo == "Cittadino") UsDb->Add_Cittadino(username,password,nome,cognome);
    else if(tipo == "Cittadino Straniero") UsDb->Add_CittadinoStraniero(username,password,nome,cognome);
}

bool ModelImpiegatoAnagrafe::ExistingUser(const QString& username) const {
    return UsDb->UtenteEsistente(username);
}

QString ModelImpiegatoAnagrafe::Tipo(const QString& username) const {
    return UsDb->Find_Utente(username)->TipoUtente();
}

Utente* ModelImpiegatoAnagrafe::getUser(const QString& username) const {
    return UsDb->Find_Utente(username);
}

void ModelImpiegatoAnagrafe::NewCittadino(Utente* straniero) {
    UsDb->NuovoCittadino(straniero);
}

void ModelImpiegatoAnagrafe::Update_Cittadino(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita, const QString& professione,const QString& mail,const QString& comune,const QString& via, const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita, const QString& passaporto){
    UsDb->UpdateCittadino(username,nome,cognome,datadinascita,professione,mail,comune,via,numerocivico,cittadinanza,cartadidentita,passaporto);
}

void ModelImpiegatoAnagrafe::Update_Cittadino_Straniero(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita, const QString& professione,const QString& mail,const QString& comune,const QString& via, const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita, const QString& passaporto, const QString& permessodisoggiorno){
    UsDb->UpdateCittadinoStraniero(username,nome,cognome,datadinascita,professione,mail,comune,via,numerocivico,cittadinanza,cartadidentita,passaporto,permessodisoggiorno);
}

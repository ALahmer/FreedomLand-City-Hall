#ifndef IMPIEGATO_ANAGRAFE_MODEL_H
#define IMPIEGATO_ANAGRAFE_MODEL_H

#include<MODEL/impiegato_anagrafe.h>
#include<MODEL/database.h>

class ModelImpiegatoAnagrafe {
private:
    Utente* impiegatoanagrafe;
    UsersDatabase* UsDb;
public:
    ModelImpiegatoAnagrafe(const QString& username, UsersDatabase* db);
    bool EmptyDB() const;
    void UpdateInfo(const QString& nome, const QString& cognome, const QDate& datadinascita,const QString& professione, const QString& mail);
    Utente* getImpiegatoAnagrafe() const;
    QString getImpiegatoAnagrafeLogged() const;
    myContainer<Utente>::myIterator begin() const;
    myContainer<Utente>::myIterator end() const;
    void DeleteUser(const QString& username);
    void AddUser(const QString& nome, const QString& cognome, const QString& username, const QString& password, const QString& tipo);
    bool ExistingUser(const QString& username) const;
    QString Tipo(const QString& username) const;
    Utente* getUser(const QString& username) const;
    void NewCittadino(Utente* straniero);
    void Update_Cittadino(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita, const QString& professione,const QString& mail,const QString& comune,const QString& via, const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita, const QString& passaporto);
    void Update_Cittadino_Straniero(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita, const QString& professione,const QString& mail,const QString& comune,const QString& via, const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita, const QString& passaporto, const QString& permessodisoggiorno);
};

#endif // IMPIEGATO_ANAGRAFE_MODEL_H

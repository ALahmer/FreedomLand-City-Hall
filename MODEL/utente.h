#ifndef UTENTE_H
#define UTENTE_H

#include "info.h"
#include<QCryptographicHash>
#include<QByteArray>

class Credenziali{
private:
    QString user;
    QString pass;
public:
    Credenziali(const QString& u = "user", const QString p = "myPassword") : user(u) , pass(QCryptographicHash::hash(p.toUtf8(),QCryptographicHash::Md5).toHex()) {}
    QString getUser() const { return user; }
    QString getPass() const { return pass; }
    void setUser(const QString& u = "user") { user = u; }
    void setPass(const QString& p = "myPassword") { pass = QCryptographicHash::hash(p.toUtf8(),QCryptographicHash::Md5).toHex(); }
    void setCredenziali(const QString& us = "user", const QString& p = "myPassword") { setUser(us); setPass(p); }
    void SetPasswordNuovoCittadino(const QString& pw) { pass = pw; }

    static Credenziali* readCredenziali(QXmlStreamReader& xmlReader) {
        Credenziali* cred = new Credenziali();
        xmlReader.readNext();
        while(!xmlReader.isEndElement() || !(xmlReader.name() == "credenziali")){
            if(xmlReader.isStartElement() && xmlReader.name() == "username"){
                cred->user = xmlReader.readElementText();
            }
            else if(xmlReader.isStartElement() && xmlReader.name() == "password"){
                cred->pass = xmlReader.readElementText();
            } else xmlReader.readNext();
        }
        return cred;
    }
};

class Utente {
private:
    Info* info;
    Credenziali* cred;
public:
    Utente(Info* i = new Info(), Credenziali* c = new Credenziali());
    Info* getInfo() const;
    Credenziali* getCred() const;
    void reset();
    QString getUsername() const;
    QString getPassword() const;
    void setInfo(const QString& n="Nessuna informazione.", const QString& c="Nessuna informazione.", const QDate& d = QDate(1990,1,1), const QString& p="Nessuna informazione.", const QString& m="Nessuna informazione.");
    void setRes(const QString& c = "Nessuna informazione.", const QString& v = "Nessuna informazione.",const QString& n = "Nessuna informazione.");
    void setCred(const QString& us = "user", const QString& p = "myPassword");
    bool operator==(const Utente& us);
    virtual ~Utente();
    virtual QString TipoUtente() const = 0;
    virtual void StoreData(QXmlStreamWriter& xmlWriter) = 0;
    //virtual void CreaModel(const QString& un) = 0;
    virtual QString getCittadinanza() const = 0;
    virtual QString getCartaDidentita() const = 0;
    virtual QString getPassaporto() const = 0;
    virtual QString getPermessoDiSoggiorno() const = 0;
};

#endif // UTENTE_H

#include<MODEL/utente.h>

Utente::Utente(Info* i, Credenziali* c) : info(i), cred(c)  {}

Info* Utente::getInfo() const {
    return info;
}
Credenziali* Utente::getCred() const {
    return cred;
}

void Utente::reset() {
    info = 0;
    cred = 0;
}

QString Utente::getUsername() const {
    return cred->getUser();
}
QString Utente::getPassword() const {
    return cred->getPass();
}

void Utente::setInfo(const QString& n, const QString& c, const QDate& d, const QString& p, const QString& m) {
    info->setInfo(n,c,d,p,m);
}

void Utente::setRes(const QString &c, const QString &v, const QString &n) {
    info->setResidenza(c,v,n);
}

void Utente::setCred(const QString& us, const QString& p) {
    cred->setCredenziali(us,p);
}

bool Utente::operator==(const Utente& us){
    return info == us.info && cred == us.cred;
}

Utente::~Utente() {
    delete info;
    delete cred;
}

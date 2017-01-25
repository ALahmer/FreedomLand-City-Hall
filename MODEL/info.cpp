#include<MODEL/info.h>

Info::Info(const QString& n, const QString& c, const QDate& d, const QString& p, const QString& m, Residenza* r) :
                        nome(n), cognome(c), dataNascita(d), professione(p), mail(m), residence(r) {}

void Info::setInfo(const QString& n, const QString& c, const QDate& d, const QString& p, const QString& m, Residenza* r) {
        nome = n;
        cognome = c;
        dataNascita = d;
        professione = p;
        mail = m;
        residence->setResidenza(r->getComune(),r->getVia(),r->getNumCivico());
}

Info* Info::readInformazioni(QXmlStreamReader& xmlReader) {
    Info* inf = new Info();
    xmlReader.readNext();
    while(!xmlReader.isEndElement() || !(xmlReader.name() == "informazioni")){
        if(xmlReader.isStartElement() && xmlReader.name() == "nome"){
            inf->nome = xmlReader.readElementText();
        }
        else if(xmlReader.isStartElement() && xmlReader.name() == "cognome"){
            inf->cognome = xmlReader.readElementText();
        }
        else if(xmlReader.isStartElement() && xmlReader.name() == "datadinascita"){
            QString data = xmlReader.readElementText();
            QDate date(QDate::fromString(data,"d/M/yyyy"));
            inf->dataNascita = date;
        }
        else if(xmlReader.isStartElement() && xmlReader.name() == "professione"){
            inf->professione = xmlReader.readElementText();
        }
        else if(xmlReader.isStartElement() && xmlReader.name() == "mail"){
            inf->mail = xmlReader.readElementText();
        }
        else if(xmlReader.isStartElement() && xmlReader.name() == "residenza"){
            inf->residence = Residenza::readResidenza(xmlReader);
        }
        else xmlReader.readNext();
    }
    return inf;
}

Info::~Info() {
    delete residence;
}

const QString& Info::getNome() const {
    return nome;
}
const QString& Info::getCognome() const {
    return cognome;
}
const QDate& Info::getDataNascita() const {
    return dataNascita;
}
QString Info::getDataNascitaQString() const {
    return dataNascita.toString("d/M/yyyy");
}
const QString& Info::getProfessione() const {
    return professione;
}
const QString& Info::getMail() const {
    return mail;
}
Residenza* Info::getResidenza() const {
    return residence;
}

void Info::setNome(const QString& n) {
    nome = n;
}
void Info::setCognome(const QString& c) {
    cognome = c;
}
void Info::setDataNascita(const QDate& d) {
    dataNascita = d;
}
void Info::setProfessione(const QString& p) {
    professione = p;
}
void Info::setMail(const QString& m) {
    mail = m;
}
void Info::setResidenza(const QString& c, const QString& v, const QString& n) {
    residence->setResidenza(c,v,n);
}

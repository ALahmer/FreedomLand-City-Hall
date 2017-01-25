#include<MODEL/cittadino.h>
#include<CONTROLLER/controller.h>

Cittadino::Cittadino(Info *i, Credenziali *c, const QString& cit, const QString& cid, const QString& pass)
    : Utente(i,c), cittadinanza(cit), carta_d_identita(cid), passaporto(pass) {}

void Cittadino::setCittadinanza(const QString& cit) {
    cittadinanza = cit;
}

QString Cittadino::getCittadinanza() const {
    return cittadinanza;
}

void Cittadino::setCartaDidentita(const QString& cid) {
    carta_d_identita = cid;
}

QString Cittadino::getCartaDidentita() const {
    return carta_d_identita;
}

void Cittadino::setPassaporto(const QString& pass) {
    passaporto = pass;
}

QString Cittadino::getPassaporto() const {
    return passaporto;
}

QString Cittadino::getPermessoDiSoggiorno() const {
    return "Cittadino con Cittadinanza";
}

QString Cittadino::TipoUtente() const {
    return "Cittadino";
}

/*void Cittadino::CreaModel(const QString& un) {
    Controller* temp;
    temp->creaModelCittadino(un);
}*/

Cittadino* Cittadino::readData(QXmlStreamReader& xmlReader) {
    Credenziali * c = 0;
    Info * i = 0;
    QString cit;
    QString cid;
    QString pass;

    xmlReader.readNext();

    while(!xmlReader.isEndElement() || !(xmlReader.name() == "documenti")){
        if(xmlReader.isStartElement() && xmlReader.name() == "cittadinanza"){
            cit = xmlReader.readElementText();
        } else if(xmlReader.isStartElement() && xmlReader.name() == "cartadidentita"){
            cid = xmlReader.readElementText();
        } else if(xmlReader.isStartElement() && xmlReader.name() == "passaporto"){
            pass = xmlReader.readElementText();
        } else xmlReader.readNext();
    }

    xmlReader.readNext();

    while(!xmlReader.isEndElement() || !(xmlReader.name() == "cittadino")){
        if(xmlReader.isStartElement() && xmlReader.name()=="credenziali"){
            c = Credenziali::readCredenziali(xmlReader);
            xmlReader.readNext();
            }
        else if(xmlReader.isStartElement() && xmlReader.name()=="informazioni"){
            i = Info::readInformazioni(xmlReader);
            xmlReader.readNext();
            }
        xmlReader.readNext();
        }

    return new Cittadino(i,c,cit,cid,pass);
}

void Cittadino::StoreData(QXmlStreamWriter& xmlWriter) {
    xmlWriter.writeStartElement("cittadino");

    Credenziali* TempCred = getCred();
    Info* TempInfo = getInfo();

    //--------------------------------------------------------------------------------
    xmlWriter.writeStartElement("documenti");
    xmlWriter.writeTextElement("cittadinanza", Cittadino::getCittadinanza());
    xmlWriter.writeTextElement("cartadidentita", Cittadino::getCartaDidentita());
    xmlWriter.writeTextElement("passaporto", Cittadino::getPassaporto());
    xmlWriter.writeEndElement();//documenti
    //--------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------
    xmlWriter.writeStartElement("credenziali");
    xmlWriter.writeTextElement("username", TempCred->getUser());
    xmlWriter.writeTextElement("password", TempCred->getPass());
    xmlWriter.writeEndElement();//credenziali
    //--------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------
    xmlWriter.writeStartElement("informazioni");
    xmlWriter.writeTextElement("nome", TempInfo->getNome());
    xmlWriter.writeTextElement("cognome", TempInfo->getCognome());
    xmlWriter.writeTextElement("datadinascita", TempInfo->getDataNascitaQString());
    xmlWriter.writeTextElement("professione", TempInfo->getProfessione());
    xmlWriter.writeTextElement("mail", TempInfo->getMail());
    //--------------------------------------------------------------------------------
    xmlWriter.writeStartElement("residenza");
    xmlWriter.writeTextElement("comune", TempInfo->getResidenza()->getComune());
    xmlWriter.writeTextElement("via", TempInfo->getResidenza()->getVia());
    xmlWriter.writeTextElement("numerocivico", TempInfo->getResidenza()->getComune());
    xmlWriter.writeEndElement();//residenza
    //--------------------------------------------------------------------------------
    xmlWriter.writeEndElement();//informazioni
    //--------------------------------------------------------------------------------

    xmlWriter.writeEndElement();// cittadino
}

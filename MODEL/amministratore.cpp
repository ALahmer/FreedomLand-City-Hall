#include<MODEL/amministratore.h>
#include<CONTROLLER/controller.h>

Amministratore::Amministratore(Info* i, Credenziali* c) : Utente(i,c) {}

QString Amministratore::TipoUtente() const {
    return "Amministratore";
}

QString Amministratore::getCittadinanza() const {
    return "";
}

QString Amministratore::getCartaDidentita() const {
    return "";
}

QString Amministratore::getPassaporto() const {
    return "";
}

QString Amministratore::getPermessoDiSoggiorno() const {
    return "";
}

/*void Amministratore::CreaModel(const QString& un) {
    Controller* temp;
    temp->creaModelAmministratore(un);
}*/

Amministratore* Amministratore::readData(QXmlStreamReader& xmlReader) {
    Credenziali * c = 0;
    Info * i = 0;
    xmlReader.readNext();
    while(!xmlReader.isEndElement() || !(xmlReader.name() == "amministratore")){
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
    return new Amministratore(i,c);
}

void Amministratore::StoreData(QXmlStreamWriter& xmlWriter) {
    xmlWriter.writeStartElement("amministratore");

    Credenziali* TempCred = getCred();
    Info* TempInfo = getInfo();

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

    xmlWriter.writeEndElement();// amministratore
}

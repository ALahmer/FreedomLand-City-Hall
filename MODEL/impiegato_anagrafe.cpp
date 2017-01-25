#include<MODEL/impiegato_anagrafe.h>
#include<CONTROLLER/controller.h>

ImpiegatoAnagrafe::ImpiegatoAnagrafe(Info* i, Credenziali* c) : Impiegato(i,c) {}

QString ImpiegatoAnagrafe::TipoUtente() const {
    return "Impiegato Anagrafe";
}

QString ImpiegatoAnagrafe::getCittadinanza() const {
    return "";
}

QString ImpiegatoAnagrafe::getCartaDidentita() const {
    return "";
}

QString ImpiegatoAnagrafe::getPassaporto() const  {
    return "";
}

QString ImpiegatoAnagrafe::getPermessoDiSoggiorno() const  {
    return "";
}

/*void ImpiegatoAnagrafe::CreaModel(const QString& un) {
    Controller* temp;
    temp->creaModelImpiegatoAnagrafe(un);
}*/

ImpiegatoAnagrafe* ImpiegatoAnagrafe::readData(QXmlStreamReader& xmlReader) {
    Credenziali * c = 0;
    Info * i = 0;
    xmlReader.readNext();
    while(!xmlReader.isEndElement() || !(xmlReader.name() == "impiegatoAnagrafe")){
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
    return new ImpiegatoAnagrafe(i,c);
}

void ImpiegatoAnagrafe::StoreData(QXmlStreamWriter& xmlWriter) {
    xmlWriter.writeStartElement("impiegatoAnagrafe");

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

    xmlWriter.writeEndElement();// impiegatoAnagrafe
}

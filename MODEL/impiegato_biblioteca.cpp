#include<MODEL/impiegato_biblioteca.h>
#include<CONTROLLER/controller.h>

ImpiegatoBiblioteca::ImpiegatoBiblioteca(Info* i, Credenziali* c) : Impiegato(i,c) {}

QString ImpiegatoBiblioteca::TipoUtente() const {
    return "Impiegato Biblioteca";
}

QString ImpiegatoBiblioteca::getCittadinanza() const {
    return "";
}

QString ImpiegatoBiblioteca::getCartaDidentita() const {
    return "";
}

QString ImpiegatoBiblioteca::getPassaporto() const  {
    return "";
}

QString ImpiegatoBiblioteca::getPermessoDiSoggiorno() const  {
    return "";
}

/*void ImpiegatoBiblioteca::CreaModel(const QString& un) {
    Controller* temp;
    temp->creaModelImpiegatoBiblioteca(un);
}*/

ImpiegatoBiblioteca* ImpiegatoBiblioteca::readData(QXmlStreamReader& xmlReader) {
    Credenziali * c = 0;
    Info * i = 0;
    xmlReader.readNext();
    while(!xmlReader.isEndElement() || !(xmlReader.name() == "impiegatoBiblioteca")){
        if(xmlReader.isStartElement() && xmlReader.name()=="credenziali"){
            c = Credenziali::readCredenziali(xmlReader);
            xmlReader.readNext();
            }
        else if(xmlReader.isStartElement() && xmlReader.name()=="informazioni"){
            i = Info::readInformazioni(xmlReader);
            xmlReader.readNext();
            }
        else xmlReader.readNext();
        }
    return new ImpiegatoBiblioteca(i,c);
}

void ImpiegatoBiblioteca::StoreData(QXmlStreamWriter& xmlWriter) {
    xmlWriter.writeStartElement("impiegatoBiblioteca");

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

    xmlWriter.writeEndElement();// impiegatoBiblioteca
}

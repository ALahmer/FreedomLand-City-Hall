#include<MODEL/cittadino_straniero.h>
#include<CONTROLLER/controller.h>

CittadinoStraniero::CittadinoStraniero(Info* i, Credenziali* c, const QString& cit, const QString& cid, const QString& pass, const QString& pds) : Cittadino(i,c,cit,cid,pass) , permesso_di_soggiorno(pds) {}

void CittadinoStraniero::setPermessoDiSoggiorno(const QString& pds){
    permesso_di_soggiorno = pds;
}

QString CittadinoStraniero::getPermessoDiSoggiorno() const {
    return permesso_di_soggiorno;
}

QString CittadinoStraniero::TipoUtente() const {
    return "Cittadino Straniero";
}

/*void CittadinoStraniero::CreaModel(const QString& un) {
    Controller* temp;
    temp->creaModelCittadinoStraniero(un);
}*/

QString CittadinoStraniero::getCittadinanza() const {
    return Cittadino::getCittadinanza();
}

QString CittadinoStraniero::getCartaDidentita() const {
    return Cittadino::getCartaDidentita();
}

QString CittadinoStraniero::getPassaporto() const {
    return Cittadino::getPassaporto();
}

CittadinoStraniero* CittadinoStraniero::readData(QXmlStreamReader& xmlReader) {
    Credenziali * c = 0;
    Info * i = 0;
    QString cit;
    QString cid;
    QString pass;
    QString pds;

    xmlReader.readNext();

    while(!xmlReader.isEndElement() || !(xmlReader.name() == "documentiperstranieri")){
        if(xmlReader.isStartElement() && xmlReader.name() == "permessodisoggiorno"){
            cit = xmlReader.readElementText();
        } else xmlReader.readNext();
    }

    xmlReader.readNext();

    while(!xmlReader.isEndElement() || !(xmlReader.name() == "documenti")){
        if(xmlReader.isStartElement() && xmlReader.name() == "cittadinanza"){
            cit = xmlReader.readElementText();
        }
        else if(xmlReader.isStartElement() && xmlReader.name() == "cartadidentita"){
            cid = xmlReader.readElementText();
        } else if(xmlReader.isStartElement() && xmlReader.name() == "passaporto"){
            pass = xmlReader.readElementText();
        } else xmlReader.readNext();
    }

    xmlReader.readNext();

    while(!xmlReader.isEndElement() || !(xmlReader.name() == "cittadinoStraniero")){
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

    return new CittadinoStraniero(i,c,cit,cid,pass,pds);
}

void CittadinoStraniero::StoreData(QXmlStreamWriter& xmlWriter) {
    xmlWriter.writeStartElement("cittadinoStraniero");

    Credenziali* TempCred = getCred();
    Info* TempInfo = getInfo();

    //--------------------------------------------------------------------------------
    xmlWriter.writeStartElement("documentiperstranieri");
    xmlWriter.writeTextElement("permessodisoggiorno", CittadinoStraniero::getPermessoDiSoggiorno());
    xmlWriter.writeEndElement();//documentiPerStranieri
    //--------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------
    xmlWriter.writeStartElement("documenti");
    xmlWriter.writeTextElement("cittadinanza", getCittadinanza());
    xmlWriter.writeTextElement("cartadidentita", getCartaDidentita());
    xmlWriter.writeTextElement("passaporto", getPassaporto());
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

    xmlWriter.writeEndElement();// cittadinoStraniero
}

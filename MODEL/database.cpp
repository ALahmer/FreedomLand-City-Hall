#include<MODEL/database.h>

QString UsersDatabase::file = "UsersDatabase.xml";

UsersDatabase::UsersDatabase() {
    Load();
}

UsersDatabase::~UsersDatabase() {
    Close();
    for(myContainer<Utente>::myIterator i = db.begin(); i != db.end(); i++) {
        db.Remove((*i));
    }
}

myContainer<Utente>::myIterator UsersDatabase::begin() const {
    return db.begin();
}

myContainer<Utente>::myIterator UsersDatabase::end() const {
    return db.end();
}

void UsersDatabase::Delete_Utente(const QString& us) {
    if(UtenteEsistente(us)){
        Utente* temp = Find_Utente(us);
        db.Remove(temp);
        delete temp;
    }
}

bool UsersDatabase::Login(const QString& username, const QString& password) const {
    if(UtenteEsistente(username)){
        Utente* temp = Find_Utente(username);
        QString pass = temp->getPassword();
        QString passToCheck = QCryptographicHash::hash(password.toUtf8(),QCryptographicHash::Md5).toHex();
        if(pass ==  passToCheck) return true;
        return false;
    } else return false;
}

bool UsersDatabase::UtenteEsistente(const QString& username) const {
    bool trovato = false;
    for(myContainer<Utente>::myIterator i = db.begin(); i != db.end(); i++) {
        if((*i)->getUsername() == username) trovato = true;
    }
    return trovato;
}

void UsersDatabase::NuovoCittadino(Utente* straniero) {
    Delete_Utente(straniero->getUsername());
    Add_New_Cittadino(straniero->getUsername(),straniero->getPassword(),straniero->getInfo()->getNome(),straniero->getInfo()->getCognome());
}

void UsersDatabase::UpdateCittadino(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita, const QString& professione,const QString& mail,const QString& comune,const QString& via, const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita, const QString& passaporto) {
    Utente* backup = Find_Utente(username);
    Delete_Utente(backup->getUsername());
    Residenza* res = new Residenza(comune,via,numerocivico);
    Info* inf = new Info(nome,cognome,datadinascita,professione,mail,res);
    Credenziali* cred = new Credenziali(username);
    cred->SetPasswordNuovoCittadino(backup->getPassword());
    Cittadino* Cit = new Cittadino(inf,cred);
    Cit->setCittadinanza(cittadinanza);
    Cit->setCartaDidentita(cartadidentita);
    Cit->setPassaporto(passaporto);
    db.Push(Cit);
}

void UsersDatabase::UpdateCittadinoStraniero(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita, const QString& professione,const QString& mail,const QString& comune,const QString& via, const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita, const QString& passaporto, const QString& permessodisoggiorno) {
    Utente* backup = Find_Utente(username);
    Delete_Utente(backup->getUsername());
    Residenza* res = new Residenza(comune,via,numerocivico);
    Info* inf = new Info(nome,cognome,datadinascita,professione,mail,res);
    Credenziali* cred = new Credenziali(username);
    cred->SetPasswordNuovoCittadino(backup->getPassword());
    CittadinoStraniero* CitS = new CittadinoStraniero(inf,cred);
    CitS->setCittadinanza(cittadinanza);
    CitS->setCartaDidentita(cartadidentita);
    CitS->setPassaporto(passaporto);
    CitS->setPermessoDiSoggiorno(permessodisoggiorno);
    db.Push(CitS);
}

void UsersDatabase::Add_New_Cittadino(const QString& un, const QString& pw, const QString& nome, const QString& cognome){
    Info* inf = new Info(nome,cognome);
    Credenziali* cred = new Credenziali(un,pw);
    cred->SetPasswordNuovoCittadino(pw);
    Cittadino* Cit = new Cittadino(inf,cred);
    db.Push(Cit);
}

void UsersDatabase::Add_Amministratore(const QString& un, const QString& pw, const QString& nome, const QString& cognome) {
    if(!UtenteEsistente(un)){
        Info* inf = new Info(nome,cognome);
        Credenziali* cred = new Credenziali(un,pw);
        Amministratore* Amm = new Amministratore(inf,cred);
        db.Push(Amm);
    } else {
        std::cout<<"Amministratore già esistente"<<std::endl;
        }
}

void UsersDatabase::Add_ImpiegatoAnagrafe(const QString& un, const QString& pw, const QString& nome, const QString& cognome) {
    if(!UtenteEsistente(un)){
        Info* inf = new Info(nome,cognome);
        Credenziali* cred = new Credenziali(un,pw);
        ImpiegatoAnagrafe* ImAn = new ImpiegatoAnagrafe(inf,cred);
        db.Push(ImAn);
    } else {
        std::cout<<"Impiegato Anagrafe già esistente"<<std::endl;
        }
}

void UsersDatabase::Add_ImpiegatoBiblioteca(const QString& un, const QString& pw, const QString& nome, const QString& cognome) {
    if(!UtenteEsistente(un)){
        Info* inf = new Info(nome,cognome);
        Credenziali* cred = new Credenziali(un,pw);
        ImpiegatoBiblioteca* ImBib = new ImpiegatoBiblioteca(inf,cred);
        db.Push(ImBib);
    } else {
        std::cout<<"Impiegato Biblioteca già esistente"<<std::endl;
        }
}

void UsersDatabase::Add_Cittadino(const QString& un, const QString& pw, const QString& nome, const QString& cognome) {
    if(!UtenteEsistente(un)){
        Info* inf = new Info(nome,cognome);
        Credenziali* cred = new Credenziali(un,pw);
        Cittadino* Cit = new Cittadino(inf,cred);
        db.Push(Cit);
    } else {
        std::cout<<"Cittadino già esistente"<<std::endl;
        }
}

void UsersDatabase::Add_CittadinoStraniero(const QString& un, const QString& pw, const QString& nome, const QString& cognome) {
    if(!UtenteEsistente(un)){
        Info* inf = new Info(nome,cognome);
        Credenziali* cred = new Credenziali(un,pw);
        CittadinoStraniero* CitStr = new CittadinoStraniero(inf,cred);
        db.Push(CitStr);
    } else {
        std::cout<<"Cittadino Straniero già esistente"<<std::endl;
        }
}

void UsersDatabase::AddAmministratore(const Amministratore& temp) {
    if(!UtenteEsistente(temp.getUsername())){
        Amministratore* p = new Amministratore(temp.getInfo(),temp.getCred());
        db.Push(p);
    } else {
        std::cout<<"Amministratore già esistente"<<std::endl;
    }
}

void UsersDatabase::AddImpiegatoAnagrafe(const ImpiegatoAnagrafe& temp) {
    if(!UtenteEsistente(temp.getUsername())){
        ImpiegatoAnagrafe* p = new ImpiegatoAnagrafe(temp.getInfo(),temp.getCred());
        db.Push(p);
    } else {
        std::cout<<"Impiegato Anagrafe già esistente"<<std::endl;
    }
}

void UsersDatabase::AddImpiegatoBiblioteca(const ImpiegatoBiblioteca& temp) {
    if(!UtenteEsistente(temp.getUsername())){
        ImpiegatoBiblioteca* p = new ImpiegatoBiblioteca(temp.getInfo(),temp.getCred());
        db.Push(p);
    } else {
        std::cout<<"Impiegato Bibilioteca già esistente"<<std::endl;
    }
}

void UsersDatabase::AddCittadino(const Cittadino& temp) {
    if(!UtenteEsistente(temp.getUsername())){
        Cittadino* p = new Cittadino(temp.getInfo(),temp.getCred(),temp.getCittadinanza(),temp.getCartaDidentita(),temp.getPassaporto());
        db.Push(p);
    } else {
        std::cout<<"Cittadino già esistente"<<std::endl;
    }
}

void UsersDatabase::AddCittadinoStraniero(const CittadinoStraniero& temp) {
    if(!UtenteEsistente(temp.getUsername())){
        CittadinoStraniero* p = new CittadinoStraniero(temp.getInfo(),temp.getCred(),temp.getCittadinanza(),temp.getCartaDidentita(),temp.getPassaporto(),temp.getPermessoDiSoggiorno());
        db.Push(p);
    } else {
        std::cout<<"Cittadino Straniero già esistente"<<std::endl;
    }
}


Utente* UsersDatabase::Find_Utente(const QString& us) const {
    Utente * result = 0;
    if(UtenteEsistente(us))
        for(myContainer<Utente>::myIterator i = db.begin(); i != db.end(); i++) {
            if((*i)->getUsername() == us) result = *i;
        }
    return result;
}

void UsersDatabase::Load(){
    ImpiegatoBiblioteca* tempImpiegatoBiblioteca = 0;
    ImpiegatoAnagrafe* tempImpiegatoAnagrafe = 0;
    Cittadino* tempCittadino = 0;
    CittadinoStraniero* tempCittadinoStraniero = 0;
    Amministratore* tempAmministratore = 0;

    QFile qfile(file);
    qfile.open(QFile::ReadWrite); //crea il file se nn c'è
    qfile.close(); //chiudo lo stream in lettura e scrittura
    if (!qfile.open(QFile::ReadOnly | QFile::Text)){
        std::cout << "Errore nella lettura del database degli utenti"<< std::endl;
    }

    QXmlStreamReader xmlReader(&qfile);
    xmlReader.readNext(); xmlReader.readNext();

    while(!xmlReader.atEnd()) {
        if(xmlReader.isStartElement()){
            if(xmlReader.name()=="database") xmlReader.readNext();
            else if(xmlReader.name()=="utente") xmlReader.readNext();
            else if(xmlReader.name()=="impiegatoBiblioteca") tempImpiegatoBiblioteca = ImpiegatoBiblioteca::readData(xmlReader);
            else if(xmlReader.name()=="impiegatoAnagrafe") tempImpiegatoAnagrafe = ImpiegatoAnagrafe::readData(xmlReader);
            else if(xmlReader.name()=="cittadino") tempCittadino = Cittadino::readData(xmlReader);
            else if(xmlReader.name()=="cittadinoStraniero") tempCittadinoStraniero = CittadinoStraniero::readData(xmlReader);
            else if(xmlReader.name()=="amministratore") tempAmministratore = Amministratore::readData(xmlReader);
            else xmlReader.readNext();
        } else if(xmlReader.isEndElement()){
                    if(xmlReader.name()=="database") xmlReader.readNext();
                    else if(xmlReader.name()=="utente") xmlReader.readNext();
                    else if(xmlReader.name()=="impiegatoBiblioteca") {
                            if(tempImpiegatoBiblioteca) AddImpiegatoBiblioteca(*tempImpiegatoBiblioteca);
                            xmlReader.readNext(); }
                    else if(xmlReader.name()=="impiegatoAnagrafe") {
                            if(tempImpiegatoAnagrafe) AddImpiegatoAnagrafe(*tempImpiegatoAnagrafe);
                            xmlReader.readNext(); }
                    else if(xmlReader.name()=="cittadino") {
                            if(tempCittadino) AddCittadino(*tempCittadino);
                            xmlReader.readNext(); }
                    else if(xmlReader.name()=="cittadinoStraniero") {
                            if(tempCittadinoStraniero) AddCittadinoStraniero(*tempCittadinoStraniero);
                            xmlReader.readNext(); }
                    else if(xmlReader.name()=="amministratore") {
                            if(tempAmministratore) AddAmministratore(*tempAmministratore);
                            xmlReader.readNext(); }
                    else xmlReader.readNext();
                }
        else xmlReader.readNext();
    }

    qfile.close();
}

void UsersDatabase::Close() {
    //std::cout<<"sono entrato nella close"<<std::endl;

    QFile qfile(file);
    qfile.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&qfile);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("database");

    for(myContainer<Utente>::myIterator i = db.begin(); i != db.end(); i++){
            xmlWriter.writeStartElement("utente");
            Utente* TempUser = *i;
            TempUser->StoreData(xmlWriter);
            xmlWriter.writeEndElement();// utente
        }

    xmlWriter.writeEndElement(); // database

    xmlWriter.writeEndDocument();
    qfile.close();

    //std::cout<<"sono uscito dalla close"<<std::endl;
}

bool UsersDatabase::Empty() const {
    return db.empty();
}

//-----------------------------------------------------------------------------------------------------------------

QString BooksDatabase::file = "BooksDatabase.xml";

BooksDatabase::BooksDatabase() {
    Load();
}

BooksDatabase::~BooksDatabase() {
    Close();
    for(myContainer<Book>::myIterator i = db.begin(); i != db.end(); i++) {
        db.Remove((*i));
    }

}

myContainer<Book>::myIterator BooksDatabase::begin() const {
    return db.begin();
}

myContainer<Book>::myIterator BooksDatabase::end() const {
    return db.end();
}

void BooksDatabase::Delete_Book(const QString& id) {
    if(BookExist(id)){
        Book* temp = Find_Book(id);
        db.Remove(temp);
    }
}

bool BooksDatabase::BookExist(const QString& id) const{
    bool trovato = false;
    for(myContainer<Book>::myIterator i = db.begin(); i != db.end(); i++) {
        if((*i)->getISBN() == id) trovato = true;
    }
    return trovato;
}

void BooksDatabase::RientraLibro(const QString& ISBN){
    Book* temp = Find_Book(ISBN);
    Delete_Book(ISBN);
    temp->setPossessoreTemporaneo();
    AddBook(temp);
}

void BooksDatabase::ImprestaLibro(const QString& ISBN, const QString& UpT){
    Book* temp = Find_Book(ISBN);
    Delete_Book(ISBN);
    temp->setPossessoreTemporaneo(UpT);
    AddBook(temp);
}

void BooksDatabase::Add_Book(const QString& id, const QString& tit , const QString& aut, const QString& ced , const QString& UpT) {
    if(!BookExist(id)){
        Book* libro = new Book(id,tit,aut,ced,UpT);
        db.Push(libro);
    }
}

void BooksDatabase::AddBook(Book* b) {
    if(!BookExist(b->getISBN())){
        db.Push(b);
    }
}


Book* BooksDatabase::Find_Book(const QString& id) const {
    Book* result = 0;
    if(BookExist(id))
        for(myContainer<Book>::myIterator i = db.begin(); i != db.end(); i++) {
            if((*i)->getISBN() == id) result = *i;
        }
    return result;
}

void BooksDatabase::Load(){
    //std::cout<<"entrata load"<<std::endl;

    QString id, tit, aut, ced, UpT;

    QFile qfile(file);
    qfile.open(QFile::ReadWrite); //crea il file se nn c'è
    qfile.close(); //chiudo lo stream in lettura e scrittura
    if (!qfile.open(QFile::ReadOnly | QFile::Text)){
        std::cout << "Errore nella lettura del database dei libri"<< std::endl;
    }

    QXmlStreamReader xmlReader(&qfile);
    xmlReader.readNext();
    xmlReader.readNext();

    while(!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement()){                       //legge tag apertura
                if(xmlReader.isStartElement() && xmlReader.name() == "id"){
                    id = xmlReader.readElementText();
                }
                else if(xmlReader.isStartElement() && xmlReader.name() == "titolo"){
                    tit = xmlReader.readElementText();
                }
                else if(xmlReader.isStartElement() && xmlReader.name() == "autore"){
                    aut = xmlReader.readElementText();
                }
                else if(xmlReader.isStartElement() && xmlReader.name() == "casaeditrice"){
                    ced = xmlReader.readElementText();
                } else if(xmlReader.isStartElement() && xmlReader.name() == "possessoretemporaneo"){
                    UpT = xmlReader.readElementText();
                } else xmlReader.readNext();

        }else
        {
             if(xmlReader.isEndElement() && xmlReader.name()=="book")
             {
                 Book* libro = new Book(id,tit,aut,ced,UpT);
                 db.Push(libro);
                 xmlReader.readNext();
             }else xmlReader.readNext();
        }
    }
    qfile.close();

    //std::cout<<"uscita load"<<std::endl;
}

void BooksDatabase::Close() {
    //std::cout<<"sono entrato nella close"<<std::endl;

    QFile qfile(file);
    qfile.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&qfile);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("database");
    for(myContainer<Book>::myIterator i = db.begin(); i != db.end(); i++){
        Book* libro = *i;

        xmlWriter.writeStartElement("book");

        xmlWriter.writeTextElement("id", libro->getISBN());
        xmlWriter.writeTextElement("titolo", libro->getTitolo());
        xmlWriter.writeTextElement("autore", libro->getAutore());
        xmlWriter.writeTextElement("casaeditrice", libro->getCasaEditrice());
        xmlWriter.writeTextElement("possessoretemporaneo", libro->getPossessoreTemporaneo());

        xmlWriter.writeEndElement();// book
    }
    xmlWriter.writeEndElement(); // database

    xmlWriter.writeEndDocument();
    qfile.close();

    //std::cout<<"sono uscito dalla close"<<std::endl;
}

bool BooksDatabase::Empty() const {
    return db.empty();
}


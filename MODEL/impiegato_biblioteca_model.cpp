#include<MODEL/impiegato_biblioteca_model.h>

ModelImpiegatoBiblioteca::ModelImpiegatoBiblioteca(const QString& username, UsersDatabase* udb,BooksDatabase* bdb) {
    UsDb = udb;
    impiegatobiblioteca = UsDb->Find_Utente(username);
    BksDb = bdb;
}

bool ModelImpiegatoBiblioteca::EmptyDB() const {
    return UsDb->Empty();
}

bool ModelImpiegatoBiblioteca::BooksEmptyDB() const {
    return BksDb->Empty();
}

void ModelImpiegatoBiblioteca::UpdateInfo(const QString& nome, const QString& cognome, const QDate& datadinascita,
                const QString& professione, const QString& mail) {
    impiegatobiblioteca->setInfo(nome,cognome,datadinascita,professione,mail);
}

Utente* ModelImpiegatoBiblioteca::getImpiegatoBiblioteca() const {
    return impiegatobiblioteca;
}

QString ModelImpiegatoBiblioteca::getImpiegatoAnagrafeLogged() const {
    return impiegatobiblioteca->getUsername();
}

myContainer<Utente>::myIterator ModelImpiegatoBiblioteca::begin() const {
    return UsDb->begin();
}

myContainer<Utente>::myIterator ModelImpiegatoBiblioteca::end() const {
    return UsDb->end();
}

myContainer<Book>::myIterator ModelImpiegatoBiblioteca::books_begin() const {
    return BksDb->begin();
}

myContainer<Book>::myIterator ModelImpiegatoBiblioteca::books_end() const {
    return BksDb->end();
}

void ModelImpiegatoBiblioteca::DeleteUser(const QString& username) {
    UsDb->Delete_Utente(username);
}

void ModelImpiegatoBiblioteca::DeleteLibro(const QString& ISBN) {
    BksDb->Delete_Book(ISBN);
}

Book* ModelImpiegatoBiblioteca::getBook(const QString& ISBN) const {
    return BksDb->Find_Book(ISBN);
}

void ModelImpiegatoBiblioteca::AddUser(const QString& nome, const QString& cognome, const QString& username, const QString& password, const QString& tipo) {
    if(tipo == "Cittadino") UsDb->Add_Cittadino(username,password,nome,cognome);
    else if(tipo == "Cittadino Straniero") UsDb->Add_CittadinoStraniero(username,password,nome,cognome);
}

void ModelImpiegatoBiblioteca::AddBook(const QString& ISBN, const QString& titolo , const QString& autore , const QString& casaEd) {
    BksDb->Add_Book(ISBN,titolo,autore,casaEd);
}

bool ModelImpiegatoBiblioteca::ExistingUser(const QString& username) const {
    return UsDb->UtenteEsistente(username);
}

void ModelImpiegatoBiblioteca::ResumeLibro(const QString& ISBN){
    BksDb->RientraLibro(ISBN);
}

void ModelImpiegatoBiblioteca::BorrowLibro(const QString& ISBN, const QString& possessore){
    BksDb->ImprestaLibro(ISBN,possessore);
}

bool ModelImpiegatoBiblioteca::ExistingBook(const QString& ISBN) const {
    return BksDb->BookExist(ISBN);
}

QString ModelImpiegatoBiblioteca::Tipo(const QString& username) const {
    return UsDb->Find_Utente(username)->TipoUtente();
}

Utente* ModelImpiegatoBiblioteca::getUser(const QString& username) const {
    return UsDb->Find_Utente(username);
}

void ModelImpiegatoBiblioteca::NewCittadino(Utente* straniero) {
    UsDb->NuovoCittadino(straniero);
}

void ModelImpiegatoBiblioteca::Update_Cittadino(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita, const QString& professione,const QString& mail,const QString& comune,const QString& via,const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita,const QString& passaporto){
    UsDb->UpdateCittadino(username,nome,cognome,datadinascita,professione,mail,comune,via,numerocivico,cittadinanza,cartadidentita,passaporto);
}

void ModelImpiegatoBiblioteca::Update_Cittadino_Straniero(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita, const QString& professione,const QString& mail,const QString& comune,const QString& via, const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita, const QString& passaporto, const QString& permessodisoggiorno){
    UsDb->UpdateCittadinoStraniero(username,nome,cognome,datadinascita,professione,mail,comune,via,numerocivico,cittadinanza,cartadidentita,passaporto,permessodisoggiorno);
}

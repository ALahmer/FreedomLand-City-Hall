#ifndef IMPIEGATO_BIBLIOTECA_MODEL_H
#define IMPIEGATO_BIBLIOTECA_MODEL_H

#include<MODEL/impiegato_biblioteca.h>
#include<MODEL/database.h>

class ModelImpiegatoBiblioteca {
private:
    Utente* impiegatobiblioteca;
    BooksDatabase* BksDb;
    UsersDatabase* UsDb;
public:
    ModelImpiegatoBiblioteca(const QString& username, UsersDatabase* udb,BooksDatabase* bdb);
    bool EmptyDB() const;
    bool BooksEmptyDB() const;
    void UpdateInfo(const QString& nome, const QString& cognome, const QDate& datadinascita,const QString& professione, const QString& mail);
    Utente* getImpiegatoBiblioteca() const;
    QString getImpiegatoAnagrafeLogged() const;
    myContainer<Utente>::myIterator begin() const;
    myContainer<Utente>::myIterator end() const;
    myContainer<Book>::myIterator books_begin() const;
    myContainer<Book>::myIterator books_end() const;
    void DeleteUser(const QString& username);
    void DeleteLibro(const QString& ISBN);
    Book* getBook(const QString& ISBN) const;
    void AddUser(const QString& nome, const QString& cognome, const QString& username, const QString& password, const QString& tipo);
    void AddBook(const QString& ISBN ="Nessuna informazione.", const QString& titolo ="Nessuna informazione.", const QString& autore ="Nessuna informazione.", const QString& casaEd ="Nessuna informazione.");
    bool ExistingUser(const QString& username) const;
    void ResumeLibro(const QString& ISBN);
    void BorrowLibro(const QString& ISBN, const QString& possessore);
    bool ExistingBook(const QString& ISBN) const;
    QString Tipo(const QString& username) const;
    Utente* getUser(const QString& username) const;
    void NewCittadino(Utente* straniero);
    void Update_Cittadino(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita, const QString& professione,const QString& mail,const QString& comune,const QString& via,const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita,const QString& passaporto);
    void Update_Cittadino_Straniero(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita, const QString& professione,const QString& mail,const QString& comune,const QString& via, const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita, const QString& passaporto, const QString& permessodisoggiorno);
};

#endif // IMPIEGATO_BIBLIOTECA_MODEL_H

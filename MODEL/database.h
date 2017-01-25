#ifndef Database_H
#define Database_H

#include<QFile>
#include<QXmlStreamWriter>
#include<MODEL/myContainer.h>
#include<MODEL/utente.h>
#include<MODEL/book.h>
#include<MODEL/amministratore.h>
#include<MODEL/impiegato_anagrafe.h>
#include<MODEL/impiegato_biblioteca.h>
#include<MODEL/cittadino_straniero.h>

class UsersDatabase{
private:
    static QString file;
    myContainer<Utente> db;

public:
    UsersDatabase();
    ~UsersDatabase();
    myContainer<Utente>::myIterator begin() const;
    myContainer<Utente>::myIterator end() const;
    void Delete_Utente(const QString& us);
    bool Login(const QString& username, const QString& password) const;
    bool UtenteEsistente(const QString& username) const;
    void NuovoCittadino(Utente* straniero);
    void UpdateCittadino(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita, const QString& professione,const QString& mail,const QString& comune,const QString& via, const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita, const QString& passaporto);
    void UpdateCittadinoStraniero(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita, const QString& professione,const QString& mail,const QString& comune,const QString& via, const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita, const QString& passaporto, const QString& permessodisoggiorno);
    void Add_New_Cittadino(const QString& un, const QString& pw, const QString& nome, const QString& cognome);
    void Add_Amministratore(const QString& un, const QString& pw, const QString& nome, const QString& cognome);
    void Add_ImpiegatoAnagrafe(const QString& un, const QString& pw, const QString& nome, const QString& cognome);
    void Add_ImpiegatoBiblioteca(const QString& un, const QString& pw, const QString& nome, const QString& cognome);
    void Add_Cittadino(const QString& un, const QString& pw, const QString& nome, const QString& cognome);
    void Add_CittadinoStraniero(const QString& un, const QString& pw, const QString& nome, const QString& cognome);
    void AddAmministratore(const Amministratore& temp);
    void AddImpiegatoAnagrafe(const ImpiegatoAnagrafe& temp);
    void AddImpiegatoBiblioteca(const ImpiegatoBiblioteca& temp);
    void AddCittadino(const Cittadino& temp);
    void AddCittadinoStraniero(const CittadinoStraniero& temp);
    Utente* Find_Utente(const QString& us) const;
    void Load();
    void Close();
    bool Empty() const;
};

//--------------------------------------------------------------------------------------------------------------------//

class BooksDatabase{
private:
    static QString file;
    myContainer<Book> db;

public:
    BooksDatabase();
    ~BooksDatabase();
    myContainer<Book>::myIterator begin() const;
    myContainer<Book>::myIterator end() const;
    void Delete_Book(const QString& id);
    bool BookExist(const QString& id) const;
    void Add_Book(const QString& id ="Nessuna informazione.", const QString& tit ="Nessuna informazione.", const QString& aut ="Nessuna informazione.", const QString& ced ="Nessuna informazione.",const QString& UpT ="Nessuna informazione.");
    void ImprestaLibro(const QString& ISBN, const QString& UpT);
    void RientraLibro(const QString& ISBN);
    void AddBook(Book* b);
    Book* Find_Book(const QString& id) const;
    void Load();
    void Close();
    bool Empty() const;
};

#endif // Database_H

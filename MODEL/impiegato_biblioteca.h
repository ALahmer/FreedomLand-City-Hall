#ifndef IMPIEGATO_BIBLIOTECA_H
#define IMPIEGATO_BIBLIOTECA_H
#include<MODEL/impiegato.h>

class ImpiegatoBiblioteca : public Impiegato {
public:
    ImpiegatoBiblioteca(Info* i = new Info(), Credenziali* c = new Credenziali());
    virtual QString TipoUtente() const;
    virtual QString getCittadinanza() const;
    virtual QString getCartaDidentita() const;
    virtual QString getPassaporto() const;
    virtual QString getPermessoDiSoggiorno() const;
    //virtual void CreaModel(const QString& un);
    static ImpiegatoBiblioteca* readData(QXmlStreamReader& xmlReader);
    virtual void StoreData(QXmlStreamWriter& xmlWriter);
};

#endif // IMPIEGATO_BIBLIOTECA_H

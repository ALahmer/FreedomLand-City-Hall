#ifndef IMPIEGATO_ANAGRAFE_H
#define IMPIEGATO_ANAGRAFE_H

#include<MODEL/impiegato.h>

class ImpiegatoAnagrafe : public Impiegato {
public:
    ImpiegatoAnagrafe(Info* i = new Info(), Credenziali* c = new Credenziali());
    virtual QString TipoUtente() const;
    virtual QString getCittadinanza() const;
    virtual QString getCartaDidentita() const;
    virtual QString getPassaporto() const;
    virtual QString getPermessoDiSoggiorno() const;
    //virtual void CreaModel(const QString& un);
    static ImpiegatoAnagrafe* readData(QXmlStreamReader& xmlReader);
    virtual void StoreData(QXmlStreamWriter& xmlWriter);
};

#endif // IMPIEGATO_ANAGRAFE_H

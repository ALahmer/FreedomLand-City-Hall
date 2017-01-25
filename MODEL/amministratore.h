#ifndef AMMINISTRATORE_H
#define AMMINISTRATORE_H

#include<MODEL/utente.h>

class Amministratore : public Utente {
public:
    Amministratore(Info* i = new Info(), Credenziali* c = new Credenziali());
    virtual QString TipoUtente() const;
    virtual QString getCittadinanza() const;
    virtual QString getCartaDidentita() const;
    virtual QString getPassaporto() const;
    virtual QString getPermessoDiSoggiorno() const;
    //virtual void CreaModel(const QString& un);
    static Amministratore* readData(QXmlStreamReader& xmlReader);
    virtual void StoreData(QXmlStreamWriter& xmlWriter);
};

#endif // AMMINISTRATORE_H

#ifndef IMPIEGATO_H
#define IMPIEGATO_H

#include<MODEL/utente.h>

class Impiegato : public Utente {
private:
    QString funzione;
public:
    Impiegato(Info* i = new Info(), Credenziali* c = new Credenziali(), const QString& fun = "Nessuna informazione.");
    void setFunzione(const QString& fun = "Nessuna informazione.");
    QString getFunzione() const;
    virtual QString TipoUtente() const = 0;
    virtual void StoreData(QXmlStreamWriter& xmlWriter) = 0;
    //virtual void CreaModel(const QString& un) = 0;
    virtual QString getCittadinanza() const = 0;
    virtual QString getCartaDidentita() const = 0;
    virtual QString getPassaporto() const = 0;
    virtual QString getPermessoDiSoggiorno() const = 0;
};

#endif // IMPIEGATO_H

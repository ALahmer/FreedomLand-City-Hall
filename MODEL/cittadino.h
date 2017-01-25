#ifndef CITTADINO_H
#define CITTADINO_H

#include<MODEL/utente.h>

class Cittadino : public Utente {
    QString cittadinanza;
    QString carta_d_identita;
    QString passaporto;

public:
    Cittadino(Info* i = new Info(), Credenziali* c = new Credenziali(), const QString& cit = "Nessuna informazione.", const QString& cid = "Nessuna informazione.",const QString& pass = "Nessuna informazione.");
    void setCittadinanza(const QString& cit = "Nessuna informazione.");
    virtual QString getCittadinanza() const;
    void setCartaDidentita(const QString& cid = "Nessuna informazione.");
    virtual QString getCartaDidentita() const;
    void setPassaporto(const QString& pass = "Nessuna informazione.");
    virtual QString getPassaporto() const;
    virtual QString getPermessoDiSoggiorno() const;
    virtual QString TipoUtente() const;
    //virtual void CreaModel(const QString& un);
    static Cittadino* readData(QXmlStreamReader& xmlReader);
    virtual void StoreData(QXmlStreamWriter& xmlWriter);
};

#endif // CITTADINO_H

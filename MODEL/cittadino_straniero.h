#ifndef CITTADINO_STRANIERO_H
#define CITTADINO_STRANIERO_H

#include<MODEL/cittadino.h>

class CittadinoStraniero : public Cittadino {
    QString permesso_di_soggiorno;
public:
    CittadinoStraniero(Info* i = new Info(), Credenziali* c = new Credenziali(), const QString& cit = "Nessuna informazione.", const QString& cid = "Nessuna informazione.", const QString& pass = "Nessuna informazione.", const QString& pds = "Nessuna informazione.");
    void setPermessoDiSoggiorno(const QString& pds = "Nessuna informazione.");
    virtual QString getPermessoDiSoggiorno() const;
    virtual QString TipoUtente() const;
    //virtual void CreaModel(const QString& un);
    virtual QString getCittadinanza() const;
    virtual QString getCartaDidentita() const;
    virtual QString getPassaporto() const;
    static CittadinoStraniero* readData(QXmlStreamReader& xmlReader);
    virtual void StoreData(QXmlStreamWriter& xmlWriter);

};

#endif // CITTADINO_STRANIERO_H

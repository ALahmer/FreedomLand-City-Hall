#ifndef RESIDENZA_H
#define RESIDENZA_H

#include <QString>
#include<QXmlStreamReader>
#include<iostream>

class Residenza {
private:
    QString comune;
    QString via;
    QString num_Civico;
public:
    Residenza(const QString& c = "Nessuna informazione.", const QString& v = "Nessuna informazione.", const QString& n = "Nessuna informazione.");
    void setResidenza(const QString& c = "Nessuna informazione.", const QString& v = "Nessuna informazione.",const QString& n = "Nessuna informazione.");
    static Residenza* readResidenza(QXmlStreamReader& xmlReader);
    const QString& getComune() const;
    const QString& getVia() const;
    const QString& getNumCivico() const;
    void setComune(const QString& c = "Nessuna informazione.");
    void setVia(const QString& v = "Nessuna informazione.");
    void setNumCivico(const QString& n = "Nessuna informazione.");
};

#endif // RESIDENZA_H

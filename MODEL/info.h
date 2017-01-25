#ifndef INFO_H
#define INFO_H

#include <QDate>
#include <MODEL/residenza.h>

class Info {
private:
    QString nome;
    QString cognome;
    QDate dataNascita;
    QString professione;
    QString mail;
    Residenza* residence;
public:
    Info(const QString& n="Nessuna informazione.", const QString& c="Nessuna informazione.", const QDate& d = QDate(1990,1,1), const QString& p="Nessuna informazione.", const QString& m="Nessuna informazione.", Residenza* r = new Residenza());
    void setInfo(const QString& n="Nessuna informazione.", const QString& c="Nessuna informazione.", const QDate& d = QDate(1990,1,1), const QString& p="Nessuna informazione.", const QString& m="Nessuna informazione.", Residenza* r = new Residenza());
    static Info* readInformazioni(QXmlStreamReader& xmlReader);
    ~Info();
    // METODI GET
    const QString& getNome() const;
    const QString& getCognome() const;
    const QDate& getDataNascita() const;
    QString getDataNascitaQString() const;
    const QString& getProfessione() const;
    const QString& getMail() const;
    Residenza* getResidenza() const;
    // METODI SET
    void setNome(const QString& n="Nessuna informazione.");
    void setCognome(const QString& c="Nessuna informazione.");
    void setDataNascita(const QDate& d = QDate(1990,1,1));
    void setProfessione(const QString& p="Nessuna informazione.");
    void setMail(const QString& m="Nessuna informazione.");
    void setResidenza(const QString& c = "Nessuna informazione.",const QString& v = "Nessuna informazione.",const QString& n = "Nessuna informazione.");
};

#endif // INFO_H

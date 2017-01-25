#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book {
private:
    QString ISBN;
    QString titolo;
    QString autore;
    QString casaEditrice;
    QString usernamePossessoreTemporaneo;
public:
    Book(const QString& id = "Nessuna informazione.", const QString& t = "Nessuna informazione.", const QString& a = "Nessuna informazione.", const QString& ce = "Nessuna informazione.", const QString& UpT = "Nessuna informazione.");

    // METODI GET
    QString getISBN() const;
    QString getTitolo() const;
    QString getAutore() const;
    QString getCasaEditrice() const;
    QString getPossessoreTemporaneo() const;

    // METODI SET
    void setISBN(const QString& id ="Nessuna informazione.");
    void setTitolo(const QString& t ="Nessuna informazione.");
    void setAutore(const QString& a ="Nessuna informazione.");
    void setCasaEditrice(const QString& ce ="Nessuna informazione.");
    void setPossessoreTemporaneo(const QString& UpT ="Nessuna informazione.");
};

#endif // BOOK_H

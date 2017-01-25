#include<MODEL/book.h>

Book::Book(const QString& id, const QString& t, const QString& a, const QString& ce, const QString& UpT) : ISBN(id), titolo(t), autore(a), casaEditrice(ce) , usernamePossessoreTemporaneo(UpT) {}

// METODI GET
QString Book::getISBN() const {
    return ISBN;
}
QString Book::getTitolo() const {
    return titolo;
}
QString Book::getAutore() const {
    return autore;
}
QString Book::getCasaEditrice() const {
    return casaEditrice;
}
QString Book::getPossessoreTemporaneo() const {
    return usernamePossessoreTemporaneo;
}

// METODI SET
void Book::setISBN(const QString& id) {
    ISBN = id;
}
void Book::setTitolo(const QString& t) {
    titolo = t;
}
void Book::setAutore(const QString& a) {
    autore = a;
}
void Book::setCasaEditrice(const QString& ce) {
    casaEditrice = ce;
}
void Book::setPossessoreTemporaneo(const QString& UpT) {
    usernamePossessoreTemporaneo = UpT;
}

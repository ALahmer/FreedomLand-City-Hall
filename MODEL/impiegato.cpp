#include<MODEL/impiegato.h>

Impiegato::Impiegato(Info* i, Credenziali* c, const QString& fun) : Utente(i,c), funzione(fun) {}

void Impiegato::setFunzione(const QString& fun) {
    funzione = fun;
}

QString Impiegato::getFunzione() const {
    return funzione;
}

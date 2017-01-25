#ifndef AMMINISTRATORECONTROLLER_H
#define AMMINISTRATORECONTROLLER_H

#include<VIEW/amministratore_view.h>

class AmministratoreController : public QObject {
    Q_OBJECT
private:
    ModelAmministratore* model;
    AmministratoreView* view;
public:
    AmministratoreController(QObject* parent=0, ModelAmministratore* m=0, AmministratoreView* v=0);

public slots:
    void slotModificaProfiloUtente(const QString& nome, const QString& cognome, const QString& password1, const QString& password2, const QDate& datadinascita, const QString& professione, const QString& mail);

    void slotAddUtente(const QString& nome, const QString& cognome, const QString& username, const QString& password, const QString& tipo);

    void DeleteUtenteSlot(const QString& username);
};

#endif // AMMINISTRATORECONTROLLER_H

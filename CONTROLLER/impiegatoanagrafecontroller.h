#ifndef IMPIEGATOANAGRAFECONTROLLER_H
#define IMPIEGATOANAGRAFECONTROLLER_H

#include<VIEW/impiegato_anagrafe_view.h>

class ImpiegatoAnagrafeController : public QObject {
    Q_OBJECT
private:
    ModelImpiegatoAnagrafe* model;
    ImpiegatoAnagrafeView* view;
public:
    ImpiegatoAnagrafeController(QObject* parent=0, ModelImpiegatoAnagrafe* m = 0, ImpiegatoAnagrafeView* v = 0);

public slots:
    void SlotModificaProfiloCittadino(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita, const QString& professione, const QString& mail,const QString& comune,const QString& via, const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita, const QString& passaporto,const QString& permessodisoggiorno);
    void slotModificaProfiloUtente(const QString& nome, const QString& cognome, const QString& password1, const QString& password2, const QDate& datadinascita, const QString& professione, const QString& mail);
    void DecretaCittadinanzaUtenteSlot(const QString& username);
    void slotAddCittadino(const QString& nome, const QString& cognome, const QString& username, const QString& password, const QString& tipo);
};
#endif // IMPIEGATOANAGRAFECONTROLLER_H

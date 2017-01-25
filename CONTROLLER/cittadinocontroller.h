#ifndef CITTADINOCONTROLLER_H
#define CITTADINOCONTROLLER_H

#include<VIEW/cittadino_view.h>

class CittadinoController : public QObject {
    Q_OBJECT
private:
    ModelCittadino* model;
    CittadinoView* view;
public:
    CittadinoController(QObject* parent=0, ModelCittadino* m=0, CittadinoView* v=0);

public slots:
    void slotModificaProfiloUtente(const QString& nome, const QString& cognome, const QString& password1, const QString& password2, const QDate& datadinascita, const QString& professione, const QString& mail);
};

#endif // CITTADINOCONTROLLER_H

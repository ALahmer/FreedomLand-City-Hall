#ifndef CITTADINOSTRANIEROCONTROLLER_H
#define CITTADINOSTRANIEROCONTROLLER_H

#include<VIEW/cittadino_straniero_view.h>

class CittadinoStranieroController : public QObject {
    Q_OBJECT
private:
    ModelCittadinoStraniero* model;
    CittadinoStranieroView* view;
public:
    CittadinoStranieroController(QObject* parent=0, ModelCittadinoStraniero* m=0, CittadinoStranieroView* v=0);

public slots:
    void slotModificaProfiloUtente(const QString& nome, const QString& cognome, const QString& password1, const QString& password2, const QDate& datadinascita, const QString& professione, const QString& mail);
};


#endif // CITTADINOSTRANIEROCONTROLLER_H

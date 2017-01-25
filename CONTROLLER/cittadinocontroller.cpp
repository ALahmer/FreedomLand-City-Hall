#include<CONTROLLER/cittadinocontroller.h>

CittadinoController::CittadinoController(QObject* parent, ModelCittadino* m, CittadinoView* v) : QObject(parent) , model(m) , view(v) {
    connect(view,SIGNAL(signalModifyProfile(QString,QString,QString,QString,QDate,QString,QString)),this,SLOT(slotModificaProfiloUtente(QString,QString,QString,QString,QDate,QString,QString)));
}

void CittadinoController::slotModificaProfiloUtente(const QString& nome, const QString& cognome, const QString& password1, const QString& password2, const QDate& datadinascita, const QString& professione, const QString& mail) {
    model->UpdateInfo(nome,cognome,datadinascita,professione,mail);
    if(password1 != "" && password2 != ""){
        model->getCittadino()->setCred(model->getCittadinoLogged(),password1);
        }
    emit view->logoutCittadino();
}

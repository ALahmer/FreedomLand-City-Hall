#include<CONTROLLER/amministratorecontroller.h>

AmministratoreController::AmministratoreController(QObject* parent, ModelAmministratore* m, AmministratoreView* v) : QObject(parent) , model(m) , view(v) {
    connect(view,SIGNAL(DeleteUtenteSignal(QString)),this,SLOT(DeleteUtenteSlot(QString)));
    connect(view,SIGNAL(signalAddUtente(QString,QString,QString,QString,QString)),this,SLOT(slotAddUtente(QString,QString,QString,QString,QString)));
    connect(view,SIGNAL(signalModifyProfile(QString,QString,QString,QString,QDate,QString,QString)),this,SLOT(slotModificaProfiloUtente(QString,QString,QString,QString,QDate,QString,QString)));
}

void AmministratoreController::slotModificaProfiloUtente(const QString& nome, const QString& cognome, const QString& password1, const QString& password2, const QDate& datadinascita, const QString& professione, const QString& mail) {
        model->UpdateInfo(nome,cognome,datadinascita,professione,mail);
        if(password1 != "" && password2 != ""){
            model->getAdmin()->setCred(model->getAdminLogged(),password1);
            }
        view->popolaTabella();
}
void AmministratoreController::slotAddUtente(const QString& nome, const QString& cognome, const QString& username, const QString& password, const QString& tipo) {
    if(!model->ExistingUser(username)) {
        model->AddUser(nome,cognome,username,password,tipo);
        view->cancellaAddNewUserWindow();
        view->popolaTabella();
    } else {
        QMessageBox errore;
        errore.setText("Errore: l'username scelto è già in uso.");
        errore.setStandardButtons(QMessageBox::Ok);
        errore.setDefaultButton(QMessageBox::Ok);
        errore.exec();
        }
}

void AmministratoreController::DeleteUtenteSlot(const QString& username) {
    if(model->ExistingUser(username)) {
        if(model->getAdminLogged() != username){
            model->DeleteUser(username);
            view->popolaTabella();
        } else {
            QMessageBox errore;
            errore.setText("Impossibile eliminare il proprio account.");
            errore.exec();
        }
    } else {
        QMessageBox errore;
        errore.setText("Impossibile eliminare l'utente selezionato.");
        errore.exec();
        }
}

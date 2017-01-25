#include<CONTROLLER/impiegatoanagrafecontroller.h>

ImpiegatoAnagrafeController::ImpiegatoAnagrafeController(QObject* parent, ModelImpiegatoAnagrafe* m, ImpiegatoAnagrafeView* v) : QObject(parent) , model(m) , view(v) {
    connect(view,SIGNAL(signalModifyProfile(QString,QString,QString,QString,QDate,QString,QString)),this,SLOT(slotModificaProfiloUtente(QString,QString,QString,QString,QDate,QString,QString)));
    connect(view,SIGNAL(DecretaCittadinanzaUtenteSignal(QString)),this,SLOT(DecretaCittadinanzaUtenteSlot(QString)));
    connect(view,SIGNAL(signalAddCittadino(QString,QString,QString,QString,QString)),this,SLOT(slotAddCittadino(QString,QString,QString,QString,QString)));
    connect(view,SIGNAL(SignalModificaProfiloCittadino(QString,QString,QString,QDate,QString,QString,QString,QString,QString,QString,QString,QString,QString) ),this,SLOT( SlotModificaProfiloCittadino(QString,QString,QString,QDate,QString,QString,QString,QString,QString,QString,QString,QString,QString)  ));
}

void ImpiegatoAnagrafeController::SlotModificaProfiloCittadino(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita, const QString& professione, const QString& mail,const QString& comune,const QString& via, const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita, const QString& passaporto,const QString& permessodisoggiorno) {
    if(permessodisoggiorno == "Cittadino con Cittadinanza"){
        model->Update_Cittadino(username,nome,cognome,datadinascita,professione,mail,comune,via,numerocivico,cittadinanza,cartadidentita,passaporto);
        QMessageBox allert;
        allert.setText("Informazioni aggiornate con successo.");
        allert.exec();
    }
    else {
        model->Update_Cittadino_Straniero(username,nome,cognome,datadinascita,professione,mail,comune,via,numerocivico,cittadinanza,cartadidentita,passaporto,permessodisoggiorno);
        QMessageBox allert;
        allert.setText("Informazioni aggiornate con successo.");
        allert.exec();
        }

    view->cancellaAddNewUserWindow();
    view->popolaTabella();
}

void ImpiegatoAnagrafeController::slotModificaProfiloUtente(const QString& nome, const QString& cognome, const QString& password1, const QString& password2, const QDate& datadinascita, const QString& professione, const QString& mail) {
    model->UpdateInfo(nome,cognome,datadinascita,professione,mail);
    if(password1 != "" && password2 != "") model->getImpiegatoAnagrafe()->setCred(model->getImpiegatoAnagrafeLogged(),password1);
    view->popolaTabella();
}

void ImpiegatoAnagrafeController::DecretaCittadinanzaUtenteSlot(const QString& username) {
    if(model->ExistingUser(username)) {
        if(model->Tipo(username) == "Cittadino Straniero"){
            Utente* temp = model->getUser(username);
            model->Update_Cittadino(temp->getUsername(),temp->getInfo()->getNome(), temp->getInfo()->getCognome(),temp->getInfo()->getDataNascita(), temp->getInfo()->getProfessione(),temp->getInfo()->getMail(), temp->getInfo()->getResidenza()->getComune(),temp->getInfo()->getResidenza()->getVia(), temp->getInfo()->getResidenza()->getNumCivico(),temp->getCittadinanza(),temp->getCartaDidentita(), temp->getPassaporto());
            view->popolaTabella();
            } else {
                QMessageBox errore;
                errore.setText("Il cittadino selezionato possiede già la cittadinanza.");
                errore.exec();
            }
    } else {
        QMessageBox errore;
        errore.setText("Impossibile decretare la cittadinanza al cittadino selezionato.");
        errore.exec();
        }
}

void ImpiegatoAnagrafeController::slotAddCittadino(const QString& nome, const QString& cognome, const QString& username, const QString& password, const QString& tipo) {
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

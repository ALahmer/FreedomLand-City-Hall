#include<CONTROLLER/impiegatobibliotecacontroller.h>

ImpiegatoBibliotecaController::ImpiegatoBibliotecaController(QObject* parent, ModelImpiegatoBiblioteca* m, ImpiegatoBibliotecaView* v) : QObject(parent) , model(m) , view(v) {
    connect(view,SIGNAL(signalModifyProfile(QString,QString,QString,QString,QDate,QString,QString)),this,SLOT(slotModificaProfiloUtente(QString,QString,QString,QString,QDate,QString,QString)));
    connect(view,SIGNAL(signalAddLibro(QString,QString,QString,QString)),this,SLOT(slotAddLibro(QString,QString,QString,QString)));
    connect(view,SIGNAL(DeleteLibroSignal(QString)),this,SLOT(DeleteLibroSlot(QString)));
    connect(view,SIGNAL(BorrowLibroSignal(QString,QString)),this,SLOT(BorrowLibroSlot(QString,QString)));
    connect(view,SIGNAL(ResumeLibroSignal(QString)),this,SLOT(ResumeLibroSlot(QString)));
}

void ImpiegatoBibliotecaController::slotModificaProfiloUtente(const QString& nome, const QString& cognome, const QString& password1, const QString& password2, const QDate& datadinascita, const QString& professione, const QString& mail) {
    model->UpdateInfo(nome,cognome,datadinascita,professione,mail);
    if(password1 != "" && password2 != ""){
        model->getImpiegatoBiblioteca()->setCred(model->getImpiegatoAnagrafeLogged(),password1);
        }
    view->popolaTabelle();
}

void ImpiegatoBibliotecaController::BorrowLibroSlot(const QString& possessore, const QString& ISBN) {
    if(model->ExistingBook(ISBN)) {
        if(model->getBook(ISBN)->getPossessoreTemporaneo() != "Nessuna informazione.") {
            QMessageBox errore;
            errore.setText("Il libro selezionato è già imprestato.");
            errore.exec();
        } else if(model->ExistingUser(possessore)){
                    model->BorrowLibro(ISBN,possessore);
                    view->popolaTabelle();
                } else {
                    QMessageBox errore;
                    errore.setText("Impossibile imprestare il libro selezionato all'utente selezionato.");
                    errore.exec();
                    }
        } else {
            QMessageBox errore;
            errore.setText("Impossibile imprestare il libro selezionato.");
            errore.exec();
        }
}

void ImpiegatoBibliotecaController::ResumeLibroSlot(const QString& ISBN) {
    if(model->ExistingBook(ISBN)) {
        if(model->getBook(ISBN)->getPossessoreTemporaneo() != "Nessuna informazione.") {
                model->ResumeLibro(ISBN);
                view->popolaTabelle();
        } else {
            QMessageBox errore;
            errore.setText("Il libro selezionato non è imprestato.");
            errore.exec();
        }
    } else {
        QMessageBox errore;
        errore.setText("Impossibile rientrare il libro selezionato.");
        errore.exec();
        }
}


void ImpiegatoBibliotecaController::DeleteLibroSlot(const QString& ISBN) {
    if(model->ExistingBook(ISBN)) {
        model->DeleteLibro(ISBN);
        view->popolaTabelle();
        } else {
            QMessageBox errore;
            errore.setText("Impossibile eliminare il libro selezionato.");
            errore.exec();
            }
}

void ImpiegatoBibliotecaController::slotAddLibro(const QString& ISBN, const QString& titolo, const QString& autore, const QString& casaEd) {
    if(!model->ExistingBook(ISBN)) {
        model->AddBook(ISBN,titolo,autore,casaEd);
        view->cancellaAddNewBookWindow();
        view->popolaTabelle();
    } else {
        QMessageBox errore;
        errore.setText("Errore: libro già esistente.");
        errore.setStandardButtons(QMessageBox::Ok);
        errore.setDefaultButton(QMessageBox::Ok);
        errore.exec();
    }
}

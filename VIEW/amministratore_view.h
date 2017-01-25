#ifndef AMMINISTRATORE_VIEW_H
#define AMMINISTRATORE_VIEW_H

#include<QGroupBox>
#include<QFrame>
#include<QToolTip>
#include<QIcon>
#include<QMainWindow>
#include<QTableWidget>
#include<QRadioButton>
#include<QHeaderView>
#include<QTableWidgetItem>

#include<MODEL/amministratore_model.h>
#include<VIEW/inserisci_nuovo_utente.h>
#include<VIEW/modifica_profilo.h>

class AmministratoreView : public QWidget {
    Q_OBJECT
private:
    const ModelAmministratore* model;

    QLabel* benvenuto;

    QTableWidget* tabella;

    QString utenteSelezionato;

    QPushButton* rimuovi;
    QPushButton* inserisciUtente;
    QPushButton* profilo;
    QPushButton* logout;
    QPushButton* esci;

    InserisciNuovoUtente* addNewUser;
    ModificaProfilo* modifyProfile;

    QVBoxLayout* layout;
public:
    AmministratoreView(QWidget *parent=0, const ModelAmministratore* modeL=0);
    ~AmministratoreView();
    void centraFinestra(int,int);
    void popolaTabella();
    void pulisciTabella();
    void cancellaAddNewUserWindow();
    void cancellaModifyProfileWindow();
private slots:
    void slotAddUtente();
    void slotModifyProfile();
    void DeleteUtente();
    void setUtenteSelezionato(int riga);
signals:
    void DeleteUtenteSignal(const QString& username);
    void logoutAmministratore();
    void signalAddUtente(const QString& nome, const QString& cognome, const QString& username, const QString& password, const QString& tipo);
    void signalModifyProfile(const QString& nome, const QString& cognome, const QString& password1,
                             const QString& password2, const QDate& datadinascita, const QString& professione,
                             const QString& mail);
};

#endif // AMMINISTRATORE_VIEW_H

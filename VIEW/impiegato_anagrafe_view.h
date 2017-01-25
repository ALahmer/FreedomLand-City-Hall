#ifndef IMPIEGATO_ANAGRAFE_VIEW_H
#define IMPIEGATO_ANAGRAFE_VIEW_H

#include<QGroupBox>
#include<QFrame>
#include<QToolTip>
#include<QIcon>
#include<QMainWindow>
#include<QTableWidget>
#include<QRadioButton>
#include<QHeaderView>
#include<QTableWidgetItem>

#include<MODEL/impiegato_anagrafe_model.h>
#include<VIEW/inserisci_nuovo_cittadino.h>
#include<VIEW/modifica_profilo.h>
#include<VIEW/scheda_utente.h>

class ImpiegatoAnagrafeView : public QWidget {
    Q_OBJECT
private:
    const ModelImpiegatoAnagrafe* model;

    QLabel* benvenuto;

    QTableWidget* tabella;

    QString utenteSelezionato;

    QPushButton* modificaCittadinanza;
    QPushButton* schedaCittadino;
    QPushButton* inserisciUtente;
    QPushButton* profilo;
    QPushButton* logout;
    QPushButton* esci;

    InserisciNuovoCittadino* addNewUser;
    SchedaUtente* infoUtente;
    ModificaProfilo* modifyProfile;

    QVBoxLayout* layout;
public:
    ImpiegatoAnagrafeView(QWidget *parent=0, const ModelImpiegatoAnagrafe* modeL=0);
    ~ImpiegatoAnagrafeView();
    void centraFinestra(int,int);
    void popolaTabella();
    void pulisciTabella();
    void cancellaAddNewUserWindow();
    void cancellaModifyProfileWindow();
    void EnableButtons();
    void DisableButtons();
private slots:
    void SchedaCittadino();
    void slotAddCittadino();
    void slotModifyProfile();
    void DecretaCittadinanzaUtente();
    void setUtenteSelezionato(int riga);
signals:
    void DecretaCittadinanzaUtenteSignal(const QString& username);
    void signalAddCittadino(const QString& nome, const QString& cognome, const QString& username, const QString& password, const QString& tipo);
    void logoutImpiegatoAnagrafe();
    void SignalModificaProfiloCittadino(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita,
                                        const QString& professione,const QString& mail,const QString& comune,const QString& via,
                                        const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita,
                                        const QString& passaporto,const QString& permessodisoggiorno);
    void SignalModificaProfiloUtente(const QString& nome, const QString& cognome, const QString& password1,
                               const QString& password2, const QDate& datadinascita, const QString& professione,
                               const QString& mail);
    void signalModifyProfile(const QString& nome, const QString& cognome, const QString& password1,
                             const QString& password2, const QDate& datadinascita, const QString& professione,
                             const QString& mail);
};

#endif // IMPIEGATO_ANAGRAFE_VIEW_H

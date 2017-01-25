#ifndef IMPIEGATO_BIBLIOTECA_VIEW_H
#define IMPIEGATO_BIBLIOTECA_VIEW_H

#include<QGroupBox>
#include<QFrame>
#include<QToolTip>
#include<QIcon>
#include<QMainWindow>
#include<QTableWidget>
#include<QRadioButton>
#include<QHeaderView>
#include<QTableWidgetItem>

#include<MODEL/impiegato_biblioteca_model.h>
#include<VIEW/inserisci_nuovo_libro.h>
#include<VIEW/modifica_profilo.h>

class ImpiegatoBibliotecaView : public QWidget {
    Q_OBJECT

private:
    const ModelImpiegatoBiblioteca* model;

    QLabel* benvenuto;


    QTableWidget* tabella;
    QTableWidget* tabella_libri;

    QString utenteSelezionato;
    QString libroSelezionato;

    QPushButton* ImprestaLibro;
    QPushButton* RientraLibro;
    QPushButton* rimuoviLibro;
    QPushButton* inserisciLibro;
    QPushButton* profilo;
    QPushButton* logout;
    QPushButton* esci;

    InserisciNuovoLibro* addNewBook;
    ModificaProfilo* modifyProfile;

    QVBoxLayout* layout;
public:
    ImpiegatoBibliotecaView(QWidget *parent=0, const ModelImpiegatoBiblioteca* modeL=0);
    ~ImpiegatoBibliotecaView();
    void centraFinestra(int,int);
    void popolaTabelle();
    void pulisciTabella();
    void cancellaAddNewBookWindow();
    void cancellaModifyProfileWindow();
    void EnableButtons();
    void DisableButtons();
private slots:
    void BorrowLibro();
    void ResumeLibro();
    void DeleteLibro();
    void slotAddLibro();
    void slotModifyProfile();
    void setUtenteSelezionato(int riga);
    void setLibroSelezionato(int riga);
signals:
    void BorrowLibroSignal(const QString& utentePossessore,const QString& ISBN);
    void ResumeLibroSignal(const QString& ISBN);
    void DeleteLibroSignal(const QString& ISBN);
    void signalAddLibro(const QString& ISBN, const QString& titolo, const QString& autore, const QString& casaEd);
    void logoutImpiegatoBiblioteca();
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

#endif // IMPIEGATO_BIBLIOTECA_VIEW_H

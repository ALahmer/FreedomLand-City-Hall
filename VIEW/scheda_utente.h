#ifndef SCHEDA_UTENTE_H
#define SCHEDA_UTENTE_H

#include<QWidget>
#include<QObject>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QComboBox>
#include<QStringList>
#include<QGridLayout>
#include<QDesktopWidget>
#include<QApplication>
#include<QMessageBox>
#include<QCalendarWidget>
#include<QScrollArea>

#include<MODEL/database.h>

class SchedaUtente : public QDialog {
    Q_OBJECT
private:
    Utente* profilo;

    QLabel* titolo1;
    QLabel* titolo2;

    QLabel* nome;
    QLineEdit* nomeEdit;

    QLabel* cognome;
    QLineEdit* cognomeEdit;

    QLabel* password1;
    QLineEdit* password1Edit;

    QLabel* password2;
    QLineEdit* password2Edit;

    QLabel* datanascita;
    QLineEdit* datanascitaEdit;
    QCalendarWidget* calendario;

    QLabel* professione;
    QLineEdit* professioneEdit;

    QLabel* mail;
    QLineEdit* mailEdit;


    QLabel* comune;
    QLineEdit* comuneEdit;
    QLabel* via;
    QLineEdit* viaEdit;
    QLabel* numerocivico;
    QLineEdit* numerocivicoEdit;

    QLabel* cittadinanza;
    QLineEdit* cittadinanzaEdit;

    QLabel* cartadidentita;
    QLineEdit* cartadidentitaEdit;

    QLabel* passaporto;
    QLineEdit* passaportoEdit;

    QLabel* permessodisoggiorno;
    QLineEdit* permessodisoggiornoEdit;

    QPushButton* abilitamodifiche;
    QPushButton* annulla;
    QPushButton* salva;

    QScrollArea* scrollArea;
    QFrame* frame;
    QGridLayout* layout;
    QVBoxLayout* lay;
    QVBoxLayout* vlayout;
    QHBoxLayout* hlay;
public:
    SchedaUtente(QWidget* parent=0, Utente* user = 0);
    ~SchedaUtente();
    void centraFinestra(int windowWidth, int windowHeight);
private slots:
    void UpdatelineEditData();
    void AbilitaModifiche();
    void SlotSalva();
signals:
    void ModificaProfiloCittadino(const QString& username,const QString& nome,const QString& cognome, const QDate& datadinascita,
                                  const QString& professione, const QString& mail,const QString& comune,const QString& via,
                                  const QString& numerocivico,const QString& cittadinanza,const QString& cartadidentita,
                                  const QString& passaporto,const QString& permessodisoggiorno);
};

#endif // SCHEDA_UTENTE_H

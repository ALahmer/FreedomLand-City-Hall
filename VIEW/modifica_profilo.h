#ifndef MODIFICA_PROFILO_H
#define MODIFICA_PROFILO_H

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

#include<MODEL/utente.h>

class ModificaProfilo : public QDialog {
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

    QPushButton* annulla;
    QPushButton* salva;

    QScrollArea* scrollArea;
    QFrame* frame;
    QGridLayout* layout;
    QVBoxLayout* lay;
    QVBoxLayout* vlayout;
    QHBoxLayout* hlay;
public:
    ModificaProfilo(QWidget* parent=0, Utente* user = 0);
    ~ModificaProfilo();
    void centraFinestra(int windowWidth, int windowHeight);
private slots:
    void UpdatelineEditData();
    void SlotSalva();
signals:
    void ModificaProfiloUtente(const QString& nome, const QString& cognome, const QString& password1,
                               const QString& password2, const QDate& datadinascita, const QString& professione,
                               const QString& mail);
};

#endif // MODIFICA_PROFILO_H

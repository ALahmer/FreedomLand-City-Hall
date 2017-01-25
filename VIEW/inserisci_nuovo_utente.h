#ifndef INSERISCI_NUOVO_UTENTE_H
#define INSERISCI_NUOVO_UTENTE_H

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

class InserisciNuovoUtente : public QWidget {
    Q_OBJECT
private:
    QLabel* titolo;

    QLabel* nome;
    QLineEdit* nomeEdit;

    QLabel* cognome;
    QLineEdit* cognomeEdit;

    QLabel* username;
    QLineEdit* usernameEdit;

    QLabel* password;
    QLineEdit* passwordEdit;

    QLabel* tipo;
    QComboBox* tipoComboBox;

    QPushButton* annulla;
    QPushButton* conferma;
    QVBoxLayout* layout;

    QString tipoScelto;
public:
    InserisciNuovoUtente(QWidget* parent=0);
    ~InserisciNuovoUtente();
    void centraFinestra(int windowWidth, int windowHeight);
private slots:
    void InserisciUtente();
    void cambiatoTipo(const QString &tipo);
signals:
    void AddUtente(const QString& nome, const QString& cognome, const QString& username, const QString& password, const QString& tipo);
};

#endif // INSERISCI_NUOVO_UTENTE_H

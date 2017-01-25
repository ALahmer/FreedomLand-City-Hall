#ifndef INSERISCI_NUOVO_LIBRO_H
#define INSERISCI_NUOVO_LIBRO_H

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

class InserisciNuovoLibro : public QWidget {
    Q_OBJECT
private:
    QLabel* titolo;

    QLabel* isbn;
    QLineEdit* isbnEdit;

    QLabel* titoloLib;
    QLineEdit* titoloLibEdit;

    QLabel* autore;
    QLineEdit* autoreEdit;

    QLabel* casaEdit;
    QLineEdit* casaEditEdit;

    QPushButton* annulla;
    QPushButton* conferma;
    QVBoxLayout* layout;

public:
    InserisciNuovoLibro(QWidget* parent=0);
    ~InserisciNuovoLibro();
    void centraFinestra(int windowWidth, int windowHeight);
private slots:
    void InserisciLibro();
signals:
    void AddLibro(const QString& ISBN, const QString& titolo, const QString& autore, const QString& casaEd);
};

#endif // INSERISCI_NUOVO_LIBRO_H

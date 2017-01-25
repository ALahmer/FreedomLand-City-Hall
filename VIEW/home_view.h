#ifndef HOME_VIEW_H
#define HOME_VIEW_H

#include<QGroupBox>
#include<QLabel>
#include<QPushButton>
#include<QVBoxLayout>
#include<QApplication>
#include<QWidget>
#include<QFrame>
#include<QLineEdit>
#include<QToolTip>
#include<QMessageBox>
#include<QIcon>
#include<QMainWindow>
#include<QDesktopWidget>
#include<QObject>
#include<QGraphicsDropShadowEffect>

class HomeView : public QGroupBox {
    Q_OBJECT
private:
    QLabel* benvenuto;
    QLabel* collegati;

    QLabel* username;
    QLineEdit* lineEditUsername;
    QLabel* password;
    QLineEdit* lineEditPassword;

    QPushButton *accediAmm;
    QPushButton *accediImpAnag;
    QPushButton *accediImpBib;
    QPushButton *accediCit;
    QPushButton *accediCitStra;

    QPushButton *esci;

    QVBoxLayout* layout;
public:
    HomeView(QWidget *parent=0);
signals:
    //void creaViewUtente(const QString& username, const QString& password);
    void creaViewUtenteAmm(const QString& username, const QString& password);
    void creaViewUtenteImpAnag(const QString& username, const QString& password);
    void creaViewUtenteImpBib(const QString& username, const QString& password);
    void creaViewUtenteCit(const QString& username, const QString& password);
    void creaViewUtenteCitStra(const QString& username, const QString& password);

    void creaViewAmministratore(const QString& username);
    void creaViewImpiegatoAnagrafe(const QString& username);
    void creaViewImpiegatoBiblioteca(const QString& username);
    void creaViewCittadino(const QString& username);
    void creaViewCittadinoStraniero(const QString& username);
public slots:
    //void getLogin();
    void getLoginAmm();
    void getLoginImpAnag();
    void getLoginImpBib();
    void getLoginCit();
    void getLoginCitStra();

    void pulisciLineEdit();
    void haScritto();
};

#endif // HOME_VIEW_H

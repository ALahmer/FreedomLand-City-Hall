#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<VIEW/startwindow.h>
#include<typeinfo>

class Controller : public QObject {
    Q_OBJECT
private:

    UsersDatabase* databaseUtenti;
    BooksDatabase* databaseLibri;

    StartWindow* finestraIniziale;

    ModelAmministratore* modelAmministratore;
    AmministratoreController* controllerAmministratore;

    ModelImpiegatoAnagrafe* modelImpiegatoAnagrafe;
    ImpiegatoAnagrafeController* controllerImpiegatoAnagrafe;

    ModelImpiegatoBiblioteca* modelImpiegatoBiblioteca;
    ImpiegatoBibliotecaController* controllerImpiegatoBiblioteca;

    ModelCittadino* modelCittadino;
    CittadinoController* controllerCittadino;

    ModelCittadinoStraniero* modelCittadinoStraniero;
    CittadinoStranieroController* controllerCittadinoStraniero;

public:
    Controller(QObject* parent=0, UsersDatabase* ud = 0, BooksDatabase* bd = 0);

public slots:
    //void creaModelUtente(const QString& username, const QString& password);
    void creaModelUtenteAmm(const QString& username, const QString& password);
    void creaModelUtenteImpAnag(const QString& username, const QString& password);
    void creaModelUtenteImpBib(const QString& username, const QString& password);
    void creaModelUtenteCit(const QString& username, const QString& password);
    void creaModelUtenteCitStra(const QString& username, const QString& password);

    void creaModelAmministratore(const QString& username);
    void creaControllerAmministratore();

    void creaModelImpiegatoAnagrafe(const QString& username);
    void creaControllerImpiegatoAnagrafe();

    void creaModelImpiegatoBiblioteca(const QString& username);
    void creaControllerImpiegatoBiblioteca();

    void creaModelCittadino(const QString& username);
    void creaControllerCittadino();

    void creaModelCittadinoStraniero(const QString& username);
    void creaControllerCittadinoStraniero();

    void DeleteModels();
    void DeleteControllers();
};
#endif // CONTROLLER_H

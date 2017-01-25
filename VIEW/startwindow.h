#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include<VIEW/home_view.h>

#include<CONTROLLER/amministratorecontroller.h>
#include<CONTROLLER/impiegatoanagrafecontroller.h>
#include<CONTROLLER/impiegatobibliotecacontroller.h>
#include<CONTROLLER/cittadinocontroller.h>
#include<CONTROLLER/cittadinostranierocontroller.h>

class StartWindow : public QMainWindow {
    Q_OBJECT
private:
    HomeView* home;

    const ModelAmministratore* modelAmministratore;
    AmministratoreView* viewAmministratore;

    const ModelImpiegatoAnagrafe* modelImpiegatoAnagrafe;
    ImpiegatoAnagrafeView* viewImpiegatoAnagrafe;

    const ModelImpiegatoBiblioteca* modelImpiegatoBiblioteca;
    ImpiegatoBibliotecaView* viewImpiegatoBiblioteca;

    const ModelCittadino* modelCittadino;
    CittadinoView* viewCittadino;

    const ModelCittadinoStraniero* modelCittadinoStraniero;
    CittadinoStranieroView* viewCittadinoStraniero;

public:
    StartWindow(QGroupBox* parent=0);
    void centraFinestra(int,int);
    void utenteNonTrovato();
    void setModelAmministratore(const ModelAmministratore* mod);
    void setModelImpiegatoAnagrafe(const ModelImpiegatoAnagrafe* mod);
    void setModelImpiegatoBiblioteca(const ModelImpiegatoBiblioteca* mod);
    void setModelCittadino(const ModelCittadino* mod);
    void setModelCittadinoStraniero(const ModelCittadinoStraniero* mod);
    AmministratoreView* getViewAmministratore();
    ImpiegatoAnagrafeView* getViewImpiegatoAnagrafe();
    ImpiegatoBibliotecaView* getViewImpiegatoBiblioteca();
    CittadinoView* getViewCittadino();
    CittadinoStranieroView* getViewCittadinoStraniero();
public slots:
    void tornaIndietro();
    //void creaUtente(const QString& username, const QString& password);
    void creaUtenteAmm(const QString& username, const QString& password);
    void creaUtenteImpAnag(const QString& username, const QString& password);
    void creaUtenteImpBib(const QString& username, const QString& password);
    void creaUtenteCit(const QString& username, const QString& password);
    void creaUtenteCitStra(const QString& username, const QString& password);

    void creaAmministratore();
    void creaImpiegatoAnagrafe();
    void creaImpiegatoBiblioteca();
    void creaCittadino();
    void creaCittadinoStraniero();
signals:
    //void creaModelUtente(const QString& username, const QString& password);
    void creaModelUtenteAmm(const QString& username, const QString& password);
    void creaModelUtenteImpAnag(const QString& username, const QString& password);
    void creaModelUtenteImpBib(const QString& username, const QString& password);
    void creaModelUtenteCit(const QString& username, const QString& password);
    void creaModelUtenteCitStra(const QString& username, const QString& password);

    void creaControllerAmministratore();
    void creaControllerImpiegatoAnagrafe();
    void creaControllerImpiegatoBiblioteca();
    void creaControllerCittadino();
    void creaControllerCittadinoStraniero();
    void DeleteModels();
    void DeleteControllers();
};

#endif // STARTWINDOW_H

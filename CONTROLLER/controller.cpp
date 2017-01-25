#include<CONTROLLER/controller.h>


Controller::Controller(QObject* parent, UsersDatabase* ud, BooksDatabase* bd) : QObject(parent), databaseUtenti(ud), databaseLibri(bd) {
    if(databaseUtenti->Empty()) databaseUtenti->Add_Amministratore("admin","admin","Amministratore","Sistema");

    //databaseUtenti->Add_Amministratore("mario","mario","Mario","Rossi");
    //databaseUtenti->Add_ImpiegatoAnagrafe("ugo","ugo","Ugo","Neri");
    //databaseUtenti->Add_ImpiegatoBiblioteca("davide","davide","Davide","Marroni");
    //databaseUtenti->Add_Cittadino("silvio","silvio","Silvio","Gialli");
    //databaseUtenti->Add_CittadinoStraniero("mattia","mattia","Mattia","Aranacioni");
    //databaseLibri->Add_Book("321-55-58954-94-3","SWE","Tullio Vardanega","Libreria Progetto");
    //databaseLibri->Add_Book("978-88-33187-3-87","Programmazione 3","Riccardo Cardin","Libreria Progetto");
    //databaseLibri->Add_Book("978-88-87331-94-3","Programmazione 2","Francesco Ranzato","Libreria Progetto");
    //databaseLibri->Add_Book("123-12-12345-1-12","Programmazione 1","Gilberto Filè","Libreria Progetto");

    finestraIniziale = new StartWindow();

    modelAmministratore = 0;
    controllerAmministratore = 0;

    modelImpiegatoAnagrafe = 0;
    controllerImpiegatoAnagrafe = 0;

    modelImpiegatoBiblioteca = 0;
    controllerImpiegatoBiblioteca = 0;

    modelCittadino = 0;
    controllerCittadino = 0;

    modelCittadinoStraniero = 0;
    controllerCittadinoStraniero = 0;

    //connect(finestraIniziale,SIGNAL(creaModelUtente(QString,QString)),this,SLOT(creaModelUtente(QString,QString)));
    connect(finestraIniziale,SIGNAL(creaModelUtenteAmm(QString,QString)),this,SLOT(creaModelUtenteAmm(QString,QString)));
    connect(finestraIniziale,SIGNAL(creaModelUtenteImpAnag(QString,QString)),this,SLOT(creaModelUtenteImpAnag(QString,QString)));
    connect(finestraIniziale,SIGNAL(creaModelUtenteImpBib(QString,QString)),this,SLOT(creaModelUtenteImpBib(QString,QString)));
    connect(finestraIniziale,SIGNAL(creaModelUtenteCit(QString,QString)),this,SLOT(creaModelUtenteCit(QString,QString)));
    connect(finestraIniziale,SIGNAL(creaModelUtenteCitStra(QString,QString)),this,SLOT(creaModelUtenteCitStra(QString,QString)));

    connect(finestraIniziale,SIGNAL(creaControllerAmministratore()),this,SLOT(creaControllerAmministratore()));
    connect(finestraIniziale,SIGNAL(creaControllerImpiegatoAnagrafe()),this,SLOT(creaControllerImpiegatoAnagrafe()));
    connect(finestraIniziale,SIGNAL(creaControllerImpiegatoBiblioteca()),this,SLOT(creaControllerImpiegatoBiblioteca()));
    connect(finestraIniziale,SIGNAL(creaControllerCittadino()),this,SLOT(creaControllerCittadino()));
    connect(finestraIniziale,SIGNAL(creaControllerCittadinoStraniero()),this,SLOT(creaControllerCittadinoStraniero()));
    connect(finestraIniziale,SIGNAL(DeleteModels()),this,SLOT(DeleteModels()));
    connect(finestraIniziale,SIGNAL(DeleteControllers()),this,SLOT(DeleteControllers()));
}

/*void Controller::creaModelUtente(const QString& username, const QString& password) {
    if(databaseUtenti->Login(username,password)) {
        Utente* temp = databaseUtenti->Find_Utente(username);
        temp->CreaModel(username);
    } else finestraIniziale->utenteNonTrovato();
}*/
void Controller::creaModelUtenteAmm(const QString& username, const QString& password) {
    if(databaseUtenti->Login(username,password) && typeid(*databaseUtenti->Find_Utente((username))) == typeid(Amministratore)) {
        creaModelAmministratore(username);
    } else finestraIniziale->utenteNonTrovato();
}
void Controller::creaModelUtenteImpAnag(const QString& username, const QString& password) {
    if(databaseUtenti->Login(username,password) && typeid(*databaseUtenti->Find_Utente((username))) == typeid(ImpiegatoAnagrafe)) {
        creaModelImpiegatoAnagrafe(username);
    } else finestraIniziale->utenteNonTrovato();
}
void Controller::creaModelUtenteImpBib(const QString& username, const QString& password) {
    if(databaseUtenti->Login(username,password) && typeid(*databaseUtenti->Find_Utente((username))) == typeid(ImpiegatoBiblioteca)) {
        creaModelImpiegatoBiblioteca(username);
    } else finestraIniziale->utenteNonTrovato();
}
void Controller::creaModelUtenteCit(const QString& username, const QString& password) {
    if(databaseUtenti->Login(username,password) && typeid(*databaseUtenti->Find_Utente((username))) == typeid(Cittadino)) {
        creaModelCittadino(username);
    } else finestraIniziale->utenteNonTrovato();
}
void Controller::creaModelUtenteCitStra(const QString& username, const QString& password) {
    if(databaseUtenti->Login(username,password) && typeid(*databaseUtenti->Find_Utente((username))) == typeid(CittadinoStraniero)) {
        creaModelCittadinoStraniero(username);
    } else finestraIniziale->utenteNonTrovato();
}

void Controller::creaModelAmministratore(const QString& username) {
    modelAmministratore = new ModelAmministratore(username,databaseUtenti);
    finestraIniziale->setModelAmministratore(modelAmministratore);
    finestraIniziale->creaAmministratore();
}


void Controller::creaControllerAmministratore() {
    controllerAmministratore = new AmministratoreController(this,modelAmministratore,finestraIniziale->getViewAmministratore());
}

void Controller::creaModelImpiegatoAnagrafe(const QString& username) {
    modelImpiegatoAnagrafe = new ModelImpiegatoAnagrafe(username,databaseUtenti);
    finestraIniziale->setModelImpiegatoAnagrafe(modelImpiegatoAnagrafe);
    finestraIniziale->creaImpiegatoAnagrafe();
}


void Controller::creaControllerImpiegatoAnagrafe() {
    controllerImpiegatoAnagrafe = new ImpiegatoAnagrafeController(this,modelImpiegatoAnagrafe,finestraIniziale->getViewImpiegatoAnagrafe());
}

void Controller::creaModelImpiegatoBiblioteca(const QString& username) {
    modelImpiegatoBiblioteca = new ModelImpiegatoBiblioteca(username,databaseUtenti,databaseLibri);
    finestraIniziale->setModelImpiegatoBiblioteca(modelImpiegatoBiblioteca);
    finestraIniziale->creaImpiegatoBiblioteca();
}


void Controller::creaControllerImpiegatoBiblioteca() {
    controllerImpiegatoBiblioteca = new ImpiegatoBibliotecaController(this,modelImpiegatoBiblioteca,finestraIniziale->getViewImpiegatoBiblioteca());
}

void Controller::creaModelCittadino(const QString& username) {
    modelCittadino = new ModelCittadino(username,databaseUtenti);
    finestraIniziale->setModelCittadino(modelCittadino);
    finestraIniziale->creaCittadino();
}

void Controller::creaControllerCittadino() {
    controllerCittadino = new CittadinoController(this,modelCittadino,finestraIniziale->getViewCittadino());
}

void Controller::creaModelCittadinoStraniero(const QString& username) {
    modelCittadinoStraniero = new ModelCittadinoStraniero(username,databaseUtenti);
    finestraIniziale->setModelCittadinoStraniero(modelCittadinoStraniero);
    finestraIniziale->creaCittadinoStraniero();
}


void Controller::creaControllerCittadinoStraniero() {
    controllerCittadinoStraniero = new CittadinoStranieroController(this,modelCittadinoStraniero,finestraIniziale->getViewCittadinoStraniero());
}

void Controller::DeleteModels() {
    delete modelAmministratore;
    delete modelImpiegatoAnagrafe;
    delete modelImpiegatoBiblioteca;
    delete modelCittadino;
    delete modelCittadinoStraniero;

    modelAmministratore = 0;
    modelImpiegatoAnagrafe = 0;
    modelImpiegatoBiblioteca = 0;
    modelCittadino = 0;
    modelCittadinoStraniero = 0;

    finestraIniziale->setModelAmministratore(modelAmministratore);
    finestraIniziale->setModelImpiegatoAnagrafe(modelImpiegatoAnagrafe);
    finestraIniziale->setModelImpiegatoBiblioteca(modelImpiegatoBiblioteca);
    finestraIniziale->setModelCittadino(modelCittadino);
    finestraIniziale->setModelCittadinoStraniero(modelCittadinoStraniero);
}

void Controller::DeleteControllers() {
    delete controllerAmministratore;
    delete controllerImpiegatoAnagrafe;
    delete controllerImpiegatoBiblioteca;
    delete controllerCittadino;
    delete controllerCittadinoStraniero;

    controllerAmministratore = 0;
    controllerImpiegatoAnagrafe = 0;
    controllerImpiegatoBiblioteca = 0;
    controllerCittadino = 0;
    controllerCittadinoStraniero = 0;
}

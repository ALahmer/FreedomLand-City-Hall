#include<VIEW/startwindow.h>

StartWindow::StartWindow(QGroupBox* parent) : QMainWindow(parent),
        modelAmministratore(0) , viewAmministratore(0) , modelImpiegatoAnagrafe(0) ,
        viewImpiegatoAnagrafe(0) , modelImpiegatoBiblioteca(0) , viewImpiegatoBiblioteca(0) ,
        modelCittadino(0) , viewCittadino(0) , modelCittadinoStraniero(0) , viewCittadinoStraniero(0) {

    this->setFixedSize(900,600);

    home = new HomeView(this);

    //connect(home,SIGNAL(creaViewUtente(QString,QString)),this,SLOT(creaUtente(QString,QString)));
    connect(home,SIGNAL(creaViewUtenteAmm(QString,QString)),this,SLOT(creaUtenteAmm(QString,QString)));
    connect(home,SIGNAL(creaViewUtenteImpAnag(QString,QString)),this,SLOT(creaUtenteImpAnag(QString,QString)));
    connect(home,SIGNAL(creaViewUtenteImpBib(QString,QString)),this,SLOT(creaUtenteImpBib(QString,QString)));
    connect(home,SIGNAL(creaViewUtenteCit(QString,QString)),this,SLOT(creaUtenteCit(QString,QString)));
    connect(home,SIGNAL(creaViewUtenteCitStra(QString,QString)),this,SLOT(creaUtenteCitStra(QString,QString)));

    setCentralWidget(home);

    setWhatsThis("Freedom Land City Hall");
    setWindowTitle("Freedom Land City Hall");
    centraFinestra(900,600);
    show();
}

void StartWindow::centraFinestra(int windowWidth, int windowHeight){
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth-windowWidth) / 2;
    y = (screenHeight-windowHeight) / 2;
    this->move(x,y);
}

void StartWindow::utenteNonTrovato() {
    QMessageBox avviso;
    avviso.setText("L'username inserito non è corretto o l'utente non è registrato.");
    avviso.exec();
}

void StartWindow::setModelAmministratore(const ModelAmministratore* mod) {
    modelAmministratore = mod;
}

void StartWindow::setModelImpiegatoAnagrafe(const ModelImpiegatoAnagrafe* mod) {
    modelImpiegatoAnagrafe = mod;
}

void StartWindow::setModelImpiegatoBiblioteca(const ModelImpiegatoBiblioteca* mod) {
    modelImpiegatoBiblioteca = mod;
}

void StartWindow::setModelCittadino(const ModelCittadino* mod) {
    modelCittadino = mod;
}

void StartWindow::setModelCittadinoStraniero(const ModelCittadinoStraniero* mod) {
    modelCittadinoStraniero = mod;
}

AmministratoreView* StartWindow::getViewAmministratore() {
    return viewAmministratore;
}

ImpiegatoAnagrafeView* StartWindow::getViewImpiegatoAnagrafe() {
    return viewImpiegatoAnagrafe;
}

ImpiegatoBibliotecaView* StartWindow::getViewImpiegatoBiblioteca() {
    return viewImpiegatoBiblioteca;
}

CittadinoView* StartWindow::getViewCittadino() {
    return viewCittadino;
}

CittadinoStranieroView* StartWindow::getViewCittadinoStraniero() {
    return viewCittadinoStraniero;
}

/*void StartWindow::creaUtente(const QString& username, const QString& password) {
    emit creaModelUtente(username,password);
}*/
void StartWindow::creaUtenteAmm(const QString& username, const QString& password) {
    emit creaModelUtenteAmm(username,password);
}
void StartWindow::creaUtenteImpAnag(const QString& username, const QString& password) {
    emit creaModelUtenteImpAnag(username,password);
}
void StartWindow::creaUtenteImpBib(const QString& username, const QString& password) {
    emit creaModelUtenteImpBib(username,password);
}
void StartWindow::creaUtenteCit(const QString& username, const QString& password) {
    emit creaModelUtenteCit(username,password);
}
void StartWindow::creaUtenteCitStra(const QString& username, const QString& password) {
    emit creaModelUtenteCitStra(username,password);
}

void StartWindow::tornaIndietro() {
    home = new HomeView(this);

    connect(home,SIGNAL(creaViewUtenteAmm(QString,QString)),this,SLOT(creaUtenteAmm(QString,QString)));
    connect(home,SIGNAL(creaViewUtenteImpAnag(QString,QString)),this,SLOT(creaUtenteImpAnag(QString,QString)));
    connect(home,SIGNAL(creaViewUtenteImpBib(QString,QString)),this,SLOT(creaUtenteImpBib(QString,QString)));
    connect(home,SIGNAL(creaViewUtenteCit(QString,QString)),this,SLOT(creaUtenteCit(QString,QString)));
    connect(home,SIGNAL(creaViewUtenteCitStra(QString,QString)),this,SLOT(creaUtenteCitStra(QString,QString)));

    setCentralWidget(home);
    setFixedSize(900,600);
    centraFinestra(900,600);
    emit DeleteControllers();

    delete viewAmministratore;
    delete viewImpiegatoAnagrafe;
    delete viewImpiegatoBiblioteca;
    delete viewCittadino;
    delete viewCittadinoStraniero;

    viewAmministratore = 0;
    viewImpiegatoAnagrafe = 0;
    viewImpiegatoBiblioteca = 0;
    viewCittadino = 0;
    viewCittadinoStraniero = 0;

    emit DeleteModels();
}

void StartWindow::creaAmministratore(){
    if(modelAmministratore) {
        viewAmministratore = new AmministratoreView(this,modelAmministratore);
        connect(viewAmministratore, SIGNAL(logoutAmministratore()),this,SLOT(tornaIndietro()));
        emit creaControllerAmministratore();
        setCentralWidget(viewAmministratore);
        setFixedSize(1024,600);
        centraFinestra(1024,600);
    }
}

void StartWindow::creaImpiegatoAnagrafe(){
    if(modelImpiegatoAnagrafe) {
        viewImpiegatoAnagrafe = new ImpiegatoAnagrafeView(this,modelImpiegatoAnagrafe);
        connect(viewImpiegatoAnagrafe, SIGNAL(logoutImpiegatoAnagrafe()),this,SLOT(tornaIndietro()));
        emit creaControllerImpiegatoAnagrafe();
        setCentralWidget(viewImpiegatoAnagrafe);
        setFixedSize(1024,600);
        centraFinestra(1024,600);
    }
}

void StartWindow::creaImpiegatoBiblioteca(){
    if(modelImpiegatoBiblioteca) {
        viewImpiegatoBiblioteca = new ImpiegatoBibliotecaView(this,modelImpiegatoBiblioteca);
        connect(viewImpiegatoBiblioteca, SIGNAL(logoutImpiegatoBiblioteca()),this,SLOT(tornaIndietro()));
        emit creaControllerImpiegatoBiblioteca();
        setCentralWidget(viewImpiegatoBiblioteca);
        setFixedSize(1024,600);
        centraFinestra(1024,600);
    }
}

void StartWindow::creaCittadino(){
    if(modelCittadino) {
        viewCittadino = new CittadinoView(this,modelCittadino);
        connect(viewCittadino, SIGNAL(logoutCittadino()),this,SLOT(tornaIndietro()));
        emit creaControllerCittadino();
        setCentralWidget(viewCittadino);
        setFixedSize(900,600);
        centraFinestra(900,600);
    }
}

void StartWindow::creaCittadinoStraniero(){
    if(modelCittadinoStraniero) {
        viewCittadinoStraniero = new CittadinoStranieroView(this,modelCittadinoStraniero);
        connect(viewCittadinoStraniero, SIGNAL(logoutCittadinoStraniero()),this,SLOT(tornaIndietro()));
        emit creaControllerCittadinoStraniero();
        setCentralWidget(viewCittadinoStraniero);
        setFixedSize(900,600);
        centraFinestra(900,600);
    }
}

#include<VIEW/impiegato_anagrafe_view.h>

ImpiegatoAnagrafeView::ImpiegatoAnagrafeView(QWidget *parent, const ModelImpiegatoAnagrafe *modeL) : QWidget(parent), model(modeL) {

    utenteSelezionato="";

    QString nomeEcognome = model->getImpiegatoAnagrafe()->getInfo()->getNome()+" "+model->getImpiegatoAnagrafe()->getInfo()->getCognome();
    benvenuto=new QLabel("Benvenuto "+nomeEcognome,this);
    benvenuto->setStyleSheet("font: 20pt 'Verdana'; color: #000; ");

    tabella=new QTableWidget(this);
    tabella->setColumnCount(5);
    tabella->setRowCount(0);
    QStringList header;
    header<<"Identificativo"<<"Nome"<<"Cognome"<<"Tipo Cittadino"<<"Data di Nascita";
    tabella->setHorizontalHeaderLabels(header);
    tabella->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabella->setSelectionMode(QAbstractItemView::SingleSelection);
    tabella->setSelectionBehavior(QAbstractItemView::SelectRows);
    for(int j=0; j<tabella->columnCount(); j++)
        tabella->horizontalHeader()->setSectionResizeMode(j,QHeaderView::Stretch);
    tabella->setMinimumWidth(420);


    connect(tabella,SIGNAL(cellClicked(int,int)),this,SLOT(setUtenteSelezionato(int)));

    //ConcessioneDecretoDiCittadinanza
    modificaCittadinanza = new QPushButton("Decreto di cittadinanza a favore",this);
    modificaCittadinanza->setFont(QFont("Verdana"));
    QPixmap pixmapcittadinanza("../My Project/IMAGES/cittadinanza.png");
    QIcon ButtonIconCittadinanza(pixmapcittadinanza);
    modificaCittadinanza->setIcon(ButtonIconCittadinanza);
    connect(modificaCittadinanza,SIGNAL(clicked()),this,SLOT(DecretaCittadinanzaUtente()));

    //SchedaCittadino
    schedaCittadino = new QPushButton("Visualizza/Modifica Cittadino ",this);
    schedaCittadino->setFont(QFont("Verdana"));
    QPixmap pixmapschedacittadino("../My Project/IMAGES/modifica.png");
    QIcon ButtonIconSchedaCittadino(pixmapschedacittadino);
    schedaCittadino->setIcon(ButtonIconSchedaCittadino);
    connect(schedaCittadino,SIGNAL(clicked()),this,SLOT(SchedaCittadino()));

    popolaTabella();

    //inserisciUtente
    inserisciUtente = new QPushButton("Inserisci un nuovo cittadino",this);
    inserisciUtente->setFont(QFont("Verdana"));
    QPixmap pixmapadduser("../My Project/IMAGES/plus.png");
    QIcon ButtonIconAddUser(pixmapadduser);
    inserisciUtente->setIcon(ButtonIconAddUser);
    connect(inserisciUtente,SIGNAL(clicked()),this,SLOT(slotAddCittadino()));
    addNewUser = 0;

    //modifica profilo
    profilo = new QPushButton("Modifica il tuo profilo",this);
    profilo->setFont(QFont("Verdana"));
    QPixmap pixmapmodifyprofile("../My Project/IMAGES/modify_profile.png");
    QIcon ButtonIconModitProfile(pixmapmodifyprofile);
    profilo->setIcon(ButtonIconModitProfile);
    connect(profilo,SIGNAL(clicked()),this,SLOT(slotModifyProfile()));
    modifyProfile = 0;

    //logout
    logout = new QPushButton("Logout",this);
    logout->setFont(QFont("Verdana"));
    logout->setToolTip("Ritorna alla schermata iniziale");
    QPixmap pixmaplogout("../My Project/IMAGES/logout.png");
    QIcon ButtonIconLogout(pixmaplogout);
    logout->setIcon(ButtonIconLogout);

    connect(logout,SIGNAL(clicked()),this,SIGNAL(logoutImpiegatoAnagrafe()));

    //esci
    esci=new QPushButton("Esci",this);
    esci->setFont(QFont("Verdana"));
    esci->setToolTip("Chiudi l'applicazione");
    QPixmap pixmapexit("../My Project/IMAGES/exit.png");
    QIcon ButtonIconExit(pixmapexit);
    esci->setIcon(ButtonIconExit);
    connect(esci,SIGNAL(clicked()),qApp,SLOT(quit()));

    QVBoxLayout* Vlayout = new QVBoxLayout();
    Vlayout->addWidget(modificaCittadinanza,Qt::AlignLeft);
    Vlayout->addWidget(schedaCittadino,Qt::AlignLeft);
    Vlayout->addWidget(inserisciUtente,Qt::AlignLeft);
    Vlayout->addWidget(profilo,Qt::AlignLeft);
    Vlayout->addWidget(logout,Qt::AlignLeft);
    Vlayout->addWidget(esci,Qt::AlignLeft);

    QHBoxLayout* Hlayout = new QHBoxLayout();
    Hlayout->addWidget(tabella);
    Hlayout->addLayout(Vlayout);

    layout=new QVBoxLayout(this);
    layout->addWidget(benvenuto);
    layout->addLayout(Hlayout);
    setLayout(layout);
    setFixedSize(1024,600);
    centraFinestra(1024,600);
}

void ImpiegatoAnagrafeView::EnableButtons() {
    modificaCittadinanza->setEnabled(true);
    schedaCittadino->setEnabled(true);
}

void ImpiegatoAnagrafeView::DisableButtons() {
    modificaCittadinanza->setEnabled(false);
    schedaCittadino->setEnabled(false);
}

void ImpiegatoAnagrafeView::setUtenteSelezionato(int riga) {
    utenteSelezionato = tabella->item(riga,0)->text();
    EnableButtons();
}

void ImpiegatoAnagrafeView::SchedaCittadino() {
    infoUtente = new SchedaUtente(0, model->getUser(utenteSelezionato));
    connect(infoUtente,SIGNAL(ModificaProfiloCittadino(QString,QString,QString,QDate,QString,QString,QString,QString,QString,QString,QString,QString,QString)),this,SIGNAL(SignalModificaProfiloCittadino(QString,QString,QString,QDate,QString,QString,QString,QString,QString,QString,QString,QString,QString)));
    infoUtente->centraFinestra(640,680);
    infoUtente->show();
}

void ImpiegatoAnagrafeView::slotAddCittadino() {
    addNewUser = new InserisciNuovoCittadino();
    connect(addNewUser,SIGNAL(AddCittadino(QString,QString,QString,QString,QString)),this,SIGNAL(signalAddCittadino(QString,QString,QString,QString,QString)));
    addNewUser->centraFinestra(400,280);
    addNewUser->show();
}

void ImpiegatoAnagrafeView::slotModifyProfile() {
    popolaTabella();
    modifyProfile = new ModificaProfilo(0,model->getImpiegatoAnagrafe());
    connect(modifyProfile,SIGNAL(ModificaProfiloUtente(QString,QString,QString,QString,QDate,QString,QString)),this,SIGNAL(signalModifyProfile(QString,QString,QString,QString,QDate,QString,QString)));
    modifyProfile->centraFinestra(600,500);
    modifyProfile->show();
}

ImpiegatoAnagrafeView::~ImpiegatoAnagrafeView() {
    delete benvenuto;
    delete tabella;
    delete esci;
    delete layout;
}

void ImpiegatoAnagrafeView::DecretaCittadinanzaUtente() {
    if(utenteSelezionato=="") {
        QMessageBox errore;
        errore.setText("Seleziona il cittadino a cui è stata decretata la cittadinanza");
        errore.exec();
    }
    else {
        QMessageBox avviso;
        avviso.setText("Vuoi decretare la cittadinanza a <i>"+utenteSelezionato+"</i> ?");
        avviso.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        avviso.setDefaultButton(QMessageBox::Yes);
        int choice = avviso.exec();
        if(choice==QMessageBox::Yes)
            emit DecretaCittadinanzaUtenteSignal(utenteSelezionato);
    }
}

void ImpiegatoAnagrafeView::centraFinestra(int windowWidth, int windowHeight) {
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth-windowWidth) / 2;
    y = (screenHeight-windowHeight) / 2;
    this->move(x,y);
}

void ImpiegatoAnagrafeView::pulisciTabella() {
    utenteSelezionato="";
    DisableButtons();
    tabella->clearContents();
    tabella->setRowCount(0);
}

void ImpiegatoAnagrafeView::popolaTabella() {
    pulisciTabella();
    if(!(model->EmptyDB())){
        int i=0;
        for(myContainer<Utente>::myIterator it = model->begin(); it != model->end(); ++it){
            Utente* temp = (*it);
            if(temp->TipoUtente() != "Amministratore" && temp->TipoUtente() != "Impiegato Anagrafe" && temp->TipoUtente() != "Impiegato Biblioteca"){
            tabella->setRowCount(i+1);
            QTableWidgetItem *username = new QTableWidgetItem(temp->getUsername());
            QTableWidgetItem *tipoUser = new QTableWidgetItem(temp->TipoUtente());
            QTableWidgetItem *nome = new QTableWidgetItem(temp->getInfo()->getNome());
            QTableWidgetItem *cognome = new QTableWidgetItem(temp->getInfo()->getCognome());
            QTableWidgetItem *datadinascita = new QTableWidgetItem(temp->getInfo()->getDataNascita().toString());
            tabella->setItem(i,0,username);
            tabella->setItem(i,1,nome);
            tabella->setItem(i,2,cognome);
            tabella->setItem(i,3,tipoUser);
            tabella->setItem(i,4,datadinascita);
            i++;}
            }
    }
}

void ImpiegatoAnagrafeView::cancellaAddNewUserWindow() {
    delete addNewUser;
    addNewUser=0;
}

void ImpiegatoAnagrafeView::cancellaModifyProfileWindow() {
    delete modifyProfile;
    modifyProfile=0;
}

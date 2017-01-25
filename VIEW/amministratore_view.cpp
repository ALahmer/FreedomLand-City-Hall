#include<VIEW/amministratore_view.h>

AmministratoreView::AmministratoreView(QWidget *parent, const ModelAmministratore *modeL) : QWidget(parent), model(modeL) {

    utenteSelezionato="";

    QString nomeEcognome = model->getAdmin()->getInfo()->getNome()+" "+model->getAdmin()->getInfo()->getCognome();
    benvenuto=new QLabel("Benvenuto "+nomeEcognome,this);
    benvenuto->setStyleSheet("font: 20pt 'Verdana'; color: #000; ");

    tabella=new QTableWidget(this);
    tabella->setColumnCount(4);
    tabella->setRowCount(0);
    QStringList header;
    header<<"Username"<<"Nome"<<"Cognome"<<"Tipo Utente";
    tabella->setHorizontalHeaderLabels(header);
    tabella->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabella->setSelectionMode(QAbstractItemView::SingleSelection);
    tabella->setSelectionBehavior(QAbstractItemView::SelectRows);
    for(int j=0; j<tabella->columnCount(); j++)
        tabella->horizontalHeader()->setSectionResizeMode(j,QHeaderView::Stretch);
    tabella->setMinimumWidth(420);

    popolaTabella();

    connect(tabella,SIGNAL(cellClicked(int,int)),this,SLOT(setUtenteSelezionato(int)));

    //eliminaUtente
    rimuovi = new QPushButton("Elimina l'utente selezionato",this);
    rimuovi->setFont(QFont("Verdana"));
    QPixmap pixmapdeleteuser("../My Project/IMAGES/trash.png");
    QIcon ButtonIconDeleteUser(pixmapdeleteuser);
    rimuovi->setIcon(ButtonIconDeleteUser);
    connect(rimuovi,SIGNAL(clicked()),this,SLOT(DeleteUtente()));

    //inserisciUtente
    inserisciUtente = new QPushButton("Inserisci un nuovo utente",this);
    inserisciUtente->setFont(QFont("Verdana"));
    QPixmap pixmapadduser("../My Project/IMAGES/plus.png");
    QIcon ButtonIconAddUser(pixmapadduser);
    inserisciUtente->setIcon(ButtonIconAddUser);
    connect(inserisciUtente,SIGNAL(clicked()),this,SLOT(slotAddUtente()));
    addNewUser = 0;

    //modificaProfilo
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

    connect(logout,SIGNAL(clicked()),this,SIGNAL(logoutAmministratore()));

    //esci
    esci=new QPushButton("Esci",this);
    esci->setFont(QFont("Verdana"));
    esci->setToolTip("Chiudi l'applicazione");
    QPixmap pixmapexit("../My Project/IMAGES/exit.png");
    QIcon ButtonIconExit(pixmapexit);
    esci->setIcon(ButtonIconExit);
    connect(esci,SIGNAL(clicked()),qApp,SLOT(quit()));

    QVBoxLayout* Vlayout = new QVBoxLayout();
    Vlayout->addWidget(rimuovi,Qt::AlignLeft);
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

void AmministratoreView::setUtenteSelezionato(int riga) {
    utenteSelezionato = tabella->item(riga,0)->text();
}

void AmministratoreView::slotAddUtente() {
    addNewUser = new InserisciNuovoUtente();
    connect(addNewUser,SIGNAL(AddUtente(QString,QString,QString,QString,QString)),this,SIGNAL(signalAddUtente(QString,QString,QString,QString,QString)));
    addNewUser->centraFinestra(390,280);
    addNewUser->show();
}

void AmministratoreView::slotModifyProfile() {
    popolaTabella();
    modifyProfile = new ModificaProfilo(0,model->getAdmin());
    connect(modifyProfile,SIGNAL(ModificaProfiloUtente(QString,QString,QString,QString,QDate,QString,QString)),this,SIGNAL(signalModifyProfile(QString,QString,QString,QString,QDate,QString,QString)));
    modifyProfile->centraFinestra(600,500);
    modifyProfile->show();
}

AmministratoreView::~AmministratoreView() {
    delete benvenuto;
    delete tabella;
    delete esci;
    delete layout;
}

void AmministratoreView::DeleteUtente() {
    if(utenteSelezionato=="") {
        QMessageBox errore;
        errore.setText("Seleziona l'utente da eliminare.");
        errore.exec();
    }
    else {
        QMessageBox avviso;
        avviso.setText("Vuoi eliminare l'utente <i>"+utenteSelezionato+"</i> ?");
        avviso.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        avviso.setDefaultButton(QMessageBox::Cancel);
        int choice = avviso.exec();
        if(choice==QMessageBox::Yes)
            emit DeleteUtenteSignal(utenteSelezionato);
    }
}

void AmministratoreView::centraFinestra(int windowWidth, int windowHeight) {
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth-windowWidth) / 2;
    y = (screenHeight-windowHeight) / 2;
    this->move(x,y);
}

void AmministratoreView::pulisciTabella() {
    utenteSelezionato="";
    tabella->clearContents();
    tabella->setRowCount(0);
}

void AmministratoreView::popolaTabella() {
    pulisciTabella();
    if(!(model->EmptyDB())){
        int i=0;
        for(myContainer<Utente>::myIterator it = model->begin(); it != model->end(); ++it){
            tabella->setRowCount(i+1);
            Utente* temp = (*it);
            QTableWidgetItem *username = new QTableWidgetItem(temp->getUsername());
            QTableWidgetItem *tipoUser = new QTableWidgetItem(temp->TipoUtente());
            QTableWidgetItem *nome = new QTableWidgetItem(temp->getInfo()->getNome());
            QTableWidgetItem *cognome = new QTableWidgetItem(temp->getInfo()->getCognome());
            tabella->setItem(i,0,username);
            tabella->setItem(i,1,nome);
            tabella->setItem(i,2,cognome);
            tabella->setItem(i,3,tipoUser);
            i++;
            }
    }
}

void AmministratoreView::cancellaAddNewUserWindow() {
    delete addNewUser;
    addNewUser=0;
}

void AmministratoreView::cancellaModifyProfileWindow() {
    delete modifyProfile;
    modifyProfile=0;
}

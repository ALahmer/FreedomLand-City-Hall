#include<VIEW/impiegato_biblioteca_view.h>

ImpiegatoBibliotecaView::ImpiegatoBibliotecaView(QWidget *parent, const ModelImpiegatoBiblioteca *modeL) : QWidget(parent), model(modeL) {

    utenteSelezionato="";

    libroSelezionato="";

    QString nomeEcognome = model->getImpiegatoBiblioteca()->getInfo()->getNome()+" "+model->getImpiegatoBiblioteca()->getInfo()->getCognome();
    benvenuto=new QLabel("Benvenuto "+nomeEcognome,this);
    benvenuto->setStyleSheet("font: 20pt 'Verdana'; color: #000; ");

    tabella=new QTableWidget(this);
    tabella->setColumnCount(4);
    tabella->setRowCount(0);
    QStringList header;
    header<<"Identificativo"<<"Nome"<<"Cognome"<<"Mail";
    tabella->setHorizontalHeaderLabels(header);
    tabella->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabella->setSelectionMode(QAbstractItemView::SingleSelection);
    tabella->setSelectionBehavior(QAbstractItemView::SelectRows);
    for(int j=0; j<tabella->columnCount(); j++)
        tabella->horizontalHeader()->setSectionResizeMode(j,QHeaderView::Stretch);
    tabella->setMinimumWidth(420);
    connect(tabella,SIGNAL(cellClicked(int,int)),this,SLOT(setUtenteSelezionato(int)));


    tabella_libri = new QTableWidget(this);
    tabella_libri->setColumnCount(5);
    tabella_libri->setRowCount(0);
    QStringList header_libri;
    header_libri<<"ISBN"<<"Titolo"<<"Autore"<<"Casa Editrice"<<"Attualmente da";
    tabella_libri->setHorizontalHeaderLabels(header_libri);
    tabella_libri->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabella_libri->setSelectionMode(QAbstractItemView::SingleSelection);
    tabella_libri->setSelectionBehavior(QAbstractItemView::SelectRows);
    for(int j=0; j<tabella_libri->columnCount(); j++)
        tabella_libri->horizontalHeader()->setSectionResizeMode(j,QHeaderView::Stretch);
    tabella_libri->setMinimumWidth(420);
    connect(tabella_libri,SIGNAL(cellClicked(int,int)),this,SLOT(setLibroSelezionato(int)));

    popolaTabelle();

    //ImprestaLibro
    ImprestaLibro = new QPushButton("Impresta il libro selezionato\n al cittadino selezionato",this);
    ImprestaLibro->setFont(QFont("Verdana"));
    QPixmap pixmapborrowbook("../My Project/IMAGES/impresta_libro_nero.png");
    QIcon ButtonIconBorrowBook(pixmapborrowbook);
    ImprestaLibro->setIcon(ButtonIconBorrowBook);
    connect(ImprestaLibro,SIGNAL(clicked()),this,SLOT(BorrowLibro()));

    //RientraLibro
    RientraLibro = new QPushButton("Rientra il libro selezionato",this);
    RientraLibro->setFont(QFont("Verdana"));
    QPixmap pixmapresumebook("../My Project/IMAGES/rientra_libro_nero.png");
    QIcon ButtonIconResumeBook(pixmapresumebook);
    RientraLibro->setIcon(ButtonIconResumeBook);
    connect(RientraLibro,SIGNAL(clicked()),this,SLOT(ResumeLibro()));

    //eliminaUtente
    rimuoviLibro = new QPushButton("Elimina il libro selezionato",this);
    rimuoviLibro->setFont(QFont("Verdana"));
    QPixmap pixmapdeletebook("../My Project/IMAGES/trash.png");
    QIcon ButtonIconDeleteBook(pixmapdeletebook);
    rimuoviLibro->setIcon(ButtonIconDeleteBook);
    connect(rimuoviLibro,SIGNAL(clicked()),this,SLOT(DeleteLibro()));

    //inserisciLibro
    inserisciLibro = new QPushButton("Inserisci un nuovo libro",this);
    inserisciLibro->setFont(QFont("Verdana"));
    QPixmap pixmapaddbook("../My Project/IMAGES/plus.png");
    QIcon ButtonIconAddBook(pixmapaddbook);
    inserisciLibro->setIcon(ButtonIconAddBook);
    connect(inserisciLibro,SIGNAL(clicked()),this,SLOT(slotAddLibro()));
    addNewBook = 0;

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

    connect(logout,SIGNAL(clicked()),this,SIGNAL(logoutImpiegatoBiblioteca()));

    //esci
    esci=new QPushButton("Esci",this);
    esci->setFont(QFont("Verdana"));
    esci->setToolTip("Chiudi l'applicazione");
    QPixmap pixmapexit("../My Project/IMAGES/exit.png");
    QIcon ButtonIconExit(pixmapexit);
    esci->setIcon(ButtonIconExit);
    connect(esci,SIGNAL(clicked()),qApp,SLOT(quit()));

    QVBoxLayout* Vlayout = new QVBoxLayout();
    Vlayout->addWidget(profilo,Qt::AlignLeft);
    Vlayout->addWidget(ImprestaLibro,Qt::AlignLeft);
    Vlayout->addWidget(RientraLibro,Qt::AlignLeft);
    Vlayout->addWidget(inserisciLibro,Qt::AlignLeft);
    Vlayout->addWidget(rimuoviLibro,Qt::AlignLeft);
    Vlayout->addWidget(logout,Qt::AlignLeft);
    Vlayout->addWidget(esci,Qt::AlignLeft);

    QVBoxLayout* VlayoutSX = new QVBoxLayout();
    VlayoutSX->addWidget(tabella,Qt::AlignRight);
    VlayoutSX->addWidget(tabella_libri,Qt::AlignRight);

    QHBoxLayout* Hlayout = new QHBoxLayout();
    Hlayout->addLayout(VlayoutSX);
    Hlayout->addLayout(Vlayout);

    layout=new QVBoxLayout(this);
    layout->addWidget(benvenuto);
    layout->addLayout(Hlayout);
    setLayout(layout);
    setFixedSize(1024,600);
    centraFinestra(1024,600);
}

void ImpiegatoBibliotecaView::DeleteLibro() {
    if(libroSelezionato=="") {
        QMessageBox errore;
        errore.setText("Seleziona il libro da eliminare.");
        errore.exec();
    }
    else {
        QMessageBox avviso;
        avviso.setText("Vuoi eliminare il libro <i>"+libroSelezionato+"</i> ?");
        avviso.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        avviso.setDefaultButton(QMessageBox::Cancel);
        int choice = avviso.exec();
        if(choice==QMessageBox::Yes)
            emit DeleteLibroSignal(libroSelezionato);
    }
}


void ImpiegatoBibliotecaView::EnableButtons() {
    rimuoviLibro->setEnabled(true);
}

void ImpiegatoBibliotecaView::DisableButtons() {
    rimuoviLibro->setEnabled(false);
}

void ImpiegatoBibliotecaView::setUtenteSelezionato(int riga) {
    utenteSelezionato = tabella->item(riga,0)->text();
}


void ImpiegatoBibliotecaView::setLibroSelezionato(int riga) {
    libroSelezionato = tabella_libri->item(riga,0)->text();
    EnableButtons();
}

void ImpiegatoBibliotecaView::ResumeLibro() {
    if(libroSelezionato=="") {
        QMessageBox errore;
        errore.setText("Seleziona il libro da rientrare.");
        errore.exec();
    } else {
        emit ResumeLibroSignal(libroSelezionato);
    }

}

void ImpiegatoBibliotecaView::BorrowLibro() {
    if(utenteSelezionato=="" || libroSelezionato=="") {
        if(utenteSelezionato==""){
                QMessageBox errore;
                errore.setText("Seleziona l'utente a cui imprestare il libro.");
                errore.exec();
        } else if(libroSelezionato==""){
                QMessageBox errore;
                errore.setText("Seleziona il libro da imprestare.");
                errore.exec();
                }
    }
    else {
        emit BorrowLibroSignal(utenteSelezionato,libroSelezionato);
    }

}

void ImpiegatoBibliotecaView::slotAddLibro() {
    addNewBook = new InserisciNuovoLibro();
    connect(addNewBook,SIGNAL(AddLibro(QString,QString,QString,QString)),this,SIGNAL(signalAddLibro(QString,QString,QString,QString)));
    addNewBook->centraFinestra(400,280);
    addNewBook->show();
}

void ImpiegatoBibliotecaView::slotModifyProfile() {
    popolaTabelle();
    modifyProfile = new ModificaProfilo(0,model->getImpiegatoBiblioteca());
    connect(modifyProfile,SIGNAL(ModificaProfiloUtente(QString,QString,QString,QString,QDate,QString,QString)),this,SIGNAL(signalModifyProfile(QString,QString,QString,QString,QDate,QString,QString)));
    modifyProfile->centraFinestra(600,500);
    modifyProfile->show();
}

ImpiegatoBibliotecaView::~ImpiegatoBibliotecaView() {
    delete benvenuto;
    delete tabella;
    delete esci;
    delete layout;
}

void ImpiegatoBibliotecaView::centraFinestra(int windowWidth, int windowHeight) {
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth-windowWidth) / 2;
    y = (screenHeight-windowHeight) / 2;
    this->move(x,y);
}

void ImpiegatoBibliotecaView::pulisciTabella() {
    libroSelezionato="";
    utenteSelezionato="";
    tabella->clearContents();
    tabella->setRowCount(0);
    tabella_libri->clearContents();
    tabella_libri->setRowCount(0);
}

void ImpiegatoBibliotecaView::popolaTabelle() {
    pulisciTabella();
    if(!(model->EmptyDB())){
        int i=0;
        for(myContainer<Utente>::myIterator it = model->begin(); it != model->end(); ++it){
            Utente* temp = (*it);
            if(temp->TipoUtente() != "Amministratore" && temp->TipoUtente() != "Impiegato Anagrafe" && temp->TipoUtente() != "Impiegato Biblioteca"){
            tabella->setRowCount(i+1);
            QTableWidgetItem *username = new QTableWidgetItem(temp->getUsername());
            QTableWidgetItem *nome = new QTableWidgetItem(temp->getInfo()->getNome());
            QTableWidgetItem *cognome = new QTableWidgetItem(temp->getInfo()->getCognome());
            QTableWidgetItem *mail = new QTableWidgetItem(temp->getInfo()->getMail());
            tabella->setItem(i,0,username);
            tabella->setItem(i,1,nome);
            tabella->setItem(i,2,cognome);
            tabella->setItem(i,3,mail);
            i++;}
            }
    }


    if(!(model->BooksEmptyDB())){
        int i=0;
        for(myContainer<Book>::myIterator it = model->books_begin(); it != model->books_end(); ++it){
            Book* temp = (*it);
            tabella_libri->setRowCount(i+1);
            QTableWidgetItem *ISBN = new QTableWidgetItem(temp->getISBN());
            QTableWidgetItem *titolo = new QTableWidgetItem(temp->getTitolo());
            QTableWidgetItem *autore = new QTableWidgetItem(temp->getAutore());
            QTableWidgetItem *casaEd = new QTableWidgetItem(temp->getCasaEditrice());
            QTableWidgetItem *possessore = new QTableWidgetItem(temp->getPossessoreTemporaneo());
            tabella_libri->setItem(i,0,ISBN);
            tabella_libri->setItem(i,1,titolo);
            tabella_libri->setItem(i,2,autore);
            tabella_libri->setItem(i,3,casaEd);
            tabella_libri->setItem(i,4,possessore);
            i++;
            }
    }
}

void ImpiegatoBibliotecaView::cancellaAddNewBookWindow() {
    delete addNewBook;
    addNewBook=0;
}

void ImpiegatoBibliotecaView::cancellaModifyProfileWindow() {
    delete modifyProfile;
    modifyProfile=0;
}

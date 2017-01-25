#include<VIEW/cittadino_straniero_view.h>

CittadinoStranieroView::CittadinoStranieroView(QWidget *parent, const ModelCittadinoStraniero *modeL) : QWidget(parent), model(modeL) {

    QString nomeEcognome = model->getCittadinoStraniero()->getInfo()->getNome()+" "+model->getCittadinoStraniero()->getInfo()->getCognome();
    benvenuto=new QLabel("Benvenuto "+nomeEcognome,this);
    benvenuto->setStyleSheet("font: 20pt 'Verdana'; color: #000; ");
    benvenuto->setFixedHeight(25);

    frame = new QFrame(this);
    frame->setObjectName("frm");
    frame->setFixedSize(600,700);
    frame->setStyleSheet("#frm{background:white; border: 2px solid black;}");

    nome = new QLabel("<b>Nome:</b> "+model->getCittadinoStraniero()->getInfo()->getNome(),frame);
    nome->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    cognome = new QLabel("<b>Cognome:</b> "+model->getCittadinoStraniero()->getInfo()->getCognome(),frame);
    cognome->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    datadinascita = new QLabel("<b>Data di Nascita:</b> "+model->getCittadinoStraniero()->getInfo()->getDataNascita().toString("d/M/yyyy"),frame);
    datadinascita->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    professione = new QLabel("<b>Professione:</b> "+model->getCittadinoStraniero()->getInfo()->getProfessione(),frame);
    professione->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    mail = new QLabel("<b>Mail:</b> "+model->getCittadinoStraniero()->getInfo()->getMail(),frame);
    mail->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    comune = new QLabel("<b>Comune:</b> "+model->getCittadinoStraniero()->getInfo()->getResidenza()->getComune(),frame);
    comune->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    via = new QLabel("<b>Via:</b> "+model->getCittadinoStraniero()->getInfo()->getResidenza()->getVia(),frame);
    via->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    numerocivico = new QLabel("<b>Numero civico:</b> "+model->getCittadinoStraniero()->getInfo()->getResidenza()->getNumCivico(),frame);
    numerocivico->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    cittadinanza = new QLabel("<b>Cittadinanza:</b> "+model->getCittadinoStraniero()->getCittadinanza(),frame);
    cittadinanza->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    cartadidentita = new QLabel("<b>Carta d'Identita:</b> "+model->getCittadinoStraniero()->getCartaDidentita(),frame);
    cartadidentita->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    passaporto = new QLabel("<b>Passaporto:</b> "+model->getCittadinoStraniero()->getPassaporto(),frame);
    passaporto->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    permessodisoggiorno = new QLabel("<b>Permesso di Soggiorno:</b> "+model->getCittadinoStraniero()->getPermessoDiSoggiorno(),frame);
    permessodisoggiorno->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");

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

    connect(logout,SIGNAL(clicked()),this,SIGNAL(logoutCittadinoStraniero()));

    //esci
    esci=new QPushButton("Esci",this);
    esci->setFont(QFont("Verdana"));
    esci->setToolTip("Chiudi l'applicazione");
    QPixmap pixmapexit("../My Project/IMAGES/exit.png");
    QIcon ButtonIconExit(pixmapexit);
    esci->setIcon(ButtonIconExit);
    connect(esci,SIGNAL(clicked()),qApp,SLOT(quit()));

    QGridLayout* layoutgrid = new QGridLayout(frame);
    layoutgrid->addWidget(nome,0,0);
    layoutgrid->addWidget(cognome,1,0);
    layoutgrid->addWidget(datadinascita,2,0);
    layoutgrid->addWidget(professione,3,0);
    layoutgrid->addWidget(mail,4,0);
    layoutgrid->addWidget(comune,5,0);
    layoutgrid->addWidget(via,6,0);
    layoutgrid->addWidget(numerocivico,7,0);
    layoutgrid->addWidget(cittadinanza,8,0);
    layoutgrid->addWidget(cartadidentita,9,0);
    layoutgrid->addWidget(passaporto,10,0);
    layoutgrid->addWidget(permessodisoggiorno,11,0);

    frame->setLayout(layoutgrid);
    frame->setFixedHeight(450);

    QVBoxLayout* Vlayout = new QVBoxLayout();
    Vlayout->addWidget(profilo,Qt::AlignLeft);
    Vlayout->addWidget(logout,Qt::AlignLeft);
    Vlayout->addWidget(esci,Qt::AlignLeft);

    QHBoxLayout* Hlayout = new QHBoxLayout();
    Hlayout->addWidget(frame);
    Hlayout->addLayout(Vlayout);

    layout=new QVBoxLayout(this);
    layout->addWidget(benvenuto);
    layout->addLayout(Hlayout);
    setLayout(layout);
    setFixedSize(900,600);
    centraFinestra(900,600);
}



void CittadinoStranieroView::slotModifyProfile() {
    modifyProfile = new ModificaProfilo(0,model->getCittadinoStraniero());
    connect(modifyProfile,SIGNAL(ModificaProfiloUtente(QString,QString,QString,QString,QDate,QString,QString)),this,SIGNAL(signalModifyProfile(QString,QString,QString,QString,QDate,QString,QString)));
    modifyProfile->centraFinestra(600,500);
    modifyProfile->show();
}

CittadinoStranieroView::~CittadinoStranieroView() {
    delete benvenuto;
    delete esci;
    delete layout;
}


void CittadinoStranieroView::centraFinestra(int windowWidth, int windowHeight) {
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth-windowWidth) / 2;
    y = (screenHeight-windowHeight) / 2;
    this->move(x,y);
}


void CittadinoStranieroView::cancellaModifyProfileWindow() {
    delete modifyProfile;
    modifyProfile=0;
}


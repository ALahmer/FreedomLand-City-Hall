#include<VIEW/home_view.h>

HomeView::HomeView(QWidget *parent) : QGroupBox(parent) {

    this->setObjectName("hv");
    this->setStyleSheet("HomeView#hv { background-image: url('../My Project/IMAGES/city_try.jpg'); background-repeat: no-repeat; background-attachment: fixed; background-position: top left }");
    this->setFixedSize(900,600);

    QFrame* menu = new QFrame(this);

    esci = new QPushButton("Esci",menu);
    esci->setFont(QFont("Verdana"));
    QPixmap pixmapexit("../My Project/IMAGES/exit.png");
    QIcon ButtonIconExit(pixmapexit);
    esci->setIcon(ButtonIconExit);


    QHBoxLayout* menu_layout = new QHBoxLayout(menu);
    menu_layout->addWidget(esci,0,Qt::AlignRight);
    menu->setLayout(menu_layout);

    benvenuto = new QLabel("Benvenuto in FreedomLand", this);
    benvenuto->setFont(QFont("Verdana",40,QFont::Bold));
    benvenuto->setStyleSheet("color: #800000;");

    collegati = new QLabel("Accedi subito per collegarti a tutti i servizi offerti dal municipio di FreedomLand.", this);
    collegati->setFont(QFont("Verdana",15));
    collegati->setStyleSheet("color: #800000");

    username = new QLabel("Inserisci qui il tuo Username: ", this);
    username->setFont(QFont("Verdana",14,QFont::Bold));
    username->setStyleSheet("color: #800000");

    password = new QLabel("Inserisci qui la tua Password: ", this);
    password->setFont(QFont("Verdana",14,QFont::Bold));
    password->setStyleSheet("color: #800000");

    lineEditUsername = new QLineEdit(this);
    lineEditUsername->setPlaceholderText("Username");
    lineEditUsername->setFixedSize(180,30);
    lineEditUsername->setFont(QFont("Verdana"));

    lineEditPassword = new QLineEdit(this);
    lineEditPassword->setPlaceholderText("Password");
    lineEditPassword->setFixedSize(180,30);
    lineEditPassword->setFont(QFont("Verdana"));
    lineEditPassword->setEchoMode(QLineEdit::Password);

    QPixmap pixmaplogin("../My Project/IMAGES/login.png");
    QIcon ButtonIconLogin(pixmaplogin);

    accediAmm = new QPushButton("Accedi come Amministratore",this);
    accediAmm->setFont(QFont("Verdana"));
    accediAmm->setIcon(ButtonIconLogin);
    connect(accediAmm,SIGNAL(clicked()),this,SLOT(getLoginAmm()));

    accediImpAnag = new QPushButton("Accedi come Impiegato Anagrafe",this);
    accediImpAnag->setFont(QFont("Verdana"));
    accediImpAnag->setIcon(ButtonIconLogin);
    connect(accediImpAnag,SIGNAL(clicked()),this,SLOT(getLoginImpAnag()));

    accediImpBib = new QPushButton("Accedi come Impiegato Biblioteca",this);
    accediImpBib->setFont(QFont("Verdana"));
    accediImpBib->setIcon(ButtonIconLogin);
    connect(accediImpBib,SIGNAL(clicked()),this,SLOT(getLoginImpBib()));

    accediCit = new QPushButton("Accedi come Cittadino",this);
    accediCit->setFont(QFont("Verdana"));
    accediCit->setIcon(ButtonIconLogin);
    connect(accediCit,SIGNAL(clicked()),this,SLOT(getLoginCit()));

    accediCitStra = new QPushButton("Accedi come Cittadino Straniero",this);
    accediCitStra->setFont(QFont("Verdana"));
    accediCitStra->setIcon(ButtonIconLogin);
    connect(accediCitStra,SIGNAL(clicked()),this,SLOT(getLoginCitStra()));

    pulisciLineEdit();

    connect(esci,SIGNAL(clicked()),qApp,SLOT(quit()));
    //connect(lineEditUsername,SIGNAL(returnPressed()),this,SLOT(getLogin()));
    //connect(lineEditPassword,SIGNAL(returnPressed()),this,SLOT(getLogin()));

    layout = new QVBoxLayout(this);

    layout->addSpacing(100);

    layout->addWidget(benvenuto,0,Qt::AlignCenter);
    layout->addWidget(collegati,0,Qt::AlignCenter);

    layout->addSpacing(40);

    layout->addWidget(username,0,Qt::AlignCenter);
    layout->addWidget(lineEditUsername,0,Qt::AlignCenter);
    layout->addWidget(password,0,Qt::AlignCenter);
    layout->addWidget(lineEditPassword,0,Qt::AlignCenter);
    layout->addWidget(accediAmm,0,Qt::AlignCenter);
    layout->addWidget(accediImpAnag,0,Qt::AlignCenter);
    layout->addWidget(accediImpBib,0,Qt::AlignCenter);
    layout->addWidget(accediCit,0,Qt::AlignCenter);
    layout->addWidget(accediCitStra,0,Qt::AlignCenter);

    layout->addSpacing(150);
    layout->addWidget(menu);

    this->setLayout(layout);
}

/*void HomeView::getLogin(){
    if(!lineEditUsername->text().isEmpty() && !lineEditPassword->text().isEmpty()){
        emit creaViewUtente(lineEditUsername->text(), lineEditPassword->text());
        pulisciLineEdit();
    }
    else {
        QMessageBox avviso;
        avviso.setText("Login non valido.");
        pulisciLineEdit();
        avviso.exec();
    }
}*/
void HomeView::getLoginAmm(){
    if(!lineEditUsername->text().isEmpty() && !lineEditPassword->text().isEmpty()){
        emit creaViewUtenteAmm(lineEditUsername->text(), lineEditPassword->text());
        pulisciLineEdit();
    }
    else {
        QMessageBox avviso;
        avviso.setText("Login non valido.");
        pulisciLineEdit();
        avviso.exec();
    }
}
void HomeView::getLoginImpAnag(){
    if(!lineEditUsername->text().isEmpty() && !lineEditPassword->text().isEmpty()){
        emit creaViewUtenteImpAnag(lineEditUsername->text(), lineEditPassword->text());
        pulisciLineEdit();
    }
    else {
        QMessageBox avviso;
        avviso.setText("Login non valido.");
        pulisciLineEdit();
        avviso.exec();
    }
}
void HomeView::getLoginImpBib(){
    if(!lineEditUsername->text().isEmpty() && !lineEditPassword->text().isEmpty()){
        emit creaViewUtenteImpBib(lineEditUsername->text(), lineEditPassword->text());
        pulisciLineEdit();
    }
    else {
        QMessageBox avviso;
        avviso.setText("Login non valido.");
        pulisciLineEdit();
        avviso.exec();
    }
}
void HomeView::getLoginCit(){
    if(!lineEditUsername->text().isEmpty() && !lineEditPassword->text().isEmpty()){
        emit creaViewUtenteCit(lineEditUsername->text(), lineEditPassword->text());
        pulisciLineEdit();
    }
    else {
        QMessageBox avviso;
        avviso.setText("Login non valido.");
        pulisciLineEdit();
        avviso.exec();
    }
}
void HomeView::getLoginCitStra(){
    if(!lineEditUsername->text().isEmpty() && !lineEditPassword->text().isEmpty()){
        emit creaViewUtenteCitStra(lineEditUsername->text(), lineEditPassword->text());
        pulisciLineEdit();
    }
    else {
        QMessageBox avviso;
        avviso.setText("Login non valido.");
        pulisciLineEdit();
        avviso.exec();
    }
}


void HomeView::haScritto(){
    accediAmm->setEnabled(true);
    accediImpAnag->setEnabled(true);
    accediImpBib->setEnabled(true);
    accediCit->setEnabled(true);
    accediCitStra->setEnabled(true);
    disconnect(lineEditUsername,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(haScritto()));
}

void HomeView::pulisciLineEdit(){
    accediAmm->setDisabled(true);
    accediImpAnag->setDisabled(true);
    accediImpBib->setDisabled(true);
    accediCit->setDisabled(true);
    accediCitStra->setDisabled(true);
    lineEditUsername->clear();
    lineEditPassword->clear();
    connect(lineEditUsername,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(haScritto()));
    connect(lineEditPassword,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(haScritto()));
}

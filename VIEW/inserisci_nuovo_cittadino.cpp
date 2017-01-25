#include<VIEW/inserisci_nuovo_cittadino.h>

InserisciNuovoCittadino::InserisciNuovoCittadino(QWidget* parent) : QWidget(parent), tipoScelto("Cittadino") {
    setFixedSize(400,280);
    titolo=new QLabel("Inserisci un nuovo cittadino",this);
    titolo->setStyleSheet("font: 20pt 'Verdana'; color: #000; ");

    nome=new QLabel("Nome:",this);
    nome->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    nomeEdit=new QLineEdit(this);
    nomeEdit->setPlaceholderText("Inserisci nome");
    nomeEdit->setFixedSize(180,22);
    nomeEdit->setFont(QFont("Verdana"));

    cognome=new QLabel("Cognome:",this);
    cognome->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    cognomeEdit=new QLineEdit(this);
    cognomeEdit->setPlaceholderText("Inserisci cognome");
    cognomeEdit->setFixedSize(180,22);
    cognomeEdit->setFont(QFont("Verdana"));

    username=new QLabel("Username:",this);
    username->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    usernameEdit=new QLineEdit(this);
    usernameEdit->setPlaceholderText("Inserisci l'username con cui il cittadino potrà accedere al sistema");
    usernameEdit->setFixedSize(180,22);
    usernameEdit->setFont(QFont("Verdana"));

    password=new QLabel("Password:",this);
    password->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    passwordEdit=new QLineEdit(this);
    passwordEdit->setPlaceholderText("Inserisci la password con cui il cittadino potrà accedere al sistema");
    passwordEdit->setFixedSize(180,22);
    passwordEdit->setFont(QFont("Verdana"));
    passwordEdit->setEchoMode(QLineEdit::Password);

    tipo=new QLabel("Tipo Account:",this);
    tipo->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    tipoComboBox=new QComboBox(this);
    QStringList tipi;
    tipi<<"Cittadino"<<"Cittadino Straniero";
    tipoComboBox->addItems(tipi);
    connect(tipoComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(cambiatoTipo(QString)));

    annulla=new QPushButton("Annulla",this);
    annulla->setFont(QFont("Verdana"));
    connect(annulla,SIGNAL(clicked()),this,SLOT(close()));

    conferma=new QPushButton("Conferma",this);
    conferma->setFont(QFont("Verdana"));
    connect(conferma,SIGNAL(clicked()),this,SLOT(InserisciCittadino()));

    QGridLayout* grid = new QGridLayout();
    grid->addWidget(nome,0,0);
    grid->addWidget(nomeEdit,0,1);
    grid->addWidget(cognome,1,0);
    grid->addWidget(cognomeEdit,1,1);
    grid->addWidget(username,2,0);
    grid->addWidget(usernameEdit,2,1);
    grid->addWidget(password,3,0);
    grid->addWidget(passwordEdit,3,1);
    grid->addWidget(tipo,4,0);
    grid->addWidget(tipoComboBox,4,1);

    QHBoxLayout* hlayout=new QHBoxLayout();
    hlayout->addWidget(annulla);
    hlayout->addWidget(conferma);

    layout=new QVBoxLayout(this);
    layout->addWidget(titolo);
    layout->addSpacing(20);
    layout->addLayout(grid);
    layout->addSpacing(10);
    layout->addLayout(hlayout);
    setLayout(layout);
}

void InserisciNuovoCittadino::cambiatoTipo(const QString& tipo) {
   if(tipo == "Cittadino")
        tipoScelto ="Cittadino";
    else if(tipo == "Cittadino Straniero")
        tipoScelto = "Cittadino Straniero";
}

void InserisciNuovoCittadino::centraFinestra(int windowWidth, int windowHeight) {
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth-windowWidth) / 2;
    y = (screenHeight-windowHeight) / 2;
    this->move(x,y);
}

void InserisciNuovoCittadino::InserisciCittadino() {
    if (nomeEdit->text().isEmpty() || cognomeEdit->text().isEmpty() || usernameEdit->text().isEmpty() || passwordEdit->text().isEmpty()) {
        QMessageBox errore;
        errore.setText("Sono richiesti tutti i campi.");
        errore.exec();
    }
    else {
        QMessageBox avviso;
        avviso.setText("Vuoi inserire il cittadino <i>"+usernameEdit->text()+"</i> ?");
        avviso.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        avviso.setDefaultButton(QMessageBox::Yes);
        int choice = avviso.exec();
        if(choice==QMessageBox::Yes)
            emit AddCittadino(nomeEdit->text(),cognomeEdit->text(),usernameEdit->text(),passwordEdit->text(),tipoScelto);
    }
}


InserisciNuovoCittadino::~InserisciNuovoCittadino() {
    delete titolo;
    delete username;
    delete usernameEdit;
    delete nome;
    delete nomeEdit;
    delete cognome;
    delete cognomeEdit;
    delete tipo;
    delete tipoComboBox;
    delete annulla;
    delete conferma;
    delete layout;
}

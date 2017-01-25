#include<VIEW/modifica_profilo.h>

ModificaProfilo::ModificaProfilo(QWidget* parent, Utente* user) : QDialog(parent), profilo(user) {

    setModal(true);
    setWindowTitle("Modifica il tuo profilo");
    setFixedSize(600,500);

    scrollArea=new QScrollArea(this);
    scrollArea->setObjectName("scrollArea");
    scrollArea->setStyleSheet("#scrollArea{background-color: white;}");

    frame=new QFrame(scrollArea);
    frame->setObjectName("frm");
    frame->setStyleSheet("#frm{background:transparent;}");

    nome = new QLabel("Nome:",frame);
    nome->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    nomeEdit = new QLineEdit(frame);
    nomeEdit->setText(profilo->getInfo()->getNome());
    nomeEdit->setFixedSize(375,30);
    nomeEdit->setFont(QFont("Verdana"));

    cognome = new QLabel("Cognome:",frame);
    cognome->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    cognomeEdit = new QLineEdit(frame);
    cognomeEdit->setText(profilo->getInfo()->getCognome());
    cognomeEdit->setFixedSize(375,30);
    cognomeEdit->setFont(QFont("Verdana"));

    password1 = new QLabel("Password:",frame);
    password1Edit = new QLineEdit(frame);
    password1Edit->setToolTip("Lasciare questo campo vuoto se non si vuole cambiare la password");
    password1Edit->setFixedSize(375,30);
    password1Edit->setEchoMode(QLineEdit::Password);

    password2 = new QLabel("Ripeti la Password:",frame);
    password2Edit = new QLineEdit(frame);
    password2Edit->setFixedSize(375,30);
    password2Edit->setEchoMode(QLineEdit::Password);

    datanascita = new QLabel("Data di nascita:",frame);
    datanascita->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");

    datanascitaEdit=new QLineEdit(frame);

    datanascitaEdit->setReadOnly(true);
    datanascitaEdit->setFixedSize(375,30);
    datanascitaEdit->setFont(QFont("Verdana"));

    calendario = new QCalendarWidget(frame);
    calendario->setSelectedDate(profilo->getInfo()->getDataNascita());
    UpdatelineEditData();
    connect(calendario,SIGNAL(clicked(QDate)),this,SLOT(UpdatelineEditData()));
    connect(calendario,SIGNAL(selectionChanged()),this,SLOT(UpdatelineEditData()));

    professione = new QLabel("Professione:",frame);
    professione->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    professioneEdit = new QLineEdit(frame);
    if(profilo->getInfo()->getProfessione() == "Nessuna informazione.") professioneEdit->setPlaceholderText("Nessuna informazione.");
    else professioneEdit->setText(profilo->getInfo()->getProfessione());
    professioneEdit->setFixedSize(375,30);
    professioneEdit->setFont(QFont("Verdana"));

    mail = new QLabel("Mail:",frame);
    mail->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    mailEdit = new QLineEdit(frame);
    if(profilo->getInfo()->getMail() == "Nessuna informazione.") mailEdit->setPlaceholderText("Nessuna informazione.");
    else mailEdit->setText(profilo->getInfo()->getMail());
    mailEdit->setFixedSize(375,30);
    mailEdit->setFont(QFont("Verdana"));

    annulla=new QPushButton("Annulla",this);
    annulla->setFont(QFont("Verdana"));
    annulla->setToolTip("Chiudi questa finestra senza modificare il proprio profilo");
    annulla->setDefault(true);
    connect(annulla,SIGNAL(clicked()),this,SLOT(close()));

    salva=new QPushButton("Salva",this);
    salva->setFont(QFont("Verdana"));
    salva->setToolTip("Salva tutte le modifiche sul tuo profilo");
    connect(salva,SIGNAL(clicked()),this,SLOT(SlotSalva()));

    layout=new QGridLayout();
    layout->setColumnMinimumWidth(0,20);
    layout->setColumnMinimumWidth(3,20);

    layout->addWidget(nome,2,1);
    layout->addWidget(nomeEdit,2,2);

    layout->addWidget(cognome,3,1);
    layout->addWidget(cognomeEdit,3,2);

    layout->addWidget(password1,4,1);
    layout->addWidget(password1Edit,4,2);

    layout->addWidget(password2,5,1);
    layout->addWidget(password2Edit,5,2);

    layout->addWidget(datanascita,6,1);
    layout->addWidget(datanascitaEdit,6,2);
    layout->addWidget(calendario,7,1,7,2);

    layout->addWidget(professione,16,1);
    layout->addWidget(professioneEdit,16,2);

    layout->addWidget(mail,17,1);
    layout->addWidget(mailEdit,17,2);

    vlayout=new QVBoxLayout(frame);
    vlayout->addLayout(layout);
    frame->setLayout(vlayout);
    scrollArea->setWidget(frame);

    hlay = new QHBoxLayout();
    hlay->addWidget(annulla,0,Qt::AlignRight);
    hlay->addWidget(salva,0,Qt::AlignLeft);

    lay=new QVBoxLayout(this);
    lay->addWidget(scrollArea);
    lay->addLayout(hlay);
    setLayout(lay);
}

void ModificaProfilo::UpdatelineEditData() {
    datanascitaEdit->setText(calendario->selectedDate().toString("d-M-yyyy"));
}

void ModificaProfilo::SlotSalva() {
    if (nomeEdit->text().isEmpty() || cognomeEdit->text().isEmpty() || professioneEdit->text().isEmpty() || mailEdit->text().isEmpty()) {
        QMessageBox errore;
        errore.setText("I campi <i>Nome</i>, <i>Cognome</i>, <i>Professione</i> e <i>Mail</i> devono essere riempiti.");
        errore.exec();
    }
    else {
        if(!password1Edit->text().isEmpty() || !password2Edit->text().isEmpty()) {
            if(password1Edit->text() != password2Edit->text()){
                QMessageBox errorePass;
                errorePass.setText("Le password devono coincidere.");
                errorePass.exec();
                } else {
                    QMessageBox avviso;
                    avviso.setText("Vuoi salvare le modifiche al tuo profilo?");
                    avviso.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
                    avviso.setDefaultButton(QMessageBox::Yes);
                    int choice = avviso.exec();
                    if(choice==QMessageBox::Yes) {
                        emit ModificaProfiloUtente(nomeEdit->text(),cognomeEdit->text(),password1Edit->text(),password2Edit->text(),
                                                   calendario->selectedDate(),professioneEdit->text(),mailEdit->text());
                        close();
                        }
                    }
        } else {
            QMessageBox avviso;
            avviso.setText("Vuoi salvare le modifiche al tuo profilo?");
            avviso.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
            avviso.setDefaultButton(QMessageBox::Yes);
            int choice = avviso.exec();
            if(choice==QMessageBox::Yes) {
                emit ModificaProfiloUtente(nomeEdit->text(),cognomeEdit->text(),password1Edit->text(),password2Edit->text(),
                                           calendario->selectedDate(),professioneEdit->text(),mailEdit->text());
                close();
                }
            }
    }
}

void ModificaProfilo::centraFinestra(int windowWidth, int windowHeight) {
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth-windowWidth) / 2;
    y = (screenHeight-windowHeight) / 2;
    this->move(x,y);
}

ModificaProfilo::~ModificaProfilo() {
    profilo = 0;

    delete nome;
    delete nomeEdit;
    delete cognome;
    delete cognomeEdit;

    delete datanascita;
    delete datanascitaEdit;
    delete calendario;

    delete professione;
    delete professioneEdit;
    delete mail;
    delete mailEdit;

    delete annulla;
    delete salva;

    delete layout;
    delete vlayout;
    delete hlay;
    delete lay;
    delete scrollArea;
}

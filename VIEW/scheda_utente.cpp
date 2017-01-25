#include<VIEW/scheda_utente.h>

SchedaUtente::SchedaUtente(QWidget* parent, Utente* user) : QDialog(parent), profilo(user) {

    setModal(true);
    setWindowTitle("Scheda Cittadino");
    setFixedSize(640,680);

    scrollArea=new QScrollArea(this);
    scrollArea->setObjectName("scrollArea");
    scrollArea->setStyleSheet("#scrollArea{background-color: white;}");

    frame=new QFrame(scrollArea);
    frame->setObjectName("frm");
    frame->setStyleSheet("#frm{background:transparent;}");

    nome = new QLabel("Nome:",frame);
    nome->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    nomeEdit = new QLineEdit(frame);
    nomeEdit->setPlaceholderText(profilo->getInfo()->getNome());
    nomeEdit->setFixedSize(375,30);
    nomeEdit->setFont(QFont("Verdana"));

    cognome = new QLabel("Cognome:",frame);
    cognome->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    cognomeEdit = new QLineEdit(frame);
    cognomeEdit->setPlaceholderText(profilo->getInfo()->getCognome());
    cognomeEdit->setFixedSize(375,30);
    cognomeEdit->setFont(QFont("Verdana"));

    datanascita = new QLabel("Data di nascita:",frame);
    datanascita->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    datanascitaEdit=new QLineEdit(frame);
    datanascitaEdit->setReadOnly(true);
    datanascitaEdit->setFixedSize(375,30);
    datanascitaEdit->setFont(QFont("Verdana"));
    calendario = new QCalendarWidget(frame);
    calendario->setSelectedDate(profilo->getInfo()->getDataNascita());
    UpdatelineEditData();
    calendario->setDisabled(true);
    connect(calendario,SIGNAL(clicked(QDate)),this,SLOT(UpdatelineEditData()));
    connect(calendario,SIGNAL(selectionChanged()),this,SLOT(UpdatelineEditData()));

    mail = new QLabel("Mail:",frame);
    mail->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    mailEdit = new QLineEdit(frame);
    mailEdit->setPlaceholderText(profilo->getInfo()->getMail());
    mailEdit->setFixedSize(375,30);
    mailEdit->setFont(QFont("Verdana"));

    professione = new QLabel("Professione:",frame);
    professione->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    professioneEdit = new QLineEdit(frame);
    professioneEdit->setPlaceholderText(profilo->getInfo()->getProfessione());
    professioneEdit->setFixedSize(375,30);
    professioneEdit->setFont(QFont("Verdana"));

    comune = new QLabel("Comune:",frame);
    comune->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    comuneEdit = new QLineEdit(frame);
    comuneEdit->setPlaceholderText(profilo->getInfo()->getResidenza()->getComune());
    comuneEdit->setFixedSize(375,30);
    comuneEdit->setFont(QFont("Verdana"));

    via = new QLabel("Via:",frame);
    via->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    viaEdit = new QLineEdit(frame);
    viaEdit->setPlaceholderText(profilo->getInfo()->getResidenza()->getVia());
    viaEdit->setFixedSize(375,30);
    viaEdit->setFont(QFont("Verdana"));

    numerocivico = new QLabel("Numero civico:",frame);
    numerocivico->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    numerocivicoEdit = new QLineEdit(frame);
    numerocivicoEdit->setPlaceholderText(profilo->getInfo()->getResidenza()->getNumCivico());
    numerocivicoEdit->setFixedSize(375,30);
    numerocivicoEdit->setFont(QFont("Verdana"));

    cittadinanza = new QLabel("Cittadinanza:",frame);
    cittadinanza->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    cittadinanzaEdit = new QLineEdit(frame);
    cittadinanzaEdit->setPlaceholderText(profilo->getCittadinanza());
    cittadinanzaEdit->setFixedSize(375,30);
    cittadinanzaEdit->setFont(QFont("Verdana"));

    cartadidentita = new QLabel("Carta d'Identità:",frame);
    cartadidentita->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    cartadidentitaEdit = new QLineEdit(frame);
    cartadidentitaEdit->setPlaceholderText(profilo->getCartaDidentita());
    cartadidentitaEdit->setFixedSize(375,30);
    cartadidentitaEdit->setFont(QFont("Verdana"));

    passaporto = new QLabel("Passaporto:",frame);
    passaporto->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    passaportoEdit = new QLineEdit(frame);
    passaportoEdit->setPlaceholderText(profilo->getPassaporto());
    passaportoEdit->setFixedSize(375,30);
    passaportoEdit->setFont(QFont("Verdana"));

    permessodisoggiorno = new QLabel("Permesso di soggiorno:",frame);
    permessodisoggiorno->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    permessodisoggiornoEdit = new QLineEdit(frame);
    if(profilo->getPermessoDiSoggiorno() == "Nessuna informazione." || profilo->getPermessoDiSoggiorno() == ""){
        permessodisoggiornoEdit->setPlaceholderText("Nessuna informazione.");
    }
    else if(profilo->getPermessoDiSoggiorno() == "Cittadino con Cittadinanza"){
                permessodisoggiornoEdit->setPlaceholderText("Cittadino con Cittadinanza");
                permessodisoggiornoEdit->setReadOnly(true);
        } else permessodisoggiornoEdit->setPlaceholderText(profilo->getPermessoDiSoggiorno());
    permessodisoggiornoEdit->setFixedSize(375,30);
    permessodisoggiornoEdit->setFont(QFont("Verdana"));

    abilitamodifiche = new QPushButton("Modifica",this);
    abilitamodifiche->setFont(QFont("Verdana"));
    abilitamodifiche->setToolTip("Premi per abilitare la modifica nei campi sovrastanti");
    abilitamodifiche->setDefault(true);
    connect(abilitamodifiche,SIGNAL(clicked()),this,SLOT(AbilitaModifiche()));

    annulla=new QPushButton("Annulla",this);
    annulla->setFont(QFont("Verdana"));
    annulla->setToolTip("Chiudi questa finestra senza modificare il proprio profilo");
    annulla->setDefault(true);
    connect(annulla,SIGNAL(clicked()),this,SLOT(close()));

    salva=new QPushButton("Salva",this);
    salva->setFont(QFont("Verdana"));
    salva->setToolTip("Aggiorna i dati del cittadino");
    connect(salva,SIGNAL(clicked()),this,SLOT(SlotSalva()));

    layout=new QGridLayout();
    layout->setColumnMinimumWidth(0,20);
    layout->setColumnMinimumWidth(3,20);

    layout->addWidget(nome,2,1);
    layout->addWidget(nomeEdit,2,2);

    layout->addWidget(cognome,3,1);
    layout->addWidget(cognomeEdit,3,2);

    layout->addWidget(datanascita,4,1);
    layout->addWidget(datanascitaEdit,4,2);
    layout->addWidget(calendario,5,1,5,2);

    layout->addWidget(professione,14,1);
    layout->addWidget(professioneEdit,14,2);

    layout->addWidget(mail,15,1);
    layout->addWidget(mailEdit,15,2);

    layout->addWidget(comune,16,1);
    layout->addWidget(comuneEdit,16,2);
    layout->addWidget(via,17,1);
    layout->addWidget(viaEdit,17,2);
    layout->addWidget(numerocivico,18,1);
    layout->addWidget(numerocivicoEdit,18,2);

    layout->addWidget(cittadinanza,19,1);
    layout->addWidget(cittadinanzaEdit,19,2);

    layout->addWidget(cartadidentita,20,1);
    layout->addWidget(cartadidentitaEdit,20,2);

    layout->addWidget(passaporto,21,1);
    layout->addWidget(passaportoEdit,21,2);

    layout->addWidget(permessodisoggiorno,22,1);
    layout->addWidget(permessodisoggiornoEdit,22,2);

    vlayout=new QVBoxLayout(frame);
    vlayout->addLayout(layout);
    frame->setLayout(vlayout);
    scrollArea->setWidget(frame);

    hlay = new QHBoxLayout();
    hlay->addWidget(abilitamodifiche,0,Qt::AlignRight);
    hlay->addWidget(annulla,0,Qt::AlignCenter);
    hlay->addWidget(salva,0,Qt::AlignLeft);

    lay=new QVBoxLayout(this);
    lay->addWidget(scrollArea);
    lay->addLayout(hlay);
    setLayout(lay);
}

void SchedaUtente::UpdatelineEditData() {
    datanascitaEdit->setPlaceholderText(calendario->selectedDate().toString("d-M-yyyy"));
}

void SchedaUtente::AbilitaModifiche() {
    nomeEdit->setText(profilo->getInfo()->getNome());
    cognomeEdit->setText(profilo->getInfo()->getCognome());
    calendario->setDisabled(false);
    professioneEdit->setText(profilo->getInfo()->getProfessione());
    mailEdit->setText(profilo->getInfo()->getMail());
    comuneEdit->setText(profilo->getInfo()->getResidenza()->getComune());
    viaEdit->setText(profilo->getInfo()->getResidenza()->getVia());
    numerocivicoEdit->setText(profilo->getInfo()->getResidenza()->getNumCivico());
    cittadinanzaEdit->setText(profilo->getCittadinanza());
    cartadidentitaEdit->setText(profilo->getCartaDidentita());
    passaportoEdit->setText(profilo->getPassaporto());
    if(profilo->getPermessoDiSoggiorno() == "Nessuna informazione." || profilo->getPermessoDiSoggiorno() == "") permessodisoggiornoEdit->setText("Nessuna informazione.");
    else if(profilo->getPermessoDiSoggiorno() == "Cittadino con Cittadinanza") permessodisoggiornoEdit->setText("Cittadino con Cittadinanza");
    else permessodisoggiornoEdit->setText(profilo->getPermessoDiSoggiorno());
}

void SchedaUtente::SlotSalva() {
    if (nomeEdit->text().isEmpty() || cognomeEdit->text().isEmpty() || professioneEdit->text().isEmpty()
            || comuneEdit->text().isEmpty() || viaEdit->text().isEmpty() || numerocivico->text().isEmpty()
            || cittadinanzaEdit->text().isEmpty() || passaportoEdit->text().isEmpty()) {
        QMessageBox errore;
        errore.setText("Tutti i campi devono essere riempiti.");
        errore.exec();
    }
    else {
            QMessageBox avviso;
            avviso.setText("Vuoi salvare definitivamente le modifiche?");
            avviso.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
            avviso.setDefaultButton(QMessageBox::Cancel);
            int choice = avviso.exec();
            if(choice==QMessageBox::Yes) {
                emit ModificaProfiloCittadino(profilo->getUsername(),nomeEdit->text(),cognomeEdit->text(),calendario->selectedDate(),
                                              professioneEdit->text(), mailEdit->text() ,comuneEdit->text(),viaEdit->text(),
                                              numerocivicoEdit->text(),cittadinanzaEdit->text(),cartadidentitaEdit->text(),
                                              passaportoEdit->text(),permessodisoggiornoEdit->text());
                close();
                }
    }
}


void SchedaUtente::centraFinestra(int windowWidth, int windowHeight) {
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth-windowWidth) / 2;
    y = (screenHeight-windowHeight) / 2;
    this->move(x,y);
}


SchedaUtente::~SchedaUtente() {
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

    delete annulla;
    delete salva;

    delete layout;
    delete vlayout;
    delete hlay;
    delete lay;
    delete scrollArea;
}

#include<VIEW/inserisci_nuovo_libro.h>

InserisciNuovoLibro::InserisciNuovoLibro(QWidget* parent) : QWidget(parent){

    setFixedSize(390,280);

    titolo=new QLabel("Inserisci un nuovo libro",this);
    titolo->setStyleSheet("font: 20pt 'Verdana'; color: #000; ");

    isbn=new QLabel("ISBN:",this);
    isbn->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    isbnEdit=new QLineEdit(this);
    isbnEdit->setPlaceholderText("Inserisci l'ISBN");
    isbn->setFixedSize(180,22);
    isbn->setFont(QFont("Verdana"));

    titoloLib=new QLabel("Titolo:",this);
    titoloLib->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    titoloLibEdit=new QLineEdit(this);
    titoloLibEdit->setPlaceholderText("Inserisci il titolo");
    titoloLibEdit->setFixedSize(180,22);
    titoloLibEdit->setFont(QFont("Verdana"));

    autore=new QLabel("Autore:",this);
    autore->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    autoreEdit=new QLineEdit(this);
    autoreEdit->setPlaceholderText("Inserisci l'autore");
    autoreEdit->setFixedSize(180,22);
    autoreEdit->setFont(QFont("Verdana"));

    casaEdit =new QLabel("Casa Editrice:",this);
    casaEdit->setStyleSheet("font: 10pt 'Verdana'; color: #000; ");
    casaEditEdit=new QLineEdit(this);
    casaEditEdit->setPlaceholderText("Inserisci la casa editrice");
    casaEditEdit->setFixedSize(180,22);
    casaEditEdit->setFont(QFont("Verdana"));

    annulla=new QPushButton("Annulla",this);
    annulla->setFont(QFont("Verdana"));
    connect(annulla,SIGNAL(clicked()),this,SLOT(close()));

    conferma=new QPushButton("Conferma",this);
    conferma->setFont(QFont("Verdana"));
    connect(conferma,SIGNAL(clicked()),this,SLOT(InserisciLibro()));

    QGridLayout* grid = new QGridLayout();
    grid->addWidget(isbn,0,0);
    grid->addWidget(isbnEdit,0,1);
    grid->addWidget(titoloLib,1,0);
    grid->addWidget(titoloLibEdit,1,1);
    grid->addWidget(autore,2,0);
    grid->addWidget(autoreEdit,2,1);
    grid->addWidget(casaEdit,3,0);
    grid->addWidget(casaEditEdit,3,1);

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

void InserisciNuovoLibro::centraFinestra(int windowWidth, int windowHeight) {
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth-windowWidth) / 2;
    y = (screenHeight-windowHeight) / 2;
    this->move(x,y);
}

void InserisciNuovoLibro::InserisciLibro() {
    if (isbnEdit->text().isEmpty() || titoloLibEdit->text().isEmpty() || autoreEdit->text().isEmpty() || casaEditEdit->text().isEmpty()) {
        QMessageBox errore;
        errore.setText("Sono richiesti tutti i campi.");
        errore.exec();
    }
    else {
        QMessageBox avviso;
        emit AddLibro(isbnEdit->text(),titoloLibEdit->text(),autoreEdit->text(),casaEditEdit->text());
    }
}


InserisciNuovoLibro::~InserisciNuovoLibro() {
    delete titolo;
    delete isbn;
    delete isbnEdit;
    delete titoloLib;
    delete titoloLibEdit;
    delete autore;
    delete autoreEdit;
    delete casaEdit;
    delete casaEditEdit;
    delete annulla;
    delete conferma;
    delete layout;
}

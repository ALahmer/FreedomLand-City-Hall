#ifndef CITTADINO_VIEW_H
#define CITTADINO_VIEW_H

#include<QGroupBox>
#include<QFrame>
#include<QToolTip>
#include<QIcon>
#include<QMainWindow>
#include<QTableWidget>
#include<QRadioButton>
#include<QHeaderView>
#include<QTableWidgetItem>

#include<MODEL/cittadino_model.h>
#include<VIEW/modifica_profilo.h>

class CittadinoView : public QWidget {
    Q_OBJECT
private:
    const ModelCittadino* model;

    QLabel* benvenuto;

    QFrame* frame;

    QLabel* nome;
    QLabel* cognome;
    QLabel* datadinascita;
    QLabel* professione;
    QLabel* mail;
    QLabel* comune;
    QLabel* via;
    QLabel* numerocivico;
    QLabel* cittadinanza;
    QLabel* cartadidentita;
    QLabel* passaporto;

    QPushButton* profilo;
    QPushButton* logout;
    QPushButton* esci;

    ModificaProfilo* modifyProfile;

    QVBoxLayout* layout;
public:
    CittadinoView(QWidget *parent=0, const ModelCittadino* modeL=0);
    ~CittadinoView();
    void centraFinestra(int,int);
    void cancellaModifyProfileWindow();
private slots:
    void slotModifyProfile();
signals:
    void logoutCittadino();
    void signalModifyProfile(const QString& nome, const QString& cognome, const QString& password1,
                             const QString& password2, const QDate& datadinascita, const QString& professione,
                             const QString& mail);
};

#endif // CITTADINO_VIEW_H

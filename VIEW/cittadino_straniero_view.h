#ifndef CITTADINO_STRANIERO_VIEW_H
#define CITTADINO_STRANIERO_VIEW_H

#include<QGroupBox>
#include<QFrame>
#include<QToolTip>
#include<QIcon>
#include<QMainWindow>
#include<QTableWidget>
#include<QRadioButton>
#include<QHeaderView>
#include<QTableWidgetItem>

#include<MODEL/cittadino_straniero_model.h>
#include<VIEW/modifica_profilo.h>

class CittadinoStranieroView : public QWidget {
    Q_OBJECT
private:
    const ModelCittadinoStraniero* model;

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
    QLabel* permessodisoggiorno;

    QPushButton* profilo;
    QPushButton* logout;
    QPushButton* esci;

    ModificaProfilo* modifyProfile;

    QVBoxLayout* layout;
public:
    CittadinoStranieroView(QWidget *parent=0, const ModelCittadinoStraniero* modeL=0);
    ~CittadinoStranieroView();
    void centraFinestra(int,int);
    void cancellaModifyProfileWindow();
private slots:
    void slotModifyProfile();
signals:
    void logoutCittadinoStraniero();
    void signalModifyProfile(const QString& nome, const QString& cognome, const QString& password1,
                             const QString& password2, const QDate& datadinascita, const QString& professione,
                             const QString& mail);
};

#endif // CITTADINO_STRANIERO_VIEW_H

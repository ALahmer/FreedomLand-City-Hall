#ifndef IMPIEGATOBIBLIOTECACONTROLLER_H
#define IMPIEGATOBIBLIOTECACONTROLLER_H

#include<VIEW/impiegato_biblioteca_view.h>

class ImpiegatoBibliotecaController : public QObject {
    Q_OBJECT
private:
    ModelImpiegatoBiblioteca* model;
    ImpiegatoBibliotecaView* view;
public:
    ImpiegatoBibliotecaController(QObject* parent=0, ModelImpiegatoBiblioteca* m=0, ImpiegatoBibliotecaView* v=0);

public slots:
    void slotModificaProfiloUtente(const QString& nome, const QString& cognome, const QString& password1, const QString& password2, const QDate& datadinascita, const QString& professione, const QString& mail);
    void BorrowLibroSlot(const QString& possessore, const QString& ISBN);
    void ResumeLibroSlot(const QString& ISBN);
    void DeleteLibroSlot(const QString& ISBN);
    void slotAddLibro(const QString& ISBN, const QString& titolo, const QString& autore, const QString& casaEd);
};

#endif // IMPIEGATOBIBLIOTECACONTROLLER_H

#-------------------------------------------------
#
# Project created by QtCreator 2016-01-10T15:18:40
#
#-------------------------------------------------

QT       += core gui



TARGET = progetto
TEMPLATE = app

QT += widgets

SOURCES += main.cpp\
    CONTROLLER/controller.cpp \
    MODEL/utente.cpp \
    MODEL/info.cpp \
    MODEL/residenza.cpp \
    MODEL/database.cpp \
    MODEL/impiegato.cpp \
    MODEL/cittadino.cpp \
    MODEL/cittadino_straniero.cpp \
    MODEL/impiegato_biblioteca.cpp \
    MODEL/book.cpp \
    MODEL/impiegato_anagrafe.cpp \
    VIEW/home_view.cpp \
    MODEL/amministratore.cpp \
    VIEW/startwindow.cpp \
    VIEW/amministratore_view.cpp \
    VIEW/inserisci_nuovo_utente.cpp \
    VIEW/modifica_profilo.cpp \
    VIEW/impiegato_anagrafe_view.cpp \
    VIEW/inserisci_nuovo_cittadino.cpp \
    VIEW/scheda_utente.cpp \
    VIEW/impiegato_biblioteca_view.cpp \
    VIEW/inserisci_nuovo_libro.cpp \
    VIEW/cittadino_view.cpp \
    VIEW/cittadino_straniero_view.cpp \
    CONTROLLER/amministratorecontroller.cpp \
    CONTROLLER/cittadinocontroller.cpp \
    CONTROLLER/cittadinostranierocontroller.cpp \
    CONTROLLER/impiegatoanagrafecontroller.cpp \
    CONTROLLER/impiegatobibliotecacontroller.cpp \
    MODEL/amministratore_model.cpp \
    MODEL/cittadino_model.cpp \
    MODEL/cittadino_straniero_model.cpp \
    MODEL/impiegato_anagrafe_model.cpp \
    MODEL/impiegato_biblioteca_model.cpp \
    MODEL/myContainer.cpp

HEADERS += \
    CONTROLLER/controller.h \
    MODEL/utente.h \
    MODEL/info.h \
    MODEL/residenza.h \
    MODEL/database.h \
    MODEL/impiegato.h \
    MODEL/cittadino.h \
    MODEL/cittadino_straniero.h \
    MODEL/impiegato_biblioteca.h \
    MODEL/book.h \
    MODEL/impiegato_anagrafe.h \
    VIEW/home_view.h \
    VIEW/startwindow.h \
    VIEW/amministratore_view.h \
    MODEL/amministratore.h \
    CONTROLLER/amministratorecontroller.h \
    CONTROLLER/impiegatoanagrafecontroller.h \
    VIEW/impiegato_anagrafe_view.h \
    CONTROLLER/impiegatobibliotecacontroller.h \
    VIEW/impiegato_biblioteca_view.h \
    CONTROLLER/cittadinocontroller.h \
    VIEW/cittadino_view.h \
    CONTROLLER/cittadinostranierocontroller.h \
    VIEW/cittadino_straniero_view.h \
    MODEL/amministratore_model.h \
    MODEL/cittadino_model.h \
    MODEL/cittadino_straniero_model.h \
    MODEL/impiegato_anagrafe_model.h \
    MODEL/impiegato_biblioteca_model.h \
    VIEW/inserisci_nuovo_utente.h \
    VIEW/modifica_profilo.h \
    VIEW/inserisci_nuovo_cittadino.h \
    VIEW/scheda_utente.h \
    VIEW/inserisci_nuovo_libro.h \
    MODEL/myContainer.h

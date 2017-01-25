#include<CONTROLLER/controller.h>

int main(int argc, char *argv[])
{    
    QApplication FreedomLandCityHall(argc, argv);
    UsersDatabase ud;
    BooksDatabase bd;
    Controller c(0,&ud,&bd);
    return FreedomLandCityHall.exec();
}

#include "imc.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Objeto para manejar las traducciones
    QTranslator traducion;
    // Solicitando al usuario que seleccione un idioma
    QStringList idiomas;
    idiomas << "Alemán" << "Español";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                                       "Idioma",
                                                       "Seleccione un idioma",
                                                       idiomas);
    // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
    if (idiomaSeleccionado == "Alemán"){
        traducion.load(":/imc_al.qm");
    }

    if (idiomaSeleccionado == "Español"){
        a.installTranslator(&traducion);
    }
    // Si es diferente de español, se instala la traducción en TODA la aplicación
    if (idiomaSeleccionado != "Español" && idiomaSeleccionado != "Alemán"){
        a.installTranslator(&traducion);
    }
    // Muestra la ventana principal
    IMC w;
    w.show();
    return a.exec();
}

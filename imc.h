/**
 * Algoritmo para obtener IMC
 *
 * Autor: Carlos Salcan [CaLeL]
 * Fecha: 02 de febrero del 2022
 * Correo: csalcan@est.ups.edu.ec
 *
 */

#ifndef IMC_H
#define IMC_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <math.h>
#include <QTranslator>
#include <QInputDialog>
#include <QPalette>
#include <QDialog>
#include <QFile>
#include <QTextStream>

#include "persona.h"
#include "acerca.h"

#define VERSION "1.0"


QT_BEGIN_NAMESPACE
namespace Ui { class IMC; }
QT_END_NAMESPACE

class IMC : public QMainWindow
{
    Q_OBJECT

public:
    IMC(QWidget *parent = nullptr);
    ~IMC();

    bool agregarDatos(float altura, float peso);

private slots:
    void on_btnCalcular_released();

    void on_actionNuevo_triggered();

    void on_actionCalcular_triggered();

    void on_actionSalir_triggered();

    void on_actionAcerca_de_IMC_triggered();

    void on_actionAbrir_triggered();

    void on_actionGuardar_triggered();

    void on_pushButton_released();

private:
    Ui::IMC *ui;

    void calcularIMC();
    void limpiar();
    void validarEstado();
    void guardar();
    void abrir();
    void mostrar();
    void archivo();

    Persona *m_persona;
    float m_imc;
    QString name;
    QString printed;

};
#endif // IMC_H

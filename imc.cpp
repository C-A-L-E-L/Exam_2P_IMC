#include "imc.h"
#include "ui_imc.h"

IMC::IMC(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IMC)
{
    ui->setupUi(this);
    m_persona = new Persona();
}

IMC::~IMC()
{
    delete ui;
}

bool IMC::agregarDatos(float altura, float peso)
{
    this->m_persona =new Persona(altura,peso);
    return true;
}

void IMC::calcularIMC()
{
    float peso = ui->inPeso->value();
    float altura = ui->inAltura->value();

    // Validar datos correctos y mostrar mensaje de advertencia
    if(peso == 0 || altura == 0){
        QMessageBox::warning(this,
                             "ADVERTENCIA",
                             "El peso o altura esta vacio/a");
        //return;
    }

    float imc = peso/pow(altura,2);

    m_imc=imc;

    // Mostrar resultado
    ui->outImc->setText(QString::number(imc,'f',2));
    ui->outPesoActual->setText(QString::number(peso,'f',2)+" kg");
    ui->outPesoMax->setText(QString::number(peso,'f',2)+" kg");
    ui->outPesoMin->setText(QString::number(peso,'f',2)+" kg");
}

void IMC::limpiar()
{
    ui->inPeso->setValue(0);
    ui->inAltura->setValue(0);
    ui->outPesoActual->setText("");
    ui->outPesoMax->setText("");
    ui->outPesoMin->setText("");
    ui->outImc->setText("");
    ui->outEstado->setText("");
}

void IMC::validarEstado()
{
    QString bdp="Bajo del peso";
    //QPalette palette=ui->outEstado->palette();
    if(m_imc < 19.5){
        //palette.setColor(ui->outEstado->foregroundRole(),Qt::red);
        ui->outEstado->setStyleSheet("background-color: red");
        //ui->outEstado->setText("Bajo el peso");
        //ui->outEstado->setStyleSheet("qlabel { background-color : red;}");
        ui->outEstado->setStyleSheet("QLabel{ background-color: red}");
    }
}

void IMC::on_btnCalcular_released()
{
    calcularIMC();
}

void IMC::on_actionNuevo_triggered()
{
    limpiar();
}

void IMC::on_actionCalcular_triggered()
{
    calcularIMC();
}

void IMC::on_actionSalir_triggered()
{
    close();
}

void IMC::on_actionAcerca_de_IMC_triggered()
{
    // Crear un obj de la ventama que deseamos invocar
    Acerca *dialogo = new Acerca(this);

    // Enviar parametro a la ventana
    dialogo->setVersion(VERSION);

    // Mostrar la ventana [dialogo->show();]
    dialogo->exec();
}


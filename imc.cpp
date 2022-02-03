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
                             tr("ADVERTENCIA"),
                             tr("El peso o altura esta vacio/a"));
        return;
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
    ui->inPeso->setValue(0.00);
    ui->inAltura->setValue(0.00);
    ui->outPesoActual->setText("0.00");
    ui->outPesoMax->setText("0.00");
    ui->outPesoMin->setText("0.00");
    ui->outImc->setText("0.00");
    ui->outEstado->setText("0.00");
}

void IMC::validarEstado()
{
    QString bdp=tr("Bajo de peso");
    QString pn=tr("Peso normal");
    QString sp=tr("Sobre Peso");
    QString ob=tr("Obesidad");

    if(m_imc < 18.5){
        ui->outEstado->setText(QString(bdp));
        ui->outEstado->setStyleSheet("QLabel {color: blue}");
        ui->outBajoF->setStyleSheet("QLabel {color: black}");
    }

    if(m_imc >= 18.5 && m_imc <= 24.9){
        ui->outEstado->setText(QString(pn));
        ui->outEstado->setStyleSheet("QLabel {color: green}");
        ui->outBienF->setStyleSheet("QLabel {color: black}");
    }

    if(m_imc >= 25.0 && m_imc <= 29.9){
        ui->outEstado->setText(QString(sp));
        ui->outEstado->setStyleSheet("QLabel {color: orange}");
        ui->outSobreF->setStyleSheet("QLabel {color: black}");
    }

    if(m_imc > 30.0){
        ui->outEstado->setText(QString(ob));
        ui->outEstado->setStyleSheet("QLabel {color: red}");
        ui->outSobreF->setStyleSheet("QLabel {color: black}");
    }
}

void IMC::guardar()
{
    // Abrir cuadro de dialogo para selecionar nombre y ubicación del archivo
    QString nombreArchivo = QFileDialog::getSaveFileName(this,
                                                         tr("GUARDAR ARCHIVO"),
                                                         QDir::home().absolutePath(),
                                                         "Archivos de salario (*.txt)");
    // Crear un obj QFile
    QFile archivo(nombreArchivo);
    // Abrirlo para escritura
    if(archivo.open(QFile::WriteOnly | QFile::Truncate)){
        // Crear stream [Flujo de texto]
        QTextStream salida(&archivo);
        // Enviar los datos del resultado a la salida
        salida << "\n\t* * IMC * *\n\n";
        salida << tr("Fecha: ") << m_persona->tostring() << "\n";
        salida << tr("Altura: ") << ui->inAltura->value() << "[m]\n";
        salida << tr("Peso: ") << ui->inPeso->value() << "[kg]\n";
        salida << tr("Peso Actual: ") << ui->outPesoActual->text() << "[kg]\n";
        salida << tr("Peso Max: ") << ui->outPesoMax->text() << "[kg]\n";
        salida << tr("Peso Min: ") << ui->outPesoMin->text() << "[kg]\n";
        salida << tr("IMC: ") << ui->outImc->text() << " [kg/m^2]\t[" << ui->outEstado->text() << "]\n\n";
    }else{
        // Mensaje de error si no s epeude abrir el archivo
        QMessageBox::warning(this,
                             tr("GUARDAR"),
                             tr("No se logro salvar el archivo"));
    }
}

void IMC::abrir()
{
    // Abrir cuadro de dialogo para selecionar nombre y ubicación del archivo
    QString nombreArchivo = QFileDialog::getOpenFileName(this,
                                                         "ABRIR ARCHIVO",
                                                         QDir::home().absolutePath(),
                                                         "Archivos de salario (*.txt)");
    // Crear un obj QFile
    QFile archivo(nombreArchivo);
    // Abrirlo para lectura
    if(archivo.open(QFile::ReadOnly)){
        // Crear stream [Flujo de texto]
        QTextStream entrada(&archivo);
        // Leer  rodo el contenido del archivo
        QString datos = entrada.readAll();
        // Cargar el contenido al area texto
        ui->outPesoActual->setText(datos);
        // MOstrar por 5 seg que todo salio bien
        ui->statusbar->showMessage("Datos leidos desde " + nombreArchivo,5000);
    }else{
        // Mensaje de error si no s epeude abrir el archivo
        QMessageBox::warning(this,
                             "ABRIR ARCHIVOS",
                             "No se puede abrir el archivo");
    }
    // Cerrar el archivo
    archivo.close();
}

void IMC::on_btnCalcular_released()
{
    calcularIMC();
    validarEstado();
}

void IMC::on_actionNuevo_triggered()
{
    limpiar();
}

void IMC::on_actionCalcular_triggered()
{
    on_btnCalcular_released();
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

void IMC::on_actionGuardar_triggered()
{
    on_pushButton_released();
}

void IMC::on_pushButton_released()
{
    guardar();
}

void IMC::on_actionAbrir_triggered()
{
    abrir();
}

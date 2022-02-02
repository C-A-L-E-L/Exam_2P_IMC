#include "acerca.h"
#include "ui_acerca.h"

Acerca::Acerca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acerca)
{
    ui->setupUi(this);
}

Acerca::~Acerca()
{
    delete ui;
}

void Acerca::setVersion(const QString &newVersion)
{
    m_version = newVersion;
    this->ui->lblNombre->setText("IMC " + m_version);
}

const QString &Acerca::version() const
{
    return m_version;
}

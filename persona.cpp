#include "persona.h"

Persona::Persona(QObject *parent) : QObject(parent)
{
    this->m_altura=0.0;
    this->m_peso=0.0;
}

Persona::Persona(float altura, float peso, QObject *parent) : QObject(parent),
    m_altura(altura),
    m_peso(peso)
{}

float Persona::altura() const
{
    return m_altura;
}

void Persona::setAltura(float newAltura)
{
    m_altura = newAltura;
}

float Persona::peso() const
{
    return m_peso;
}

void Persona::setPeso(float newPeso)
{
    m_peso = newPeso;
}

QString Persona::tostring()
{
    QString str = "";
    // Mostrar los datos
    str.append("Fecha: " + fecha() + "\n");
    return str;
}

QString Persona::fecha()
{
    QDate fecha = QDate::currentDate();
    QString Date = fecha.toString(Qt::DefaultLocaleLongDate);
    return Date;
}

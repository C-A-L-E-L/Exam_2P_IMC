/**
 * Algoritmo para obtener IMC
 *
 * Autor: Carlos Salcan [CaLeL]
 * Fecha: 02 de febrero del 2022
 * Correo: csalcan@est.ups.edu.ec
 *
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <QObject>
#include <QDateTime>
#include <QDate>

class Persona : public QObject
{
    Q_OBJECT
public:
    explicit Persona(QObject *parent = nullptr);
    Persona(float altura, float peso, QObject *parent = nullptr);

    float altura() const;
    void setAltura(float newAltura);
    float peso() const;
    void setPeso(float newPeso);
    float imc() const;
    void setImc(float newImc);

    QString tostring();
    QString fecha();

signals:

private:
    float m_altura;
    float m_peso;
    float m_imc;

};

#endif // PERSONA_H

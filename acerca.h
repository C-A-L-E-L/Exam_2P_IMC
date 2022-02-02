#ifndef ACERCA_H
#define ACERCA_H

#include <QDialog>

namespace Ui {
class Acerca;
}

class Acerca : public QDialog
{
    Q_OBJECT

public:
    explicit Acerca(QWidget *parent = nullptr);
    ~Acerca();

    void setVersion(const QString &newVersion);

    const QString &version() const;

private:
    Ui::Acerca *ui;

    QString m_version;
};

#endif // ACERCA_H

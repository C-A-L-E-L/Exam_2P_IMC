#ifndef IMC_H
#define IMC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class IMC; }
QT_END_NAMESPACE

class IMC : public QMainWindow
{
    Q_OBJECT

public:
    IMC(QWidget *parent = nullptr);
    ~IMC();

private:
    Ui::IMC *ui;
};
#endif // IMC_H

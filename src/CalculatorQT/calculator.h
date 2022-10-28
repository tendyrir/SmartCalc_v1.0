#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

extern "C" {
#include "smartcalc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    void print_digits();
    void print_operations();
    void print_trigonometry_function();

    void on_button_op_del_clicked();
    void on_button_op_exe_clicked();

//    void on_button_op_exe_clicked();



};
#endif // CALCULATOR_H

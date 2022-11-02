#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

extern "C" {
#include "s21_smartcalc.h"
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

    QString check_dot;
    QString calc_input;

    QVector<double> x, y;

    double current_value;

    bool is_var_x_clicked;

private slots:
    void print_digits();
    void print_operations();
    void print_function();
    void print_function_graph();

    void on_button_op_del_clicked();
    void on_button_sign_brace_clicked();
    void on_button_sign_dot_clicked();
    void on_button_op_exe_clicked();
//    void on_button_var_x_clicked();

};
#endif // CALCULATOR_H

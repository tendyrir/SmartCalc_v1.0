#include "calculator.h"
#include "./ui_calculator.h"

QString check_dot;

Calculator::Calculator(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calculator) {

    ui->setupUi(this);

    connect(ui->button_num_0, SIGNAL(clicked()), this, SLOT(print_digits()));
    connect(ui->button_num_1, SIGNAL(clicked()), this, SLOT(print_digits()));
    connect(ui->button_num_2, SIGNAL(clicked()), this, SLOT(print_digits()));
    connect(ui->button_num_3, SIGNAL(clicked()), this, SLOT(print_digits()));
    connect(ui->button_num_4, SIGNAL(clicked()), this, SLOT(print_digits()));
    connect(ui->button_num_5, SIGNAL(clicked()), this, SLOT(print_digits()));
    connect(ui->button_num_6, SIGNAL(clicked()), this, SLOT(print_digits()));
    connect(ui->button_num_7, SIGNAL(clicked()), this, SLOT(print_digits()));
    connect(ui->button_num_8, SIGNAL(clicked()), this, SLOT(print_digits()));
    connect(ui->button_num_9, SIGNAL(clicked()), this, SLOT(print_digits()));

    connect(ui->button_op_sum, SIGNAL(clicked()), this, SLOT(print_operations()));
    connect(ui->button_op_min, SIGNAL(clicked()), this, SLOT(print_operations()));
    connect(ui->button_op_div, SIGNAL(clicked()), this, SLOT(print_operations()));
    connect(ui->button_op_mul, SIGNAL(clicked()), this, SLOT(print_operations()));
    connect(ui->button_op_pow, SIGNAL(clicked()), this, SLOT(print_operations()));
    connect(ui->button_op_mod, SIGNAL(clicked()), this, SLOT(print_operations()));
    connect(ui->button_op_del, SIGNAL(clicked()), this, SLOT(on_pushButton_clear_clicked()));

    connect(ui->button_sign_opb, SIGNAL(clicked()), this, SLOT(print_operations()));
    connect(ui->button_sign_clb, SIGNAL(clicked()), this, SLOT(print_operations()));
    connect(ui->button_sign_dot, SIGNAL(clicked()), this, SLOT(print_operations()));


}

Calculator::~Calculator() { delete ui; }

void Calculator::print_digits() {

  QPushButton *button = (QPushButton *) sender();
  QString new_label;
  check_dot += button->text();
  if (ui->input->text() != "0") {
    new_label = ui->input->text() + button->text();
//    input_real = input_real + button->text();
  } else {
    new_label = button->text();
//    input_real = button->text();
  }
  ui->input->setText(new_label);
}

void Calculator::print_operations() {
  check_dot = 0;
  QPushButton *button = (QPushButton *) sender();
  if (ui->input->text() != "0") {
    ui->input->setText(ui->input->text() + button->text());
  } else {
    ui->input->setText(button->text());
  }
//  if (button->text() == "mod") {
//    input_real = input_real + "m";
//  } else {
//    if (ui->label->text() != "0") {
//      input_real = input_real + button->text();
//    } else {
//      input_real = button->text();
//    }
//  }
}

void Calculator::on_button_op_del_clicked() {
  ui->input->setText("0");
//  input_real = "0";
//  ui->widget->graph(0)->data()->clear();
  check_dot = 0;
//  x.clear();
//  y.clear();
}

//void Calculator::on_button_op_exe_clicked() {
//  QString text = input_real;
//  QByteArray str_bit = text.toLocal8Bit();
//  char *input_str = str_bit.data();
//  int code = validation(input_str);
//  if (code) {
//    ui->input->setText("Error");
//  } else {
//    double output = calc(input_str);
//    QString str_output = QString::number(output);
//    ui->input->setText(str_output);
//  }
//}

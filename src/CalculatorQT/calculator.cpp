#include "calculator.h"
#include "./ui_calculator.h"
#include <iostream>

Calculator::Calculator(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calculator) {

    ui->setupUi(this);

    ui->widget->addGraph();

    ui->graph_min_x->setMinimum(-1000000);
    ui->graph_max_x->setMinimum(-1000000);

    ui->graph_min_x->setMaximum(1000000);
    ui->graph_max_x->setMaximum(1000000);


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

    connect(ui->button_op_asin, SIGNAL(clicked()), this, SLOT(print_trigonometry_function()));
    connect(ui->button_op_acos, SIGNAL(clicked()), this, SLOT(print_trigonometry_function()));
    connect(ui->button_op_atan, SIGNAL(clicked()), this, SLOT(print_trigonometry_function()));
    connect(ui->button_op_sqrt, SIGNAL(clicked()), this, SLOT(print_trigonometry_function()));

    connect(ui->button_op_sin, SIGNAL(clicked()), this, SLOT(print_trigonometry_function()));
    connect(ui->button_op_cos, SIGNAL(clicked()), this, SLOT(print_trigonometry_function()));
    connect(ui->button_op_log, SIGNAL(clicked()), this, SLOT(print_trigonometry_function()));

    connect(ui->button_op_tg, SIGNAL(clicked()), this, SLOT(print_trigonometry_function()));
    connect(ui->button_op_ln, SIGNAL(clicked()), this, SLOT(print_trigonometry_function()));

    connect(ui->button_sign_opb, SIGNAL(clicked()), this, SLOT(print_operations()));
    connect(ui->button_sign_clb, SIGNAL(clicked()), this, SLOT(print_operations()));
    connect(ui->button_sign_dot, SIGNAL(clicked()), this, SLOT(print_operations()));

    connect(ui->button_var_x, SIGNAL(clicked()), this, SLOT(on_button_var_x_clicked()));


    connect(ui->button_graph_x, SIGNAL(clicked()), this, SLOT(print_digits()));
    connect(ui->button_graph_build, SIGNAL(clicked()), this, SLOT(print_function_graph()));


}

Calculator::~Calculator() { delete ui; }


/*
 *  Prints digits by pressing buttons
 */
void Calculator::print_digits() {

  QPushButton *button = (QPushButton *) sender();
  QString new_label;

  check_dot += button->text();

  if (ui->input->text() != "0") {
    new_label = ui->input->text() + button->text();
    calc_input = calc_input + button->text();
  } else {
    new_label = button->text();
    calc_input = button->text();
  }
  ui->input->setText(new_label);
}


//void Calculator::print_operations() {
//  check_dot = 0;
//  QPushButton *button = (QPushButton *) sender();
//  if (ui->input->text() != "0") {
//    ui->input->setText(ui->input->text() + button->text());
////    calc_input = calc_input + button->text();
//  } else {
//    ui->input->setText(button->text());
////    calc_input = button->text();
//  }

//  if (button->text() == "mod") {
//    input_real = input_real + "m";
//  } else {
//    if (ui->label->text() != "0") {
//      input_real = input_real + button->text();
//    } else {
//      input_real = button->text();
//    }
//  }
//}

void Calculator::print_operations() {
  check_dot = 0;
  bool aboba = true;
  QPushButton *button = (QPushButton *)
      sender();
  QString input_check = ui->input->text();
  QString array[] = {"+", "-", "/", "*", "mod"};

  for(int i = 0; i < 5; i++) {
    if(input_check.endsWith(array[i])) {
      aboba = false;
      break;
    }
  }

  if (aboba) {
    if (ui->input->text() != "0") {
      ui->input->setText(ui->input->text() + button->text());
    } else {
      ui->input->setText(button->text());
    }
    if (button->text() == "mod") {
      calc_input = calc_input + "m";
    } else {
      if (ui->input->text() != "0") {
        calc_input = calc_input + button->text();
      } else {
        calc_input = button->text();
      }
    }
  }

}


/*
 * Reseting calculator to zero
*/
void Calculator::on_button_op_del_clicked() {
  ui->input->setText("0");
  calc_input = "0";
  ui->widget->graph(0)->data()->clear();
  check_dot = 0;
  x.clear();
  y.clear();
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

void Calculator::on_button_op_exe_clicked() {
    QString text;
//    if (X_output != "q") {
//        change_X();
//        text = qtext;
//    } else {
//        text = input_real;
//    }
    text = ui->input->text();
    QByteArray str_bit = text.toLocal8Bit();
    char *input_str = str_bit.data();
//  int code = validation(input_str);
//  if (code) {
//    ui->label_2->setText("Error");
//  } else {


    char* infix_input_with_unary_minus = replace_unary_minus(input_str);
    char* infix = infix_to_postfix(infix_input_with_unary_minus);
    double output = postfix_to_result(infix);
    QString str_output = QString::number(output);
    ui->input->setText(str_output);
//  }
}



void Calculator::print_trigonometry_function() {
  check_dot = 0;
  QPushButton *button = (QPushButton *)sender();
  button->setChecked(true);

  if (button->text() == "sin") {
    if (ui->input->text() != "0") {
      calc_input = calc_input + "s(";
      ui->input->setText(ui->input->text() + "sin(");
    } else {
      calc_input = "s(";
      ui->input->setText("sin(");
    }
  }

  if (button->text() == "cos") {
    if (ui->input->text() != "0") {
      calc_input = calc_input + "c(";
      ui->input->setText(ui->input->text() + "cos(");
    } else {
      calc_input = "c(";
      ui->input->setText("cos(");
    }
  }

  if (button->text() == "tg") {
    if (ui->input->text() != "0") {
      calc_input = calc_input + "t(";
      ui->input->setText(ui->input->text() + "tg(");
    } else {
      calc_input = "t(";
      ui->input->setText("tg(");
    }
  }

  if (button->text() == "acos") {
    if (ui->input->text() != "0") {
      calc_input = calc_input +"k(";
      ui->input->setText(ui->input->text() + "acos(");
    } else {
      calc_input ="k(";
      ui->input->setText("acos(");
    }
  }

  if (button->text() == "asin") {
    if (ui->input->text() != "0") {
      calc_input = calc_input + "i(";
      ui->input->setText(ui->input->text() + "asin(");
    } else {
      calc_input = "i(";
      ui->input->setText("asin(");
    }
  }

  if (button->text() == "atan") {
    if (ui->input->text() != "0") {
      calc_input = calc_input + "n(";
      ui->input->setText(ui->input->text() + "a(");
    } else {
      calc_input = "n(";
      ui->input->setText("a(");
    }
  }

  if (button->text() == "sqrt") {
    if (ui->input->text() != "0") {
      calc_input = calc_input + "q(";
      ui->input->setText(ui->input->text() + "sqrt(");
    } else {
      calc_input = "q(";
      ui->input->setText("sqrt(");
    }
  }

  if (button->text() == "ln") {
    if (ui->input->text() != "0") {
      calc_input = calc_input + + "l(";
      ui->input->setText(ui->input->text() + "ln(");
    } else {
      calc_input = "l(";
      ui->input->setText("n(");
    }
  }

  if (button->text() == "log") {
    if (ui->input->text() != "0") {
      calc_input = calc_input + "o(";
      ui->input->setText(ui->input->text() + "log(");
    } else {
      calc_input = "o(";
      ui->input->setText("log(");
    }
  }

//  if (ui->input->text() != "0") {
//    ui->input->setText(ui->input->text() + button->text() + '(');
//  } else {
//    ui->input->setText(button->text() + "(");
//  }

}

void Calculator::print_function_graph() {

//  ui->widget->graph(0)->data()->clear();

  QString text = calc_input;
  QByteArray graph_bit = text.toLocal8Bit();
  double output;
  char *graph_str = graph_bit.data();
//  CharStack char_stack;

  int min = ui->graph_max_x->value();
  int max = ui->graph_min_x->value();





  // int code = validation(graph_str);
  // if (!code) {
  //   output = create_graphic(graph_str, max, min);
  // } else {
  //   ui->label->setText("Error");
  // }


  for (current_value = min; current_value <= max; current_value += 0.1) {
    x.push_back(current_value);
    output = create_function_graph(graph_str, current_value);
//    std::cout << output;
    y.push_back(output);

  }

  ui->widget->graph(0)->addData(x, y);
  ui->widget->xAxis->setRange(min, max);
  ui->widget->yAxis->setRange(min, max);
  ui->widget->replot();

}


//void MainWindow::create_graph() {
//  ui->widget->graph(0)->data()->clear();
//  QString text = input_real;
//  QByteArray graph_bit = text.toLocal8Bit();
//  char *graph_str = graph_bit.data();
//  double output;
//  int min = ui->spinBox_min->value();
//  int max = ui->spinBox_max->value();
//  int code = validation(graph_str);
//  if (code == 1) {
//    ui->label_2->setText("Error");
//  } else {
//    for (X = min; X <= max; X += 0.1) {
//      x.push_back(X);
//      output = create_graphic(graph_str, sign_st, X);
//      y.push_back(output);
//    }
//    ui->widget->graph(0)->addData(x, y);
//    ui->widget->xAxis->setRange(min, max);
//    ui->widget->yAxis->setRange(min, max);
//    ui->widget->replot();
//    if(max || min) {
//      ui->label_2->setText("Graph is build");
//    }
//  }
//}


void Calculator::on_button_var_x_clicked() {
    QString new_label;

    if (ui->input->text() != "0") {
      new_label = ui->input->text() + "X";
      calc_input = calc_input + "X";

    } else {
      new_label = "X";
      calc_input = "X";
    }

//    isClickedX = true;

    ui->input->setText(new_label);
}

std::string Calculator::change_X(std::string X) {
  std::string input_real_string = "";
  input_real_string = input_real.toStdString();
  size_t pos = 0;
  for (;;) {
    pos = input_real_string.find("X", pos);
    if (pos == std::string::npos) break;
    input_real_string.replace(pos, 1, X);
    pos += X.size();
  }

  return input_real_string;
}



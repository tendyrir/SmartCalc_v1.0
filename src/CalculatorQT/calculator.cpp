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

////  if (button->text() == "mod") {
////    input_real = input_real + "m";
////  } else {
////    if (ui->label->text() != "0") {
////      input_real = input_real + button->text();
////    } else {
////      input_real = button->text();
////    }
////  }
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
  if(aboba) {
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

void Calculator::on_button_op_exe_clicked()
{
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

    char *infix = infix_to_postfix(input_str);

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

//    if (ui->input->text() != "0") {
//      input_real = input_real + "s(";
//    } else {
//      input_real = "s(";
//    }

    if (ui->input->text() != "0") {
      ui->input->setText(ui->input->text() + "s(");
    } else {
      ui->input->setText("s(");
    }


  }
  if (button->text() == "cos") {

//    if (ui->input->text() != "0") {
//      input_real = input_real + "c(";
//    } else {
//      input_real = "c(";
//    }
      if (ui->input->text() != "0") {
        ui->input->setText(ui->input->text() + "c(");
      } else {
        ui->input->setText("c(");
      }

  }
  if (button->text() == "tan") {
//    if (ui->input->text() != "0") {
//      input_real = input_real + "t(";
//    } else {
//      input_real = "t(";
//    }
      if (ui->input->text() != "0") {
        ui->input->setText(ui->input->text() + "t(");
      } else {
        ui->input->setText("t(");
      }
  }
  if (button->text() == "acos") {
//    if (ui->input->text() != "0") {
//      input_real = input_real +"a(";
//    } else {
//      input_real ="a(";
//    }
      if (ui->input->text() != "0") {
        ui->input->setText(ui->input->text() + "k(");
      } else {
        ui->input->setText("k(");
      }

  }
  if (button->text() == "asin") {
//    if (ui->input->text() != "0") {
//      input_real = input_real + "i(";
//    } else {
//      input_real = "i(";
//    }
      if (ui->input->text() != "0") {
        ui->input->setText(ui->input->text() + "i(");
      } else {
        ui->input->setText("i(");
      }
  }
  if (button->text() == "atan") {
//    if (ui->input->text() != "0") {
//      input_real = input_real + "n(";
//    } else {
//      input_real = "n(";
//    }
      if (ui->input->text() != "0") {
        ui->input->setText(ui->input->text() + "a(");
      } else {
        ui->input->setText("a(");
      }
  }

  if (button->text() == "sqrt") {
//    if (ui->input->text() != "0") {
//      input_real = input_real + "q(";
//    } else {
//      input_real = "q(";
//    }
      if (ui->input->text() != "0") {
        ui->input->setText(ui->input->text() + "q(");
      } else {
        ui->input->setText("q(");
      }
  }
  if (button->text() == "ln") {
//    if (ui->input->text() != "0") {
//      input_real = input_real + + "l(";
//    } else {
//      input_real = "l(";
//    }
      if (ui->input->text() != "0") {
        ui->input->setText(ui->input->text() + "n(");
      } else {
        ui->input->setText("n(");
      }
  }
  if (button->text() == "log") {
//    if (ui->input->text() != "0") {
//      input_real = input_real + "o(";
//    } else {
//      input_real = "o(";
//    }
      if (ui->input->text() != "0") {
        ui->input->setText(ui->input->text() + "o(");
      } else {
        ui->input->setText("o(");
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


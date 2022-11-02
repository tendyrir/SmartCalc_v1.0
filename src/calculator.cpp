#include "calculator.h"
#include "./ui_calculator.h"

Calculator::Calculator(QWidget *parent) : QMainWindow(parent), ui(new Ui::Calculator) {
  ui->setupUi(this);

  ui->widget->addGraph();
  ui->graph_min_x->setMinimum(-1000000);
  ui->graph_max_x->setMinimum(-1000000);
  ui->graph_min_x->setMaximum(1000000);
  ui->graph_max_x->setMaximum(1000000);

  ui->graph_min_x->setValue(-10);
  ui->graph_max_x->setValue(10);

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

  connect(ui->button_op_del, SIGNAL(clicked()), this, SLOT(on_button_op_del_clicked()));

  connect(ui->button_op_asin, SIGNAL(clicked()), this, SLOT(print_function()));
  connect(ui->button_op_acos, SIGNAL(clicked()), this, SLOT(print_function()));
  connect(ui->button_op_atan, SIGNAL(clicked()), this, SLOT(print_function()));
  connect(ui->button_op_sqrt, SIGNAL(clicked()), this, SLOT(print_function()));
  connect(ui->button_op_sin, SIGNAL(clicked()), this, SLOT(print_function()));
  connect(ui->button_op_cos, SIGNAL(clicked()), this, SLOT(print_function()));
  connect(ui->button_op_log, SIGNAL(clicked()), this, SLOT(print_function()));
  connect(ui->button_op_tg, SIGNAL(clicked()), this, SLOT(print_function()));
  connect(ui->button_op_ln, SIGNAL(clicked()), this, SLOT(print_function()));

  connect(ui->button_sign_opb, SIGNAL(clicked()), this, SLOT(on_button_sign_brace_clicked()));
  connect(ui->button_sign_clb, SIGNAL(clicked()), this, SLOT(on_button_sign_brace_clicked()));

  connect(ui->button_sign_dot, SIGNAL(clicked()), this, SLOT(on_button_sign_dot_clicked()));
  
  connect(ui->button_graph_build, SIGNAL(clicked()), this, SLOT(print_function_graph()));

  connect(ui->button_graph_x, SIGNAL(clicked()), this, SLOT(print_digits()));
  connect(ui->button_var_x, SIGNAL(clicked()), this, SLOT(print_digits()));

  connect(ui->button_op_exe, SIGNAL(clicked()), this, SLOT(on_button_op_exe_clicked()));
}

Calculator::~Calculator() { delete ui; }

/*
 *  Prints digits and x by pressing buttons
 */
void Calculator::print_digits() {

  QPushButton *button = (QPushButton *) sender();
  QString new_label;

  check_dot += button->text();
  if (button->text() == "X") {
    is_var_x_clicked = true;
  }

  if (ui->input->text() != "0") {
    new_label = ui->input->text() + button->text();
    calc_input = calc_input + button->text();
  } else {
    new_label = button->text();
    calc_input = button->text();
  }
  ui->input->setText(new_label);
}

/* 
 *  Prints operations  
 */
void Calculator::print_operations() {

  check_dot = 0;
  bool ends_with_op = false;
  QPushButton *button = (QPushButton *)sender();
  QString possible_ops[] = {"+", "-", "/", "*", "mod"};
  for (int i = 0; i < 5; i++) {
    if (ui->input->text().endsWith(possible_ops[i])) {
      ends_with_op = true;
      break;
    }
  }

  if (!ends_with_op) {

    if (ui->input->text() != "0") {
      ui->input->setText(ui->input->text() + button->text());
    } else {
      ui->input->setText("0" + button->text());
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
 *  Full clear - AC button
 */
void Calculator::on_button_op_del_clicked() {
  ui->input->setText("0");
  ui->result->setText("0");

  ui->expression_x_replace->setValue(0);
  ui->graph_min_x->setValue(-10);
  ui->graph_max_x->setValue(10);

  calc_input = "0";

  is_var_x_clicked = false;

  ui->widget->graph(0)->data()->clear();

  check_dot = 0;
  x.clear();
  y.clear();
}


/*
 *  Prints braces
 */
void Calculator::on_button_sign_brace_clicked() {
  check_dot = 0;
  QPushButton *button = (QPushButton *)sender();

  if (ui->input->text() != "0") {
    ui->input->setText(ui->input->text() + button->text());
    calc_input = calc_input + button->text();
  } else {
    ui->input->setText(button->text());
    calc_input = button->text();
  }
}

/*
 *  Prints dot and checks for second one
 */
void Calculator::on_button_sign_dot_clicked() {

  QPushButton *button = (QPushButton *)(sender());
  if (!check_dot.contains('.')) {
    ui->input->setText(ui->input->text() + ".");
    calc_input = calc_input + ".";
  }
  check_dot += button->text();
}


/*
 *  Execute calculating expression and prints it to the result field
 */
void Calculator::on_button_op_exe_clicked() {

    QString text = calc_input;

    if (is_var_x_clicked) {

      std::string X = std::to_string(ui->expression_x_replace->value());

      std::string input_real_string = "";
      input_real_string = calc_input.toStdString();
      size_t pos = 0;
      for (;;) {
        pos = input_real_string.find("X", pos);
        if (pos == std::string::npos)
            break;
        input_real_string.replace(pos, 1, X);
        pos += X.size();
      }

      text = QString::fromStdString(input_real_string);
    }

    QByteArray str_bit = text.toLocal8Bit();
    char *input_str = str_bit.data();

//    int error = input_validation(input_str);
//    if (error != 1) {
//        ui->result->setText("Error");
//    } else {
        char* infix_input_with_unary_minus = replace_unary_minus(input_str);
        char* infix = infix_to_postfix(infix_input_with_unary_minus);
        double output = postfix_to_result(infix);
        QString str_output = QString::number(output, 'g', 10);
        ui->result->setText(str_output);
//    }
}


/*
 *  Prints graphic with dots
 */
void Calculator::print_function_graph() {

  ui->widget->graph(0)->data()->clear();

  x.clear();
  y.clear();

  QString text = calc_input;

  if (is_var_x_clicked) {
    std::string X = std::to_string(ui->expression_x_replace->value());

    std::string input_real_string = "";
    input_real_string = calc_input.toStdString();
    size_t pos = 0;
    for (;;) {
      pos = input_real_string.find("X", pos);
      if (pos == std::string::npos)
          break;
      input_real_string.replace(pos, 1, X);
      pos += X.size();
    }

    text = QString::fromStdString(input_real_string);
  }

  QByteArray graph_bit = text.toLocal8Bit();
  char *graph_str = graph_bit.data();
  double output;

  int min = ui->graph_min_x->value();
  int max = ui->graph_max_x->value();

//  НЕЛЬЗЯ ДЕЛАТЬ ГРАФИК ОТ НУЛЯ И ОТ ПУСТОЙ ФУНКЦИИ И ПРОСТО НАЖИМАТЬ НА КНОПКУ БИЛД


//  int error = input_validation(graph_str);
//  if (error == 1) {
//    ui->result->setText("Error");
//  } else {

    for (current_value = min; current_value <= max; current_value += 0.01) {
      x.push_back(current_value);
      output = create_function_graph(graph_str, current_value);
      y.push_back(output);
    }
//  }

    ui->widget->xAxis->setRange(min, max);
    ui->widget->yAxis->setRange(min, max);

    ui->widget->graph(0)->setPen(QColor(Qt::black));
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 1));
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();

    if (max || min) {
      ui->result->setText("Check Out Your Graph!");
    }
}


/*
 *  Prints function names
 */
void Calculator::print_function() {
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
      calc_input = calc_input + "a(";
      ui->input->setText(ui->input->text() + "atan(");
    } else {
      calc_input = "a(";
      ui->input->setText("atan(");
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
      calc_input = calc_input + + "n(";
      ui->input->setText(ui->input->text() + "ln(");
    } else {
      calc_input = "n(";
      ui->input->setText("ln(");
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
}








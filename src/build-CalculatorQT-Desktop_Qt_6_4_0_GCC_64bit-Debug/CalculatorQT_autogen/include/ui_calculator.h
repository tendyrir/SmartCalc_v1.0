/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralwidget;
    QLabel *input;
    QPushButton *button_num_7;
    QPushButton *button_num_8;
    QPushButton *button_num_9;
    QPushButton *button_num_4;
    QPushButton *button_num_5;
    QPushButton *button_num_6;
    QPushButton *button_num_1;
    QPushButton *button_num_2;
    QPushButton *button_num_3;
    QPushButton *button_num_0;
    QPushButton *button_op_sum;
    QPushButton *button_op_min;
    QPushButton *button_op_mul;
    QPushButton *button_op_div;
    QPushButton *button_op_exe;
    QPushButton *button_op_del;
    QPushButton *button_sign_dot;
    QPushButton *button_op_pow;
    QPushButton *button_sign_opb;
    QPushButton *button_sign_clb;
    QPushButton *button_op_mod;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName("Calculator");
        Calculator->resize(269, 207);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Calculator->sizePolicy().hasHeightForWidth());
        Calculator->setSizePolicy(sizePolicy);
        Calculator->setMinimumSize(QSize(269, 207));
        Calculator->setMaximumSize(QSize(269, 207));
        centralwidget = new QWidget(Calculator);
        centralwidget->setObjectName("centralwidget");
        input = new QLabel(centralwidget);
        input->setObjectName("input");
        input->setGeometry(QRect(10, 10, 251, 31));
        sizePolicy.setHeightForWidth(input->sizePolicy().hasHeightForWidth());
        input->setSizePolicy(sizePolicy);
        input->setAutoFillBackground(true);
        input->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        input->setMargin(5);
        button_num_7 = new QPushButton(centralwidget);
        button_num_7->setObjectName("button_num_7");
        button_num_7->setGeometry(QRect(10, 80, 51, 31));
        button_num_8 = new QPushButton(centralwidget);
        button_num_8->setObjectName("button_num_8");
        button_num_8->setGeometry(QRect(60, 80, 51, 31));
        button_num_9 = new QPushButton(centralwidget);
        button_num_9->setObjectName("button_num_9");
        button_num_9->setGeometry(QRect(110, 80, 51, 31));
        button_num_4 = new QPushButton(centralwidget);
        button_num_4->setObjectName("button_num_4");
        button_num_4->setGeometry(QRect(10, 110, 51, 31));
        button_num_5 = new QPushButton(centralwidget);
        button_num_5->setObjectName("button_num_5");
        button_num_5->setGeometry(QRect(60, 110, 51, 31));
        button_num_6 = new QPushButton(centralwidget);
        button_num_6->setObjectName("button_num_6");
        button_num_6->setGeometry(QRect(110, 110, 51, 31));
        button_num_1 = new QPushButton(centralwidget);
        button_num_1->setObjectName("button_num_1");
        button_num_1->setGeometry(QRect(10, 140, 51, 31));
        button_num_2 = new QPushButton(centralwidget);
        button_num_2->setObjectName("button_num_2");
        button_num_2->setGeometry(QRect(60, 140, 51, 31));
        button_num_3 = new QPushButton(centralwidget);
        button_num_3->setObjectName("button_num_3");
        button_num_3->setGeometry(QRect(110, 140, 51, 31));
        button_num_0 = new QPushButton(centralwidget);
        button_num_0->setObjectName("button_num_0");
        button_num_0->setGeometry(QRect(10, 170, 101, 31));
        button_op_sum = new QPushButton(centralwidget);
        button_op_sum->setObjectName("button_op_sum");
        button_op_sum->setGeometry(QRect(160, 140, 51, 31));
        button_op_min = new QPushButton(centralwidget);
        button_op_min->setObjectName("button_op_min");
        button_op_min->setGeometry(QRect(160, 170, 51, 31));
        button_op_mul = new QPushButton(centralwidget);
        button_op_mul->setObjectName("button_op_mul");
        button_op_mul->setGeometry(QRect(160, 80, 51, 31));
        button_op_div = new QPushButton(centralwidget);
        button_op_div->setObjectName("button_op_div");
        button_op_div->setGeometry(QRect(160, 110, 51, 31));
        button_op_exe = new QPushButton(centralwidget);
        button_op_exe->setObjectName("button_op_exe");
        button_op_exe->setGeometry(QRect(210, 110, 51, 91));
        button_op_del = new QPushButton(centralwidget);
        button_op_del->setObjectName("button_op_del");
        button_op_del->setGeometry(QRect(210, 50, 51, 61));
        button_sign_dot = new QPushButton(centralwidget);
        button_sign_dot->setObjectName("button_sign_dot");
        button_sign_dot->setGeometry(QRect(110, 170, 51, 31));
        button_op_pow = new QPushButton(centralwidget);
        button_op_pow->setObjectName("button_op_pow");
        button_op_pow->setGeometry(QRect(160, 50, 51, 31));
        button_sign_opb = new QPushButton(centralwidget);
        button_sign_opb->setObjectName("button_sign_opb");
        button_sign_opb->setGeometry(QRect(60, 50, 51, 31));
        button_sign_clb = new QPushButton(centralwidget);
        button_sign_clb->setObjectName("button_sign_clb");
        button_sign_clb->setGeometry(QRect(110, 50, 51, 31));
        button_op_mod = new QPushButton(centralwidget);
        button_op_mod->setObjectName("button_op_mod");
        button_op_mod->setGeometry(QRect(10, 50, 51, 31));
        Calculator->setCentralWidget(centralwidget);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "Calculator", nullptr));
        input->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        button_num_7->setText(QCoreApplication::translate("Calculator", "7", nullptr));
        button_num_8->setText(QCoreApplication::translate("Calculator", "8", nullptr));
        button_num_9->setText(QCoreApplication::translate("Calculator", "9", nullptr));
        button_num_4->setText(QCoreApplication::translate("Calculator", "4", nullptr));
        button_num_5->setText(QCoreApplication::translate("Calculator", "5", nullptr));
        button_num_6->setText(QCoreApplication::translate("Calculator", "6", nullptr));
        button_num_1->setText(QCoreApplication::translate("Calculator", "1", nullptr));
        button_num_2->setText(QCoreApplication::translate("Calculator", "2", nullptr));
        button_num_3->setText(QCoreApplication::translate("Calculator", "3", nullptr));
        button_num_0->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        button_op_sum->setText(QCoreApplication::translate("Calculator", "+", nullptr));
        button_op_min->setText(QCoreApplication::translate("Calculator", "-", nullptr));
        button_op_mul->setText(QCoreApplication::translate("Calculator", "*", nullptr));
        button_op_div->setText(QCoreApplication::translate("Calculator", "/", nullptr));
        button_op_exe->setText(QCoreApplication::translate("Calculator", "=", nullptr));
        button_op_del->setText(QCoreApplication::translate("Calculator", "AC", nullptr));
        button_sign_dot->setText(QCoreApplication::translate("Calculator", ".", nullptr));
        button_op_pow->setText(QCoreApplication::translate("Calculator", "^", nullptr));
        button_sign_opb->setText(QCoreApplication::translate("Calculator", "(", nullptr));
        button_sign_clb->setText(QCoreApplication::translate("Calculator", ")", nullptr));
        button_op_mod->setText(QCoreApplication::translate("Calculator", "mod", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H

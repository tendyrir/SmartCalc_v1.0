/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
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
#include "qcustomplot.h"

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
    QPushButton *button_op_sin;
    QPushButton *button_op_cos;
    QPushButton *button_op_tg;
    QPushButton *button_op_acos;
    QPushButton *button_op_asin;
    QPushButton *button_op_atan;
    QPushButton *button_op_ln;
    QPushButton *button_op_log;
    QPushButton *button_op_sqrt;
    QLabel *result;
    QCustomPlot *widget;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(502, 734);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Calculator->sizePolicy().hasHeightForWidth());
        Calculator->setSizePolicy(sizePolicy);
        Calculator->setMinimumSize(QSize(0, 0));
        Calculator->setMaximumSize(QSize(1000, 1000));
        centralwidget = new QWidget(Calculator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        input = new QLabel(centralwidget);
        input->setObjectName(QString::fromUtf8("input"));
        input->setGeometry(QRect(10, 10, 291, 31));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(input->sizePolicy().hasHeightForWidth());
        input->setSizePolicy(sizePolicy1);
        input->setAutoFillBackground(true);
        input->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        input->setMargin(5);
        button_num_7 = new QPushButton(centralwidget);
        button_num_7->setObjectName(QString::fromUtf8("button_num_7"));
        button_num_7->setGeometry(QRect(10, 80, 51, 31));
        button_num_8 = new QPushButton(centralwidget);
        button_num_8->setObjectName(QString::fromUtf8("button_num_8"));
        button_num_8->setGeometry(QRect(70, 80, 51, 31));
        button_num_9 = new QPushButton(centralwidget);
        button_num_9->setObjectName(QString::fromUtf8("button_num_9"));
        button_num_9->setGeometry(QRect(130, 80, 51, 31));
        button_num_4 = new QPushButton(centralwidget);
        button_num_4->setObjectName(QString::fromUtf8("button_num_4"));
        button_num_4->setGeometry(QRect(10, 110, 51, 31));
        button_num_5 = new QPushButton(centralwidget);
        button_num_5->setObjectName(QString::fromUtf8("button_num_5"));
        button_num_5->setGeometry(QRect(70, 110, 51, 31));
        button_num_6 = new QPushButton(centralwidget);
        button_num_6->setObjectName(QString::fromUtf8("button_num_6"));
        button_num_6->setGeometry(QRect(130, 110, 51, 31));
        button_num_1 = new QPushButton(centralwidget);
        button_num_1->setObjectName(QString::fromUtf8("button_num_1"));
        button_num_1->setGeometry(QRect(10, 140, 51, 31));
        button_num_2 = new QPushButton(centralwidget);
        button_num_2->setObjectName(QString::fromUtf8("button_num_2"));
        button_num_2->setGeometry(QRect(70, 140, 51, 31));
        button_num_3 = new QPushButton(centralwidget);
        button_num_3->setObjectName(QString::fromUtf8("button_num_3"));
        button_num_3->setGeometry(QRect(130, 140, 51, 31));
        button_num_0 = new QPushButton(centralwidget);
        button_num_0->setObjectName(QString::fromUtf8("button_num_0"));
        button_num_0->setGeometry(QRect(10, 170, 111, 31));
        button_op_sum = new QPushButton(centralwidget);
        button_op_sum->setObjectName(QString::fromUtf8("button_op_sum"));
        button_op_sum->setGeometry(QRect(190, 140, 51, 31));
        button_op_min = new QPushButton(centralwidget);
        button_op_min->setObjectName(QString::fromUtf8("button_op_min"));
        button_op_min->setGeometry(QRect(190, 170, 51, 31));
        QFont font;
        font.setKerning(true);
        button_op_min->setFont(font);
        button_op_mul = new QPushButton(centralwidget);
        button_op_mul->setObjectName(QString::fromUtf8("button_op_mul"));
        button_op_mul->setGeometry(QRect(190, 80, 51, 31));
        button_op_div = new QPushButton(centralwidget);
        button_op_div->setObjectName(QString::fromUtf8("button_op_div"));
        button_op_div->setGeometry(QRect(190, 110, 51, 31));
        button_op_exe = new QPushButton(centralwidget);
        button_op_exe->setObjectName(QString::fromUtf8("button_op_exe"));
        button_op_exe->setGeometry(QRect(250, 110, 51, 91));
        button_op_del = new QPushButton(centralwidget);
        button_op_del->setObjectName(QString::fromUtf8("button_op_del"));
        button_op_del->setGeometry(QRect(250, 50, 51, 61));
        button_sign_dot = new QPushButton(centralwidget);
        button_sign_dot->setObjectName(QString::fromUtf8("button_sign_dot"));
        button_sign_dot->setGeometry(QRect(130, 170, 51, 31));
        button_op_pow = new QPushButton(centralwidget);
        button_op_pow->setObjectName(QString::fromUtf8("button_op_pow"));
        button_op_pow->setGeometry(QRect(190, 50, 51, 31));
        button_sign_opb = new QPushButton(centralwidget);
        button_sign_opb->setObjectName(QString::fromUtf8("button_sign_opb"));
        button_sign_opb->setGeometry(QRect(70, 50, 51, 31));
        button_sign_clb = new QPushButton(centralwidget);
        button_sign_clb->setObjectName(QString::fromUtf8("button_sign_clb"));
        button_sign_clb->setGeometry(QRect(130, 50, 51, 31));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(button_sign_clb->sizePolicy().hasHeightForWidth());
        button_sign_clb->setSizePolicy(sizePolicy2);
        button_op_mod = new QPushButton(centralwidget);
        button_op_mod->setObjectName(QString::fromUtf8("button_op_mod"));
        button_op_mod->setGeometry(QRect(10, 50, 51, 31));
        button_op_sin = new QPushButton(centralwidget);
        button_op_sin->setObjectName(QString::fromUtf8("button_op_sin"));
        button_op_sin->setGeometry(QRect(310, 50, 51, 31));
        button_op_cos = new QPushButton(centralwidget);
        button_op_cos->setObjectName(QString::fromUtf8("button_op_cos"));
        button_op_cos->setGeometry(QRect(370, 50, 51, 31));
        button_op_tg = new QPushButton(centralwidget);
        button_op_tg->setObjectName(QString::fromUtf8("button_op_tg"));
        button_op_tg->setGeometry(QRect(430, 50, 51, 31));
        button_op_acos = new QPushButton(centralwidget);
        button_op_acos->setObjectName(QString::fromUtf8("button_op_acos"));
        button_op_acos->setGeometry(QRect(310, 80, 51, 31));
        button_op_asin = new QPushButton(centralwidget);
        button_op_asin->setObjectName(QString::fromUtf8("button_op_asin"));
        button_op_asin->setGeometry(QRect(370, 80, 51, 31));
        button_op_atan = new QPushButton(centralwidget);
        button_op_atan->setObjectName(QString::fromUtf8("button_op_atan"));
        button_op_atan->setGeometry(QRect(430, 80, 51, 31));
        button_op_ln = new QPushButton(centralwidget);
        button_op_ln->setObjectName(QString::fromUtf8("button_op_ln"));
        button_op_ln->setGeometry(QRect(310, 110, 51, 31));
        button_op_log = new QPushButton(centralwidget);
        button_op_log->setObjectName(QString::fromUtf8("button_op_log"));
        button_op_log->setGeometry(QRect(370, 110, 51, 31));
        button_op_sqrt = new QPushButton(centralwidget);
        button_op_sqrt->setObjectName(QString::fromUtf8("button_op_sqrt"));
        button_op_sqrt->setGeometry(QRect(430, 110, 51, 31));
        result = new QLabel(centralwidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(310, 10, 171, 31));
        sizePolicy1.setHeightForWidth(result->sizePolicy().hasHeightForWidth());
        result->setSizePolicy(sizePolicy1);
        result->setAutoFillBackground(true);
        result->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        result->setMargin(5);
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 210, 471, 501));
        widget->setAutoFillBackground(true);
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
        button_op_sin->setText(QCoreApplication::translate("Calculator", "sin", nullptr));
        button_op_cos->setText(QCoreApplication::translate("Calculator", "cos", nullptr));
        button_op_tg->setText(QCoreApplication::translate("Calculator", "tg", nullptr));
        button_op_acos->setText(QCoreApplication::translate("Calculator", "acos", nullptr));
        button_op_asin->setText(QCoreApplication::translate("Calculator", "asin", nullptr));
        button_op_atan->setText(QCoreApplication::translate("Calculator", "atan", nullptr));
        button_op_ln->setText(QCoreApplication::translate("Calculator", "ln", nullptr));
        button_op_log->setText(QCoreApplication::translate("Calculator", "log", nullptr));
        button_op_sqrt->setText(QCoreApplication::translate("Calculator", "sqrt", nullptr));
        result->setText(QCoreApplication::translate("Calculator", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H

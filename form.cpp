#include "form.h"
#include "ui_form.h"
#include "HQ.h"
#include <string>
using namespace std;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_Plus_clicked()
{
    QString Q_lhs = ui->textEdit1->toPlainText();
    QString Q_rhs = ui->textEdit2->toPlainText();
    string lhs = Q_lhs.toStdString();
    string rhs = Q_rhs.toStdString();
    string value = HQ_cal::Plus(lhs, rhs);
    QString Q_value = QString::fromStdString(value);
    ui->textEdit->setText(Q_value);
}

void Form::on_Minus_clicked()
{
    QString Q_lhs = ui->textEdit1->toPlainText();
    QString Q_rhs = ui->textEdit2->toPlainText();

    ui->textEdit->setText(Q_lhs);
    ui->textEdit->setText(Q_rhs);

    string lhs = Q_lhs.toStdString();
    string rhs = Q_rhs.toStdString();

    ui->textEdit->setText(QString::fromStdString(lhs));
    ui->textEdit->setText(QString::fromStdString(rhs));

    string value = HQ_cal::Minus(lhs, rhs);
    QString Q_value = QString::fromStdString(value);
    ui->textEdit->setText(Q_value);
}

void Form::on_Times_clicked()
{
    QString Q_lhs = ui->textEdit1->toPlainText();
    QString Q_rhs = ui->textEdit2->toPlainText();
    string lhs = Q_lhs.toStdString();
    string rhs = Q_rhs.toStdString();
    string value = HQ_cal::Times(lhs, rhs);
    QString Q_value = QString::fromStdString(value);
    ui->textEdit->setText(Q_value);
}

void Form::on_Divide_clicked()
{
    QString Q_lhs = ui->textEdit1->toPlainText();
    QString Q_rhs = ui->textEdit2->toPlainText();
    string lhs = Q_lhs.toStdString();
    string rhs = Q_rhs.toStdString();
    string value_remain = HQ_cal::Divide(lhs, rhs).remain;
    string value_quotion = HQ_cal::Divide(lhs, rhs).quotion;
    QString Q_value_quotion = QString::fromStdString("remain is " + value_remain);
    QString Q_value_remain = QString::fromStdString("quotion is " + value_quotion);
    ui->textEdit->setText(Q_value_remain + '\n');
    ui->textEdit->setText(Q_value_quotion);
}

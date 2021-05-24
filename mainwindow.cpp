#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include "in.h"
#include "reversepolish.h"
#include "register.h"
#include "form.h"

std::string UserText;
std::string UserShowText;
vector<int> Count;

class In In;
class OperatorFactory OperatorFactory;
class MRegister MRegister;
map<string, class Operator&> OperatorFactory::ms_register;

class Plus Plus;
class Minus Minus;
class Times Times;
class Divide Divide;
class Mod Mod;
class Pow Pow;
class Exp Exp;

class Sin Sin;
class Cos Cos;
class Tan Tan;
class Sinh Sinh;
class Cosh Cosh;
class Tanh Tanh;
class Factorial Factorial;
class Square Square;
class Sqrt Sqrt;
class Power10 Power10;
class Negate Negate;
class Reciprocal Reciprocal;
class Ln Ln;
class Abs Abs;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_twond_clicked()
{
    static int flag = 1;
    switch(flag) {
        case 1:
            ui->Sin->setText("sinh");
            ui->Cos->setText("cosh");
            ui->Tan->setText("tanh");
            flag = 0;
        break;
        case 0:
            ui->Sin->setText("sin");
            ui->Cos->setText("cos");
            ui->Tan->setText("tan");
            flag = 1;
        break;
    }
}

void MainWindow::on_Square_clicked()
{
    UserText += "Q";
    UserShowText += "^2";
    Count.push_back(2);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_Sqrt_clicked()
{
    UserText += "q";
    UserShowText += "sqrt";
    Count.push_back(4);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_Pow_clicked()
{
    UserText += "^";
    UserShowText += "^";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_TenPow_clicked()
{
    UserText += "p";
    UserShowText += "10^";
    Count.push_back(3);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_Abs_clicked()
{
    UserText += "|";
    UserShowText += "abs";
    Count.push_back(3);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_Fractorial_clicked()
{
    UserText += "!";
    UserShowText += "!";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_Pi_clicked()
{
    UserText += "3.141592653";
    UserShowText += "pi";
    Count.push_back(2);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_reciprocal_clicked()
{
    UserText += "r";
    UserShowText += "1/";
    Count.push_back(2);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_leftparenthsis_clicked()
{
    UserText += "(";
    UserShowText += "(";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_rightparenthsis_clicked()
{
    UserText += ")";
    UserShowText += ")";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_Ln_clicked()
{
    UserText += "l";
    UserShowText += "ln";
    Count.push_back(2);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_Exp_clicked()
{
    UserText += "e";
    UserShowText += "exp";
    Count.push_back(3);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_Mod_clicked()
{
    UserText += "%";
    UserShowText += "%";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_Divide_clicked()
{
    UserText += "/";
    UserShowText += "/";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_Times_clicked()
{
    UserText += "*";
    UserShowText += "*";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_Minus_clicked()
{
    UserText += "-";
    UserShowText += "-";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_Plus_clicked()
{
    UserText += "+";
    UserShowText += "+";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_Sin_clicked()
{
    if (ui->Sin->text() == "sin") {
        UserText += "s";
        UserShowText += "sin";
        Count.push_back(3);
        ui->lineEdit->setText(QString::fromStdString(UserShowText));
    } else if (ui->Sin->text() == "sinh") {
        UserText += "S";
        UserShowText += "sinh";
        Count.push_back(4);
        ui->lineEdit->setText(QString::fromStdString(UserShowText));
    }
}

void MainWindow::on_Cos_clicked()
{
    if (ui->Cos->text() == "cos") {
        UserText += "c";
        UserShowText += "cos";
        Count.push_back(3);
        ui->lineEdit->setText(QString::fromStdString(UserShowText));
    } else if (ui->Cos->text() == "cosh") {
        UserText += "C";
        UserShowText += "cosh";
        Count.push_back(4);
        ui->lineEdit->setText(QString::fromStdString(UserShowText));
    }
}

void MainWindow::on_Tan_clicked()
{
    if (ui->Tan->text() == "tan") {
        UserText += "t";
        UserShowText += "tan";
        Count.push_back(3);
        ui->lineEdit->setText(QString::fromStdString(UserShowText));
    } else if (ui->Tan->text() == "tanh") {
        UserText += "T";
        UserShowText += "tanh";
        Count.push_back(4);
        ui->lineEdit->setText(QString::fromStdString(UserShowText));
    }
}

void MainWindow::on_negate_clicked()
{
    UserText += "n";
    UserShowText += "+/-";
    Count.push_back(3);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_equal_clicked()
{
    static int OperatorInitFlag = 0;
    if(!OperatorInitFlag) {
        OperatorInit(OperatorFactory);
    }
    try {
        if(UserText.empty())
            throw 1;
        In.Init(UserText);
        //    for(auto q = In.GetVec().begin(); q != In.GetVec().end(); ++q) {
        //        ui->lineEdit->append(QString::fromStdString(*q));
        //    }
        //    ui->lineEdit->append(" ");

        queue<string> target = RPInit(In.GetVec());
        //    while (!target.empty()) {
        //        ui->lineEdit->append(QString::fromStdString(target.front()));
        //        target.pop();
        //    }
        //    ui->lineEdit->append(" ");

        double value = RPCalculate(target);

        string t = to_string(value);
        ui->lineEdit->setText(QString::fromStdString(t));

        UserText.clear();
        UserShowText.clear();
        Count.clear();
        In.GetVec().clear();

        UserShowText += t;
        UserText += t;
        Count.push_back(t.length());
    } catch (...) {
        ui->lineEdit->setText("ERROR!");
        UserText.clear();
        UserShowText.clear();
        In.GetVec().clear();
    }
}

void MainWindow::on_zero_clicked()
{
    UserText += "0";
    UserShowText += "0";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_one_clicked()
{
    UserText += "1";
    UserShowText += "1";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_two_clicked()
{
    UserText += "2";
    UserShowText += "2";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_three_clicked()
{
    UserText += "3";
    UserShowText += "3";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_four_clicked()
{
    UserText += "4";
    UserShowText += "4";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_five_clicked()
{
    UserText += "5";
    UserShowText += "5";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_six_clicked()
{
    UserText += "6";
    UserShowText += "6";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_seven_clicked()
{
    UserText += "7";
    UserShowText += "7";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_eight_clicked()
{
    UserText += "8";
    UserShowText += "8";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_nine_clicked()
{
    UserText += "9";
    UserShowText += "9";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_point_clicked()
{
    UserText += ".";
    UserShowText += ".";
    Count.push_back(1);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_clean_clicked()
{
    if(!Count.empty()){
        if(IsNum(*(UserText.end()-1))) {
            for (int q = 0; q < *(Count.end()-1); ++q){
                if(!UserShowText.empty() && !UserText.empty()){
                    UserShowText.pop_back();
                    UserText.pop_back();
                }
            }
        }else {
            for (int q = 0; q < *(Count.end()-1); ++q){
                if(!UserShowText.empty() && !UserText.empty()){
                    UserShowText.pop_back();
                }
                UserText.pop_back();
            }
        }
        Count.pop_back();
    }
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_MS_clicked()
{
    if(!UserText.empty()){
        In.Init(UserText);
        if (!In.GetVec().empty()){
            if (IsNum(*((In.GetVec().end()-1)->end()-1))) {
                MRegister.MS();
            } else {
                ui->lineEdit->setText("ERROR!");
            }
        }
    }
    In.GetVec().clear();
}

void MainWindow::on_Mminus_clicked()
{
    if(!UserText.empty()){
        In.Init(UserText);
        if (!In.GetVec().empty()){
            if (IsNum(*((In.GetVec().end()-1)->end()-1))) {
                MRegister.MMinus();
            } else {
                ui->lineEdit->setText("ERROR!");
            }
        }
    }
    In.GetVec().clear();
}

void MainWindow::on_Mplus_clicked()
{
    if(!UserText.empty()){
        In.Init(UserText);
        if (!In.GetVec().empty()){
            if (IsNum(*((In.GetVec().end()-1)->end()-1))) {
                MRegister.MPlus();
            } else {
                ui->lineEdit->setText("ERROR!");
            }
        }
    }
    In.GetVec().clear();
}

void MainWindow::on_MR_clicked()
{
    double value = MRegister.MR();

    int t = value;
    int size = 0;
    while (t/10 != 0) {
        ++size;
        t /= 10;
    }
    size += 8;
    Count.push_back(size);

    UserText += to_string(value);
    UserShowText += to_string(value);
    ui->lineEdit->setText(QString::fromStdString(UserShowText));
}

void MainWindow::on_MC_clicked()
{
    MRegister.MC();
    //Count.pop_back();
}

void MainWindow::on_HQ_clicked()
{
    Form* new_window = new Form();
    new_window->show();
}

void MainWindow::on_pushButton_clicked()
{
    system("terminator -x bash -c '/home/ranewouters/CAL/demo'");
//    system("terminator");
}

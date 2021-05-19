#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_twond_clicked();

    void on_Square_clicked();

    void on_Sqrt_clicked();

    void on_Pow_clicked();

    void on_TenPow_clicked();

    void on_Abs_clicked();

    void on_Fractorial_clicked();

    void on_Pi_clicked();

    void on_reciprocal_clicked();

    void on_leftparenthsis_clicked();

    void on_rightparenthsis_clicked();

    void on_Ln_clicked();

    void on_Exp_clicked();

    void on_Mod_clicked();

    void on_Divide_clicked();

    void on_Times_clicked();

    void on_Minus_clicked();

    void on_Plus_clicked();

    void on_Sin_clicked();

    void on_Cos_clicked();

    void on_Tan_clicked();

    void on_negate_clicked();

    void on_equal_clicked();

    void on_zero_clicked();

    void on_one_clicked();

    void on_two_clicked();

    void on_three_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_point_clicked();

    void on_clean_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

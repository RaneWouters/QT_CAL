#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_Plus_clicked();

    void on_Minus_clicked();

    void on_Times_clicked();

    void on_Divide_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H

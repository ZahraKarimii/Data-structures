#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>

#include "profile.h"

namespace Ui {
class signup;
}

class signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_pushButtonSignup_clicked();

private:
    Ui::signup *ui;
    profile *Profile;
};

#endif // SIGNUP_H

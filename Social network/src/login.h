#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

#include "signup.h"
#include "profile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButtonSignup_clicked();

    void on_pushButtonLogin_clicked();

private:
    Ui::login *ui;
    signup *signUp;
    profile *Profile;
};
#endif // LOGIN_H

#include "signup.h"
#include "ui_signup.h"
#include "user.h"
#include <QMessageBox>

signup::signup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButtonSignup_clicked()
{
    User user;
    userInformation userInfo;
    QString name = ui->lineEditName->text();
    QString lastname = ui->lineEditLastname->text();
    QString age = ui->lineEditAge->text();
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    if (userInfo.readSignup(username) == false)
    {
        user.name = name;
        user.lastname = lastname;
        user.age = age;
        user.username = username;
        user.password = password;
        userInfo.users.push_back(user);
        userInfo.writeUser();
        userInfo.writeUsername(username);
        hide();
        Profile = new profile(this);
        Profile->show();
    }
    else
    {
        QMessageBox::warning(this, "Sign Up", "This Username Already Exists!");
    }
}

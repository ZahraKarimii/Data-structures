#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "user.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_pushButtonSignup_clicked()
{
    hide();
    signUp = new signup(this);
    signUp->show();
}

void login::on_pushButtonLogin_clicked()
{
    userInformation userInfo;
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    if (userInfo.readLogin(username, password) == true)
    {
        userInfo.writeUsername(username);
        hide();
        Profile = new profile(this);
        Profile->show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username And Password Is Not Correct!");
    }
}

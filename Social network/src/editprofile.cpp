#include "editprofile.h"
#include "ui_editprofile.h"
#include <QMessageBox>
#include "profile.h"
#include "user.h"

editProfile::editProfile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editProfile)
{
    ui->setupUi(this);
}

editProfile::~editProfile()
{
    delete ui;
}

void editProfile::on_pushButtonSignup_clicked()
{
    userInformation userInfo;
    QString username = userInfo.readUsername();
    QString oldName = ui->lineEditName->text();
    QString oldLastname = ui->lineEditLastname->text();
    QString oldAge = ui->lineEditAge->text();
    QString oldPassword = ui->lineEditPassword->text();
    QString newName = ui->lineEditName_2->text();
    QString newLastname = ui->lineEditLastname_2->text();
    QString newAge = ui->lineEditAge_2->text();
    QString newPassword = ui->lineEditPassword_2->text();
    if (userInfo.readName(username, oldName) == true)
    {
        userInfo.changeName(newName, username);
    }
    else
    {
        QMessageBox::warning(this, "Edit Profile", "Your Information Is Not Correct!");
    }
    if (userInfo.readlastName(username, oldLastname) == true)
    {
        userInfo.changeLastanem(newLastname, username);
    }
    else
    {
        QMessageBox::warning(this, "Edit Profile", "Your Information Is Not Correct!");
    }
    if (userInfo.readAge(username, oldAge) == true)
    {
        userInfo.changeAge(newAge, username);
    }
    else
    {
        QMessageBox::warning(this, "Edit Profile", "Your Information Is Not Correct!");
    }
    if (userInfo.readPassword(username, oldPassword) == true)
    {
        userInfo.changePassword(newPassword, username);
    }
    else
    {
        QMessageBox::warning(this, "Edit Profile", "Your Information Is Not Correct!");
    }
}

void editProfile::on_pushButtonBack_clicked()
{
    profile *Profile= new profile;
    Profile->show();
    hide();
}

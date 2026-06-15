#include "profile.h"
#include "ui_profile.h"
#include <QMessageBox>
#include <QWidget>
#include <QInputDialog>
#include "userPosts.h"
#include "userFollowers.h"
#include "signup.h"
#include "suggest.h"

QMessageBox::StandardButton reply;

profile::profile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::profile)
{
    ui->setupUi(this);
}

profile::~profile()
{
    delete ui;
}

void profile::showEvent(QShowEvent *event)
{
    userInformation userInfo;
    QWidget::showEvent(event);
    ui->lineEditUsername->setText(userInfo.readUsername());
}

void profile::on_pushButtonPosts_clicked()
{
    reply = QMessageBox::question(this, "Posts", "Do You Want To Creat A New Post?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        hide();
        CreatPost = new creatPost(this);
        CreatPost->show();
    }
    else
    {
        reply = QMessageBox::question(this, "Posts", "Do You Want To Watch Your Post?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            hide();
            ShowPosts = new showPosts(this);
            ShowPosts->show();
        }
    }
}

void profile::on_pushButtonFollowers_clicked()
{
    hide();
    ShowFriends = new showFriends(this);
    ShowFriends->show();
}

void profile::on_pushButtonFollowing_clicked()
{
    hide();
    ShowFriends = new showFriends(this);
    ShowFriends->show();
}

void profile::on_pushButtonEditProfile_clicked()
{
    hide();
    EditProfile = new editProfile(this);
    EditProfile->show();
}

void profile::on_pushButtonEditDelete_clicked()
{
    userInformation userinfo;
    QString username = userinfo.readUsername();
    post posts;
    friends Friends;
    userinfo.deleteUser(username);
    userinfo.deleteUser2(username);
    posts.deleteUser(username);
    Friends.deleteUser(username);
    hide();
    signup *signUp = new signup();
    signUp->show();
}

void profile::on_pushButtonSearch_clicked()
{
    userInformation userinfo;
    bool ok;
    QString username = QInputDialog::getText(nullptr, "Search", "Enter Username:", QLineEdit::Normal, "", &ok);
    if (userinfo.readUsername() != username)
    {
        if (userinfo.searchUsername(username) == true)
        {
            userInformation::globalUsername = username;
            hide();
            ShowUsersProfile = new showUsersProfile(this);
            ShowUsersProfile->show();
        }
        else
        {
            QMessageBox::warning(this, "Search", "User Not Found!");
        }
    }
    else
    {
        QMessageBox::warning(this, "Search", "You Can Not Search Your Username!");
    }
}

void profile::on_pushButtonSuggest_clicked()
{
    hide();
    suggest *Suggest = new suggest();
    Suggest->show();
}

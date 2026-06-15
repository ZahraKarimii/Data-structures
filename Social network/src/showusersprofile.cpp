#include "showusersprofile.h"
#include "ui_showusersprofile.h"
#include "userFollowers.h"
#include "profile.h"
#include "showfriendsposts.h"
#include "showfriendsfriends.h"
#include <QMessageBox>

QString userInformation::globalUsername;

showUsersProfile::showUsersProfile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::showUsersProfile)
{
    ui->setupUi(this);
}

showUsersProfile::~showUsersProfile()
{
    delete ui;
}

void showUsersProfile::showEvent(QShowEvent *event)
{
    userInformation userInfo;
    QWidget::showEvent(event);
    ui->lineEditUsername->setText(userInformation::globalUsername);
}

void showUsersProfile::on_pushButtonPosts_clicked()
{
    QString username = userInformation::globalUsername;
    friends Friends;
    if (Friends.readFriends(username).contains(username))
    {
        hide();
        showFriendsPosts *ShowFriendsPosts = new showFriendsPosts();
        ShowFriendsPosts->show();
    }
    else
    {
        QMessageBox::information(this, "Posts", "You Do Not Follow This Page!");
    }
}
void showUsersProfile::on_pushButtonFollow_clicked()
{
    userInformation userInfo;
    userFriends UserFriends;
    friends Friends;
    UserFriends.username = userInfo.readUsername();
    UserFriends.friendsUsername = userInformation::globalUsername;
    Friends.friends.push_back(UserFriends);
    UserFriends.username = userInformation::globalUsername;
    UserFriends.friendsUsername = userInfo.readUsername();
    Friends.friends.push_back(UserFriends);
    Friends.writeFriends();
}

void showUsersProfile::on_pushButtonBack_clicked()
{
    profile *Profile= new profile;
    Profile->show();
    hide();
}

void showUsersProfile::on_pushButtonFollowers_clicked()
{
    QString username = userInformation::globalUsername;
    friends Friends;
    if (Friends.readFriends(username).contains(username))
    {
        hide();
        showFriendsFriends *ShowFriendsFriends = new showFriendsFriends();
        ShowFriendsFriends->show();
    }
    else
    {
        QMessageBox::information(this, "Posts", "You Do Not Follow This Page!");
    }
}

void showUsersProfile::on_pushButtonFollowing_clicked()
{
    QString username = userInformation::globalUsername;
    friends Friends;
    if (Friends.readFriends(username).contains(username))
    {
        hide();
        showFriendsFriends *ShowFriendsFriends = new showFriendsFriends();
        ShowFriendsFriends->show();
    }
    else
    {
        QMessageBox::information(this, "Posts", "You Do Not Follow This Page!");
    }
}

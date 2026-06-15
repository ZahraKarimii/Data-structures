#include "showfriendsfriends.h"
#include "ui_showfriendsfriends.h"
#include "showusersprofile.h"
#include "profile.h"
#include "userFollowers.h"

showFriendsFriends::showFriendsFriends(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::showFriendsFriends)
{
    ui->setupUi(this);
}

showFriendsFriends::~showFriendsFriends()
{
    delete ui;
}

void showFriendsFriends::on_pushButtonBack_clicked()
{
    hide();
    showUsersProfile *ShowUsersProfile = new showUsersProfile();
    ShowUsersProfile->show();
}

void showFriendsFriends::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    userInformation userInfo;
    friends Friends;
    QString username = userInformation::globalUsername;
    QMap<QString, QList<QString>> usersFriends = Friends.readFriends(username);
    if (usersFriends.contains(username))
    {
        QList<QString> friends = usersFriends[username];
        QString result = friends.join("\n");
        ui->textEditShowFriends->setText(result);
    }
}

#include "showfriends.h"
#include "ui_showfriends.h"
#include "profile.h"
#include "userFollowers.h"

showFriends::showFriends(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::showFriends)
{
    ui->setupUi(this);
}

showFriends::~showFriends()
{
    delete ui;
}
void showFriends::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    userInformation userInfo;
    friends Friends;
    QString username = userInfo.readUsername();
    QMap<QString, QList<QString>> usersFriends = Friends.readFriends(username);
    if (usersFriends.contains(username))
    {
        QList<QString> friends = usersFriends[username];
        QString result = friends.join("\n");
        ui->textEditShowFriends->setText(result);
    }
}
void showFriends::on_pushButtonBack_clicked()
{
    profile *Profile= new profile;
    Profile->show();
    hide();
}

#include "showfriendsposts.h"
#include "ui_showfriendsposts.h"
#include "userPosts.h"
#include "showusersprofile.h"
#include "showfriendsposts.h"
#include "user.h"

showFriendsPosts::showFriendsPosts(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::showFriendsPosts)
{
    ui->setupUi(this);
}

showFriendsPosts::~showFriendsPosts()
{
    delete ui;
}
void showFriendsPosts::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    userInformation userInfo;
    post Post;
    QString username = userInformation::globalUsername;
    QMap<QString, QList<QString>> usersPosts = Post.readPost(username);
    if (usersPosts.contains(username))
    {
        QList<QString> posts = usersPosts[username];
        QString result = posts.join("\n");
        ui->textEditShowPost->setText(result);
    }
}
void showFriendsPosts::on_pushButtonBack_clicked()
{
    hide();
    showUsersProfile *ShowUsersProfile = new showUsersProfile();
    ShowUsersProfile->show();
}

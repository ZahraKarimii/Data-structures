#include "showposts.h"
#include "ui_showposts.h"
#include <QMap>
#include <QList>
#include "userPosts.h"
#include <QListWidget>
#include <QString>
#include "profile.h"
#include "user.h"
#include <QMessageBox>

showPosts::showPosts(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::showPosts)
{
    ui->setupUi(this);
}

showPosts::~showPosts()
{
    delete ui;
}

void showPosts::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    userInformation userInfo;
    post Post;
    QString username = userInfo.readUsername();
    QMap<QString, QList<QString>> usersPosts = Post.readPost(username);
    if (usersPosts.contains(username))
    {
        QList<QString> posts = usersPosts[username];
        QString result = posts.join("\n");
        ui->textEditShowPost->setText(result);
    }
}
void showPosts::on_pushButtonBack_clicked()
{
    profile *Profile= new profile;
    Profile->show();
    hide();
}


void showPosts::on_pushButtonedit_clicked()
{
    userInformation userInfo;
    post Post;
    QString username = userInfo.readUsername();
    Post.deletePost(username);
    Post.writeForEdit(ui->textEditShowPost->toPlainText().split("\n"), username);
}

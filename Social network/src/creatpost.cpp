#include "creatpost.h"
#include "ui_creatpost.h"
#include "profile.h"
#include "userPosts.h"
#include "user.h"

creatPost::creatPost(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::creatPost)
{
    ui->setupUi(this);
}

creatPost::~creatPost()
{
    delete ui;
}

void creatPost::on_pushButtonBack_clicked()
{
    profile *Profile= new profile;
    Profile->show();
    hide();
}

void creatPost::on_pushButtonSend_clicked()
{
    userInformation userInfo;
    userPost UserPost;
    post Post;
    UserPost.username = userInfo.readUsername();
    UserPost.post = ui->lineEditWritePost->text();
    Post.posts.push_back(UserPost);
    Post.writePost();
}

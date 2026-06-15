#ifndef PROFILE_H
#define PROFILE_H

#include <QMainWindow>

#include "creatpost.h"
#include "showposts.h"
#include "showfriends.h"
#include "editprofile.h"
#include "showusersprofile.h"

namespace Ui {
class profile;
}

class profile : public QMainWindow
{
    Q_OBJECT

public:
    explicit profile(QWidget *parent = nullptr);
    ~profile();
protected:
    void showEvent(QShowEvent *event) override;
private slots:
    void on_pushButtonPosts_clicked();

    void on_pushButtonFollowers_clicked();

    void on_pushButtonFollowing_clicked();

    void on_pushButtonEditProfile_clicked();

    void on_pushButtonEditDelete_clicked();

    void on_pushButtonSearch_clicked();

    void on_pushButtonSuggest_clicked();

private:
    Ui::profile *ui;
    creatPost *CreatPost;
    showPosts *ShowPosts;
    showFriends *ShowFriends;
    editProfile *EditProfile;
    showUsersProfile *ShowUsersProfile;
};

#endif // PROFILE_H

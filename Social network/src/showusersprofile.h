#ifndef SHOWUSERSPROFILE_H
#define SHOWUSERSPROFILE_H

#include <QMainWindow>

namespace Ui {
class showUsersProfile;
}

class showUsersProfile : public QMainWindow
{
    Q_OBJECT

public:
    explicit showUsersProfile(QWidget *parent = nullptr);
    ~showUsersProfile();
protected:
    void showEvent(QShowEvent *event) override;
private slots:
    void on_pushButtonPosts_clicked();

    void on_pushButtonFollow_clicked();

    void on_pushButtonBack_clicked();

    void on_pushButtonFollowers_clicked();

    void on_pushButtonFollowing_clicked();

private:
    Ui::showUsersProfile *ui;
};

#endif // SHOWUSERSPROFILE_H

#ifndef SHOWFRIENDSFRIENDS_H
#define SHOWFRIENDSFRIENDS_H

#include <QMainWindow>

namespace Ui {
class showFriendsFriends;
}

class showFriendsFriends : public QMainWindow
{
    Q_OBJECT

public:
    explicit showFriendsFriends(QWidget *parent = nullptr);
    ~showFriendsFriends();
protected:
    void showEvent(QShowEvent *event) override;
private slots:
    void on_pushButtonBack_clicked();
private:
    Ui::showFriendsFriends *ui;
};

#endif // SHOWFRIENDSFRIENDS_H

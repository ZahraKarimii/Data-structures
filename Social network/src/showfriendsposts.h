#ifndef SHOWFRIENDSPOSTS_H
#define SHOWFRIENDSPOSTS_H

#include <QMainWindow>

namespace Ui {
class showFriendsPosts;
}

class showFriendsPosts : public QMainWindow
{
    Q_OBJECT

public:
    explicit showFriendsPosts(QWidget *parent = nullptr);
    ~showFriendsPosts();
private slots:
    void on_pushButtonBack_clicked();
private:
    Ui::showFriendsPosts *ui;
protected:
    void showEvent(QShowEvent *event) override;
};


#endif // SHOWFRIENDSPOSTS_H

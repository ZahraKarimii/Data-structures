#ifndef SHOWFRIENDS_H
#define SHOWFRIENDS_H

#include <QMainWindow>

namespace Ui {
class showFriends;
}

class showFriends : public QMainWindow
{
    Q_OBJECT

public:
    explicit showFriends(QWidget *parent = nullptr);
    ~showFriends();
protected:
    void showEvent(QShowEvent *event) override;
private slots:
    void on_pushButtonBack_clicked();

private:
    Ui::showFriends *ui;
};

#endif // SHOWFRIENDS_H

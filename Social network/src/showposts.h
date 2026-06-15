#ifndef SHOWPOSTS_H
#define SHOWPOSTS_H

#include <QMainWindow>

namespace Ui {
class showPosts;
}

class showPosts : public QMainWindow
{
    Q_OBJECT

public:
    explicit showPosts(QWidget *parent = nullptr);
    ~showPosts();
protected:
    void showEvent(QShowEvent *event) override;
private slots:


    void on_pushButtonBack_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonedit_clicked();

private:
    Ui::showPosts *ui;
};

#endif // SHOWPOSTS_H

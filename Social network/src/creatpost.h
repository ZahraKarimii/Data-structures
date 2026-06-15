#ifndef CREATPOST_H
#define CREATPOST_H

#include <QMainWindow>

namespace Ui {
class creatPost;
}

class creatPost : public QMainWindow
{
    Q_OBJECT

public:
    explicit creatPost(QWidget *parent = nullptr);
    ~creatPost();

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonSend_clicked();

private:
    Ui::creatPost *ui;
};

#endif // CREATPOST_H

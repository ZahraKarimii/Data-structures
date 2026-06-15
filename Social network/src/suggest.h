#ifndef SUGGEST_H
#define SUGGEST_H

#include <QMainWindow>
#include "profile.h"

namespace Ui {
class suggest;
}

class suggest : public QMainWindow
{
    Q_OBJECT

public:
    explicit suggest(QWidget *parent = nullptr);
    ~suggest();
protected:
    void showEvent(QShowEvent *event) override;
private slots:
    void on_pushButtonBack_clicked();

private:
    Ui::suggest *ui;
    profile *Profile;
};

#endif // SUGGEST_H

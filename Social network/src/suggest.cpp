#include "suggest.h"
#include "ui_suggest.h"
#include "userFollowers.h"

suggest::suggest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::suggest)
{
    ui->setupUi(this);
}

suggest::~suggest()
{
    delete ui;
}

void suggest::on_pushButtonBack_clicked()
{
    hide();
    Profile = new profile(this);
    Profile->show();
}
void suggest::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    userInformation userInfo;
    friends Friends;
    QList<QString> suggest = Friends.suggestion(userInfo.readUsername());
    QString result = suggest.join("\n");
    ui->textEditShowSuggest->setText(result);
}

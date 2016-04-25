#include "helpdialog.h"
#include "ui_helpdialog.h"
#include "../config/directives.h"

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);
    ui->buildLabel->setText(App::Version);
}

HelpDialog::~HelpDialog()
{
    delete ui;
}

///Imported Headers
//HelpDialog
#include "helpdialog.h"
//Directives
#include "../config/directives.h"

///GUI Headers
//HelpDialog
#include "ui_helpdialog.h"

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

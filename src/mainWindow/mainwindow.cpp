#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createNewNotepadTab();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    on_MainWindow_destroyed();
}

void MainWindow::on_actionAbout_triggered()
{
    h.exec();
}

void MainWindow::on_MainWindow_destroyed()
{
    QApplication::quit();
}

void MainWindow::on_actionChange_Font_triggered()
{
    bool ok;
    QFont customFont = QFontDialog::getFont(&ok, this);
    if(ok)
    {
        selectCurrentNotepadTextEditor()->setFont(customFont);
    }
}

void MainWindow::on_actionSet_Default_triggered()
{

}

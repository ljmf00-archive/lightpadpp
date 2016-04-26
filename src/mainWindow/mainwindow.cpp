#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../helpDialog/helpdialog.h"

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
    exit(0);
}

void MainWindow::on_actionAbout_triggered()
{
    HelpDialog h;
    h.exec();
}

void MainWindow::on_actionUndo_triggered()
{
    selectCurrentNotepadTextEditor()->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    selectCurrentNotepadTextEditor()->redo();
}

void MainWindow::on_actionSelect_All_triggered()
{
    selectCurrentNotepadTextEditor()->selectAll();
}

void MainWindow::on_actionOpen_File_triggered()
{
    openFileToNotepadTab();
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    destroyNotepadTab(index);
}

void MainWindow::on_actionNew_triggered()
{
    createNewNotepadTab();
}

void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_actionSave_As_triggered()
{
    saveFileFromNotepadTab();
}

void MainWindow::on_actionSave_All_triggered()
{

}

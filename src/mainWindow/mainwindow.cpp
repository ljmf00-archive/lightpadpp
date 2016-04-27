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
    saveFileAsFromNotepadTab();
}

void MainWindow::on_actionSave_All_triggered()
{

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

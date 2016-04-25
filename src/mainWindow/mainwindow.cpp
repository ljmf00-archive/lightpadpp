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
    NotepadEditor[NotepadTabNumber]->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    NotepadEditor[NotepadTabNumber]->redo();
}

void MainWindow::on_actionSelect_All_triggered()
{
    NotepadEditor[NotepadTabNumber]->selectAll();
}

void MainWindow::on_actionOpen_File_triggered()
{
    if(OpenFilePath.isNull())
    {
        OpenFilePath = "/home/";
    }
    OpenFileName = QFileDialog::getOpenFileName(this, tr("Open File"),OpenFilePath,tr("All (*.*)"));
    if(!OpenFilePath.isNull())
    {
        OpenFilePath = QFileInfo(OpenFileName).path();
    }
    QFile file(OpenFileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "Error", file.errorString());
    }
    else
    {
        createNotepadTab(QFileInfo(OpenFileName).fileName());
    }
    QTextEdit* tempEditor = NULL;
    QWidget* tempWidget = ui->tabWidget->widget(ui->tabWidget->currentIndex());
    tempEditor = (QTextEdit*)tempWidget;
    tempEditor->setText(file.readAll());
    file.close();
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    destroyNotepadTab(index);
}

void MainWindow::on_actionNew_triggered()
{
    createNewNotepadTab();
}

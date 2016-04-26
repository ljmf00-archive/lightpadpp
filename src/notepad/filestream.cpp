#include "../mainWindow/mainwindow.h"
#include "ui_mainwindow.h"
#include "../config/directives.h"

void MainWindow::openFileToNotepadTab()
{

    if(OpenFilePath.isNull())
    {
        OpenFilePath = App::DefaultPath;
    }
    if(!OpenFilePath.isNull())
    {
        OpenFilePath = QFileInfo(OpenFileName).path();
    }
    OpenFileName = QFileDialog::getOpenFileName(this, tr("Open File"),OpenFilePath);
    //if(OpenFileName.isNull())
    QFile file(OpenFileName);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "Error", file.errorString());
    }
    else
    {
        createNotepadTab(QFileInfo(OpenFileName).fileName());
    }
    selectCurrentNotepadTextEditor()->setText(file.readAll());
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), QFileInfo(OpenFileName).fileName());
    file.close();
}

void MainWindow::saveFileFromNotepadTab()
{
    if(SaveFilePath.isNull())
    {
        SaveFilePath = App::DefaultPath;
    }
    SaveFileName = QFileDialog::getSaveFileName(this, tr("Save File"), SaveFilePath);
    //if(SaveFileName.isNull())
    QFile file(SaveFileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(0, "Error", file.errorString());
    }
    else
    {
        QTextStream stream(&file);
        stream << selectCurrentNotepadTextEditor()->toPlainText();
    }
    file.close();
}

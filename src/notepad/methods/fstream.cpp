///Imported Headers
//MainWindow
#include "../../mainWindow/mainwindow.h"
//Directives
#include "../../config/directives.h"

///GUI Headers
//MainWindow
#include "ui_mainwindow.h"

///Qt Headers
#include <QDir>

void MainWindow::openFileToNotepadTab()
{
    if(OpenFilePath.isNull())
    {
        OpenFilePath = QDir::homePath();
    }
    if(!OpenFilePath.isNull())
    {
        OpenFilePath = QFileInfo(OpenFileName).path();
    }
    OpenFileName = QFileDialog::getOpenFileName(this, tr("Open File"),OpenFilePath);
    if(OpenFileName.isNull()) return;
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

void MainWindow::saveFileAsFromNotepadTab()
{
    if(SaveFilePath.isNull())
    {
        SaveFilePath = QDir::homePath();
    }
    SaveFileName = QFileDialog::getSaveFileName(this, tr("Save File"), SaveFilePath);
    if(SaveFileName.isNull()) return;
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

void MainWindow::saveFileFromNotepadTab()
{

}

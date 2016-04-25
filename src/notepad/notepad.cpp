#include "../mainWindow/mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::createNotepadTab(QString NotepadTabName)
{
    NotepadEditor[NotepadTabNumber] = new QTextEdit();
    ui->tabWidget->addTab(NotepadEditor[NotepadTabNumber], NotepadTabName);
    ui->tabWidget->setCurrentWidget(NotepadEditor[NotepadTabNumber]);
    NotepadTabNumber++;
}

void MainWindow::createNewNotepadTab()
{
    QString NewNotepadTab;
    if(NewTabNumber!=0)
    {
        NewNotepadTab="unnamed" + QString::number(NewTabNumber);
    }
    else
    {
        NewNotepadTab="unnamed";
    }
    createNotepadTab(NewNotepadTab);
    NewTabNumber++;
}

void MainWindow::destroyNotepadTab(int index)
{
    if(ui->tabWidget->tabText(index).contains("unnamed"))
    {
        ui->tabWidget->removeTab(index);
        NewTabNumber--;
    }
    else
    {
        ui->tabWidget->removeTab(index);
    }

    if(index==0)
    {
        createNewNotepadTab();
    }
}

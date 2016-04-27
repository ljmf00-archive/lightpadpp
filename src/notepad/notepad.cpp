#include "../mainWindow/mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::createNotepadTab(QString NotepadTabName)
{
    NotepadEditor = new QTextEdit(this);
    connect(NotepadEditor, SIGNAL(textChanged()), this, SLOT(on_currentNotepadTextEditor_textChanged()));
    ui->tabWidget->addTab(NotepadEditor, NotepadTabName);
    ui->tabWidget->setCurrentWidget(NotepadEditor);
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
    if(ui->tabWidget->tabText(index).contains("*"))
    {
        QMessageBox::StandardButton questionReply = QMessageBox::question(this, "Test", "Are you sure you want to quit without saving?", QMessageBox::No|QMessageBox::Yes);
        if(questionReply == QMessageBox::Yes)
        {

        }
    }
    if(ui->tabWidget->tabText(index).contains("unnamed"))
    {
        ui->tabWidget->removeTab(index);
        NewTabNumber--;
    }
    else
    {
        ui->tabWidget->removeTab(index);
    }

    if(ui->tabWidget->count()==0)
    {
        createNewNotepadTab();
    }
}

QTextEdit* MainWindow::selectCurrentNotepadTextEditor()
{
    QWidget* tempWidget = ui->tabWidget->widget(ui->tabWidget->currentIndex());
    return (QTextEdit*)tempWidget;
}

void MainWindow::on_currentNotepadTextEditor_textChanged()
{
    if(!ui->tabWidget->tabText(ui->tabWidget->currentIndex()).contains("*"))
    {
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),ui->tabWidget->tabText(ui->tabWidget->currentIndex())+"*");
    }
}


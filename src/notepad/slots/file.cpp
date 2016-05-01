///Imported Headers
//MainWindow
#include "../../mainWindow/mainwindow.h"

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

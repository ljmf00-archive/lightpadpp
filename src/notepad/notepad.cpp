///Imported Headers
//MainWindow
#include "../mainWindow/mainwindow.h"

///GUI Headers
//MainWindow
#include "ui_mainwindow.h"

/* selectCurrentNotepadTextEditor()             \
 * Method to : select current text editor from  \
 *           : current index tab                \
*/
QTextEdit* MainWindow::selectCurrentNotepadTextEditor()
{
    //select current index tab
    QWidget* tempWidget = ui->tabWidget->widget(ui->tabWidget->currentIndex());
    //return QTextEdit widget of : current index tab
    return (QTextEdit*)tempWidget;
}

/* editSaveStateNotepadText()           \
 * Method to : if contains "*" add "*"  \
*/
void MainWindow::editSaveStateNotepadText()
{
    //test if !(no) : current tab index contains "*"
    if(!ui->tabWidget->tabText(ui->tabWidget->currentIndex()).contains("*"))
    {
        //add "*" into current tab index text
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),ui->tabWidget->tabText(ui->tabWidget->currentIndex())+"*");
    }
}

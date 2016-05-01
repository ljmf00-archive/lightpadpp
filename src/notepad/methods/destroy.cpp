///Imported Headers
//MainWindow
#include "../../mainWindow/mainwindow.h"

///GUI Headers
//MainWindow
#include "ui_mainwindow.h"

void MainWindow::destroyNotepadTab(int index)
{
    // test if : contains "*" in specific tab index
    if(ui->tabWidget->tabText(index).contains("*"))
    {
        /* QMessageBox::question                                                                                                    \
         * Opens a question message box with the given title and text in front of the specified parent widget.                      \
         * The standard buttons are added to the message box. defaultButton specifies the button used when Enter is pressed.        \
         * defaultButton must refer to a button that was given in buttons. If defaultButton is QMessageBox::NoButton,               \
         * QMessageBox chooses a suitable default automatically.                                                                    \
         * Returns the identity of the standard button that was clicked. If Esc was pressed instead, the escape button is returned. \
        */
        QMessageBox::StandardButton questionReply = QMessageBox::question(this, "Test", "Are you sure you want to quit without saving?", QMessageBox::No|QMessageBox::Yes);
        if(questionReply == QMessageBox::No)
        {
            //break method if select No Button
            return;
        }
    }
    // test if : contins "unnamed" in specific tab index
    if(ui->tabWidget->tabText(index).contains("unnamed"))
    {
        //remove tab with specific index
        ui->tabWidget->removeTab(index);
        //add -1 in NewTabNumber
        NewTabNumber--;
    }
    else
    {
        //only remove tab with specific index
        ui->tabWidget->removeTab(index);
    }
    // test if : tab cout is 0; create new tab
    if(ui->tabWidget->count()==0)
    {
        //createnewtab
        createNewNotepadTab();
    }
}

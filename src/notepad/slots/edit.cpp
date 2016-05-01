///Imported Headers
//MainWindow
#include "../../mainWindow/mainwindow.h"

void MainWindow::on_actionUndo_triggered()
{
    /* undo()                                                                                                   \
     * Undoes the last operation.                                                                               \
     * If there is no operation to undo, i.e. there is no undo step in the undo/redo history, nothing happens.  \
    */
    selectCurrentNotepadTextEditor()->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    /* redo()                                                                                                   \
     * Redoes the last operation.                                                                               \
     * If there is no operation to redo, i.e. there is no redo step in the undo/redo history, nothing happens.  \
    */
    selectCurrentNotepadTextEditor()->redo();
}

void MainWindow::on_actionSelect_All_triggered()
{
    // selectAll() : Selects all text.
    selectCurrentNotepadTextEditor()->selectAll();
}

void MainWindow::on_currentNotepadTextEditor_textChanged()
{
    //Edit Save state of: current text editor
    editSaveStateNotepadText();
}

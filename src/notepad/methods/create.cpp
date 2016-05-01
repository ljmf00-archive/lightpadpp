///Impoted Headers
//MainWindow
#include "../../mainWindow/mainwindow.h"
#include "../../syntax/syntax.h"

///GUI Headers
//MainWindow
#include "ui_mainwindow.h"

void MainWindow::createNotepadTab(QString NotepadTabName)
{
    QFont fontInconsolata(QFontDatabase::applicationFontFamilies(QFontDatabase::addApplicationFont(":/fonts/Inconsolata.pfa")).at(0), 12);
    QTextEdit *NotepadEditor = new QTextEdit();
    NotepadEditor->setFont(fontInconsolata);
    SyntaxHighlighter *highlighter = new SyntaxHighlighter(NotepadEditor->document());
    QObject::connect(NotepadEditor, SIGNAL(textChanged()), this, SLOT(on_currentNotepadTextEditor_textChanged()));
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

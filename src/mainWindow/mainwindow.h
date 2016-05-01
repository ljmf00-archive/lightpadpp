#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QFileDialog>
#include <QTabWidget>
#include <QTextEdit>
#include <QLabel>
#include <QMessageBox>
#include <QTextStream>
#include <QFont>
#include <QFontDialog>
#include <QFontDatabase>
#include <QSyntaxHighlighter>

#include "../helpDialog/helpdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *ui;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionSelect_All_triggered();
    void on_actionOpen_File_triggered();
    void on_tabWidget_tabCloseRequested(int index);
    void on_actionNew_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionSave_All_triggered();
    void on_MainWindow_destroyed();
    void on_actionChange_Font_triggered();
    void on_currentNotepadTextEditor_textChanged();
    
    void on_actionSet_Default_triggered();

private:
    void createNotepadTab(QString NotepadTabName);
    void createNewNotepadTab();
    void openFileToNotepadTab();
    void saveFileAsFromNotepadTab();
    void saveFileFromNotepadTab();
    void editSaveStateNotepadText();
    void destroyNotepadTab(int index);
    QTextEdit* selectCurrentNotepadTextEditor();
    HelpDialog h;
    MainWindow* mw;
    int NewTabNumber = 0;
    QString OpenFileName;
    QString OpenFilePath;
    QString SaveFileName;
    QString SaveFilePath;
    QLabel *Status;
};

#endif // MAINWINDOW_H

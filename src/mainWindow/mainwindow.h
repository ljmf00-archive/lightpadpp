#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTabWidget>
#include <QTextEdit>
#include <QLabel>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
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

private:
    void createNotepadTab(QString NotepadTabName);
    void createNewNotepadTab();
    void destroyNotepadTab(int index);
    int NotepadTabNumber = 0;
    int NewTabNumber = 0;
    Ui::MainWindow *ui;
    QString OpenFileName;
    QString OpenFilePath;
    QTextEdit *NotepadEditor[];
    QLabel *Status;
};

#endif // MAINWINDOW_H

#include "check.h"

#include <QMessageBox>
#include <QTextStream>

void StartChecker::createFilefromSource(QFile file, QFile source)
{
    if(file.exists()) return;
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text) && !source.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(new QWidget(), "Critical Error", "Run as Administrator to write config files!");
        return;
    }
    QTextStream(&file) << source.readAll();
    file.close();
    source.close();
}

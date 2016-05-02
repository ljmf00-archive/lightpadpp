#ifndef STARTCHECKER_H
#define STARTCHECKER_H

#include <QFile>

class StartChecker
{
public:
    StartChecker();

private:
    void createFilefromSource(QFile file, QFile source);
};

#endif // STARTCHECKER_H

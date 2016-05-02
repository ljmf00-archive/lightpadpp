#include <QDir>
#include "check.h"

StartChecker::StartChecker()
{
    if(!QDir("config").exists() || !QDir("config/scheme").exists() || !QDir("config/syntax").exists() || !QDir("config/themes").exists())
    {
        QDir().mkdir("config");
        QDir().mkdir("config/scheme");
//        createFilefromSource(QFile("config/scheme/Monokai.yaml"), QFile source);
        QDir().mkdir("config/syntax");
        QDir().mkdir("config/themes");
    }
}

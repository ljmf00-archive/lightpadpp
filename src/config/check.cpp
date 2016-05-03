#include <QDir>
#include "check.h"

StartChecker::StartChecker()
{
    if(!QDir("config").exists() || !QDir("config/scheme").exists() || !QDir("config/syntax").exists() || !QDir("config/themes").exists())
    {
        QDir().mkdir("config");
        QDir().mkdir("config/scheme");
        createFilefromSource(new QFile("config/scheme/Monokai.yaml"), new QFile(":/config/scheme/Monokai.yaml"));
        QDir().mkdir("config/syntax");
        QDir().mkdir("config/themes");
    }
}

#include "syntax.h"

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    C_CPP_syntaxHighlighter();
}

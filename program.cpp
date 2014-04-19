#include "program.h"

Program::Program(QObject *parent) :
    QObject(parent)
{
}

void Program::quit()
{
    exit(0);
}

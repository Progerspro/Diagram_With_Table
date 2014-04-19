#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>

class Program : public QObject
{
    Q_OBJECT
public:
    explicit Program(QObject *parent = 0);

signals:

public slots:
    void quit();

};

#endif // PROGRAM_H

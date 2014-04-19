#ifndef FORM_H
#define FORM_H
#include <QWidget>
#include <QString>
#include <QTableWidgetItem>
#include <QLabel>
#include "data.h"

namespace Ui {
class Form;
}

class Form : public QWidget,public Data
{

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    QVector<double> x,y;
    QCustomPlot* plot;
    QVBoxLayout* layout;
    QString str;
    QLabel lbl;
    void show_diagram();
    void draw(int table_count, QTableWidgetItem* Name);
    void init();
    void count(int max_size, QTableWidgetItem *item);
    void temp_test(int table_count,QString Name);
    void temp_count(int max_size);
private:
    Ui::Form *ui;
};

#endif // FORM_H

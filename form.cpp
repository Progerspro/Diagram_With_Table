#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    plot = new QCustomPlot;
    layout = new QVBoxLayout;
}

Form::~Form()
{
    delete ui;
}

void Form::draw(int table_count,QTableWidgetItem* Name)
{
    if (!Name)
      return;
    static int new1;
    for(int a = new1; a < table_count; a++)
    {
        if(a >= 5)
            break;
    plot->addGraph();
    plot->graph(a)->setData(x,y);
    plot->graph(a)->setPen(QPen(Qt::red));
    plot->graph(a)->setName(Name->text());
    plot->replot();
    new1++;
    }
}
void Form::init()
{

    plot->legend->setVisible(true);
    plot->xAxis->setLabel("x");
    plot->yAxis->setLabel("y");
    plot->xAxis->setRange(0,100);
    plot->yAxis->setRange(0,100);
    layout->addWidget(plot);
    setLayout(layout);
}

void Form::count(int max_size,QTableWidgetItem* item)
{
    qDebug() << item;
    if (!item)
      return;
    x.resize(max_size);
    y.resize(max_size);

    for(int a = 0 ; a < max_size; a++)
    {

        x[a] = item->text().toInt();
        y[a] = item->text().toInt();
    }
}


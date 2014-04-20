#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    srand(QDateTime::currentDateTime().toTime_t());
    ui->setupUi(this);
    plot = new QCustomPlot;
    for(int a = 0 ; a < 5 ; a++)
    bar[a] = new QCPBars(plot->xAxis,plot->yAxis);
    layout = new QVBoxLayout;
}

Form::~Form()
{
    delete ui;
}

void Form::draw(int Graph_Count,QTableWidgetItem* Name)
{
    if (!Name)
      return;
    static int new1;
  for(int a = new1; a < Graph_Count; a++)
    {
        if(a >= 5)
            break;
        plot->addPlottable(bar[a]);
    bar[a]->setName(Name->text());
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    bar[a]->setPen(graphPen);
    bar[a]->setData(x,y);
    plot->rescaleAxes();
    plot->replot();




    /*plot->graph(a)->setData(x,y);
    QPen graphPen;
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    plot->graph(a)->setPen(graphPen);
    plot->graph(a)->setBrush(QBrush(Qt::Dense6Pattern));
    plot->graph(a)->setName(Name->text());
    plot->replot();
    */
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

void Form::count(int max_size, QTableWidgetItem* item_Num,int Key)
{
    static int num;
    if (!item_Num)
      return;
    x.resize(max_size);
    y.resize(max_size);

    for(int a = num ; a < num + 1 ;)
    {
        x[a] = Key;
        y[a] = item_Num->text().toInt();
        num++;
        break;
    }
}

void Form::clean_all()
{
   x.clear();
   y.clear();
}


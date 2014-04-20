#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    error = 0;
    ui->setupUi(this);
    //Количество строк
    ui->tableWidget->setRowCount(2);
    center_wid = new QWidget(this);
    setCentralWidget(center_wid);
    vlayout = new QVBoxLayout(center_wid);
    vlayout->addSpacing(10);
    vlayout->setMargin(5);
    vlayout->addWidget(ui->tableWidget);
    vlayout->addWidget(ui->pushButton);
    messages_init();
    connect(ui->action,SIGNAL(triggered()),this,SLOT(quit()));
    connect(ui->action_2,SIGNAL(triggered()),this,SLOT(about()));
    form = new Form;
    i = 0;
    cou = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    ++i;
    if(i == 1)
    {
         ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
    }
    else if(column == cou)
    {
        if(column >= 4)
        {
            error++;
            if(error <= 1)
            Error_message.show();
            return;
        }
        ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
        cou++;
    }
}
//For quit
void MainWindow::quit()
{
    exit(0);
}
void MainWindow::about()
{
    about_message.show();
}
void MainWindow::messages_init()
{
    //About message
    about_message.setText("Project was created by Edward Rukia!");
    about_message.setIcon(QMessageBox::Information);
    about_message.setStandardButtons(QMessageBox::Ok);
    about_message.setDefaultButton(QMessageBox::Ok);
    about_message.setDetailedText(QLibraryInfo::buildDate().toString()+'\n'+QLibraryInfo::licensee());
    //Error message
    Error_message.setText("Error! You can't make this table bigger.");
    Error_message.setIcon(QMessageBox::Critical);
    Error_message.setStandardButtons(QMessageBox::Ok);
    Error_message.setDefaultButton(QMessageBox::Ok);
}


//TODO Fix the item take
void MainWindow::on_pushButton_clicked()
{
    form->clean_all();
    int num = 0;
    int num1 = 0;
    form->init();
    for(int a = num;a < ui->tableWidget->columnCount();a++)
    {
        for(int b = num1; b < 5;b++)
        {
    if(ui->tableWidget->columnCount() == 5)
    {
        form->count(10000,ui->tableWidget->item(1,b),ui->tableWidget->columnCount());
    }
    else if(ui->tableWidget->columnCount() < 5 )
    {
        form->count(10000,ui->tableWidget->item(1,b),ui->tableWidget->columnCount() - 1);
    }
    num1++;
    break;
        }
        num++;
        form->draw(num,ui->tableWidget->item(0,a));
    }
    form->show();
}

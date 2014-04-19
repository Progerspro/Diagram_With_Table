#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    error = 0;
    ui->setupUi(this);
    //Количество строк
    ui->tableWidget->setRowCount(3);
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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    row = ui->tableWidget->rowCount();
    column = ui->tableWidget->columnCount();
    if(column <= 4)
    {
    ui->tableWidget->setColumnCount(column + 1);
    }
    else
    {
        error++;
        if(error <= 1)
        Error_message.show();
        return;
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
    column_num = ui->tableWidget->columnCount();
    form->init();
    for(int a = 1;a <= 2;a++)
        for(int b = 0; b < ui->tableWidget->columnCount();b++)
        {
    form->count(500,ui->tableWidget->item(a,b));
        }
        for(int a = 0; a < ui->tableWidget->columnCount();a++)
        {
             form->draw(ui->tableWidget->columnCount(),ui->tableWidget->item(0,a));
        }
    form->show();
}

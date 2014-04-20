#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMessageBox>
#include <QLibraryInfo>
#include "data.h"
#include "form.h"
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow,public Data
{
    Q_OBJECT
private:
    int error;
    int i;
    int cou;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QMessageBox about_message;
    QMessageBox Error_message;
    QVBoxLayout* vlayout;
    QWidget* center_wid;
    Form* form;
private slots:

    void on_tableWidget_cellDoubleClicked(int row, int column);
    void messages_init();
    void quit();
    void about();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H

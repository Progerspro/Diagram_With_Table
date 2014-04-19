#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <QDialog>

namespace Ui {
class Diagram;
}

class Diagram : public QDialog
{
    Q_OBJECT

public:
    explicit Diagram(QWidget *parent = 0);
    ~Diagram();
    void show_diagram();
private:
    Ui::Diagram *ui;
};

#endif // DIAGRAM_H

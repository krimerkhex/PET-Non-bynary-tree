#ifndef SRCHFORM_H
#define SRCHFORM_H

#include <QWidget>
#include "Tree/Tree.h"
#include <QMessageBox>

namespace Ui {
class SrchForm;
}

class SrchForm : public QWidget
{
    Q_OBJECT

public:
    explicit SrchForm(QWidget *parent = nullptr, Tree *in = nullptr);
    ~SrchForm();

private slots:
    void on_EndButton_clicked();

private:
    Tree *tree;
    Ui::SrchForm *ui;
};

#endif // SRCHFORM_H

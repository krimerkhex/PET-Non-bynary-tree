#ifndef RMVFORM_H
#define RMVFORM_H

#include "Tree/Tree.h"
#include <QWidget>
#include <QMessageBox>

namespace Ui {
class RmvForm;
}

class RmvForm : public QWidget
{
    Q_OBJECT

public:
    explicit RmvForm(QWidget *parent = nullptr, Tree *in = nullptr);
    ~RmvForm();

private slots:
    void on_EndButton_clicked();

private:
    Tree *tree;
    Ui::RmvForm *ui;
};

#endif // RMVFORM_H

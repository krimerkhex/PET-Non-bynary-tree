#ifndef ADDFORM_H
#define ADDFORM_H

#include <QWidget>
#include "Tree/Tree.h"
#include <QMessageBox>

namespace Ui {
class AddForm;
}

class AddForm : public QWidget {
    Q_OBJECT

public:
    explicit AddForm(QWidget *parent = nullptr, Tree *in = nullptr);
    ~AddForm();

private slots:
    void on_EndButton_clicked();

private:
    Tree *tree;
    Ui::AddForm *ui;
};

#endif // ADDFORM_H

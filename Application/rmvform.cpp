#include "rmvform.h"
#include "ui_rmvform.h"

RmvForm::RmvForm(QWidget *parent, Tree *in) :
    QWidget(parent),
    tree(in),
    ui(new Ui::RmvForm) {
    ui->setupUi(this);
}

RmvForm::~RmvForm() {
    delete ui;
}


void RmvForm::on_EndButton_clicked() {
    if (ui->search->text().length()) {
        this->tree->deleteNode(ui->search->text().toStdString());
        ui->search->clear();
        this->hide();
    } else {
        QMessageBox::critical(this, "Critical", "All things must be full");
    }
}

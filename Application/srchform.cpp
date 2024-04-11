#include "srchform.h"
#include "ui_srchform.h"

SrchForm::SrchForm(QWidget *parent, Tree *in) :
    QWidget(parent),
    tree(in),
    ui(new Ui::SrchForm) {
    ui->setupUi(this);
}

SrchForm::~SrchForm() {
    delete ui;
}

void SrchForm::on_EndButton_clicked() {
    if (ui->search->text().length()) {
        bool flag = (this->tree->find(ui->search->text().toStdString()) != nullptr);
        QMessageBox::information(this, "Search result", flag ? "That name on tree" : "No name like this");
        ui->search->clear();
        this->hide();
    } else {
        QMessageBox::critical(this, "Critical", "All things must be full");
    }
}


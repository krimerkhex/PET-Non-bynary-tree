#include "addform.h"
#include "ui_addform.h"

AddForm::AddForm(QWidget *parent, Tree *in) :
    QWidget(parent),
    tree(in),
    ui(new Ui::AddForm) {
    ui->setupUi(this);
}

AddForm::~AddForm()
{
    delete ui;
}

void AddForm::on_EndButton_clicked() {
    if (ui->name->text().length()) {
        File *ptr = nullptr;
        if (ui->Text->isChecked()) {
            ptr = new TextFile(ui->name->text().toStdString());
        } else if (ui->Docs->isChecked()) {
            ptr = new DocumentFile(ui->name->text().toStdString());
        } else if (ui->Imagen->isChecked()) {
            ptr = new ImagenFile(ui->name->text().toStdString());
        } else if (ui->Video->isChecked()) {
            ptr = new VideoFile(ui->name->text().toStdString());
        } else if (ui->Table->isChecked()) {
            ptr = new TableFile(ui->name->text().toStdString());
        }
        (this->tree->getRoot() == nullptr) ? this->tree->add(ptr) : this->tree->add(ptr, ui->search->text().toStdString());
        this->hide();
        ui->search->clear();
        ui->name->clear();
    } else {
        QMessageBox::critical(this, "Critical", "All things must be full");
    }
}


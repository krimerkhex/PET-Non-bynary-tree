#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tree(new Tree())
    , addform(new AddForm(nullptr, tree))
    , infoform(new InfoForm())
    , rmvform(new RmvForm(nullptr, tree))
    , srchform(new SrchForm(nullptr, tree)) {
    ui->setupUi(this);

    File* file = new File("File", "", "root", 0, 0);

    this->addform->setWindowTitle("AddForm");
    this->infoform->setWindowTitle("InfoForm");
    this->rmvform->setWindowTitle("RemoveForm");
    this->srchform->setWindowTitle("SearchForm");

    this->tree->add(file);

    this->tree->add(new TextFile("text", "wqetwryeyi"), file->getFileName());
    this->tree->add(new DocumentFile("document", "", "wqetwryeyi"), file->getFileName());
    this->tree->add(new TableFile("table", "", 2, 3), file->getFileName());
    this->tree->add(new ImagenFile("imagen", "", 4, 6), file->getFileName());
    this->tree->add(new VideoFile("video", "", 2, 3, 5), file->getFileName());
    this->displayTree();

    std::ofstream ofs;
    ofs.open ("save.dot", std::ofstream::out);
    ofs.close();

    this->on_actionInfo_triggered();
}

MainWindow::~MainWindow() {
    delete addform;
    delete infoform;
    delete rmvform;
    delete srchform;
    delete this->tree;
    delete ui;
}

void MainWindow::displayTree() {
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(4);
    QStringList labels; labels << "File Name" << "File Type" << "Count of attributs" << "Count of methods";
    ui->treeWidget->setHeaderLabels(labels);
    if (this->tree->getRoot() != nullptr) {
        auto ui_root = new QTreeWidgetItem(ui->treeWidget);
        ui_root->setText(0, QString::fromStdString(this->tree->getRoot()->getName()));
        ui_root->setText(1, QString::fromStdString(this->tree->getRoot()->getValue()->getFileType()));
        ui_root->setText(2, QString::number(this->tree->getRoot()->getValue()->getAttributs()));
        ui_root->setText(3, QString::number(this->tree->getRoot()->getValue()->getMethods()));
        ui->treeWidget->addTopLevelItem(ui_root);
        this->createTree(ui_root, this->tree->getRoot());
    }
}

void MainWindow::createTree(QTreeWidgetItem *ui_root, TreeNode *root) {
    if (root != nullptr) {
        for (auto it : *root->getChildren()) {
            auto ui_child = new QTreeWidgetItem();
            ui_child->setText(0, QString::fromStdString(it->getName()));
            ui_child->setText(1, QString::fromStdString(it->getValue()->getFileType()));
            ui_child->setText(2, QString::number(it->getValue()->getAttributs()));
            ui_child->setText(3, QString::number(it->getValue()->getMethods()));
            ui_root->addChild(ui_child);
            if (it->getChildren()->size()) {
                this->createTree(ui_child, it);
            }
        }

    }

}

// Получение данных из файла
void MainWindow::on_actionInput_setting_triggered() {/*
    QString filename = QFileDialog::getSaveFileName(this, tr("Open File"), QDir::homePath(), tr("Files (*.dot);;All Files (*)"));
    if (!filename.isEmpty()) {*/
        std::ifstream infile;
    infile.open("save.dot");
        if (infile.is_open()) {
            File *ptr = nullptr;
            std::string parent;
            std::string name;
            std::string type;
            while(infile >> parent >> name >> type) {
                if (type == "TextFile") {
                    ptr = new TextFile(name);
                } else if (type == "DocumantFile") {
                    ptr = new DocumentFile(name);
                } else if (type == "ImagenFile") {
                    ptr = new ImagenFile(name);
                } else if (type == "VideoFile") {
                    ptr = new VideoFile(name);
                } else if (type == "TableFile") {
                    ptr = new TableFile(name);
                }
                (this->tree->getRoot() == nullptr) ? this->tree->add(ptr) : this->tree->add(ptr, name);
            }
            infile.close();
            this->displayTree();
        } else {
            std::cout << "Unable to open file";
        }
//    }
}

void MainWindow::intoFile(std::ofstream &file, TreeNode *ptr) {
    if (!ptr) {
        return;
    }
    file << ptr->getParent()->getName() << " -> " << ptr->getName() << std::endl;
    file << ptr->getParent()->getName() << "\n" << ptr->getValue()->getFileType() << "\n"  << ptr->getValue()->getFileName() << std::endl;
    file << "}" << std::endl;
    if (ptr->getChildren()->size()) {
        for (auto it : *ptr->getChildren()) {
            intoFile(file, it);
        }
    }
}

// Вывод данных в файл
void MainWindow::on_actionOutput_settings_triggered() {/*
    QString filename = QFileDialog::getOpenFileName(this, tr("Save File"), QDir::homePath(), tr("Files (*.dot);;All Files (*)"));
    if (!filename.isEmpty()) {*/
    std::ofstream infile;
    infile.open("save.dot", std::ofstream::out);
    infile.clear();
    if (infile.is_open()) {
        this->intoFile(infile, tree->getRoot());
        infile.close();
        }
//    }
}

void MainWindow::on_actionExit_triggered() {
    delete addform;
    delete infoform;
    delete rmvform;
    delete srchform;
    delete tree;
    delete ui;
    exit(1);
}

void MainWindow::on_actionAdd_node_triggered() {
    this->addform->show();
    this->displayTree();
}

void MainWindow::on_actionRemove_node_triggered() {
    this->rmvform->show();
    this->displayTree();
}

void MainWindow::on_actionSearch_node_triggered() {
    this->srchform->show();
}

void MainWindow::on_actionRefresh_tree_triggered() {
    this->displayTree();
}

void MainWindow::on_actionInfo_triggered() {
    this->infoform->show();
}

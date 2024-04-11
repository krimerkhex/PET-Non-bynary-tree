#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Tree/Tree.h"
#include "addform.h"
#include "infoform.h"
#include "rmvform.h"
#include "srchform.h"

#include <fstream>

#include <QMainWindow>
#include <QFileDialog>
#include <QWidget>
#include <QVariant>
#include <QAbstractItemModel>
#include <QTreeWidgetItem>
#include <QModelIndex>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void displayTree();

private slots:
    void on_actionInput_setting_triggered();
    void on_actionOutput_settings_triggered();
    void on_actionExit_triggered();
    void on_actionAdd_node_triggered();
    void on_actionRemove_node_triggered();
    void on_actionSearch_node_triggered();
    void on_actionRefresh_tree_triggered();
    void on_actionInfo_triggered();

private:
    Ui::MainWindow *ui;
    Tree *tree;
    void createTree(QTreeWidgetItem *ui_root, TreeNode *root);
    AddForm *addform;
    InfoForm *infoform;
    RmvForm *rmvform;
    SrchForm *srchform;
    bool flag = false;
    void intoFile(std::ofstream &file, TreeNode *ptr);
};

#endif // MAINWINDOW_H



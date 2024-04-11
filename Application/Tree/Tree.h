#ifndef TREE_TREE_H
#define TREE_TREE_H

#include "../List/list.h"
#include "../Queue/queue.h"

#include "classes.h"

class TreeNode {
public:
    TreeNode(File* value) : value_(value), name(value->getFileName()) {
        parent_ = nullptr;
    }

    ~TreeNode() = default;
    
    void setParent(TreeNode* par) {
        parent_ = par;
    }

    TreeNode* getParent() {
        return parent_;
    }

    int childCount() {
        return children_.size();
    }

    File* getValue() { return value_; }
    my::List<TreeNode*>* getChildren() { return &children_; }
    std::string getName() { return name; }


protected:
    File* value_;
    std::string name;
    TreeNode* parent_ = nullptr;
    my::List<TreeNode*> children_;
};

class Tree {
public:
    Tree() : root_(nullptr) {}
    
    void add(File* value, std::string name = "") {
        if (find(value->getFileName()) == nullptr) {
            auto node = new TreeNode(value);
            auto parent = find(name);
            if (parent != nullptr) {
                parent->getChildren()->push_back(node);
                node->setParent(parent);
            } else {
                root_ = node;
            }
        }
    }
    
    TreeNode* find(std::string value) const {
        if (root_ == nullptr) {
            return nullptr;
        }
        my::Queue<TreeNode*> queue;
        queue.push(root_);
        while (!queue.empty()) {
            auto node = queue.front();
            queue.pop();
            if (node->getValue()->getFileName() == value) {
                return node;
            }
            auto temp = node->getChildren();
            for (auto child : *temp) {
                queue.push(child);
            }
        }
        return nullptr;
    }
    
    void deleteNode(std::string name) {
        TreeNode* node = find(name);
        if (node == nullptr) {
            return;
        }
        if (node == root_) {
            root_ = nullptr;
        } else {
            auto parent = node->getParent();
            auto temp = parent->getChildren();
            bool flag = true;
            for (auto it = temp->begin(); (it != temp->end()) && flag; ++it) {
                if ((*it)->getName() == name) {
                    temp->erase(it);
                    flag = false;
                }
            }
        }
        deleteSubtree(node);
    }
    
    void deleteSubtree(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        auto temp = node->getChildren();
        for (auto child : *temp) {
            deleteSubtree(child);
        }
        delete node;
    }
    
void print(TreeNode* node, std::string prefix = "", bool isLast = true) {
        std::cout << prefix;
        std::cout << (isLast ? "I-- " : "|-- ");
        std::cout << node->getValue()->getFileType() << " " << node->getValue()->getFileName() << std::endl;


        prefix += (isLast ? "    " : "|   ");

        auto children = node->getChildren();
        auto it = children->begin();
        for (int i = 0; i < children->size(); i++, ++it) {
            print(*it, prefix, i == children->size() - 1);
        }
    }

    TreeNode* getRoot() { return root_; }
    
private:
    TreeNode* root_;
};

#endif

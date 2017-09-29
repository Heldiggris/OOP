#include "TBinaryTree.h"
#include "TBinaryTreeItem.h"
#include <stdlib.h>
#include <iostream>


TBinaryTree::TBinaryTree() {
    head = nullptr;
}


TBinaryTreeItem* TBinaryTree::find(size_t a)
{
    TBinaryTreeItem* item = head;
    while (item != nullptr) {
        if (item->Square() == a) {
            return item;
        }
        else if (item->Square() > a) {
            item = item->left;
        }
        else if (item->Square() < a) {
            item = item->right;
        }
    }
    return nullptr;
}


TBinaryTreeItem* TBinaryTree::minValueNode(TBinaryTreeItem* root)
{
    TBinaryTreeItem* min = root;
 
    while (min->left != nullptr)
        min = min->left;
 
    return min;
}

TBinaryTreeItem* TBinaryTree::deleteNode(TBinaryTreeItem* root, size_t square)
{
    if (root == nullptr) return root;
 
    if (square < root->Square())
        root->left = deleteNode(root->left, square);
    else if (square > root->Square())
        root->right = deleteNode(root->right, square);
    else {
        if (root->left == nullptr) {
            TBinaryTreeItem *temp = root->right;
            root->left = nullptr;
            root->right = nullptr;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            TBinaryTreeItem *temp = root->left;
            root->left = nullptr;
            root->right = nullptr;
            delete root;
            return temp;
        }
 
        TBinaryTreeItem* temp = minValueNode(root->right);
        root->rectangle = temp->rectangle;
        root->right = deleteNode(root->right, temp->Square());
    }
    return root;
}


void TBinaryTree::remove(size_t a)
{
    head = TBinaryTree::deleteNode(head, a);

}

void TBinaryTree::insert(Rectangle &&rectangle)
{
    if (head == nullptr) {
        head = new TBinaryTreeItem(rectangle);
        return;
    }


    TBinaryTreeItem* item = head;
    while (true) {
        if (rectangle.Square() <= item->Square()) {
            if (item->left == nullptr) {
                item->left = new TBinaryTreeItem(rectangle);
                break;
            }
            else {
                item = item->left;
            }
        }
        else {
            if (item->right == nullptr) {
                item->right = new TBinaryTreeItem(rectangle);
                break;
            }
            else {
                item = item->right;
            }
        }
    }
}

void TBinaryTree::print_tree(TBinaryTreeItem* item, size_t a, std::ostream& os)
{
    for (size_t i = 0; i < a; i++) {
        os << "  ";
    }
    os << item->Square() << std::endl;
    if (item->left != nullptr) {
        TBinaryTree::print_tree(item->left, a + 1, os);
    }
    else if (item->right != nullptr) {
        for (size_t i = 0; i <= a; i++) {
            os << "  ";
        }
        os << "null" << std::endl;
    }
    if (item->right != nullptr) {
        TBinaryTree::print_tree(item->right, a + 1, os);
    }
    else if (item->left != nullptr) {
        for (size_t i = 0; i <= a; i++) {
            os << "  ";
        }
        os << "null" << std::endl;
    }
}



void TBinaryTree::print()
{
    if (head != nullptr) {
        TBinaryTree::print_tree(head, 0, std::cout);
    }
}

void TBinaryTree::print(std::ostream& os)
{
    if (head != nullptr) {
        TBinaryTree::print_tree(head, 0, os);
    }
}


bool TBinaryTree::empty()
{
    return head == nullptr;
}

TBinaryTree::~TBinaryTree()
{
    delete head;
}


std::ostream& operator<<(std::ostream& os, TBinaryTree& tree) {
    tree.print(os);
    return os;
}

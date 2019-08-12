#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
template <class T>
class BtreeNode {
    //二叉链表,无parent
public:
    T *data;
    BtreeNode *lchild;
    BtreeNode *rchild;

    BtreeNode(T *e) {
        data = e;
        lchild = NULL;
        rchild = NULL;
    }
    void add_lchild(BtreeNode *lchild) {
        this->lchild = lchild;
    }
    void add_rchild(BtreeNode *rchild) {
        this->rchild = rchild;
    }
    void add_child(BtreeNode *lchild = NULL, BtreeNode *rchild = NULL) {
        this->lchild = lchild;
        this->rchild = rchild;
    }
};

template <class T>
class Btree
{
    //private:
public:
    BtreeNode<T> *root;
    Btree() {
        root = NULL;
    }
    Btree(BtreeNode<T> *root) {
        this->root = root;
    }
    size_t depth(BtreeNode<T> *root, size_t high) {
        if(root) {
            ++high;
            size_t left = depth(root->lchild, high);
            size_t right = depth(root->rchild, high);
            return left > right ? left : right;
        } else {
            return high;
        }
    }


    void DLR(BtreeNode<T> *root, vector<T> &result) {
        if(root) {
            result.push_back(*(root->data));
            DLR(root->lchild, result);
            DLR(root->rchild, result);
        }
    }
    vector<T> DLRTraverse() {
        BtreeNode<T> *p = root;
        vector<T> result;
        stack<BtreeNode<T> *> right_children;
        while(p) {
            result.push_back(*(p->data));
            if(p->rchild) {
                right_children.push(p->rchild);
            }
            if(p->lchild) {
                p = p->lchild;
            } else {
                if(!right_children.empty()) {
                    p = right_children.top();
                    right_children.pop();
                } else {
                    p = NULL;
                }
            }
        }
        return result;
    }

    void LDR(BtreeNode<T> *root, vector<T> &result) {
        if(root) {
            LDR(root->lchild, result);
            result.push_back(*(root->data));
            LDR(root->rchild, result);
        }
    }
    vector<T> LDRTraverse() {
        BtreeNode<T> *p = root;
        vector<T> result;
        stack<BtreeNode<T> *> right_children;
        stack<BtreeNode<T> *> parent;
        while(p) {
            if(p->rchild) {
                right_children.push(p->rchild);
            }
            if(p->lchild) {
                parent.push(p);
                p = p->lchild;
            } else {
                result.push_back(*(p->data));
                if(!parent.empty()) {
                    p = parent.top();
                    result.push_back(*(p->data));
                    parent.pop();
                } else {
                    p = NULL;
                }
                if(!right_children.empty()) {
                    p = right_children.top();
                    right_children.pop();
                }
            }
        }
        return result;
    }
    void LRD(BtreeNode<T> *root, vector<T> &result) {
        if(root) {
            LRD(root->lchild, result);
            LRD(root->rchild, result);
            result.push_back(*(root->data));
        }
    }
    vector<T> LevelTraverse() {


    }
    void show() {
        size_t depth = tree.depth();


    }
};

#endif // BTREE_H

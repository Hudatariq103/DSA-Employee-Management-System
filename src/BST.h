#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
using namespace std;

class BST {
private:
    struct Node { string id; Node* left; Node* right; Node(string x):id(x),left(nullptr),right(nullptr){} };
    Node* root;
    Node* insertNode(Node* r, string id) {
        if (r == nullptr) return new Node(id);
        if (id < r->id) r->left = insertNode(r->left,id);
        else if (id > r->id) r->right = insertNode(r->right,id);
        return r;
    }
    bool searchNode(Node* r, string id) const {
        if (!r) return false;
        if (r->id == id) return true;
        if (id < r->id) return searchNode(r->left,id);
        return searchNode(r->right,id);
    }
    void inorder(Node* r) const { if (r) { inorder(r->left); cout << r->id << "  "; inorder(r->right); } }
    void destroy(Node* r) { if(r){destroy(r->left);destroy(r->right);delete r;} }
public:
    BST():root(nullptr){} ~BST(){destroy(root);}
    void clear(){destroy(root);root=nullptr;}
    void insert(string id){root=insertNode(root,id);}
    bool search(string id) const{return searchNode(root,id);}
    void displaySorted() const { if(!root) cout << "No IDs stored."; else inorder(root); cout << "\n"; }
};
#endif

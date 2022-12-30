#include <iostream>
#include <iomanip>
#include <map>
#include <string>


// Implementing Red-Black Tree in C++

#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *parent;
  Node *left;
  Node *right;
  int color;
};

typedef Node *NodePtr;

class RedBlackTree {
   private:
  NodePtr root;
  NodePtr TNULL;

  void initializeNULLNode(NodePtr node, NodePtr parent) {
    node->data = 0;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = 0;
  }


  // For balancing the tree after deletion
  void deleteFix(NodePtr x) {
    NodePtr s;  //sibling
    while (x != root && x->color == 0) {  //while x is not root and x is black
      if (x == x->parent->left) { //if x is a left child
        s = x->parent->right; //sibling is right child
        if (s->color == 1) {  //if sibling is red
          s->color = 0;    //sibling becomes black
          x->parent->color = 1; //parent becomes red
          leftRotate(x->parent);   //left rotate at parent
          s = x->parent->right; //sibling becomes right child
        }

        if (s->left->color == 0 && s->right->color == 0) {  //if both children of sibling are black
          s->color = 1; //sibling becomes red
          x = x->parent;  //x becomes parent
        } else {
          if (s->right->color == 0) { //if right child of sibling is black
            s->left->color = 0; //left child of sibling becomes black
            s->color = 1; //sibling becomes red
            rightRotate(s); //right rotate at sibling
            s = x->parent->right; //sibling becomes right child
          }

          s->color = x->parent->color;  //sibling becomes same color as parent
          x->parent->color = 0; //parent becomes black
          s->right->color = 0;  //right child of sibling becomes black
          leftRotate(x->parent);  //left rotate at parent
          x = root;
        }
      } else {
        s = x->parent->left;  //sibling is left child
        if (s->color == 1) {  //if sibling is red
          s->color = 0;   //sibling becomes black
          x->parent->color = 1; //parent becomes red
          rightRotate(x->parent); //right rotate at parent
          s = x->parent->left;  //sibling becomes left child
        }

        if (s->right->color == 0 && s->right->color == 0) { //if both children of sibling are black
          s->color = 1; //sibling becomes red
          x = x->parent;  //x becomes parent
        } else {  //if one child of sibling is red
          if (s->left->color == 0) {  //if left child of sibling is black
            s->right->color = 0;  //right child of sibling becomes black
            s->color = 1; //sibling becomes red
            leftRotate(s);  //left rotate at sibling
            s = x->parent->left;  //sibling becomes left child
          }

          s->color = x->parent->color;  //sibling becomes same color as parent
          x->parent->color = 0; //parent becomes black
          s->left->color = 0; //left child of sibling becomes black
          rightRotate(x->parent); //right rotate at parent
          x = root; //x becomes root
        }
      }
    }
    x->color = 0; //x becomes black
  } 

  void rbTransplant(NodePtr u, NodePtr v) { //replaces one subtree as a child of its parent with another subtree
    if (u->parent == nullptr) { //if u is the root
      root = v; //v becomes the root
    } else if (u == u->parent->left) { //if u is a left child
      u->parent->left = v; //v becomes the left child
    } else {
      u->parent->right = v; //v becomes the right child
    }
    v->parent = u->parent; //the parent of v becomes the parent of u
  }

  void deleteNodeHelper(NodePtr node, int key) {
    NodePtr z = TNULL; //node to be deleted
    NodePtr x, y;
    while (node != TNULL) { //searching for the node to be deleted
      if (node->data == key) { //if found
        z = node; // node to be deleted
      }

      if (node->data <= key) {//if the key is greater than the current node, go to the right child
        node = node->right;//otherwise, go to the left child
      } else {
        node = node->left;//otherwise, go to the left child
      }
    }

    if (z == TNULL) { //if the node to be deleted is not found
      cout << "Key not found in the tree" << endl; 
      return;
    }

    y = z; //y is the node to be deleted
    int y_original_color = y->color; //store the original color of the node to be deleted
    if (z->left == TNULL) {
      x = z->right; //if the left child of the node to be deleted is null, replace it with the right child
      rbTransplant(z, z->right); //replace the node to be deleted with the right child
    } else if (z->right == TNULL) { //if the right child of the node to be deleted is null, replace it with the left child
      x = z->left;//if the left child of the node to be deleted is null, replace it with the right child
      rbTransplant(z, z->left); //replace the node to be deleted with the left child
    } else {
      y = minimum(z->right); //find the minimum node in the right subtree of the node to be deleted
      y_original_color = y->color; //store the original color of the minimum node
      x = y->right; //x is the right child of the minimum node
      if (y->parent == z) { //if the parent of the minimum node is the node to be deleted
        x->parent = y; //the parent of x becomes y
      } else {
        rbTransplant(y, y->right);  //replace the minimum node with its right child
        y->right = z->right; //the right child of y becomes the right child of the node to be deleted
        y->right->parent = y; // the parent of the right child of y becomes y
      }
      rbTransplant(z, y); //replace the node to be deleted with the minimum node
      y->left = z->left; //the left child of y becomes the left child of the node to be deleted
      y->left->parent = y; // the parent of the left child of y becomes y
      y->color = z->color;  //the color of y becomes the color of the node to be deleted
    }
    delete z;
    if (y_original_color == 0) {    //if the original color of the minimum node is black
      deleteFix(x);            //balance the tree
    }
  }

  // For balancing the tree after insertion
  void insertFix(NodePtr k) {
    NodePtr u;  //uncle
    while (k->parent->color == 1) {   //while the parent of k is red
      if (k->parent == k->parent->parent->right) {  //if the parent of k is the right child of its parent
        u = k->parent->parent->left;  //u is the left child of the grandparent of k
        if (u->color == 1) {  //if u is red
          u->color = 0; //u becomes black
          k->parent->color = 0; //the parent of k becomes black
          k->parent->parent->color = 1; //the grandparent of k becomes red
          k = k->parent->parent;  //k becomes the grandparent of k
        } else {  //if u is black
          if (k == k->parent->left) { //if k is the left child of its parent
            k = k->parent;  //k becomes its parent
            rightRotate(k); //right rotate at k
          }
          k->parent->color = 0; //the parent of k becomes black
          k->parent->parent->color = 1;  //the grandparent of k becomes red
          leftRotate(k->parent->parent);   //left rotate at the grandparent of k
        }
      } else {
        u = k->parent->parent->right; //u is the right child of the grandparent of k

        if (u->color == 1) {  //if u is red
          u->color = 0; //u becomes black
          k->parent->color = 0; //the parent of k becomes black
          k->parent->parent->color = 1; //the grandparent of k becomes red
          k = k->parent->parent;  //k becomes the grandparent of k
        } else { 
          if (k == k->parent->right) {  //if k is the right child of its parent
            k = k->parent;  //k becomes its parent
            leftRotate(k);  //left rotate at k
          }
          k->parent->color = 0; //the parent of k becomes black
          k->parent->parent->color = 1 ;  //the grandparent of k becomes red
          rightRotate(k->parent->parent);   //right rotate at the grandparent of k
        }
      }
      if (k == root) {  //if k becomes the root
        break;
      }
    }
    root->color = 0;  //the root becomes black
  }

  void printHelper(NodePtr root, string indent, bool last) {
    if (root != TNULL) {
      cout << indent;
      if (last) {
        cout << "R----";
        indent += "   ";
      } else {
        cout << "L----";
        indent += "|  ";
      }

      string sColor = root->color ? "RED" : "BLACK";
      cout << root->data << "(" << sColor << ")" << endl;
      printHelper(root->left, indent, false);
      printHelper(root->right, indent, true);
    }
  }

   public:
  RedBlackTree() {
    TNULL = new Node;
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
  }

  NodePtr minimum(NodePtr node) {
    while (node->left != TNULL) {
      node = node->left;
    }
    return node;
  }

  NodePtr maximum(NodePtr node) {
    while (node->right != TNULL) {
      node = node->right;
    }
    return node;
  }

  // Left rotate  at node x
  void leftRotate(NodePtr x) {
    NodePtr y = x->right; //y is the right child of x
    x->right = y->left;   //the left child of y becomes the right child of x
    if (y->left != TNULL) { //if the left child of y is not null
      y->left->parent = x;  //the parent of the left child of y becomes x
    }
    y->parent = x->parent;  //the parent of y becomes the parent of x
    if (x->parent == nullptr) { //if the parent of x is null
      this->root = y; //y becomes the root
    } else if (x == x->parent->left) {  //if x is the left child of its parent
      x->parent->left = y;  //the left child of the parent of x becomes y
    } else {
      x->parent->right = y; //the right child of the parent of x becomes y
    }
    y->left = x;    //the left child of y becomes x
    x->parent = y;    //the parent of x becomes y
  }

  // Right rotate  at node x 
  void rightRotate(NodePtr x) { 
    NodePtr y = x->left;  //y is the left child of x
    x->left = y->right;  //the right child of y becomes the left child of x
    if (y->right != TNULL) {  //if the right child of y is not null
      y->right->parent = x; //the parent of the right child of y becomes x
    }
    y->parent = x->parent;  //the parent of y becomes the parent of x
    if (x->parent == nullptr) { //if the parent of x is null
      this->root = y; //y becomes the root
    } else if (x == x->parent->right) { //if x is the right child of its parent
      x->parent->right = y; //the right child of the parent of x becomes y
    } else {
      x->parent->left = y;  //the left child of the parent of x becomes y
    }
    y->right = x; //the right child of y becomes x
    x->parent = y;   //the parent of x becomes y
  }

  // Inserting a node
  void insert(int key) {  //inserting a node with key value
    NodePtr node = new Node;  //creating a new node
    node->parent = nullptr; //the parent of the new node is null
    node->data = key; //the key of the new node is the key value
    node->left = TNULL; //the left child of the new node is null
    node->right = TNULL;  //the right child of the new node is null
    node->color = 1;  //the color of the new node is red

    NodePtr y = nullptr;  //y is the parent of x
    NodePtr x = this->root; //x is the root

    while (x != TNULL) {  //while x is not null
      y = x;  //y becomes x
      if (node->data < x->data) { //if the key of the new node is less than the key of x
        x = x->left;  //x becomes the left child of x
      } else {  //if the key of the new node is greater than the key of x
        x = x->right; //x becomes the right child of x
      }
    }

    node->parent = y; //the parent of the new node becomes y
    if (y == nullptr) {   //if y is null
      root = node;  //the new node becomes the root
    } else if (node->data < y->data) {  //if the key of the new node is less than the key of y
      y->left = node; //the new node becomes the left child of y
    } else {    
      y->right = node;  //the new node becomes the right child of y
    }

    if (node->parent == nullptr) {  //if the parent of the new node is null
      node->color = 0;  //the color of the new node becomes black
      return;
    }

    if (node->parent->parent == nullptr) {  //if the grandparent of the new node is null
      return; 
    } 

    insertFix(node);  //fixing the tree
  }

  NodePtr getRoot() {
    return this->root;
  }

  void deleteNode(int data) {
    deleteNodeHelper(this->root, data);
  }

  void printTree() {
    if (root) {
      printHelper(this->root, "", true);
    }
  }
};

int main() {
  RedBlackTree bst;
  bst.insert(55);
  bst.insert(40);
  bst.insert(65);
  bst.insert(60);
  bst.insert(75);
  bst.insert(57);

  bst.printTree();
  cout << endl
     << "After deleting" << endl;
  bst.deleteNode(40);
  bst.printTree();
}
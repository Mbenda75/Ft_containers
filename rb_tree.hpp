# ifndef RB_TREE_HPP
# define RB_TREE_HPP


/*  -Every node is either red or black.
    -All NIL nodes (figure 1) are considered black.
    -A red node does not have a red child.
    -Every path from a given node to any of its descendant NIL nodes goes through the same number of black nodes
    https://www.programiz.com/dsa/red-black-tree
    https://www.youtube.com/watch?v=h1Z8_ebEqao&t=1272s
    https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
*/
namespace ft{

enum Rb_color { red = false, black = true };

template <class T>
struct nodeRB
{
  typedef T value_type;
  typedef nodeRB* ptr;
  typedef const nodeRB* const_ptr;
  

  value_type value; 
  Rb_color  color;
  ptr       parent;
  ptr       left;
  ptr       right;

};

template<class Key, class Val, class KeyOfValue, class Compare, class Alloc> 
class rbTree
{
    public :

      typedef Val			value_type;
		  typedef Key			key_type;
		  typedef Compare		key_compare;
		  typedef Alloc 		allocator_type;
      typedef std::size_t size_type;
  
		  typedef nodeRB<value_type>	node_type;
		  typedef nodeRB<value_type>*	node_ptr;
      
    private :

      node_ptr root;
      node_ptr nil;
      size_type size;
      key_compare comp;
      allocator_type alloc;


    public :

      rbTree() : root(nullptr), nil(nullptr), size(0), comp(), alloc() {}

      void deleteFix(rbTree x) {
      rbTree s;  //sibling
      while (x != root && x->color == 0) {    //while x is not root and x is black
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

      void rbTransplant(rbTree u, rbTree v) { //replaces one subtree as a child of its parent with another subtree
        if (u->parent == nullptr) { //if u is the root
          root = v; //v becomes the root
        } else if (u == u->parent->left) { //if u is a left child
          u->parent->left = v; //v becomes the left child
        } else {
          u->parent->right = v; //v becomes the right child
        }
        v->parent = u->parent; //the parent of v becomes the parent of u
      }

      void deleteNodeHelper(rbTree node, int key) {
        rbTree z = nil; //node to be deleted
        rbTree x, y;
        while (node != nil) { //searching for the node to be deleted
          if (node->data == key) { //if found
            z = node; // node to be deleted
          }

          if (node->data <= key) {//if the key is greater than the current node, go to the right child
            node = node->right;//otherwise, go to the left child
          } else {
            node = node->left;//otherwise, go to the left child
          }
        }

        if (z == nil) { //if the node to be deleted is not found
          cout << "Key not found in the tree" << endl; 
          return;
        }

        y = z; //y is the node to be deleted
        int y_original_color = y->color; //store the original color of the node to be deleted
        if (z->left == nil) {
          x = z->right; //if the left child of the node to be deleted is null, replace it with the right child
          rbTransplant(z, z->right); //replace the node to be deleted with the right child
        } else if (z->right == nil) { //if the right child of the node to be deleted is null, replace it with the left child
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
      void insertFix(rbTree k) {
        rbTree u;  //uncle
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

      void printHelper(rbTree root, string indent, bool last) {
        if (root != nil) {
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

      rbTree minimum(rbTree node) {
        while (node->left != nil) {
          node = node->left;
        }
        return node;
      }

      rbTree maximum(rbTree node) {
        while (node->right != nil) {
          node = node->right;
        }
        return node;
      }

      // Left rotate  at node x
      void leftRotate(rbTree x) {
        rbTree y = x->right; //y is the right child of x
        x->right = y->left;   //the left child of y becomes the right child of x
        if (y->left != nil) { //if the left child of y is not null
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
      void rightRotate(rbTree x) { 
        rbTree y = x->left;  //y is the left child of x
        x->left = y->right;  //the right child of y becomes the left child of x
        if (y->right != nil) {  //if the right child of y is not null
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
        rbTree node = new Node;  //creating a new node
        node->parent = nullptr; //the parent of the new node is null
        node->data = key; //the key of the new node is the key value
        node->left = nil; //the left child of the new node is null
        node->right = nil;  //the right child of the new node is null
        node->color = 1;  //the color of the new node is red

        rbTree y = nullptr;  //y is the parent of x
        rbTree x = this->root; //x is the root

        while (x != nil) {  //while x is not null
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

      rbTree getRoot() {
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

      rbTree minimum(rbTree node) {
    while (node->left != nil) { //while the left child of node is not null
      node = node->left;  //node becomes the left child of node
    }
    return node;
  }

  rbTree maximum(rbTree node) {   
    while (node->right != nil) {  //while the right child of node is not null
      node = node->right; //node becomes the right child of node 
    }
    return node;
  }

  rbTree successor(rbTree x) {
    if (x->right != nil) {    //if the right child of x is not null
      return minimum(x->right); //return the minimum of the right child of x
    }

    rbTree y = x->parent; //y is the parent of x
    while (y != nil && x == y->right) { //while y is not null and x is the right child of y
      x = y;  //x becomes y
      y = y->parent;  //y becomes the parent of y
    }
    return y;
  }

  rbTree predecessor(rbTree x) {
    if (x->left != nil) { //if the left child of x is not null
      return maximum(x->left);  //return the maximum of the left child of x
    }

    rbTree y = x->parent; //y is the parent of x
    while (y != nil && x == y->left) {  //while y is not null and x is the left child of y    
      x = y;  //x becomes y   
      y = y->parent;  //y becomes the parent of y
    }
    return y;

  }
  rbTree searchTreeHelper(rbTree node, int key) {
    if (node == nil || key == node->data) { //if the node is null or the key is equal to the key of the node
      return node;
    }

    if (key < node->data) { //if the key is less than the key of the node
      return searchTreeHelper(node->left, key); //search the left subtree
    }
    return searchTreeHelper(node->right, key);  //search the right subtree
  }

  rbTree searchTree(int k) {
    return searchTreeHelper(this->root, k); 
  }
};    
}

  

#endif
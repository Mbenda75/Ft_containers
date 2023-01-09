
#ifndef RB_TREE_HPP
# define RB_TREE_HPP

#include <memory>
#include "rb_node.hpp"
#include "rb_iterator.hpp"


/*
	The binary tree is Red Black tree !
	SOURCES :
		- https://www.youtube.com/watch?v=h1Z8_ebEqao&t=1272s (main source)
		- https://www.cs.usfca.edu/~galles/visualization/RedBlack.html (visualizer)
		- https://www.happycoders.eu/algorithms/red-black-tree-java/ (rb tree in java)
		- https://www.programiz.com/dsa/red-black-tree
	
	The rule of rb tree:
		- Each node is either red or black.
		- (The root is black.)
		- All NIL leaves are black.
		- A red node must not have red children.
		- All paths from a node to the leaves below contain the same number of black nodes.

	Other rules of the rb tree with a pair
		- You can't have the same key in the tree but you can have a same key value !
		If the rule are not respected:
			- If the Uncle of the new node is red. We need to do a color flip
			- If the Uncle of the new node is black. We need to do a rotate 
	The _end variable is because the an iterator can't be NULL
*/

namespace ft
{
	template <class Key, class T, class KeyOfValue, class Compare, class Alloc>
	class rbTree
	{
	public:

		typedef T			value_type;	// value_type is the type of the value
		typedef Key			key_type;	// key_type is the type of the key
		typedef Compare		key_compare;	// key_compare is the comparison function for the key
		typedef Alloc 		allocator_type;	// allocator_type is the allocator for the node

		typedef Node<value_type>	node_type;	// node_type is the node
		typedef Node<value_type>*	node_ptr;	// node_ptr is the pointer to the node
		typedef typename allocator_type::template rebind<Node<T> >::other pair_alloc_type;	// pair_alloc_type is the allocator for the node

		typedef std::size_t size_type;

		rbTree(const key_compare &comp = key_compare(), const pair_alloc_type &alloc = pair_alloc_type()): _comp(comp), _alloc(alloc), _size(0)
		{
			_end = _alloc.allocate(1);
			_alloc.construct(_end, node_type(value_type(), NULL, NULL, NULL, black));
			_root = _end;
		}

		 ~rbTree()
		{
			clear_h(_root);
			_alloc.destroy(_end);
			_alloc.deallocate(_end, 1);
		}
	private:
		node_ptr 		_root;	// root of the tree
		node_ptr		_end;	// end of the tree
		key_compare 	_comp;	// comparison function for the key
		pair_alloc_type	_alloc;	// allocator for the node
		size_type 		_size;	// size of the tree
	public:
		node_ptr getRoot() const
		{
			return (this->_root);
		}

		node_ptr getEnd() const
		{
			return (this->_end);
		}

		size_type getSize() const
		{
			return (this->_size);
		}

		size_type max_size() const
		{
			return (_alloc.max_size());
		}

		// find the node with the minimum key
		node_ptr mini() const
		{
			node_ptr node = _root;
			if (node == _end)
				return _root;
			while (node->left != _end)
				node = node->left;
			return node;
		}

		// find the node with the minimum key
		node_ptr mini(node_ptr node) const
		{
			if (node == _end)
				return _root;
			while (node->left != _end)
				node = node->left;
			return node;
		}

		void left_rotate(node_ptr x)
		{
			node_ptr y = x->right; // y saves x's right branch

			x->right = y->left; // x's new right child is y's old left child
			if (y->left != _end)
				y->left->parent = x;
			y->parent = x->parent; // y is new x so it takes old x's parent
			if (x->parent == NULL)
				this->_root = y;
			else if (x == x->parent->left) // if x was it's parent's left child, y becomes it's new parent's left child
				x->parent->left = y;
			else
				x->parent->right = y; // mirror case
			y->left = x;
			x->parent = y;
		}

		void right_rotate(node_ptr x) // mirror case
		{
			node_ptr y = x->left;

			x->left = y->right;
			if (y->right != _end)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				this->_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->right = x;
			x->parent = y;
		}

		void fixInsert(node_ptr z)  // fix the color of all node and the balancing of the tree
		{
			node_ptr u;
			while (z->parent->_color == red)
			{
				if (z->parent == z->parent->parent->right) // parent is gp's right child
				{
					u = z->parent->parent->left; // uncle is left
					if (u->_color == red) // if uncle also red so color flip
					{
						u->_color = black;	// uncle is black now	
						z->parent->_color = black; // parent is black now 
						z->parent->parent->_color = red;	// gp is red now 
						z = z->parent->parent;	// z is gp now and we check it's color again
					}
					else // the uncle is black so rotate
					{
						if (z == z->parent->left) // z is left child
						{
							z = z->parent; // z is save in z's parent !
							right_rotate(z); // new z is old parent
						}
						z->parent->_color = black;	// parent is black now 	
						z->parent->parent->_color = red; // gp is red now 
						left_rotate(z->parent->parent);	 // gp is new z and we rotate it to the left 
					}
				}
				else // parent is gp's left child #mirror_case
				{
					u = z->parent->parent->right; // uncle
					if (u->_color == red)	// uncle is red	 #mirror_case	 
					{
						u->_color = black;
						z->parent->_color = black;
						z->parent->parent->_color = red;
						z = z->parent->parent;
					}
					else
					{
						if (z == z->parent->right)
						{
							// mirror case
							z = z->parent; // z is save in z's parent !
							left_rotate(z);
						}
						// mirror case
						z->parent->_color = black;
						z->parent->parent->_color = red;
						right_rotate(z->parent->parent);
					}
				}
				if (z == _root)
					break;
			}
			_root->_color = black; // root is black
		}

		node_ptr insertNode(const value_type &data)
		{
			node_ptr node;
			node = _alloc.allocate(1);
			_alloc.construct(node, node_type(data, NULL, _end, _end, red)); // create new node

			node_ptr y = NULL;
			node_ptr x = this->_root;

			while (x != _end) // find node's natural placement
			{
				y = x; // y is parent of x 
				if (_comp(KeyOfValue()(node->data), KeyOfValue()(x->data))) // if node's key is smaller than x's key
					x = x->left;
				else if (_comp(KeyOfValue()(x->data), KeyOfValue()(node->data))) // if node's key is bigger than x's key
					x = x->right;
				else
				{
					_alloc.destroy(node); // if the key already exist, destroy the node and return end
					_alloc.deallocate(node, 1); // and return end  iterator
					return _end;
				}
			}
			node->parent = y; //	place the new node at it's right placement 
			if (y == NULL) // Root case
			{
				_size++; 
				this->_root = node; // if the tree is empty, the new node is the root	
				node->_color = black; // root is black
				return (this->_root); // return the root
			}
			else if (_comp(KeyOfValue()(node->data), KeyOfValue()(y->data))) // place the new node at it's right placement
				y->left = node;// if node's key is smaller than y's key
			else
				y->right = node;
			this->_size++;
			if (node->parent->parent == NULL) // if the grandparent is null, simply return
				return (node); 
			fixInsert(node); 
			return (node);
		}

		bool deleteNode(key_type key)
		{
			return (_erase(key));
		}

		// search the tree for the key k and return the corresponding node
		node_ptr searchTree(key_type k) const
		{
			return _search_node(this->_root, k); // call the recursive function to search the tree
		}

		void clear_h(node_ptr const &node)
		{
			clear_all(node);
			this->_root = _end;
		}

		void clear_all(node_ptr const &node)
		{
			if (node == _end) // break of the recursion
				return;
			clear_all(node->left); // left subtree first then right subtree 
			clear_all(node->right);	 	// then delete the node
			_alloc.destroy(node);	// destroy the node
			_alloc.deallocate(node, 1);	// deallocate the node
			_size--;
		}

		void swap(rbTree &x)
		{
			std::swap(this->_root, x._root);
			std::swap(this->_end, x._end);
			std::swap(this->_size, x._size);
		}

		void rbTransplant(node_ptr u, node_ptr v) // replaces u by v
		{
			if (u->parent == NULL)
				_root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		// fix the rb tree modified by the delete operation
		void fixDelete(node_ptr x)
		{
			node_ptr w;

			while (x != this->_root && x->_color == black)
			{
				if (x == x->parent->left) // if x is the left child
				{
					w = x->parent->right; // w is x's right brother
					if (w->_color == red)
					{
						w->_color = black; // case 1 : w is red -> change color and rotate around x's parent to get a black brother (case 2, 3 or 4)
						x->parent->_color = red;	// x's parent is now red because of the rotation (case 1)
						left_rotate(x->parent); // new parent is w, old parent p became w's left child, p is still x's parent and x->parent->right bacame old w->left
						w = x->parent->right;	// w is now x's new right brother (case 2, 3 or 4)
					}

					if (w->left->_color == black && w->right->_color == black) 
					{
						w->_color = red; // case 2 : w is black and both of his children are black -> change color of w to red and go up the tree
						x = x->parent; // x's parent is now black because of the rotation (case 1) and x is now black because of the color change (case 2)
					}
					else // at least one child is red
					{
						if (w->right->_color == black) // left child is red
						{
							w->left->_color = black; // case 3 : w is black, left child is red and right child is black -> change color of left child to black and rotate around w to get a red right child (case 4)
							w->_color = red; // w is now red because of the rotation (case 3)
							right_rotate(w); // new parent is w->left, old parent w became w->left->right, w is still x's parent and x->parent->right bacame old w->left->right
							w = x->parent->right; // w is now x's new right brother (case 4)
						}
						w->_color = x->parent->_color; 		// case 4 : w is black and right child is red -> change color of w to x's parent color and color of x's parent to black and color of w's right child to black
						x->parent->_color = black;		// x's parent is now black because of the rotation (case 3) and x is now black because of the color change (case 4)
						w->right->_color = black;	// w's right child is now black because of the color change (case 4)
						left_rotate(x->parent);	// new parent is w, old parent p became w's left child, p is still x's parent and x->parent->right bacame old w->left
						x = _root;	// x is now the root of the tree and is black because of the color change (case 4)
					}
				}
				else // mirror case
				{
					w = x->parent->left;
					if (w->_color == red)
					{
						w->_color = black;
						x->parent->_color = red;
						right_rotate(x->parent);
						w = x->parent->left;
					}

					if (w->left->_color == black && w->right->_color == black)
					{
						w->_color = red;
						x = x->parent;
					}
					else
					{
						if (w->left->_color == black)
						{
							w->right->_color = black;
							w->_color = red;
							left_rotate(w);
							w = x->parent->left;
						}
						w->_color = x->parent->_color;
						x->parent->_color = black;
						w->left->_color = black;
						right_rotate(x->parent);
						x = _root;
					}
				}
			}
			x->_color = black; // root is black no matter what
		}

		bool _erase(key_type key)
		{
			node_ptr z, x, y;

			z = searchTree(key);
			if (z == _end)
				return false;

			y = z; // y saves the suppressed node's placement
			rbColor y_og_color = y->_color;
			if (z->left == _end) // z only had 1 child whitch is the right one so so it get's replaced by it's child
			{
				x = z->right; // x saves the right child's branch
				rbTransplant(z, z->right);
			}
			else if (z->right == _end) //mirror case
			{
				x = z->left;
				rbTransplant(z, z->left);
			}
			else // suppressed node had 2 children and is replaced by the minimum of it's right branch
			{
				y = mini(z->right); // search for the minimum in the right child's branch
				y_og_color = y->_color;
				x = y->right; // x saves the minimum's right branch
				if (y->parent == z) // the minimum is z->right
					x->parent = y;
				else
				{
					rbTransplant(y, y->right); // replaces the minimum by it's right branch
					y->right = z->right; // set the new z's right side
					y->right->parent = y;
				}
				rbTransplant(z, y); // replace z by the correct value whitch is y and maintain the tree as a good search tree
				y->left = z->left;
				y->left->parent = y;
				y->_color = z->_color;
			}
			_alloc.destroy(z);
			_alloc.deallocate(z, 1);
			_size--;
			if (y_og_color == black) // fix the lost black color on x
				fixDelete(x);
			return true;
		}

		node_ptr _search_node(node_ptr node, key_type key) const
		{
			if (node == _end)
				return _end;
			if (key == KeyOfValue()(node->data))
				return node;
			if (node != _end)
			{
				if (_comp(key, KeyOfValue()(node->data))) // if key < node->data  go left
					return _search_node(node->left, key);
				return _search_node(node->right, key);
			}
			return _end;
		}
	};
};

#endif
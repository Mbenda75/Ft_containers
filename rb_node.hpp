#ifndef RB_NODE_HPP
#define RB_NODE_HPP

namespace ft {
enum	rbColor {red, black};
template <class T>
struct Node {
		typedef	T		value_type;
		
		value_type		data; // holds the key
		struct Node	*parent; // pointer to the parent
		struct Node	*left; // pointer to left child
		struct Node	*right; // pointer to right child
		rbColor		_color; // 0 -> Red, 1 -> Black
		Node(value_type data, Node* parent, Node* left, Node* right, rbColor clr): data(data), parent(parent), left(left), right(right), _color(clr) {}
};
}

#endif
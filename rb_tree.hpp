# ifndef RB_TREE_HPP
# define RB_TREE_HPP


/*  -Every node is either red or black.
    -All NIL nodes (figure 1) are considered black.
    -A red node does not have a red child.
    -Every path from a given node to any of its descendant NIL nodes goes through the same number of black nodes
    https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
*/
namespace ft{

enum Rb_color { red = false, black = true };

struct Rb_tree_base
{
  typedef Rb_tree_base* _ptr;
  typedef const Rb_tree_base* _const_ptr;
  
  Rb_color  _color;
  _ptr       _parent;
  _ptr       _left;
  _ptr       _right;

};

template<class Key, class Val, class KeyOfValue,
class Compare, class alloc> 
class rb_tree
{

};

}



#endif
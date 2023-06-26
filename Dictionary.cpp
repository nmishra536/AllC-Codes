

/************************************************************
Navya Mishra
nmishra3
PA 8
***********************************************************/
//-----------------------------------------------------------------------------
// Dictionary.cpp
// Implementation file for Dictionary ADT based on a Binary Search Tree. Includes
// a built-in iterator called current, that can perform a smallest-to-largest
// (forward) or a largest-to-smallest (reverse) iteration over all keys.
//-----------------------------------------------------------------------------
#include "Dictionary.h"
#include <cstring>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>



//**************************************************
//
//	This pseudo code would be my last one for the quarter.
//  The next assignment is basically the same thing plus 6 or so more functions.
//  I wont be implementing them, because the line by line code is LITERALLY given by
//  The Professor/Father himself. You will notice most of these functions are found in this link:
//  https://people.ucsc.edu/~ptantalo/cse101/Winter23/Examples/Pseudo-Code/BST-RBT-Algorithms 
//  That being said, you guys should be able to handle pa8 on your own.
//  Hope I delivered my best effort for ya'll, 'twas a pleasure tutoring you guys.
//  If you ever need advise or guidance regarding this course or other courses, shoot me an email fs. 
//  Best of luck with finals, labs, whatever else.
//  Hope to see some of you guys in CSE130 and or CSE185, we'll get to struggle together now.
//
//  -Mike
//
//**************************************************


// Private Constructor --------------------------------------------------------

// Node constructor
Dictionary::Node::Node(keyType k, valType v){
   //set key to k, val to v, left & right & parent nodes to null pointers
    key = k;
    val = v;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    color = BLACK;
}

// Helper Functions (Optional) ------------------------------------------------

   /*void Dictionary::RB_Insert(Node* N) {
        Node* y = nil;
        Node* x = root;
        while (x != nil) {
            y = x;
            if (N->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        N->parent = y;
        if (y == nil) {
            root = N;
        } else if (N->key < y->key) {
            y->left = N;
        } else {
            y->right = N;
        }
        N->left = nil;
        N->right = nil;
        N->color = RED;
        RB_InsertFixUp(N);
    }*/

// LeftRotate()
   void Dictionary:: LeftRotate(Node* N){
   Node* y = N->right;
    N->right = y->left;

    if (y->left != nil) {
        y->left->parent = N;
    }

    y->parent = N->parent;
    if (N->parent == nil) {
        root = y;
    } else if (N == N->parent->left) {
        N->parent->left = y;
    } else {
        N->parent->right = y;
    }

    y->left = N;
    N->parent = y;
   }

   // RightRotate()
   void Dictionary::RightRotate(Node* N){
        // set y
    Node* y = N->left;
    
    // turn y's right subtree into x's left subtree
    N->left = y->right;
    if (y->right != nil) {
        y->right->parent = N;
    }
    
    // link y's parent to x
    y->parent = N->parent;
    if (N->parent == nil) {
        root = y;
    }
    else if (N == N->parent->right) {
        N->parent->right = y;
    }
    else {
        N->parent->left = y;
    }
    
    // put x on y's right
    y->right = N;
    N->parent = y;
   }

   // RB_InsertFixUP()
   void Dictionary:: RB_InsertFixUp(Node* N){
      while (N->parent->color == RED) {
        if (N->parent == N->parent->parent->left) {
            Node* y = N->parent->parent->right;
           // std::cout << "1" << std::endl;
            if (y->color == RED) {
               // std::cout << "2" << std::endl;
                N->parent->color = BLACK;              // case 1
                y->color = BLACK;                      // case 1
                N->parent->parent->color = RED;        // case 1
                N = N->parent->parent;                 // case 1
            }
            else {
                //std::cout << "3" << std::endl;
                if (N == N->parent->right) {
                  // std::cout << "4" << std::endl;
                    N = N->parent;                     // case 2
                    LeftRotate(N);                     // case 2
                }
                N->parent->color = BLACK;              // case 3
                N->parent->parent->color = RED;        // case 3
                RightRotate(N->parent->parent);        // case 3
            }
        }
        else {
         // std::cout << "5" << std::endl;
            Node* y = N->parent->parent->left;
            if (y->color == RED) {
               // std::cout << "6" << std::endl;
                N->parent->color = BLACK;              // case 4
                y->color = BLACK;                      // case 4
                N->parent->parent->color = RED;        // case 4
                N = N->parent->parent;                 // case 4
            }
            else {
               // std::cout << "7" << std::endl;
                if (N == N->parent->left) {
                 //  std::cout << "8" << std::endl;

                    N = N->parent;                     // case 5
                    RightRotate(N);                    // case 5
                }
                N->parent->color = BLACK;              // case 6
                N->parent->parent->color = RED;        // case 6
                LeftRotate(N->parent->parent);         // case 6
            }
        }
    }
    // std::cout << "done" << std::endl;
    root->color = BLACK;
   }

   // RB_Transplant()
   void Dictionary::RB_Transplant(Node* u, Node* v){
   if (u->parent == nil) {
      root = v;
   } else if (u == u->parent->left) {
      u->parent->left = v;
   } else {
      u->parent->right = v;
   }
   v->parent = u->parent;
   }

   // RB_DeleteFixUp()
   void Dictionary::RB_DeleteFixUp(Node* N){
      while (N != root && N->color == BLACK)
   {
      if (N == N->parent->left)
      {
         Node* W = N->parent->right;
         if (W->color == RED)
         {
            W->color = BLACK;                    // case 1
            N->parent->color = RED;              // case 1
            LeftRotate(N->parent);            // case 1
            W = N->parent->right;                // case 1
         }
         if (W->left->color == BLACK && W->right->color == BLACK)
         {
            W->color = RED;                      // case 2
            N = N->parent;                       // case 2
         }
         else 
         {
            if (W->right->color == BLACK)
            {
               W->left->color = BLACK;           // case 3
               W->color = RED;                   // case 3
               RightRotate(W);                // case 3
               W = N->parent->right;             // case 3
            }
            W->color = N->parent->color;          // case 4
            N->parent->color = BLACK;             // case 4
            W->right->color = BLACK;              // case 4
            LeftRotate(N->parent);             // case 4
            N = root;                           // case 4
         }
      }
      else 
      {
         Node* W = N->parent->left;
         if (W->color == RED)
         {
            W->color = BLACK;                    // case 5
            N->parent->color = RED;              // case 5
            RightRotate(N->parent);           // case 5
            W = N->parent->left;                 // case 5
         }
         if (W->right->color == BLACK && W->left->color == BLACK)
         {
            W->color = RED;                      // case 6
            N = N->parent;                       // case 6
         }
         else 
         {
            if (W->left->color == BLACK)
            {
               W->right->color = BLACK;          // case 7
               W->color = RED;                   // case 7
               LeftRotate(W);                 // case 7
               W = N->parent->left;              // case 7
            }
            W->color = N->parent->color;          // case 8
            N->parent->color = BLACK;             // case 8
            W->left->color = BLACK;               // case 8
            RightRotate(N->parent);            // case 8
            N = root;                           // case 8
         }
      }
   }
   N->color = BLACK;
   }

   // RB_Delete()
   void Dictionary:: RB_Delete(Node* N){
      Node* y = N;
Node* x;
int y_original_color = y->color;
if (N->left == nil) {
   x = N->right;
   RB_Transplant(N, N->right);
} else if (N->right == nil) {
   x = N->left;
   RB_Transplant(N, N->left);
} else {
      y = findMin(N->right);
      y_original_color = y->color;
      x = y->right;
   if (y->parent == N) {
      x->parent = y;
   } else {
      RB_Transplant(y, y->right);
      y->right = N->right;
      y->right->parent = y;
   }
   RB_Transplant(N, y);
      y->left = N->left;
      y->left->parent = y;
      y->color = N->color;
}
if (y_original_color == BLACK) {
   RB_DeleteFixUp(x);
}
   }


// inOrderString()
// Appends a string representation of the tree rooted at R to s. The appended
// string consists of: "key : value\n" for each key-value pair in the tree
// rooted at R, arranged in order by keys.
void Dictionary::inOrderString(std::string& s, Node* R) const{
   //if R is not nil{:
   if (R != nil){
        inOrderString(s, R->left);
     // recursively call inOrderString on the left node of R
       //std::string key_str(R->key);
       //s.append(key_str);
       //s.append( ": ");
       //s.append(std::to_string(R->val));

       //s += key_str + ": " + std::to_string(R->val) + "\n";
        //std::string key_str = R->key.substr(1);
        s +=  R->key + " : " + std::to_string(R->val) + "\n";
     // append the node's key and value (using to string function) to "s"
      //// should like like this: "<key> : <value>\n"
        inOrderString(s, R->right);
        //recursively call inOrderString on the right node of R
   }
}

// preOrderString()
// Appends a string representation of the tree rooted at R to s. The appended
// string consists of keys only, separated by "\n", with the order determined
// by a pre-order tree walk.
void Dictionary:: preOrderString(std::string& s, Node* R) const{
   //if R is not nil
    if (R != nil) {
      //append the node's key to "s"
       s += R->key + "\n";
      //// should like like this: "key : value\n"
       preOrderString(s, R->left);
      //recursively call inOrderString on the left node of R
       preOrderString(s, R->right);
     // recursively call inOrderString on the right node of R
}
//std::cout<<s<<std::endl;
}

// preOrderCopy()
// Recursively inserts a deep copy of the subtree rooted at R into this
// Dictionary. Recursion terminates at N.
void Dictionary::preOrderCopy(Node* R, Node* N){
   //if R and N are different:
   if (R!=N){
      setValue(R->key, R->val); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!help here
      //set the value of R to its key (there's a function for this)
      preOrderCopy(R->left, N);
      //recursively call preOrderCopy on R->left and N
      preOrderCopy(R->right, N);
      //recursively call preOrderCopy on R->right and N
   }
}

// postOrderDelete()
// Deletes all Nodes in the subtree rooted at R, sets R to nil.
void Dictionary::postOrderDelete(Node* R){
   //if R is not nil:
   if (R != nil) {
      //recursively call postOrderDelete on R->left
       postOrderDelete(R->left);
      //recursively call postOrderDelete on R->right
      postOrderDelete(R->right);
     //.. delete R
     delete R;
     //R = nullptr;

   }
}

// search()
// Searches the subtree rooted at R for a Node with key==k. Returns
// the address of the Node if it exists, returns nil otherwise.
Dictionary::Node* Dictionary::search(Node* R, keyType k) const{
   //iterate as long as R isn't nil:
    while (R != nil) {
	   //if root is nil or k is the same as Node R's key:
		  //return R
          if (R->key == k) { // Found the key
            return R;
        }
	   //else if k is smaller than Node R's key:
		 // set R to its right node
        else if (k < R->key) { // Search in the left subtree
            R = R->left;
        }
	   //else: // k greater than R->key
		 // set R to it's right node
          else { // Search in the right subtree
            R = R->right;
        }
    }
   //return nil
    return nil;
}

// findMin()
// If the subtree rooted at R is not empty, returns a pointer to the
// leftmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMin(Node* R){
   //set a temp node*min to R;
    Node* min = R;
   //if min isn't nil:
   if (min != nil) {
      //loop min to hug (set to) the nodes on the left side of the tree as long as it's not nil
    while (min->left != nil) {
            min = min->left;
        }
   }
   return min;
}

// findMax()
// If the subtree rooted at R is not empty, returns a pointer to the
// rightmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMax(Node* R){
   //same as above but hug the nodes on the right side
    Node* max = R;
    if (max != nil) {
        while (max->right != nil) {
            max = max->right;
        }
    }
    return max;
}

// findNext()
// If N does not point to the rightmost Node, returns a pointer to the
// Node after N in an in-order tree walk.  If N points to the rightmost
// Node, or is nil, returns nil.
Dictionary::Node* Dictionary::findNext(Node* N){
   //if N is nil return nil
    if (N == nil) {
        return nil;

   //else if N->right isn't nil return the minimum of N->right
    } else if (N->right != nil) {
        return findMin(N->right);
   //else:
      //set a temp Node* y to the parent node of N
	  //iterate as long as y isn't nil and N is not y->right:
	     // set N to y and then set y to it's parent node
     } else {
        Node* y = N->parent;
        while (y != nil && N == y->right) {
            N = y;
            y = y->parent;
        }
    
    return y;
     }
}

// findPrev()
// If N does not point to the leftmost Node, returns a pointer to the
// Node before N in an in-order tree walk.  If N points to the leftmost
// Node, or is nil, returns nil.
Dictionary::Node* Dictionary::findPrev(Node* N){
   // same as above but with N->left
    //also instead of finding the minimum find the maximum of N->left
    if (N == nil) {
        return nil; // Return null if N is null
    } else if (N->left != nil) {
        // If N has a left child, return the maximum key in its left subtree
        Node* maxNode = N->left;
        while (maxNode->right != nil) {
            maxNode = maxNode->right;
        }
        return maxNode;
    } else {
        // Otherwise, go up the tree until we find the first left ancestor
        Node* curNode = N;
        Node* parentNode = curNode->parent;
        while (parentNode != nil && curNode == parentNode->left) {
            curNode = parentNode;
            parentNode = curNode->parent;
        }
        return parentNode;
    }
}


// Class Constructors & Destructors -------------------------------------------

// Creates new Dictionary in the empty state.
Dictionary::Dictionary(){
  // set nil to a new Node("someLongAssStringHere", 999) // key shouldn't be something in the dictionary
   nil = new Node("someLongAssStringHere", 999);
   //set the root to nil
   root = nil;
   //set current nil
   current = nil;
   //set num_pairs to 0
   num_pairs = 0;
   nil->color = BLACK;
}

// Copy constructor.
Dictionary::Dictionary(const Dictionary& D){
   // create an empty Dictionary
   //set nil to a new Node("someLongAssStringHere", 999) // key shouldn't be something in the dictionary
   nil = new Node("someLongAssStringHere", 999);
   //set the root to nil
   root = nil;
   //set current nil
   current = nil;
   //set num_pairs to 0
   num_pairs = 0;
   //pre order copy the pairs of D (root of D, nil of D) into this Dictionary 
   preOrderCopy(D.root, D.nil);

}

// Destructor
Dictionary::~Dictionary(){
   //post order delete on the root node
   postOrderDelete(root);
   delete nil;
}


// Access functions --------------------------------------------------------

// size()
// Returns the size of this Dictionary.
int Dictionary::size() const{
   return num_pairs;
}

// contains()
// Returns true if there exists a pair such that key==k, and returns false
// otherwise.
bool Dictionary::contains(keyType k) const{
   //set a temp Node* N to search from the root if k is in the dectionary
   //return N is not nil
   Node* N = search(root, k);
   return N != nil;
}

// getValue()
// Returns a reference to the value corresponding to key k.
// Pre: contains(k)
valType& Dictionary::getValue(keyType k) const{
  // set a temp Node* N to search from the root if k is in the dectionary
  // if N is nil:
     // throw std::logic_error("Dictionary: getValue(): key \""+k+"\" does not exist");
  // return value of N
   Node* N = root;
   while (N != nil) {
      if (k == N->key) {
         return N->val;
      }
      else if (k < N->key) {
         N = N->left;
      }
      else {
         N = N->right;
      }
   }
   throw std::logic_error("Dictionary: getValue(): key \""+k+"\" does not exist");
}


// hasCurrent()
// Returns true if the current iterator is defined, and returns false
// otherwise.
bool Dictionary::hasCurrent() const{
   return (current != nil);
}

// currentKey()
// Returns the current key.
// Pre: hasCurrent()
keyType Dictionary::currentKey() const{
   //if hasCurrent returns false:
    if (!hasCurrent()) {
      throw std::logic_error("Dictionary: currentKey(): current undefined");
   //return the key of current node
     }
   return current->key;
}

// currentVal()
// Returns a reference to the current value.
// Pre: hasCurrent()
valType& Dictionary::currentVal() const{  
   if( !hasCurrent() ){
      throw std::logic_error("Dictionary: currentVal(): current undefined");
    }
     return current->val;
}
  

// Manipulation procedures -------------------------------------------------

// clear()
// Resets this Dictionary to the empty state, containing no pairs.
void Dictionary::clear(){
   //post order delete on the root node
   postOrderDelete(root);
   //set the root to nil
   root = nil;
   //set current nil
   //set num_pairs to 0
   current = nil;
   num_pairs = 0;
}

// setValue()
// If a pair with key==k exists, overwrites the corresponding value with v,
// otherwise inserts the new pair (k, v).
void Dictionary::setValue(keyType k, valType v){
  
  
  
   //set a temp node* P to nil
   Node* P = nil;
   //set a temo node* R to root
   Node* R = root;
   //iterate as long as R is not nil:
   while(R != nil){
      //set P to R
      P = R;
      //check to see if k is smaller than the key of R:
         //if so, shift R to it's left node
        if(k < R->key){
            R = R->left;
        }
      //else if k is greater than the key of R:
         //if so, shift R to it's right node
        else if(k > R->key){
            R = R->right;
        }
      //else:  // k is equal to R->key
        // set the value of R to v
         //return;
          else{
            R->val = v;
            return;
        }
    }

   //set a temp node* N to a new Node of key=k and val=v
   //if P equalls nil:
    Node* N = new Node(k, v);
    if(P == nil){
      //set every member node of N to nil
      //set the root to N;
       N->left = nil;
       N->right = nil;
       N->parent = nil;
       root = N;
       N->color = RED;
    }
   //else if k is smaller than the key of node P:
      //set the left node of P to N
      //set the parent of N to P
      //set the left and right node of N to nil
    else if(k < P->key){
        N->parent = P;
        P->left = N;
        N->left = nil;
        N->right = nil;
        N->color = RED;
        //P->left = N;
       
    } 
   //else:
      //set the right node of P to N
      //set the parent node of N to P
      //set the left and right node of N to nil
      else{
         P->right = N;
        N->parent = P;
        N->left = nil;
        N->right = nil;
        N->color = RED;
        //P->right = N;
        //N->parent = P;
    }

   //increment num_pairs
   num_pairs++;
   RB_InsertFixUp(N);
}

// added a helper function to help with remove()

/*void Dictionary::transplant(Node* u, Node* v) {
   // copied straight from the handout
   //if u.parent == NIL
     // root = v
  // else if u == u.parent.left
     // u.parent.left = v
   //else
     // u.parent.right = v
   //if v != NIL
     // v.parent = u.parent

    if (u->parent == nil) {
      root = v;
   } else if (u == u->parent->left) {
      u->parent->left = v;
   } else {
      u->parent->right = v;
   }
   if (v != nil) {
      v->parent = u->parent;
   }

}*/

// remove()
// Deletes the pair for which key==k. If that pair is current, then current
// becomes undefined.
// Pre: contains(k).
void Dictionary::remove(keyType k){
   //set a temp Node* N to search for k from the root
   
   //assign a new node with key val to search and then remove
   //check if node is nil --> error
   //if curr == node, curr == nil
   // call rb delete on node
   //delete node
   //decrement num of pairs. 

   Node* n = search(root, k);
   if (n == nil){
         throw std::logic_error("Dictionary: remove(): key \""+k+"\" does not exist");

   }
   if (current == n){
      current = nil;
   }
   RB_Delete(n);
   delete(n);
   num_pairs--;
   /*Node* n = root;
   while (n != nullptr && n->key != k) {
        if (k < n->key) {
            n = n->left;
        } else {
            n = n->right;
        }
    }
   //if N is nil:
     // throw std::logic_error("Dictionary: remove(): key \""+k+"\" does not exist");
     if (n == nullptr) {
        throw std::logic_error("Dictionary: remove(): key \"" + k + "\" does not exist");
    }
   //if the left node of N is nil:

      //call transplant on N and it's right node, decrement num_pairs
   //else if the right node of N is nil:
      //call transplant on N and it's left node, derement num_pairs
   if (n->left == nil) {
        RB_Transplant(n, n->right);
    } else if (n->right == nil) {
        RB_Transplant(n, n->left);
    } else {
   //else:
     // make a temp node* y to find the minimum leaf node on the right node of N:
     // if the parent node of y is not the same as N:
        // call transplant on y and it's right node
        // set the right node of y to the right node of N
        // set the parent node of the right node of y to y // confusing shit here
     // else:
        // call transplant on N and y
        // set the left node of y to the left node of N
        // set the parent node of the left node of y to y
     // decrement num_pairs
      Node* y = n->right;
        while (y->left != nil) {
            y = y->left;
        }
        if (y->parent != n) {
            RB_Transplant(y, y->right);
            y->right = n->right;
            y->right->parent = y;
        }
        RB_Transplant(n, y);
        y->left = n->left;
        y->left->parent = y;
    }
    num_pairs--;
    if (current != nil && current->key == k) {
        current = nil;
    }
    delete(n);*/
}

// begin()
// If non-empty, places current iterator at the first (key, value) pair
// (as defined by the order operator < on keys), otherwise does nothing.
void Dictionary::begin(){
   //set the current node to the minimum leaf node from the root
   //std::cout << "in begin()" <<std::endl;
   Node* node = root;
   while (node != nil && node->left != nil) {
      node = node->left;
   }
   current = node;
   //std::cout << "out of begin()" <<std::endl;
}

// end()
// If non-empty, places current iterator at the last (key, value) pair
// (as defined by the order operator < on keys), otherwise does nothing.
void Dictionary::end(){
   //set the current node to the maximum leaf node from the root
    //std::cout << "in end()" <<std::endl;
   //std::cout << "in end()" <<std::endl;
    if (num_pairs == 0 ){
        return;
    }
   //Node* 
   current = root;
//std::cout << "got node" <<std::endl;
   while (current->right != nil) {
  //  std::cout << "in loop" <<std::endl;
      current = current->right;
   }
      //std::cout << "out of end()" <<std::endl;

  // std::cout << "out of loop" <<std::endl;
   //this->current = current;
   //std::cout << current <<std::endl;
}

// next()
// If the current iterator is not at the last pair, advances current
// to the next pair (as defined by the order operator < on keys). If
// the current iterator is at the last pair, makes current undefined.
// Pre: hasCurrent()
void Dictionary::next(){
   //if hasCurrent is false:
      //throw std::logic_error("Dictionary: next(): current not defined");
   //set the current node to the next paired leaf node from the current
 if (!hasCurrent()){
      throw std::logic_error("Dictionary: next(): current not defined");
 }
   Node* curr = current;
   Node* parent = curr->parent;

   if (curr->right != nil) {
      curr = curr->right;
      while (curr->left != nil) {
         curr = curr->left;
      }
      current = curr;
   } else {
    while (parent != nil && curr == parent->right) {
         curr = parent;
         parent = parent->parent;
      }
      if (parent == nil && curr == root->right) {
         current = nil;
      } else {
           current = parent;
      }
   }
}


// prev()
// If the current iterator is not at the first pair, moves current to
// the previous pair (as defined by the order operator < on keys). If
// the current iterator is at the first pair, makes current undefined.
// Pre: hasCurrent()
void Dictionary::prev(){
   //if hasCurrent is false:
      //throw std::logic_error("Dictionary: next(): current not defined");
   //set the current node to the previous paired leaf node from the current
if (!hasCurrent()) {
    throw std::logic_error("Dictionary: prev(): current not defined");
}
if (current->left != nil) {
    // if left child exists, go left then keep going right until leaf
    current = current->left;
    while (current->right != nil) {
    current = current->right;
    }
} else {
    // if left child does not exist, go up to the parent
    Node* parent = current->parent;
    while (parent != nil && current == parent->left) {
        current = parent;
        parent = parent->parent;
    }
    current = parent;
}

}


// Other Functions ------------------------------------------------------------

// to_string()
// Returns a string representation of this Dictionary. Consecutive (key, value)
// pairs are separated by a newline "\n" character, and the items key and value
// are separated by the sequence space-colon-space " : ". The pairs are arranged
// in order, as defined by the order operator <.
std::string Dictionary::to_string() const{
  // create a string "s"
  // perform an in order operation from the root and append to "s"
   //return s
   std::string s;
   inOrderString(s, root);
   return s;


}

// pre_string()
// Returns a string consisting of all keys in this Dictionary. Consecutive
// keys are separated by newline "\n" characters. The key order is given
// by a pre-order tree walk.
std::string Dictionary::pre_string() const{
   //create a string "s"
   //perform an pre order operation from the root and append to "s"
   //return s
   std::string s;
   preOrderString(s, root);
   return s;

}

// equals()
// Returns true if and only if this Dictionary contains the same (key, value)
// pairs as Dictionary D.
bool Dictionary::equals(const Dictionary& D) const{
  // return num_pairs is the same as num_pairs of D and the strings of both Dictionaries
   if (num_pairs != D.num_pairs) {
        return false;
    }
    std::string x;
    std::string y;
    preOrderString(x, root);
    preOrderString(y, root);
    if (y!=x){
        return false;
    }
  /*while (this->current!= nil) {
    if (!D.contains(key) || D.getValue(key) != getValue(key) ) {
        return false;
    }
    next();
}*/

// Check if each pair in the other dictionary exists in this dictionary
/*while (D.current != nil) {
    if (!contains(D->key) || getValue(D->key) != D.getValue(D->key)) {
        return false;
    }
    D.next();
}*/

    
     return true;

}


// Overloaded Operators -------------------------------------------------------

// Ya'll know how to do these by now

// operator<<()
// Inserts string representation of Dictionary D into stream, as defined by
// member function to_string().
std::ostream& operator<<( std::ostream& stream, Dictionary& D ){
    stream << D.to_string();
    return stream;
}

// operator==()
// Returns true if and only if Dictionary A equals Dictionary B, as defined
// by member function equals().
bool operator==( const Dictionary& A, const Dictionary& B ){
  return A.equals(B);
}

// operator=()
// Overwrites the state of this Dictionary with state of D, and returns a
// reference to this Dictionary.
Dictionary& Dictionary::operator=( const Dictionary& D ){
    /*if (this != &D) { // check for self-assignment
// Delete all nodes in this dictionary
    clear();
    }
    Dictionary C = Dictionary(D);
    C.begin();
     while (C.current != nil) {
        std::string curr;
        curr = C.currentKey();
        int val;
        val = C.getValue(curr);
        setValue(curr, val);
        C.next();
    }*/
    Dictionary temp = D;
    std::swap(nil, temp.nil);
    std::swap(root, temp.root);
    std::swap(current, temp.current);
    std::swap(num_pairs, temp.num_pairs);

    return *this;
}


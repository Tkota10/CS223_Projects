/*
Name of File: AVLTree.cpp
Creator: Tarun Kota
Class: CS223, PSET_5(AVL Trees)
Date: 04/17/23
Purpose: This file describes the implementation of an An AVL Tree 
and its various functions. Some of them include insert, rotations, balnce and
remove.
*/

#include <iostream>
#include "AVLTree.h"
#include "pretty_print.h"

using namespace std;

/*
 * Input: data (the value to store), multiplicity of the node, height of the
 *      node, left and right child pointers
 * Returns: avl tree node.
 * Does: creates a new node with values given as input parameter
 */
static Node *new_node(int data, int multiplicity, int height, Node *left, Node *right)
{
    Node *node = new Node();

    node->data = data;
    node->count = multiplicity;
    node->height = height;
    node->left = left;
    node->right = right;

    return node;
}

/*
 * Input: data (the value to store)
 * Returns: avl tree node.
 * Does: calls a helper function to create a new node with default
 *        values parameter
 */
static Node *new_node(int data)
{
    return new_node(data, 1, 0, NULL, NULL);
}

/********************************
 * BEGIN PUBLIC AVLTREE SECTION *
 ********************************/

/*
 * Input: None
 * Returns: instance of the AVLTree class with an empty root node. 
 * Does: It is a constructor for the AVLTree class
 */
AVLTree::AVLTree()
{
    root = NULL;
}

/*
 * Input: a reference to an AVLTree object 
 * Returns: an instance of the AVLTree class that is a copy of 
 * the "source" AVLTree object.
 * Does: a copy constructor that uses pre-order traversal to perform a deep 
 * copy of the contents of the "source" AVLTree object to the new AVLTree 
 * object.
 */
AVLTree::AVLTree(const AVLTree &source)
{
   root=pre_order_copy(source.root); 
}

/*
 * Input: None
 * Returns: None
 * Does: It recursively deletes all the nodes of the AVLTree 
 * object in post-order.
 */
AVLTree::~AVLTree()
{
    post_order_delete(root);
}

/*
 * Input: a reference to an AVLTree object
 * Returns: a reference to the modified AVLTree object
 * Does: overloads the "=" operator for the AVLTree class to perform a deep 
 * copy of the contents of the source AVLTree object to the current AVLTree 
 * object.
 */
AVLTree& AVLTree::operator=(const AVLTree& source) {
    // Check if the source is not the same as this AVLTree object
    if (this == &source)
    {
        return *this;
    }
    // delete current tree if it exists
    post_order_delete(root);
    // use pre-order traversal to copy the tree
    root = pre_order_copy(source.root);
    // don't forget to "return *this"
    return *this;
}


int AVLTree::find_min() const
{
    return find_min(root)->data;
}

int AVLTree::find_max() const
{
    return find_max(root)->data;
}

bool AVLTree::contains(int value) const
{
    return contains(root, value);
}

void AVLTree::insert(int value)
{
    root = insert(root, value);
}

void AVLTree::remove(int value)
{
    root = remove(root, value);
}

int AVLTree::tree_height() const
{
    return tree_height(root);
}

int AVLTree::node_count() const
{
    return node_count(root);
}

int AVLTree::count_total() const
{
    return count_total(root);
}

void AVLTree::print_tree() const
{
    print_pretty(root, 1, 0, std::cout);
}

/*************************
 * BEGIN PRIVATE SECTION *
 *************************/

/*
 * Input: Node pointer 
 * Returns: Node
 * Does: recursively traverses an AVLTree to find and return a pointer 
 * to the node with the minumum value.
 */
Node *AVLTree::find_min(Node *node) const
{
    if (node == NULL){
        return NULL;
    }
    if (node->left == NULL){
        return node;
    }

    return find_min(node->left);
}

/*
 * Input: Node pointer 
 * Returns: Node
 * Does: recursively traverses an AVLTree to find and return a pointer 
 * to the node with the maximum value.
 */
Node *AVLTree::find_max(Node *node) const
{
     if (node == NULL){ //Might not need this
        return NULL;
    }
    if (node->right == NULL){
        return node;
    }
    
    return find_max(node->right);
}
/*
 * Input: Node pointer and value
 * Returns: Boolean
 * Does: Returns true if the value is found somewhere in the Node AVL Tree, and
 * false if not.
 */
bool AVLTree::contains(Node *node, int value) const
{
    if (node == NULL) {
        return false;
    }
    if (node->data == value) {
        return true;
    }
    if (node->data < value) {
        return contains(node->right, value);
    }
    else {
        return contains(node->left, value);
    }
}


Node *AVLTree::insert(Node *node, int value)
{
    /* BST insertion start */
    if (node == NULL)
    {
        return new_node(value);
    }
    else if (value < node->data)
    {
        node->left = insert(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = insert(node->right, value);
    }
    else if (value == node->data)
    {
        node->count++;
        return node;
    }
    /* BST insertion ends */

    /* AVL maintenance start */
    node->height = 1 + max(tree_height(node->left), tree_height(node->right));
    node = balance(node);
    /* AVL maintenace end */

    return node;
}

Node *AVLTree::remove(Node *node, int value)
{
    /* BST removal begins */
    if (node == NULL)
    {
        return NULL;
    }

    Node *root = node;
    if (value < node->data)
    {
        node->left = remove(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = remove(node->right, value);
    }
    else
    {
        // We found the value. Remove it.
        if (node->count > 1)
        {
            node->count--;
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                root = NULL;
                delete node;
                return root;
            }
            else if (node->left != NULL && node->right == NULL)
            {
                root = node->left;
                node->left = NULL;
                delete node;
            }
            else if (node->left == NULL && node->right != NULL)
            {
                root = node->right;
                node->right = NULL;
                delete node;
            }
            else
            {
                Node *replacement = find_min(node->right);
                root->data = replacement->data;
                root->count = replacement->count;
                replacement->count = 1;
                root->right = remove(root->right, replacement->data);
            }
        }
    }
    /* BST removal ends */

    /* AVL maintenance begins */
    if (root != NULL)
    {
        root->height = 1 + 
                        max(tree_height(root->left), tree_height(root->right));
        root = balance(root);
    }
    /* AVL maintenance ends */

    return root;
}
/*
 * Input: Node pointer
 * Returns: The Height of the Node
 * Does: Returns the tree_height of a Node
 */
int AVLTree::tree_height(Node *node) const
{
    if (node == NULL) {
        return -1;
    }
    return node->height; //Is this the right way of thinking about it?
}


/*
 * Input: Node pointer
 * Returns: The number of the Nodes in the AVL Tree
 * Does: Returns the number of nodes in the AVL Tree of the Node
 */
int AVLTree::node_count(Node *node) const
{
    
    if (node == NULL) {
        return 0;
    }
    
    return 1 + node_count(node->left) + node_count(node->right);
}

/*
 * Input: Node pointer
 * Returns: The sum of all the values in the Nodes in the AVL Tree
 * Does: Returns the sum of all the values in the Nodes in the AVL Tree
 */
int AVLTree::count_total(Node *node) const
{
    if (node == NULL){
        return 0;
    }
    if (node->count > 1){
        int count = node->count;
        return (count*node->data)+ count_total(node->left) 
                                    + count_total(node->right);
    }
    
    return node->data + count_total(node->left) + count_total(node->right);
}

/*
 * Input: Node pointer
 * Returns: The copied Node
 * Does: recursively copies the nodes of an AVLTree in pre-order, 
 * creating new nodes with the same data and structure, 
 * and then returns a pointer to the new root node.
 */

Node *AVLTree::pre_order_copy(Node *node) const
{
    if (node == NULL)
    {
        return NULL;
    }
    Node *new_node = new Node();
    new_node->count=node->count;
    new_node->data=node->data;
    new_node->height=node->height;

    new_node->left = pre_order_copy(node->left);
    new_node->right = pre_order_copy(node->right);

    return new_node;
}
/*
 * Input: Node pointer
 * Returns: void
 * Does: The function "post_order_delete" recursively deletes the 
 * nodes of an AVLTree in post-order, 
 * starting from the leaves and moving up to the root.
 */
void AVLTree::post_order_delete(Node *node)
{
    if (node == NULL) {
        return;
    }

    post_order_delete(node->left);
    post_order_delete(node->right);

    delete node;
}
/*
 * Input: Node pointer
 * Returns: The modified Node
 * Does: checks the balance factor of a node in an AVLTree and performs 
 * rotation operations to rebalance the subtree if necessary, then returns 
 * the new root node.
 */
Node *AVLTree::balance(Node *node)
{
    if (node == NULL) {
        return NULL;
    }

    int balanceFactor = height_diff(node);

    if (balanceFactor > 1) { 
    
        //LEFT LEFT
        if (height_diff(node->left) > 0){
            node = right_rotate(node);
        }
        //LEFT RIGHT
        else{
            node->left = left_rotate(node->left);
            node = right_rotate(node);
        } 
        
    }
    else if (balanceFactor < -1) {

        //Right Right
        if (height_diff(node->right) < 0){
            node = left_rotate(node);
        }
        
        //Right Left
        else {
            node->right = right_rotate(node->right);
            node = left_rotate(node);
        }
    }
    
    return node;

}

/*
 * Input: Node pointer
 * Returns: The modified Node
 * Does: right rotation operation on a node in an AVLTree, 
 * updating the heights of the affected nodes, and 
 * returns a pointer to the new root node.
 */
Node *AVLTree::right_rotate(Node *node)
{
    Node *newnode = node->left;
    if(newnode == NULL)
    {
        return NULL;
    }
    Node *Temp = newnode->right;
 
    
    newnode->right = node;
    node->left = Temp;
 
    
    node->height = max(tree_height(node->left),
                    tree_height(node->right)) + 1;
    newnode->height = max(tree_height(newnode->left),
                    tree_height(newnode->right)) + 1;
    
    return newnode;
}
/*
 * Input: Node pointer
 * Returns: The modified Node
 * Does: Left rotation operation on a node in an AVLTree, 
 * updating the heights of the affected nodes, and 
 * returns a pointer to the new root node.
 */
Node *AVLTree::left_rotate(Node *node)
{
    Node *newnode = node->right;
    if(newnode == NULL)
    {
        return NULL;
    }

    Node *Temp = newnode->left;

    newnode->left = node;
    node->right = Temp;
    
    node->height = max(tree_height(node->left),
                    tree_height(node->right)) + 1;
    newnode->height = max(tree_height(newnode->left),
                    tree_height(newnode->right)) + 1;

    return newnode;
}

/*
 * Input: Node
 * Returns: The difference in Heights
 * Does: Returns the difference between the heights of the left and right 
 * Nodes
 */
int AVLTree::height_diff(Node *node) const
{
    // TODO: Students write code here

    if (node==NULL){
        return 0;
    }  
    return tree_height(node->left) - tree_height(node->right);
}

Node *AVLTree::find_parent(Node *node, Node *child) const
{
    if (node == NULL)
        return NULL;

    // if either the left or right is equal to the child,
    // we have found the parent
    if (node->left == child or node->right == child)
    {
        return node;
    }

    // Use the binary search tree invariant to walk the tree
    if (child->data > node->data)
    {
        return find_parent(node->right, child);
    }
    else
    {
        return find_parent(node->left, child);
    }
}

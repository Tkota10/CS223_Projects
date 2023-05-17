#ifndef __PRETTY_PRINT_H__
#define __PRETTY_PRINT_H__

#include "AVLTree.h"

/*
 * Input: N/A
 * Returns: N/A
 * Does: Pretty-prints the tree rooted at root. See pretty_print.cpp for
 *      details
 */
void print_pretty(Node *root, int level, int indent_space, std::ostream &out);

#endif

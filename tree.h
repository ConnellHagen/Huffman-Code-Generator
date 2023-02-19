#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "heap.h"

typedef struct HuffmanNode
{
    char c;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
} HuffmanNode;

// Root for Huffman Tree
extern HuffmanNode* huffman_tree;
 
/** 
 * `build_huffman_tree`
 * 1. Step through the heap and initialize t_node with a new huffman tree node 
 * 2. Repeat while there are more than 1 elements in the heap: 
 *    2a. Remove two elements from the heap
 *    2b. Create a new huffman tree node 
 *    2c. Reinsert a new heap element that is the parent of the two deleted elements
 * 3. The last element in the heap contains the root of the huffman tree
 */
void build_huffman_tree();
void print_huffman_tree(HuffmanNode* root, int level);

#endif

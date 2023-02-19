#ifndef CODE_H
#define CODE_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "tree.h" 
#include "heap.h" 

// for the 256 ASCII characters, and a possible Huffman Code length of up to 20 bits
extern char huffman_code[256][20];
 
void init_code();
void print_code();

/**
 * `transfer_buffer` takes the string of characters in `code_buffer` from index 0
 * to `pos` and places that code in the corresponding character array in `huffman_code`
 */
void transfer_buffer(HuffmanNode* node, int pos);
/** 
 * `gen_code` traverses the huffman tree and stores the huffman codes in huffman_code.
 * The codes start at the root node, and add a 0 for each left traversal and
 * add a 1 for each right traversal.
 * Puts partial results in `code_buffer`. 
 */
void gen_code(HuffmanNode* node, int pos); 

#endif

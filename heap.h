#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#include "tree.h"

typedef struct HeapNode
{
	char c;     				 // The symbol 
	int freq;   				 // The frequency of the symbol 
	struct HuffmanNode* t_node;  // Pointer to the corresponding huffman tree node
} HeapNode;  

extern HeapNode heap[256];
extern int heap_size;
 
void heap_init();
void heap_insert(char c, HuffmanNode* t, int freq);

/**
 * `delete_min` removes the root of the heap and then
 * sorts the resulting heap
 */
HeapNode delete_min();

void swap_nodes(int pos1, int pos2);

/** 
 * `bubble_up` moves an element up the heap recursively, as long as it
 * is smaller than the element it is a child of 
 * 
 * `bubble_down` moves an element down the heap recursively, as long
 * as it is larger than the child element it is swapping with.
 * If both child nodes are smaller than the element, it will swap
 * with the smaller of the two.
 */
void bubble_up(int pos);
void bubble_down(int pos);

void heap_print(); 

#endif

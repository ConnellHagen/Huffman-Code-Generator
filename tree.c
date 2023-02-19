#include "heap.h"
 
// The root to the Huffman tree
HuffmanNode* huffman_tree = NULL;

HuffmanNode* create_node(char c, HuffmanNode* l, HuffmanNode* r)
{
    HuffmanNode* node = malloc(sizeof(HuffmanNode)); 

    node->c = c;
    node->left = l;
    node->right = r;
 
    return node;
}

void build_huffman_tree()
{
	while(heap_size > 1)
	{
		HeapNode node1 = delete_min();
		HeapNode node2 = delete_min();

		HuffmanNode* left_node = node1.t_node;
		HuffmanNode* right_node = node2.t_node;

		if(left_node == NULL)
		{
			left_node = create_node(node1.c, NULL, NULL);
		}
		if(right_node == NULL)
		{
			right_node = create_node(node2.c, NULL, NULL);
		}

		HuffmanNode* new_node = create_node('X', left_node, right_node);

		heap_insert('X', new_node, node1.freq + node2.freq);
	}

	huffman_tree = heap[1].t_node;

}
 
void print_huffman_tree(HuffmanNode* root, int level)
{
	if(level == 0)
	   printf("\n----------------\n  TREE BEGIN\n-----------------\n");

	if(root == NULL)
		return;

	for(int i = 0; i < level; i++)
		printf("   ");

	if(root->left != NULL || root->right != NULL) 
		printf("Node (I)\n");
	else if(isprint(root->c)) 
		printf("Node %d(%c)	\n", root->c, root->c);
	else 
		printf("Node %d(--)\n", root->c);


	print_huffman_tree(root->left, level + 1);
	print_huffman_tree(root->right, level + 1);

	if(level == 0)
        	printf("\n-----------\n  TREE END\n------------\n");

}

// testing as included by instructor in the original file
#ifdef TEST

int main()
{
	printf("here\n");
    heap_init();

    heap_insert('a', NULL, 44);
    heap_insert('b', NULL, 32);
    heap_insert('d', NULL, 99);
    heap_insert('f', NULL, 43);
    heap_insert('u', NULL, 51);
    heap_insert('y', NULL, 1);

    build_huffman_tree();
    print_huffman_tree(huffman_tree, 0); 
    return 0;

}

#endif
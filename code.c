#include "heap.h"
#include "tree.h"

char huffman_code[256][20];
char code_buffer[20];

void init_code()
{
	for(int i = 0; i < 256; i++)
	{
 		huffman_code[i][0] = 0;
	}
}

void print_code()
{
	printf("\n----------------\n  CODES BEGIN\n-----------------\n");

	for(int i = 0; i < 256; i++)
	{
		if(huffman_code[i][0] == 0) continue;
		
		if(isprint(i))
			printf("%d (%c): %s\n", i, i, huffman_code[i]);
		else
			printf("%d (--): %s\n", i, huffman_code[i]);
	    
	}
	printf("\n----------------\n  CODES END\n-----------------\n");
}

void transfer_buffer(HuffmanNode* node, int pos)
{
	for(int i = 0; i < pos; i++)
	{
		huffman_code[(int)(node->c)][i] = code_buffer[i];
	}
}

void gen_code(HuffmanNode* node, int pos)
{
    if(node->left == NULL && node->right == NULL)
	{
		transfer_buffer(node, pos);
	}
	if(node->left != NULL)
	{
		code_buffer[pos] = 0 + '0';
		gen_code(node->left, pos + 1);
	}
	if(node->right != NULL)
	{
		code_buffer[pos] = 1 + '0';
		gen_code(node->right, pos + 1);
	}

}

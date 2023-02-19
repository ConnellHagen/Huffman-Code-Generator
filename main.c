#include "heap.h"
#include "tree.h"
#include "code.h"

#define BUFFER_SIZE 1000000

int debug_heap = 0;
int debug_huffman_tree = 0;

int main(int argc, char** argv)
{
	FILE* in_file; 
    char buffer[BUFFER_SIZE];
	int input_size = 0;

    int counting_bin[256];

    if (argc != 2)
    {
        fprintf(stderr, "Error: usage: %s [file-name]\n", argv[0]);
        return -1;
    }

	// Open the input file for read
    in_file = fopen(argv[1], "rb");

    if(!in_file)
    {
        fprintf(stderr, "Error: invalud input file: %s\n", argv[1]);
        return -1;
    }

	// Read the input and place the input in the buffer 
    input_size = fread(buffer, sizeof(char), BUFFER_SIZE, in_file);
	
	// Close the input file for read
    fclose(in_file);

	// Check for empty file
	if(input_size <= 0) 	
		return 0;

	// Counting the frequency of each charactor 
        for(int i = 0; i < 256; i++)
            counting_bin[i] = 0;

        for(int i = 0; i < input_size; i++)
            counting_bin[(int)buffer[i]]++;

	// Initialize and creating the heap
    heap_init();

    for(int i = 0; i < 256; i++)
    {
        if(counting_bin[i])
            heap_insert(i, NULL, counting_bin[i]);
    }

	// Insert end of file marker
	heap_insert(0, NULL, 0);   

	// build the buffman tree
    build_huffman_tree();

	// initialize and generate code based on the huffman tree
    init_code();
    gen_code(huffman_tree, 0);

    print_code();

    return 0;
}


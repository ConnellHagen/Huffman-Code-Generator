#include <stdbool.h>

#include "heap.h"

HeapNode heap[256];
int heap_size;

void heap_init()
{
    heap_size = 0;
    heap[0].c = 0;
    heap[0].t_node = NULL;
    heap[0].freq = 0;
}

void heap_insert(char c, HuffmanNode* t, int freq)
{
    // increment heap size first, because the root node is at index 1
    heap_size++;
    heap[heap_size].t_node = t;
    heap[heap_size].c = c;
    heap[heap_size].freq = freq;
    bubble_up(heap_size);
}

HeapNode delete_min()
{
    HeapNode old_root = heap[1];
    heap[1] = heap[heap_size];
    heap_size--;
    bubble_down(1);
        
    return old_root;
}

void swap_nodes(int pos1, int pos2)
{
    HeapNode temp = heap[pos1];
    heap[pos1] = heap[pos2];
    heap[pos2] = temp;
}

void bubble_up(int pos)
{
    // cannot bubble up the root
    if(pos == 1) return;

    bool is_left_child = pos % 2 == 0;
    int comparision_index = is_left_child ?
        pos / 2 :
        (pos - 1) / 2;

    if(heap[pos].freq < heap[comparision_index].freq)
    {
        swap_nodes(comparision_index, pos);
        bubble_up(comparision_index);
    }
}

void bubble_down(int pos)
{    
    int leftval = INT_MAX;
    int rightval = INT_MAX;

    if(pos * 2 <= heap_size)
        leftval = heap[pos * 2].freq;
    if(pos * 2 + 1 <= heap_size)
        rightval = heap[pos * 2 + 1].freq;

    // if the heap is already sorted, return
    if(heap[pos].freq <= leftval && heap[pos].freq <= rightval) return;

    // index of the left child node, will be incremented if the right node must be swapped instead
    int swap_index = pos * 2;

    // both child nodes are smaller and a decision must be made on which to swap with
    if(heap[pos].freq > leftval && heap[pos].freq > rightval)
    {
        int min = leftval;
        if(rightval < leftval) min = rightval;
        if(min != leftval)
            swap_index++;
   
        swap_nodes(swap_index, pos);
        bubble_down(swap_index);
        return;
    }
    
    // tests which child node is smaller
    if(heap[pos].freq <= leftval)
        swap_index++;

    swap_nodes(swap_index, pos);
    bubble_down(swap_index);
}
 
void heap_print()
{
    printf("\n----------------\n  HEAP BEGIN\n-----------------\n");
    for (int i = 1; i <= heap_size; i++)
    {
        printf("%d ", i);
        if(isprint(heap[i].c)) 
            printf("(%c)", heap[i].c);
        else 
		    printf("(--)");
        printf("%d\n", heap[i].freq);
    }
    printf("\n----------------\n  HEAP END\n-----------------\n");
}

// testing as included by instructor in the original file
#ifdef TEST

int main()
{
    heap_init();
    heap_insert('a', NULL, 44);
    heap_insert('b', NULL, 32);
    heap_insert('d', NULL, 99);
    heap_insert('f', NULL, 43);
    heap_insert('u', NULL, 51);
    heap_insert('y', NULL, 1);
    print_heap();

    delete_min();
    print_heap();

    delete_min();
    print_heap();

    return 0;
}

#endif
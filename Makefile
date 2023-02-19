CC = gcc
CFLAGS = -Wall -g
TEST = -DTEST
HUFFOBJ = main.o heap.o tree.o code.o
HEAPOBJ = heaptest.o
TREEOBJ = treetest.o heap.o

huffman: $(HUFFOBJ)
	$(CC) $(CFLAGS) -o huffman $(HUFFOBJ)

heaptest: $(HEAPOBJ)
	$(CC) $(CFLAGS) -o heaptest $(HEAPOBJ)

treetest: $(TREEOBJ)
	$(CC) $(CFLAGS) -o treetest $(TREEOBJ)


heaptest.o: heap.c
	$(CC) -c $(TEST) -o heaptest.o heap.c

treetest.o: tree.c
	$(CC) -c $(TEST) -o treetest.o tree.c

.o : .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o huffman heaptest treetest
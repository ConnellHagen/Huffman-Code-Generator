# Huffman Code Generator

## About
Huffman Coding is an algorithm developed by David A. Huffman used for lossless data compression. The algorithm has the following steps:

- The file is read and the frequency of each character is summed up.
- The characters are placed in a min-heap with their frequencies as their respective weights.
- Two elements are removed from the heap, placed as children of an arbitrary node in a tree, and assigned a new frequency equal to that of their previous frequencies added together. The tree element is then re-inserted into the heap. This step is repeated until there is only one element left in the heap.
- The left-over tree element with characters as its leaves is traversed. For each step left to reach a leaf, a 0 is added to its code, for each step right to reach a leaf, a 1 is added to its code. Find codes for every leaf node, and its corresponding character.

This project was an assignment for my CSCI2021 machine architecture and organization class where we were instructed to recreate this algorithm.

## Usage
First, prepare a text file to use the algorithm on. The file must only use the standard 256 ASCII characters.

Second, using the `huffman` binary found in the "Releases" section, run `huffman` with your file as a command-line argument. ex: `./huffman some_directory/text_file.txt`. The binary can also be created by compiling the `.c` files yourself with `make`.

The terminal will then print out a list of every character that is in the file you used, along with the corresponsing Huffman code for it.

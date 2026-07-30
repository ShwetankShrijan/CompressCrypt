# CompressCrypt

CompressCrypt is a C++ project that combines **lossless data compression** using Huffman Coding with **data encryption** to securely store and transmit text. The project is being developed in stages, starting with Huffman compression and decompression before integrating encryption.

## Features

- Reads input text from a file
- Calculates character frequencies
- Builds a Huffman Tree using a priority queue (min-heap)
- Generates optimal prefix-free Huffman codes
- Encodes the input text into a compressed binary string
- Decodes the compressed data back to the original text
- Modular design for easy integration of encryption algorithms

## Technologies

- C++
- STL
- Priority Queue (Min Heap)
- Binary Trees
- Greedy Algorithms
- File I/O
- Data Compression
- Cryptography *(planned)*

## How Huffman Encoding Works

1. Read the input text.
2. Count the frequency of every character.
3. Insert each character into a min-heap based on its frequency.
4. Repeatedly combine the two least frequent nodes until only one node remains.
5. The resulting tree is the Huffman Tree.
6. Traverse the tree:
   - Left edge = `0`
   - Right edge = `1`
7. Replace every character in the original text with its Huffman code to produce the encoded bitstream.

Since more frequent characters receive shorter codes, the overall size of the encoded message is reduced.

## How Huffman Decoding Works

Decoding uses the same Huffman Tree created during encoding.

1. Start at the root of the Huffman Tree.
2. Read the encoded bitstream one bit at a time.
3. Move left for `0` and right for `1`.
4. When a leaf node is reached, output the corresponding character.
5. Return to the root and continue until all bits are processed.

Because Huffman codes are prefix-free, the original message can be reconstructed without ambiguity.

## Current Status

- [x] Read input file
- [x] Character frequency analysis
- [x] Huffman Tree construction
- [x] Huffman code generation
- [x] Huffman encoding
- [x] Huffman decoding

## TODO

- [ ] Write compressed output to a binary file
- [ ] Read compressed data from a binary file
- [ ] Implement XOR encryption module
- [ ] Upgrade encryption to AES-256
- [ ] Store and reconstruct the Huffman Tree from file
- [ ] Support compression of any file type
- [ ] Add compression statistics (original size vs compressed size)
- [ ] Add command-line interface
- [ ] Improve error handling and logging
- [ ] Add unit tests

# CompressCrypt

CompressCrypt is a C++ project that combines **lossless data compression** using Huffman Coding with **data encryption** to securely store and transmit data. The current implementation focuses on building a complete Huffman compression engine with binary file serialization. Encryption modules will be integrated in future versions.

---

## Features

- Reads input text from a file
- Calculates character frequencies
- Builds a Huffman Tree using a priority queue (min-heap)
- Generates optimal prefix-free Huffman codes
- Encodes text using Huffman Coding
- Compresses encoded data using bit-level packing
- Stores compressed data in a binary file
- Stores compression metadata (bit count and frequency table)
- Reads compressed binary data from disk
- Decodes compressed data back to the original text
- Modular architecture for future encryption integration

---

## Technologies

- C++
- Standard Template Library (STL)
- Priority Queue (Min Heap)
- Binary Trees
- Greedy Algorithms
- Bit Manipulation
- Binary File I/O
- Data Compression
- Cryptography *(planned)*

---

## How Huffman Encoding Works

1. Read the input text.
2. Count the frequency of every character.
3. Insert each character into a min-heap based on its frequency.
4. Repeatedly combine the two least frequent nodes until only one node remains.
5. The remaining node becomes the root of the Huffman Tree.
6. Traverse the tree:
   - Left edge = `0`
   - Right edge = `1`
7. Replace each character in the original text with its Huffman code.
8. Pack the resulting bitstream into bytes before writing it to a binary file.

Because more frequent characters receive shorter codes, the overall file size is reduced.

---

## How Huffman Decoding Works

1. Read the compressed binary data.
2. Unpack the stored bytes back into the original bitstream.
3. Start at the root of the Huffman Tree.
4. Read one bit at a time.
5. Move left for `0` and right for `1`.
6. When a leaf node is reached, output the corresponding character.
7. Return to the root and continue until all bits are processed.

Since Huffman codes are prefix-free, the original message can be reconstructed without ambiguity.

---

## Binary File Format

The compressed binary file currently stores:

- Original encoded bit count
- Number of unique characters
- Character frequency table
- Packed compressed bitstream

This metadata is intended to support reconstruction of the Huffman Tree during decompression.

---

## Project Structure

```
CompressCrypt/
├── data/
│   └── encoded.bin
├── include/
│   └── bitpack.h
├── sample/
│   └── messages.txt
├── src/
│   ├── bitpack.cpp
│   └── main.cpp
├── README.md
└── .gitignore
```

---

## Current Status

- [x] Read input file
- [x] Character frequency analysis
- [x] Huffman Tree construction
- [x] Huffman code generation
- [x] Huffman encoding
- [x] Huffman decoding
- [x] Bit packing
- [x] Binary file output
- [x] Binary file input
- [x] Compression metadata serialization

---

## Future Improvements

- [ ] Reconstruct the Huffman Tree from stored metadata
- [ ] Implement XOR encryption
- [ ] Add password-based encryption
- [ ] Upgrade encryption to AES-256
- [ ] Support compression of any file type
- [ ] Display compression statistics
- [ ] Build a command-line interface
- [ ] Improve error handling and logging
- [ ] Add automated unit tests

---

## Roadmap

### Version 1.0
- Huffman compression
- Bit packing
- Binary file serialization
- Metadata storage
- Lossless decompression

### Version 2.0
- XOR encryption
- Password-based protection
- AES-256 encryption

### Version 3.0
- Command-line interface
- Support for arbitrary file types
- Compression statistics
- Performance improvements

#ifndef BLOCK_H
#define BLOCK_H

#include "Cypher.h"

class Block
{
  private:
    // attributes
    const std::vector<std::vector<char*>> block; // data
    const int size; // dimensions
    bool full;
    // helpers:
    void addBytes(const std::vector<char> seg, int y);
    void subtractBytes(const std::vector<char> seg, int y);
    void addPreviousRow(int y);
    void subtractPreviousRow(int y);
    std::vector<char> getRow(int y);
    std::vector<char> getCol(int x);
    void setRow(int y, const std::vector<char> row);
    void setCol(int x, const std::vector<char> col);
  public:
    // constructors:
    Block(); // default
    Block(char* bytes, int length, int pos, int size); // full
    Block(const Block& block); // copy
    // deconstructor:
    ~Block();
    // actions:
    void load(char* bytes, int length, int size);
    void addToBlock(const std::vector<char> seg);
    void subtractFromBlock(const std::vector<char> seg);
    void scrambleBlock(const std::vector<char> seg0, const vector<char> seg1);
    void unscrambleBlock(const std::vector<char> seg0, const vector<char> seg1);
    // helpers:
    friend Cypher;
    friend void swap(Block& block0, Block& block1);
    // overloads:
    Block& operator=(Block block); // assignment
};

const std::vector<char> getSortedIndex(const std::vector<char> seg, int pos); // helper

#endif

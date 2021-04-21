#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

struct SortedIndex
{
  // attributes:
  std::vector<int> sortedIndexs;
  int length;
  // constructors:
  SortedIndex(const char* bytes, int bytesLength, int begin, int length);
};

class Block
{
  private:
    // attributes
    std::vector<std::vector<char*>> block;
    int size;
    // helpers:
    void addPreviousY(int toY);
    void subtractPreviousY(int toY);
    void addBytes(const char* bytes, int bytesLength, int fromIndex, int toY);
    void subtractBytes(const char* bytes, int bytesLength, int fromIndex, int toY);
    void flipY(int y0, int y1);
    void flipX(int x0, int x1);
  public:
    // constructors:
    Block(); // default
    Block(char* bytes, int bytesLength, int fromIndex, int size);
    Block(const Block &block); // copy
    // deconstructor:
    ~Block();
    // actions:
    void load(char* bytes, int bytesLength, int fromIndex, int size);
    void addToBlock(const char* bytes, int bytesLength, int fromIndex);
    void subtractFromBlock(const char* bytes, int bytesLength, int fromIndex);
    void scrambleBlock(const char* bytes, int bytesLength, int fromIndex);
    void unscrambleBlock(const char* bytes, int bytesLength, int fromIndex);
    // helpers:
    friend void swap(Block &block0, Block &block1);
    // overloads:
    Block & operator=(Block block);
};

#endif

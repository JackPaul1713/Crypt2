#include <string>
#include <fstream>
#include <cmath>
#include "Block.h"

using namespace std;

//// constructors ////
Block::Block(): // default
block(), size(0)
{}
Block::Block(char* bytes, int bytesLength, int fromIndex, int size):
block(size), size(size)
{
  load(bytes, bytesLength, fromIndex, size);
}
Block::Block(const Block &block): // copy
block(block.block), size(block.size)
{}

//// deconstructor ////
Block::~Block()
{}

//// actions ////
void Block::load(char* bytes, int bytesLength, int fromIndex, int size)
{
  // set attributes:
  this->size = size; // attribute: size
  block.resize(size); // attribute: block y size
  for(int y = 0; y < size; y++) // loop through block
  {
    block[y] = vector<char*>(size); // attribute: block x size
    for(int x = 0; x < size; x++) // loop through block[y]
    {
      if(!(fromIndex < bytesLength)) // wrap from index arround
      {
        fromIndex = 0;
      }
      block[y][x] = &bytes[fromIndex]; // attribute: block[y][x]
      fromIndex++; // increment from index
    }
  }
}
void Block::addToBlock(const char* bytes, int bytesLength, int fromIndex)
{
  addBytes(bytes, bytesLength, fromIndex, 0); // add bytes to block[0]
  for(int y = 1; y < size; y++) // loop through block
  {
    addPreviousY(y); // add block[previous] to block[y], starting at 1
  }
}
void Block::subtractFromBlock(const char* bytes, int bytesLength, int fromIndex)
{
  subtractBytes(bytes, bytesLength, fromIndex, 0); // subtract bytes from block[0]
  for(int y = 1; y < size; y++) // loop through block
  {
    subtractPreviousY(y); // subtract block[previous] from block[y], starting at 1
  }
}
void Block::scrambleBlock(const char* bytes, int bytesLength, int fromIndex) // TODO
{

}
void Block::unscrambleBlock(const char* bytes, int bytesLength, int fromIndex) // TODO
{

}

//// helpers ////
SortedIndex::SortedIndex(const char* bytes, int bytesLength, int fromIndex, int length): // TODO NEXT
sortedIndexs(length), length(length)
{
  // var:
  char min = (char)-128;

  for(int i = 0; i < length; i++) // loop through specified bytes
  {
    for
  }
}
void swap(Block &block0, Block &block1)
{
  // swap all attributes between objects:
  using std::size;
  swap(block0.block, block1.block);
  swap(block0.size, block1.size);
}
void Block::addPreviousY(int toY)
{
  for(int x = 0; x < size; x++) // loop through block[toY]
  {
    *block[toY][x] += *block[toY-1][x]; // add byte block[toY-1][x] to block[toY][x]
  }
}
void Block::subtractPreviousY(int toY)
{
  for(int x = 0; x < size; x++) // loop through block[toY]
  {
    *block[toY][x] -= *block[toY-1][x]; // subtract byte block[toY-1][x] from block[toY][x]
  }
}
void Block::addBytes(const char* bytes, int bytesLength, int fromIndex, int toY)
{
  for(int x = 0; x < size; x++) // loop through block[toY]
  {
    if(!(fromIndex < bytesLength)) // wrap from index arround
    {
      fromIndex = 0;
    }
    *block[toY][x] += bytes[fromIndex]; // add byte to block[toY][x]
    fromIndex++; // increment from index
  }
}
void Block::subtractBytes(const char* bytes, int bytesLength, int fromIndex, int toY)
{
  for(int x = 0; x < size; x++) // loop through block[toY]
  {
    if(!(fromIndex < bytesLength)) // wrap from index arround
    {
      fromIndex = 0;
    }
    *block[toY][x] -= bytes[fromIndex]; // subtract byte from block[toY][x]
    fromIndex++; // increment from index
  }
}
void Block::flipY(int y0, int y1)
{
  swap(block[y0], block[y1]);
}
void Block::flipX(int x0, int x1)
{
  for(int y = 0; y < size; y++) // loop through block
  {
    swap(block[y][x0], block[y][x1]);
  }
}
//// overloads ////
Block & Block::operator=(Block block)
{
  swap(*this, block);
  return(*this);
}

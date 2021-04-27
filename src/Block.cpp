#include <vector>
#include <string>
#include <algorithm>
#include "Block.h"

using namespace std;

//// constructors ////
Block::Block(): // default
block(), size(0), full(false)
{}
Block::Block(char* bytes, int length, int pos, int size): // full
block(), size(0), full(false)
{
  load(bytes, length, pos, size);
}
Block::Block(const Block &block): // copy
block(block.block), size(block.size), full(block.full)
{}

//// deconstructor ////
Block::~Block()
{}

//// helpers ////
void swap(Block &block0, Block &block1)
{
  // swap all attributes between objects:
  using std::size;
  swap(block0.block, block1.block);
  swap(block0.size, block1.size);
}
const vector<char> getSortedIndex(vector<char> seg) // TODO
{
  /*
  * values of sorted index represent to
  * indexs of sorted index represent from
  *
  * sortedIndex {?, ?, ?, ?}
  * to:   ?, ?, ?, ?...
  * from: 0, 1, 2, 3...
  */

  // variables:
  int index;
  char min;
  vector<char> sortedIndex(seg.size());
  // fill:
  for(int i = 0; i < sortedIndex.size(); i++) // loop through sorted index
  {
    // reset:
    index = 0; // index of minimum
    min = seg.at(0); // value of minimum
    // find:
    for(int j = 1; j < seg.size(); j++) // loop through segment
    {
      if(seg.at(j) < min)
      {
        index = j;
        min = seg.at(j);
      }
    }
    // update:
    sortedIndex.push_back(index); // add index of minimum
    seg.pop(index); // remove minimum
  }
  // return:
  return(sortedIndex);
}
const vector<char> getUnsortedIndex(vector<char> seg) // TODO
{
  /* 
  * values of unsorted index represent to
  * indexs of unsorted index represent from
  *
  * sortedIndex {?, ?, ?, ?}
  * to:   ?, ?, ?, ?...
  * from: 0, 1, 2, 3...
  */
}

void Block::addBytes(const vector<char> seg, int y)
{
  for(int x = 0; x < size; x++) // loop through block[y]
  {
    if(!(pos < key.size())) // wrap pos arround
    {
      pos = 0;
    }
    *block[y][x] += key.at(pos); // add byte to block[y][x]
    pos++; // increment pos
  }
}
void Block::subtractBytes(const vector<char> seg, int y)
{
  for(int x = 0; x < size; x++) // loop through block[y]
  {
    if(!(pos < key.size())) // wrap pos arround
    {
      pos = 0;
    }
    *block[y][x] -= key.at(pos); // subtract byte from block[y][x]
    pos++; // increment pos
  }
}
void Block::addPreviousRow(int y)
{
  for(int x = 0; x < size; x++) // loop through block[y]
  {
    *block[y][x] += *block[y-1][x]; // add byte block[y-1][x] to block[y][x]
  }
}
void Block::subtractPreviousRow(int y)
{
  for(int x = 0; x < size; x++) // loop through block[y]
  {
    *block[y][x] -= *block[y-1][x]; // subtract byte block[y-1][x] from block[y][x]
  }
}
// vector<char> getRow(int y)
// {
//   vector<char> row(size);
//   for(int x = 0; x < size; x++) // loop through block[y]
//   {
//     row[x] = *block[y][x]; // set row to x values
//   }
//   return(row);
// }
// vector<char> getCol(int x)
// {
//   vector<char> col(size);
//   for(int y = 0; y < size; y++) // loop through block
//   {
//     col[y] = *block[y][x]; // set row to y values
//   }
//   return(col);
// }
// void setRow(int y, const vector<char> row)
// {
//   for(int x = 0; x < size; x++) // loop through block[y]
//   {
//     *block[y][x] = row[x]; // set x values
//   }
// }
// void setCol(int x, const vector<char> col)
// {
//   for(int y = 0; y < size; y++)
//   {
//     *block[y][x] = row[x]; // set y values
//   }
// }



//// actions ////
void Block::load(char* bytes, int length, int pos, int size)
{
  // set attributes:
  this->size = size; // attribute: size
  block.resize(size); // attribute: block y size
  for(int y = 0; y < size; y++) // loop through block
  {
    block[y] = vector<char*>(size); // attribute: block x size
    for(int x = 0; x < size; x++) // loop through block[y]
    {
      if(pos < length) // wrap pos arround
      {
        block[y][x] = &bytes[pos]; // attribute: block[y][x]
        pos++; // increment from index
      }
      else
      {
        return;
      }
    }
  }
  full = true; // attribute: full
}
void Block::addToBlock(const vector<char> seg)
{
  addBytes(bytes, length, pos, 0); // add bytes to block[0]
  for(int y = 1; y < size; y++) // loop through block, starting at 1
  {
    addPreviousRow(y); // add block[previous] to block[y]
  }
}
void Block::subtractFromBlock(const vector<char> seg)
{

  for(int y = size-1; y >= 1; y--) // loop through block, ending at 1
  {
    subtractPreviousRow(y); // subtract block[previous] from block[y]
  }
  subtractBytes(bytes, length, pos, 0); // subtract bytes from block[0]
}
void Block::scrambleBlock(const vector<char> seg0, const vector<char> seg1) // TODO
{
  // variables:
  vector<char> sortedIndex0 = getSortedIndexTo(seg0);
  vector<char> sortedIndex1 = getSortedIndexTo(seg1);
  int from = 0;
  int to = sortedIndex0[from];
  // scramble rows:
  while(findNot(-1, sortedIndex0) != -1)
  {
    if(from != to)
    {
      swapRows(from, to);
      to = sortedIndex[to];
    }
    else
    {
      sortedIndex0[from] = -1;
      from = findNot(-1, sortedIndex0);
      to = sortedIndex0[from];
    }
  }
  // scramble cols:
}
void Block::unscrambleBlock(const vector<char> seg0, const vector<char> seg1) // TODO
{

}

//// overloads ////
Block& Block::operator=(Block block) // assignment
{
  swap(*this, block);
  return(*this);
}

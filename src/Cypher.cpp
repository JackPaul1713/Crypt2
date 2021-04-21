#include <string>
#include <fstream>
#include "Cypher.h"
#include "Key.h"

using namespace std;

//// constructors ////
Cypher::Cypher(): // default
key()
{}
Cypher::Cypher(Key key):
key(key)
{}
Cypher::Cypher(const Cypher &cypher): // copy
key(cypher.key)
{}

//// deconstructor ////
Cypher::~Cypher()
{}

//// actions ////
void Cypher::encrypt(char* bytes, int length) // TODO REDO
{
  // variables:
  int addIndex;
  int scrambleIndex;
  int maxBlockSize;
  // calculate start indexs:
  {
    // variables:
    int addLength = key.length;
    int scrambleLength = key.length;
    int addLenUsed = 0;
    int scrambleLenUsed = 0;
    maxBlockSize = (log(length) / log(4)) - 1; // 4^(maxBlockSize + 1) = length
    // calculate:
    for(int blockSize = 4; blockSize < maxBlockSize; blockSize *= 4)
    {
      addLength += (addLength % blockSize);
      scrambleLength += (scrambleLength % (blockSize * 2));
      addLenUsed += addLength;
      scrambleLength += scrambleLength;
    }
    addIndex = key.length - (addLenUsed % key.length);
    scrambleIndex = key.length - (scrambleLenUsed % key.length)
  }
  // add and scramble:
}
void Cypher::decrypt(char* bytes, int length) // TODO
{

}
void Cypher::encryptFile(string filename) // TODO
{

}
void Cypher::decryptFile(string filename) // TODO
{

}

//// helpers ////
void swap(Cypher &cypher0, Cypher &cypher1) // TODO
{
  // swap all attributes between objects:
  using std::swap;
  swap(cypher0.key, cypher1.key);
}

//// overloads ////
Cypher & Cypher::operator=(Cypher cypher)
{
  swap(*this, cypher);
  return(*this);
}

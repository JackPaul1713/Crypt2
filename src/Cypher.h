#ifndef CYPHER_H
#define CIPHER_H

#include <string>
#include "Key.h"

class Cypher
{
  private:
    // attributes:
    Key key;
    int addIndex;
    int scrambleIndex;
    // helpers:
    void add(const char* fromBytes, int fromIndex, char* toBytes, int toIndex, int size);
    void subtract(const char* fromBytes, int fromIndex, char* toBytes, int toIndex, int size);
    void flipRow(char* bytes, int fromIndex, int toIndex, int size);
    void flipCol(char* bytes, int fromIndex, int toIndex, int size);
    void scramble(char* bytes, int index, int size);
    void unscramble(char* bytes, int index, int size);
  public:
    // actions:
    void encrypt(char* bytes);
    void decrypt(char* bytes);
    void encryptFile(string filename);
    void decryptFile(string filename);
}

// overloads:
Cypher & operator=(Cypher &cypher);

#endif

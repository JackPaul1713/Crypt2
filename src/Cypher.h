#ifndef CYPHER_H
#define CIPHER_H

#include <string>
#include <vector>
#include "Key.h"
#include "Block.h"

class Cypher
{
  private:
    // attributes:
    const std::vector<char> key;
  public:
    // constructors:
    Cypher(); // default
    Cypher(std::vector<char> key);
    Cypher(const Cypher &cypher); // copy
    // deconstructor:
    ~Cypher();
    // actions:
    void encrypt(char* bytes, int length);
    void decrypt(char* bytes, int length);
    void encryptFile(std::string filename);
    void decryptFile(std::string filename);
    // helpers:
    std::vector getSeg(int pos, int size);
    friend void swap(Cypher& cypher0, Cypher& cypher1);
    // overloads:
    Cypher& operator=(Cypher& cypher);
};

#endif

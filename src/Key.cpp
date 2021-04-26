#include <string>
#include <fstream>
#include "Key.h"

using namespace std;

//// constructors ////
Key::Key(): // default
file(""), key(), password(""), length(0)
{}
Key::Key(string file, string password, int length): // new
file(file), key(), password(password), length(length)
{
  key = generateKey();
  download();
}
Key::Key(string file, string password): // existing
file(file), key(), password(password), length(0)
{
  upload();
}
Key::Key(const Key &key): // copy
file(key.file), key(key.key), password(key.password), length(key.length)
{}

//// deconstructor ////
Key::~Key()
{}

//// getters ////
string Key::getFile()
{
  return(file);
}
vector<char> Key::getKey()
{
  return(key);
}
int Key::getLength()
{
  return(length);
}

//// setters ////
void Key::renameFile(string name) // TODO
{

}
void Key::changePassword(string newPassword) // TODO
{

}
void Key::changeLength(int newLength) // TODO
{

}
void Key::regenerate()
{
  key = generateKey();
  download();
}

//// save ////
void Key::upload() // TODO
{

}
void Key::download() // TODO
{

}

//// helpers ////
void swap(Key &key0, Key &key1)
{
  // swap all attributes between objects:
  using std::swap;
  swap(key0.file, key1.file);
  swap(key0.key, key1.key);
  swap(key0.password, key1.password);
  swap(key0.length, key1.length);
}
char Key::generateRandomByte(int number, int modifier)
{
  return((rand() % number) - modifier);
}
vector<char> Key::generateKey() // generates key of length this->length
{
  vector<char> key(length);
  for(int i = 0; i < length; i++) // loop through key
  {
    key.at(i) = generateRandomByte(255, -128); // assign random char
  }
  return(key);
}

//// overloads ////
Key & Key::operator=(Key key)
{
  swap(*this, key);
  return(*this);
}

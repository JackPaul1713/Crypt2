#include <string>
#include <fstream>
#include "Key.h"

using namespace std;

//// helpers ////
void swap(Key &key)
{
  // swap all attributes between objects:
  swap(this->file, key->file);
  swap(this->key, key->key);
  swap(this->mold, key->mold);
  swap(this->password, key->password);
  swap(this->length, key->length);
}
char generateRandomByte(int number, int modifier)
{
  return((rand() % number) - modifier);
}
vector<char> Key::generateKey() // generates key of lenght length(attribute)
{
  vector<char> key(length);
  for(int i = 0; i < length; i++) // loop through key
  {
    key.at(i) = generateRandomByte(255, -128); // assign random char
  }
  return(key);
}

//// save ////
void Key::load()
{

}
void Key::download()
{

}

//// constructors ////
Key::Key(std::string file, std::string password, int length): // new key
file(file), password(password), length(length)
{
  key = generate_key();
  download();
}
Key::Key(std::string file, std::string password): // existing key
file(file), password(password)
{
  load();
}
Key::Key(const Key &key): // copy
file(key->file), key(key->key), mold(key->mold), password(key->password), length(key->length)
{}

//// modify ////
void Key::change_password()
{

}
void Key::change_length()
{

}
void Key::regenerate()
{

}

//// overloads ////
Key & operator=(Key &key)
{
  Key temp_key(key);
  this->swap(key);
  return(*this);
}

#ifndef KEY_H
#define KEY_H

#include <string>

class Key
{
  private:
    // attributes:
    std::string file;
    vector<char> key;
    std::string password;
    int length;
    // helpers:
    void swap(Key key);
    char generateRandomByte(int number, int modifier);
    vector<char> generateKey(); // generates key of lenght length(attribute)
    // save:
    void load(); // decrypts key from file
    void download(); // encrypts key to file
  public:
    // constructors:
    Key(std::string file, std::string password, int length); // new key
    Key(std::string file, std::string password); // existing key
    Key(Key key); // copy
    // deconstructor:
    ~Key();
    // modify:
    void changePassword();
    void changeLength();
    void regenerate();
};

// overloads:
Key & operator=(Key &key);

#endif

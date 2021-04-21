#ifndef KEY_H
#define KEY_H

#include <string>
#include <vector>

class Key
{
  private:
    // attributes:
    std::string file;
    std::vector<char> key;
    std::string password;
    int length;
    // friends:
    friend class Cypher;
    // helpers:
    char generateRandomByte(int number, int modifier);
    std::vector<char> generateKey(); // generates key of lenght length(attribute)
    // save:
    void upload(); // decrypts key from file
    void download(); // encrypts key to file
  public:
    // constructors:
    Key(); // default
    Key(std::string file, std::string password, int length); // new key
    Key(std::string file, std::string password); // existing key
    Key(const Key &key); // copy
    // deconstructor:
    ~Key();
    // getters:
    std::string getFile();
    std::vector<char> getKey();
    int getLength();
    // setters:
    void renameFile(std::string name);
    void changePassword(std::string newPassword);
    void changeLength(int newLength);
    void regenerate();
    // helpers:
    friend void swap(Key &key0, Key &key1);
    // overloads:
    Key & operator=(Key key);
};

#endif

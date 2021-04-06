#ifndef KEY_H
#define KEY_H

#include <string>

class Key
{
  private:
    std::string file;
    unsigned char* pkey;
    unsigned char* key;
    std::string password;
    int length;
    void load();
    void download();
  public:
    //// constructors ////
    Key(std::string file, std::string password, int length); // new key
    Key(std::string file, std::string password); // old key

    //// deconstructor ////
    ~Key();

    //// modify ////
    void change_password();
    void change_length();
    void scramble();

    //// use ////
    void encrypt(unsigned char*& bites);
    void decrypt(unsigned char*& bites);
    void encrypt_file(std::string file);
    void decrypt_file(std::string file);
};

#endif

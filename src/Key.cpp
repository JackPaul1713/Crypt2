#include <string>
#include <fstream>
#include "Key.h"

using namespace std;
void load();
void download();

//// constructors ////
Key::Key(std::string file, std::string password, int length) // new key
{

}
Key::Key(std::string file, std::string password) // old key
{

}

//// deconstructor ////
Key::~Key()
{

}

//// modify ////
void Key::change_password()
{

}
void Key::change_length()
{

}
void Key::scramble()
{

}

//// use ////
void Key::encrypt(unsigned char*& bites)
{

}
void Key::decrypt(unsigned char*& bites)
{

}
void Key::encrypt_file(string file)
{

}
void Key::decrypt_file(string file)
{

}

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  //// var ////
  char* characters = new char[255];

  //// in /////
  ifstream ifs("testfile.txt", ios::binary);
  ifs.read(characters, 255);

  //// edit ////
  for(int i = 0; i < 255; i++)
  {
    characters[i] = characters[i] + 1;
  }

  //// out ////
  ofstream ofs("testfile.txt", ios::binary);
  ofs.write(characters, 255);

  return(0);
}

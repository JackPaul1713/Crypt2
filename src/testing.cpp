#include CYPHER_H
#include KEY_H
#include BLOCK_H

using namespace std;
int main()
{
  // var:
  char* bytes = new char(64);
  Block block;
  // fill bytes:
  for(int i = 0; i < 64; i++)
  {
    bytes[i] = '0'
  }
  // load block:
  block.load(bytes, 64);
  
  return(0);
}

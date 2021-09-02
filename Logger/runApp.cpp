#include <iostream>
#include"logger.h"
using namespace std;
using namespace LogUtil;

int main() 
{
    string path = "/Users/vikas/LowLevelDesign/LLD_in_cpp/Logger/log.txt";
    startLogger(path);
    Log(Type::Fatal, "Got Crashed");
    Log(Type::Error, "Got Error");
    return 0;
}

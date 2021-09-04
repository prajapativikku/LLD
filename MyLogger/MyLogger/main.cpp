//
//  main.cpp
//  MyLogger
//
//  Created by Vikas  on 04/09/21.
//

#include <iostream>
#include"logger.h"
 using namespace std;
 using namespace LogUtil;

int main(int argc, const char * argv[]) {
    string path = "/Users/vikas/LowLevelDesign/LLD_in_cpp/MyLogger/MyLogger/log.txt";
    startLogger(path);
    Log(Type::Fatal, "Got Crashed");
    Log(Type::Error, "Got Error");
    return 0;
}

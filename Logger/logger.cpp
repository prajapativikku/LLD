#include"logger.h"
using namespace LogUtil;

MyLog* MyLog::myLog = NULL;

void startLogger(string &path)
{
    MyLog *mylog = MyLog::getInstance();
    mylog->startLogging(path);
}

void Log(Type t, const string &msg)
{
    MyLog *mylog = MyLog::getInstance();
    mylog->addMsg(t, msg);
}

MyLog* MyLog::getInstance() {
    lock_guard<mutex> lg(mut);
    if(myLog == NULL) 
        myLog = new MyLog();
    return myLog;
}
void MyLog::addMsg(Type t, const string &msg)
{
    lock_guard<mutex> lg(mut);
    if(file.is_open())
    {
        file<<level[t]<<": "<<msg<<endl;
    }
}
void MyLog::startLogging(string &path)
{
    file.open(path);
    addMsg(Type::Info, "starting logger");
}
MyLog::~MyLog()
{
    addMsg(Type::Info, "Stopping logger");
    delete myLog;
    myLog = NULL;
}


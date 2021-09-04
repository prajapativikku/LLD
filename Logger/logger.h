#include<string>
#include<mutex>
#include<fstream>

using namespace std;

namespace LogUtil 
{
enum Type
{
    Fatal,
    Error,
    Warning,
    Info
};

void startLogger(string &filePath);
void Log(Type t, const string &msg);
void finishLogger();

//singleTon Class
class MyLog
{
private:
    MyLog() {}
    MyLog(const MyLog&);
    MyLog* operator = (const MyLog&);
    
    static MyLog* myLog;
    ofstream file;
    static mutex mut;
    const string level[4] = {"Fatal", "Error", "Info", "Warning"};
    
public:
    static MyLog* getInstance();
    void addMsg(Type, const string&);
    void startLogging(string&);
    ~MyLog();
};

}

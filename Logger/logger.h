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
    void Log(Type t, string &msg);

    //singleTon Class
    class MyLog 
    {
        private:
            MyLog() {}
            MyLog(const MyLog&);
            MyLog* operator = (const MyLog&);

            static MyLog* myLog;
            ofstream file;
            mutex mut;
            const string level[4] = {"Fatal", "Error", "Info", "Warning"};

        public:
            static MyLog* getInstance();
            void addMsg(Type, string);
            void startLogging(string);
    };

}

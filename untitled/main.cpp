
// 用类对象创建线程
#include <iostream>
#include <thread>
using namespace std;


// 类要变成可调用对象需要重载操作符（）
class TA{
public:
    int m_i;
    TA(int i):m_i(i){}
    void operator()()//不能带参数，代码从这开始执行
    {
        cout<<"我的线程"<<m_i<<"开始执行了"<<endl;
        //...
        cout<<"我的线程结束执行了"<<endl;
    }
};

int main(){
    int myi =6;
    TA ta(myi);
    thread my_thread(ta);// ta 可调用对象
    my_thread.join();//等待子线程执行结束

    cout<<"I love China"<<endl;
    return 0;
}

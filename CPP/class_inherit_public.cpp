#include<iostream>
#include<assert.h>
using namespace std;
 
class A{
public:
  int id;
  A(){
    public_variate = 1;
    protected_variate = 2;
    private_variate = 3;
  }
  void fun(){
    cout << public_variate << endl;   //正确
    cout << protected_variate << endl;   //正确
    cout << private_variate << endl;   //正确
  }
public:
  int public_variate;
protected:
  int protected_variate;
private:
  int private_variate;
};
class B : public A{
public:
  int id;
  B(int i){
    A();
    id = i;
  }
  int add() {
      return public_variate+protected_variate;
  }
  void fun(){
    cout << id << endl;       //正确，public成员
    cout << public_variate << endl;       //正确，基类的public成员，在派生类中仍是public成员。
    cout << protected_variate << endl;       //正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
    // cout << private_variate << endl;       //错误，基类的private成员不能被派生类访问。
  }
};
int main(){
  B b(10);
  cout << b.id << endl;
  cout << b.public_variate << endl;   //正确
//   cout << b.protected_variate << endl;   //错误，类外不能访问protected成员
//   cout << b.private_variate << endl;   //错误，类外不能访问private成员
//   system("pause");
  cout << "求和:" << b.add() << endl;
  return 0;
}
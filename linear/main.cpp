#include <iostream>
#include "list.h"
using namespace std;
void Jesephus(int amount = 39) {
    List<int> jesephus;
    for(int i = 1; i <= amount; ++i) {
        jesephus.push_back(i);
    }

    jesephus.end()->next = jesephus.begin();
//    for(auto it = jesephus.begin(); it != jesephus.end(); it= it->next) {
//        cout<<it->data<<"\t";
//    }
    auto mark = jesephus.begin();
    auto kill = jesephus.begin();
    int times = 1;
    while(times < 40) {
        for(int i = 1; i <= 2; ++i) {
            mark = mark->next;
        }
        kill = mark;
        cout<<kill->data<<"\t";
        //        if(times % 5 == 0) cout<<endl;
        //if(mark == NULL) break;
        mark = jesephus.erase(kill);
        cout<<"time:"<<times<<"\t"
           <<"me:"<<mark<<"\t"
          <<"before:"<<mark->prior<<"\t"
         <<"\tafter:"<<mark->next<<endl;
        ++times;
    }
}
int main()
{
    cout << "Hello World!" << endl;
    Jesephus();
    return 0;
}

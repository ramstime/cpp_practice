
#include <iostream>

using namespace std;

// from the header file
class Singleton {
public:
static Singleton* instance();
  void display(){
      cout<<"hello display"<<endl;
  }
private:
   static Singleton* pInstance;
};
 
 
// from the implementation file
Singleton* Singleton::pInstance = 0;
 
Singleton* Singleton::instance() {
   //if (pInstance == 0) {
    static Singleton pInstance;// = new Singleton;
  // }
   return &pInstance;
}
int main()
{
    cout<<"Hello World"<<endl;
    Singleton *obj = Singleton::instance();
    obj->display();
    return 0;
}

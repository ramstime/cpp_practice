#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

//c++17 write multithread program, one thread prints odd and other prints even, But it should be in sequence order
/*
odd - 1
even - 2
odd - 3
even - 4
.
.
*/
int count = 1;
int MAX = 10;
mutex m;
condition_variable cond;
bool even = false;
bool odd = true;

void
printEven ()
{
  while (count < MAX)
    {
      unique_lock < mutex > mlock (m);
      cond.wait (mlock,[]
		 {
		 return even;}
      );
      odd = true;
      even = false;
      cout << "Even Print" << count << endl;
      count++;
      cond.notify_all ();
    }
}

void
printOdd ()
{
  while (count < MAX)
    {
      unique_lock < mutex > mlock (m);
      cond.wait (mlock,[]
		 {
		 return odd;}
      );
      odd = false;
      even = true;
      cout << "Odd Print" << count << endl;
      count++;
      cond.notify_all ();
    }
}


int
main ()
{
  thread t1 (printOdd);
  thread t2 (printEven);
  t1.join ();			//wait for thread 1 to join
  t2.join ();			//wait for thread 2 to join
  return 0;
}

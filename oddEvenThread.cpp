#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
//compiled in c++/c++14/c++17/c++20
// write multithread program, one thread prints odd and other prints even, But it should be in sequence order
/*
odd - 1
even - 2
odd - 3
even - 4
.
.
*/
int counter = 1;
int MAX = 20;
mutex m;
condition_variable cond;
bool even = false;
bool odd = true;

void
printEven ()
{

  while (counter < MAX)
    {
      unique_lock < mutex > mlock (m);
      //wait for odd thread to signal
      cond.wait (mlock,[]
		 {
		 return even;
		 }
      );
      //flip values
      odd = true;
      even = false;
      cout << "Even - " << counter << endl;
      counter++;
      //signal the odd thread
      cond.notify_all ();
    }
}

void
printOdd ()
{

  while (counter < MAX)
    {
      unique_lock < mutex > mlock (m);
      //wait for event thread to signal
      cond.wait (mlock,[]
		 {
		 return odd;
		 }
      );
      //flip values
      odd = false;
      even = true;
      cout << "Odd  - " << counter << endl;
      counter++;
      //signal the even thread
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

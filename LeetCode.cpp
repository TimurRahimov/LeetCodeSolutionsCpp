#include <iostream>
#include "problems/Problem1106.h"
#include "problems/Problem2530.h"

#define P1106
#define P2530

using namespace std;

int main()
{   

#ifdef P1106
	Problem1106().test();
#endif // P1106
#ifdef P2530
	Problem2530().test();
#endif // P2530

}

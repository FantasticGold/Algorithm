#include <iostream>
using namespace std;

/**
  * @param a: number A
  * @param b: number B
  * @return: the greatest common divisor of A and B
  * @other: 0 < b, b <= a
  */
int GCD(int a, int b) {
  return b == 0 ? a : GCD(b, a % b);
}
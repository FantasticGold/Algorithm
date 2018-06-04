#include "GCD.h"
#include <cstdlib>
#include <ctime>

#define MAX 100
#define SIZE 10

int test(int& a, int& b) {
  if (a < b) {
    int tmp = a;
    a = b;
    b = tmp;
  }
  return GCD(a, b);
}

int main() {
  int a, b, ans;
  
  srand(time(NULL));
  for (int i = 0; i < SIZE; ++i) {
    a = rand() % MAX + 1;
    b = rand() % MAX + 1;
    ans = test(a, b);
    printf("a = %3d, b = %3d, ans = %3d\n", a, b, ans);
  }

  return 0;
}
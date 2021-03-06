#include "EK.h"
#include <cstdio>

int main() {
  int m;
  scanf("%d %d", &n, &m);

  memset(caps, 0, sizeof(caps));
  printf("Capacity Network:\n");
  while (m--) {
    int from, to, cap;
    scanf("%d %d %d", &from, &to, &cap);
    printf("%2d -> %2d: %2d\n", from, to, cap);
    caps[from][to] = cap;
  }

  int mf = EK(1, n);
  printf("\nMax Flow = %d\n"
         "Max Flow Network:\n", mf);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (flows[i][j] > 0) {
        printf("%2d -> %2d: %2d\n", i, j, flows[i][j]);
      }
    }
  }

  return 0;
}
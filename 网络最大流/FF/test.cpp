#include "FF.h"
#include <cstdio>

int main() {
  int m;
  scanf("%d %d", &n, &m);

  printf("Capacity Network:\n");
  while (m--) {
    int from, to, cap;
    scanf("%d %d %d", &from, &to, &cap);
    printf("%2d -> %2d: %2d\n", from, to, cap);
    ADD(from, to, cap);
  }

  int mf = FF(1, n);
  printf("\nMax Flow = %d\n"
         "Max Flow Network:\n", mf);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < edges[i].size(); ++j) {
      if (edges[i][j].flow > 0) {
        printf("%2d -> %2d: %2d\n", i, edges[i][j].to, edges[i][j].flow);
      }
    }
  }

  return 0;
}
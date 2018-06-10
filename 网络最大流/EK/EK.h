// Edmond-Karp

#include <iostream>
using namespace std;
#include <queue>

const int INF = 0x3f3f3f3f;
const int MAX = 1010;

int caps[MAX][MAX];
int flows[MAX][MAX];

int pre[MAX];
int flow[MAX];

int n;

int BFS(int src, int sink) {

}

int EK(int src, int sink) {
  int mf = 0, af, from, to;
  while ((af = BFS(src, sink)) != -1) {
    to = sink;
    while (to != src) {
      from = pre(to);
      flows[from][to] += flow;
      flows[to][from] -= flow;
      to = from;
    }
    mf += af;
  }
  return mf;
}
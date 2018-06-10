// Edmond-Karp

#include <iostream>
using namespace std;
#include <queue>
#include <cstring>

const int INF = 0x3f3f3f3f;
const int MAX = 1010;

int caps[MAX][MAX];  // the capacity network
int flows[MAX][MAX];  // the flow network

int pre[MAX];  // the previous nodes
int flow[MAX];  // the flow through the nodes

int n;  // the number of the nodes

/**
  * @param src: the source of the network
  * @param sink: the sink of the network
  * @return: the augment flow of the network 
  */
int BFS(int src, int sink) {
  memset(pre, -1, sizeof(pre));
  pre[src] = src;
  flow[src] = INF;
  flow[sink] = -1;

  queue<int> q;
  q.push(src);
  while (!q.empty()) {
    int from = q.front();
    q.pop();

    for (int to = 1; to <= n; ++to) {
      if (pre[to] == -1 && flows[from][to] < caps[from][to]) {
        pre[to] = from;
        flow[to] = min(flow[from], caps[from][to] - flows[from][to]);
        q.push(to);
      }
    }
  }

  return flow[sink];
}

/**
  * @param src: the source of the network
  * @param sink: the sink of the network
  * @return: the max flow of the network
  */
int EK(int src, int sink) {
  int mf = 0, af, from, to;
  while ((af = BFS(src, sink)) != -1) {
    to = sink;
    while (to != src) {
      from = pre[to];
      flows[from][to] += af;
      flows[to][from] -= af;
      to = from;
    }
    mf += af;
  }
  return mf;
}
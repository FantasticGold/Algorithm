// Ford-Fulkerson

#include <iostream>
using namespace std;
#include <vector>
#include <cstring>

const int INF = 0x3f3f3f3f;
const int MAX = 1010;

struct Edge {
  int to;
  int cap;
  int flow;
  int rev;
};

vector<Edge> edges[MAX];  // the capacity and flow of the edges
bool used[MAX];  // whether the nodes are used or not

int n;  // the number of the nodes

/**
  * @param from: the first node of the edge
  * @param to: the second node of the edge
  * @param cap: the capacity of the edge
  */
void ADD(int from, int to, int cap) {
  edges[from].push_back((Edge){ to, cap, 0, edges[to].size() });
  edges[to].push_back((Edge){ from, 0, 0, edges[from].size()-1 });
}

/**
  * @param src: the source of the network
  * @param sink: the sink of the network
  * @return: the flow through the nodes 
  */
int DFS(int src, int sink, int flow) {
  if (src == sink) return flow;
  used[src] = true;
  for (int i = 0; i < edges[src].size(); ++i) {
    Edge &tmp = edges[src][i];
    if (!used[tmp.to] && tmp.flow < tmp.cap) {
      int af = DFS(tmp.to, sink, min(flow, tmp.cap - tmp.flow));
      if (af != -1) {
        tmp.flow += af;
        edges[tmp.to][tmp.rev].flow -= af;
        return af;
      }
    }
  }
  return -1;
}

/**
  * @param src: the source of the network
  * @param sink: the sink of the network
  * @return: the max flow of the network 
  */
int FF(int src, int sink) {
  int mf = 0, af;
  while (true) {
    memset(used, false, sizeof(used));
    if ((af = DFS(src, sink, INF)) != -1) {
      mf += af;
    } else {
      break;
    }
  }
  return mf;
}


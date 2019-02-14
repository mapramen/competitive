#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
int u[N], v[N], h[N], subtreeSize[N], heapNo[N], parentEdge[N];
ll w[N], s[N], c[N], new_w[N], new_s[N], subtreeBaseWeight[N], subtreeWeight[N];
priority_queue< pii, vector< pii >, greater< pii > > heaps[N];
bool ansValid = 1;

void MoveHeap(int s, int t){
  while(!heaps[s].empty()){
    heaps[t].push(heaps[s].top());
    heaps[s].pop();
  }
}

void DFS(int i){
  // printf("S: %d %d %d %lld\n", i, subtreeSize[i], h[i], subtreeWeight[i]);
  int heavyChild = 0;

  for(auto k : adj[i]){
    DFS(k);
    subtreeSize[i] += subtreeSize[k];
    subtreeBaseWeight[i] += subtreeBaseWeight[k];
    subtreeWeight[i] += subtreeWeight[k];

    h[i] = max(h[i], h[k]);

    if(subtreeSize[k] > subtreeSize[heavyChild])
      heavyChild = k;
  }

  if(heavyChild == 0)
    heapNo[i] = i;
  else
    heapNo[i] = heapNo[heavyChild];

  int cur_heap_no = heapNo[i];

  for(auto k : adj[i]){
    if(k != heavyChild)
      MoveHeap(heapNo[k], cur_heap_no);
  }

  int pEdge = parentEdge[i];
  ll cW = w[pEdge] - 1, cS = s[pEdge] - subtreeBaseWeight[i];
  c[pEdge] = max(0ll, min(cW, cS));
  new_w[pEdge] = w[pEdge] - c[pEdge], new_s[pEdge] = s[pEdge] - c[pEdge];

  subtreeSize[i]++;
  h[i]++;

  // printf("M: %d %d %d %lld\n", i, subtreeSize[i], h[i], subtreeWeight[i]);

  while(new_s[pEdge] + c[pEdge] < subtreeWeight[i] && !heaps[cur_heap_no].empty()){
    int edgeHeight, edgeNo;
    tie(edgeHeight, edgeNo) = heaps[cur_heap_no].top();
    heaps[cur_heap_no].pop();

    // printf("L: %d %d %lld %lld\n", edgeNo, c[edgeNo], new_s[pEdge] + c[pEdge], subtreeWeight[i]);

    int temp = min(c[edgeNo], subtreeWeight[i] - new_s[pEdge] - c[pEdge]);
    c[edgeNo] -= temp;
    subtreeWeight[i] -= temp;

    if(c[edgeNo])
      heaps[cur_heap_no].push(MP(edgeHeight, edgeNo));
  }

  ansValid &= (s[pEdge] >= subtreeWeight[i]);

  subtreeBaseWeight[i] += new_w[pEdge];
  subtreeWeight[i] += (new_w[pEdge] + c[pEdge]);
  heaps[cur_heap_no].push(MP(h[i], pEdge));
  // printf("E: %d %d %d %lld\n", i, subtreeSize[i], h[i], subtreeWeight[i]);
}

int main(){
  int n;

  scanf("%d", &n);

  for(int k = 1; k < n; k++){
    scanf("%d%d%lld%lld", &u[k], &v[k], &w[k], &s[k]);
    parentEdge[v[k]] = k;
    adj[u[k]].PB(v[k]);
  }

  w[0] = s[0] = LLONG_MAX;
  DFS(1);

  if(ansValid == 0)
    printf("-1\n");
  else{
    printf("%d\n", n);
    for(int k = 1; k < n; k++){
      new_w[k] += c[k];
      new_s[k] += c[k];
      printf("%d %d %lld %lld\n", u[k], v[k], new_w[k], new_s[k]);
    }
  }

  return 0;
}

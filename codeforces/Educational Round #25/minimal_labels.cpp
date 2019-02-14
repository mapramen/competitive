#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
int outDegree[N], ans[N];
bool visited[N];

int main(){
  int n, m, nxt;
  priority_queue<int> Q;

  scanf("%d%d", &n, &m);
  for(int x = 1; x <= m; x++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[j].PB(i);
    outDegree[i]++;
  }

  for(int i = 1; i <= n; i++){
    if(outDegree[i] == 0)
      Q.push(i);
  }

  nxt = n;
  while(!Q.empty()){
    int i = Q.top();
    Q.pop();
    ans[i] = nxt--;

    for(auto k : adj[i]){
      outDegree[k]--;
      if(outDegree[k] == 0)
        Q.push(k);
    }
  }

  for(int i = 1; i <= n; i++)
    printf("%d ", ans[i]);
  printf("\n");

  return 0;
}

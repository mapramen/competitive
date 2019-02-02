#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
int a[N], degree[N];
deque<int> Q;

void CheckAndAddToQ(int i, int x){
  if(degree[i])
    return;
    
  if(a[i] == x)
    Q.push_front(i);
  else
    Q.push_back(i);
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[j].PB(i);
    ++degree[i];
  }

  for(int i = 0; i < n; ++i)
    CheckAndAddToQ(i, 0);

  int ans = 0;
  while(!Q.empty()){
    int x = a[Q.front()];
    while(!Q.empty() && a[Q.front()] == x){
      int i = Q.front();
      Q.pop_front();
      for(auto k : adj[i]){
        --degree[k];
        CheckAndAddToQ(k, x);
      }
    }
    ans += x;
  }

  printf("%d\n", ans);

  return 0;
}

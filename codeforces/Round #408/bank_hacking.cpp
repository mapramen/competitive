#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001

vector< vector<int> > adj(N);
int a[N];
bool visited[N];

int main(){
  int n, ans = INT_MAX;
  priority_queue< pii > Q;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
    Q.push(MP(a[i], i));
  }

  for(int x = 1; x < n; x++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  for(int i = 1; i <= n; i++){
    int ansx = a[i];
    visited[i] = 1;

    for(auto k : adj[i]){
      visited[k] = 1;
      ansx = max(ansx, 1 + a[k]);
    }

    while(Q.size() > 0 && visited[Q.top().second] == 1)
      Q.pop();

    if(Q.size())
      ansx = max(ansx, 2 + Q.top().first);

    Q.push(MP(a[i], i));
    visited[i] = 0;

    for(auto k : adj[i]){
      visited[k] = 0;
      Q.push(MP(a[k], k));
    }

    ans = min(ans, ansx);
  }

  printf("%d\n", ans);

  return 0;
}

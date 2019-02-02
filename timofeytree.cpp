#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
int degree[N], c[N], t[N], timer;

int main(){
  int n, m, ans;
  queue<int> q;

  scanf("%d", &n);
  m = n - 1;

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j), adj[j].PB(i);
    degree[i]++, degree[j]++;
  }

  for(int i = 1; i <= n; i++)
    scanf("%d", &c[i]);

  for(int i = 1; i <= n; i++){
    if(degree[i] > 1)
      continue;
    q.push(i);
  }

  while(!q.empty()){
    int i = q.front();
    q.pop();
    t[i] = ++timer;

    for(auto k : adj[i]){
      if(c[k] != c[i])
        continue;

      degree[k]--;
      if(degree[k] == 1)
        q.push(k);
    }

    ans = i;
  }

  if(timer < n - 1)
    cout << "NO\n";
  else{
    if(timer != n)
      for(ans = 1; t[ans] != 0; ans++);

    cout << "YES\n" << ans << '\n';
  }

  return 0;
}

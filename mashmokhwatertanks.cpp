#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
int c[N];
ll a[N];

void DFS(int i, int p, int h){
  c[h]++;
  for(auto k : adj[i]){
    if(k != p)
      DFS(k, i, h + 1);
  }
}

void Fill(int n){
  for(int i = 0, k = 0; i <= n; i++)
    while(c[i]--)
      a[k++] = i;
}

ll Compute(int n, int k, int p){
  ll ans = 0;
  for(ll i = 1, j = 1, s = 0; i < n; s -= a[i], i++){
    for( ; j < n && j - i + 1 <= k && ((j - i + 1) * a[j] - (s + a[j])) <= p; s += a[j], j++);
    ans = max(ans, j - i);
  }
  return ans;
}

int main(){
  int n, k, p;

  scanf("%d%d%d", &n, &k, &p);

  for(int x = 1; x < n; x++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(1, 0, 0);
  Fill(n);
  printf("%lld\n", Compute(n, k, p));

	return 0;
}

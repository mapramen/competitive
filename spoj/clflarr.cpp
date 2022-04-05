#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<pii>> V(N);
int c[N];
priority_queue<pii> Q;

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int k = 1; k <= q; ++k){
    int l, r;
    scanf("%d%d%d", &l, &r, &c[k]);
    V[l].push_back({k, r});
  }

  for(int i = 1; i <= n; ++i){
    for(pii& p: V[i]){
      Q.push(p);
    }

    while(!Q.empty() && Q.top().second < i){
      Q.pop();
    }

    printf("%d\n", Q.empty() ? 0 : c[Q.top().first]);
  }

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 500000
#define L 10

vector<vector<pii>> adj(N), Q(L + 1);
int d[N], inf = L * N;

void CheckAndPush(int k, int i, int val){
  if(d[i] == -1 || val < d[i]){
    d[i] = val;
    Q[k % (L + 1)].push_back({i, val});
  }
}

pii Query(int n, int s){
  for(int i = 0; i < n; ++i){
    d[i] = -1;
  }

  CheckAndPush(0, s, 0);

  for(int k = 0; k < n * L; ++k){
    vector<pii>& q = Q[k % (L + 1)];
    
    for(int x = 0; x < q.size(); ++x){
      int i = q[x].first, val = q[x].second;
      if(d[i] != val){
        continue;
      }

      for(pii& edge: adj[i]){
        int j = edge.first, w = edge.second;
        CheckAndPush(k + w, j, val + w);
      }
    }

    q.clear();
  }

  int max_dis = *max_element(d, d + n);
  int cnt = 0;
  for(int i = 0; i < n; ++i){
    cnt += d[i] == max_dis;
  }

  return {max_dis, cnt};
}

int main(){
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  while(q--){
    int i;
    scanf("%d", &i);
    pii ans = Query(n, i);
    printf("%d %d\n", ans.first, ans.second);
  }

  return 0;
}
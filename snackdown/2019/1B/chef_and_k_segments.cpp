#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector< pii > > V;
vector<int> C, T;
int l[N], r[N];

void Update(int i, int x){
  for( ; i < T.size(); i += (i & -i)){
    T[i] += x;
  }
}

int PrefixSumQuery(int x){
  int i = 0, k = 20;
  for( ; x > 0 && k > -1; --k){
    int j = (i + (1 << k));
    if(j < T.size() && T[j] < x){
      x -= T[j];
      i = j;
    }
  }
  return i + 1;
}

void PreProcess(int n){
  for(int i = 1; i <= n; ++i){
    C.PB(l[i]);
    C.PB(r[i]);
    C.PB(r[i] + 1);
  }
  C.PB(0);

  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  int m = C.size();
  T.resize(m);
  V.resize(m);

  for(int i = 1; i <= n; ++i){
    int cl = lower_bound(C.begin(), C.end(), l[i]) - C.begin();
    int cr = lower_bound(C.begin(), C.end(), r[i]) - C.begin();
    V[cl].PB(MP(1, cl));
    V[cr + 1].PB(MP(-1, cl));
  }
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 1; i <= n; ++i){
      scanf("%d%d", &l[i], &r[i]);
    }

    PreProcess(n);

    int c = 0, ans = 0;
    for(int i = 0; i < V.size(); ++i){
      for(auto p : V[i]){
        int x, j;
        tie(x, j) = p;
        Update(j, x);
        c += x;
      }

      if(c >= k){
        int j = PrefixSumQuery(k);
        int ansx = C[i] - C[j];
        ans = max(ans, ansx);
      }

      V[i].clear();
    }

    printf("%d\n", ans);

    V.clear();
    T.clear();
    C.clear();
  }

  return 0;
}

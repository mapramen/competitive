#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 100001

vector< vector<int> > C(N), T(N);

void PreProcess(int n){
  for(int i = 1; i <= n; ++i){
    C[i].PB(-1), C[i].PB(0), C[i].PB(N - 1);
    sort(C[i].begin(), C[i].end());
    C[i].erase(unique(C[i].begin(), C[i].end()), C[i].end());
    T[i].resize(C[i].size());
  }
}

int GetUpperLowerBound(vector<int>& v, int x){
  return lower_bound(v.begin(), v.end(), x) - v.begin() - 1;
}

void Update(vector<int>& T, vector<int>& C, int i, int x){
  for(i = GetUpperLowerBound(C, i) + 1; i < T.size(); i += (i & -i))
    T[i] = max(T[i], x);
}

int Query(vector<int>& T, vector<int>& C, int i){
  int ans = 0;
  for(i = GetUpperLowerBound(C, i); i > 0; i -= (i & -i))
    ans = max(ans, T[i]);
  return ans;
}

int main(){
  int n, m;
  vector< tiii > edges;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    edges.PB(MT(j, i, k));
    C[i].PB(k);
    C[j].PB(k);
  }

  PreProcess(n);

  int ans = 0;
  for(auto edge : edges){
    int i, j, k;
    tie(i, j, k) = edge;
    int ansx = 1 + Query(T[j], C[j], k);
    Update(T[i], C[i], k, ansx);
    ans = max(ans, ansx);
  }

  printf("%d\n", ans);

  return 0;
}

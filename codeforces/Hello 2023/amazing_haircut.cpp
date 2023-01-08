#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200005

int a[N], b[N], c[N];
set<int> S;
bool need_to_cut[N];
priority_queue<pii,vector<pii>,greater<pii>> Q;

void Reset(int n){
  for( ; !Q.empty(); Q.pop());

  S.clear();
  
  for(int i = 0; i <= n + 1; ++i){
    S.insert(i);
    need_to_cut[i] = true;
  }

  b[0] = b[n + 1] = INT_MAX;
}

void Union(int i, int j){
  i = *S.lower_bound(i), j = *S.lower_bound(j);
  if(b[i] != b[j]){
    return;
  }

  if(i < j){
    swap(i, j);
  }

  S.erase(j);
  need_to_cut[i] = need_to_cut[i] || need_to_cut[j];
}

bool Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  int m;
  scanf("%d", &m);

  for(int i = 1; i <= m; ++i){
    scanf("%d", &c[i]);
  }

  Reset(n);

  for(int i = 1; i <= n; ++i){
    if(b[i] > a[i]){
      return false;
    }
    need_to_cut[i] = b[i] != a[i];
    Q.push({b[i], i});
  }

  for(int i = n; i != 0; --i){
    Union(i, i + 1);
  }

  sort(c + 1, c + m + 1);

  for(int k = 1; !Q.empty(); Q.pop()){
    auto [_, i] = Q.top();
    auto it = S.find(i);

    if(it == S.end()){
      continue;
    }

    if(need_to_cut[i]){
      for( ; k <= m && c[k] < b[i]; ++k);

      if(k > m || (k <= m && c[k] != b[i])){
        return false;
      }
      
      ++k;
    }

    int l = *prev(it), r = *next(it);
    S.erase(it);
    Union(l, r);
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> indexes(N);
int T[N];

void Reset(int n, int l){
  for(int i = 1; i <= n; ++i){
    T[i] = 0;
  }

  for(int x = 0; x < l; ++x){
    indexes[x].clear();
  }
}

void Update(int n, int i, int val){
  for( ; i <= n; i += (i & -i)){
    T[i] = max(T[i], val);
  }
}

int Query(int i){
  int ans = 0;
  for( ; i != 0; i -= (i & -i)){
    ans = max(ans, T[i]);
  }
  return ans;
}

int Solve(){
  int n, l;
  scanf("%d%d", &n, &l);
  
  Reset(n, l);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    indexes[x].push_back(i);
  }

  for(int x = 0; x < l; ++x){
    reverse(indexes[x].begin(), indexes[x].end());
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    for(int j: indexes[x]){
      int ansx = 1 + Query(j - 1);
      Update(n, j, ansx);
      ans = max(ans, ansx);
    }
  }

  return 2 * (n - ans);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}
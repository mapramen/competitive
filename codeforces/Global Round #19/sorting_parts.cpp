#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<pii> a(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a.begin(), a.end());

  for(int i = 0, j = -1; i < n - 1; ++i){
    j = max(j, a[i].second);
    if(j > i){
      return true;
    }
  }

  return false;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}
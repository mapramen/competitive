#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int a[N], b[N];
set<int> S[N];

int main(){
  int n, ans = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    S[a[i]].insert(i);
  }

  for(int i = 1, j = 1; i <= n; ++i){
    if(S[i].size()){
      int k = *S[i].begin();
      b[k] = i;
      S[i].clear();
    }
    else{
      ++ans;
      for( ; j <= n && (b[j] != 0 || S[a[j]].size() == 1); ++j);
      b[j] = i;
      S[a[j]].erase(j);
    }
  }

  printf("%d\n", ans);
  for(int i = 1; i <= n; ++i)
    printf("%d ", b[i]);
  printf("\n");

  return 0;
}

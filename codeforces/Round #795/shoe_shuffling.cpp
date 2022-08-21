#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

int a[N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  vector<int> ans;
  for(int i = 1, j = 1; i <= n; i = j){
    for(j = i + 1; j <= n && a[j] == a[i]; ++j);
    if(j == i + 1){
      ans.clear();
      break;
    }

    int k = j - i;
    for(int x = i; x < j; ++x){
      ans.push_back(i + (x + 1 - i) % k);
    }
  }

  if(ans.empty()){
    printf("-1\n");
    return;
  }

  for(int& x: ans){
    printf("%d ", x);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}
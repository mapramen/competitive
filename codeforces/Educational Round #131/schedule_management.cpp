#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int c[N];

bool Check(int n, int t){
  ll x = 0, y = 0;
  for(int i = 1; i <= n; ++i){
    x += max(0, c[i] - t);
    y += max(0, t - c[i]) / 2;
  }
  return x <= y;
}

int BinarySearch(int n){
  int x = 1, y = N, ans = N;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n, mid)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    c[i] = 0;
  }

  while(m--){
    int i;
    scanf("%d", &i);
    ++c[i];
  }

  return BinarySearch(n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}
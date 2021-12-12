#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N], b[N];

bool Check(int n, int m){
  int c = 0;
  for(int i = 1; i <= n; ++i){
    if(m - c - 1 <= a[i] && c <= b[i]){
      ++c;
    }
  }
  return c >= m;
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i], &b[i]);
  }

  int x = 0, y = n, ans = 0;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n, mid)){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}
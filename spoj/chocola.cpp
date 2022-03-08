#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

int a[N], b[N];

void ReadArray(int n, int a[]){
  for(int i = 1; i < n; ++i){
    scanf("%d", &a[i]);
  }
  a[n] = 0;
  sort(a + 1, a + n + 1, greater<int>());
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  ReadArray(n, a);
  ReadArray(m, b);

  int x = 1, y = 1, ans = 0;
  for(int i = 1, j = 1; i < n || j < m; ){
    if(a[i] > b[j]){
      ans += y * a[i];
      ++i, ++x;
    }
    else{
      ans += x * b[j];
      ++j, ++y;
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
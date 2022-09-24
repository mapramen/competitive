#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 501

int a[N], b[N];

bool ShouldReverse(int a[], int l, int r){
  for( ; l < r && a[l] >= a[r]; ++l, --r);
  return l < r && a[r] < a[l];
}

vector<pii> Characterize(int n, int a[]){
  vector<pii> v;
  for(int len = n; len != 0; --len){
    for(int i = 1, j = len; j <= n; ++i, ++j){
      if(ShouldReverse(a, i, j)){
        v.push_back({i, j});
        reverse(a + i + 1, a + j + 1);
      }
    }
  }
  return v;
}

vector<pii> ReadArray(int n, int a[]){
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  return Characterize(n, a);
}

void Solve(){
  int n;
  scanf("%d", &n);

  vector<pii> A = ReadArray(n, a);
  vector<pii> B = ReadArray(n, b);

  for(int i = 1; i <= n; ++i){
    if(a[i] != b[i]){
      printf("NO\n");
      return;
    }
  }

  reverse(B.begin(), B.end());
  A.insert(A.end(), B.begin(), B.end());

  printf("YES\n");
  for(auto [l, r]: A){
    printf("%d %d\n", l, r);
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}
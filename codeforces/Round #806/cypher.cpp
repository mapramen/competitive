#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101
#define B 10

int a[N];
char s[N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    int m;
    scanf("%d%s", &m, s);

    for(int j = 0; j < m; ++j){
      a[i] += (s[j] == 'U' ? -1 : 1);
      a[i] %= B;
      a[i] = (B + a[i]) % B;
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", a[i]);
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
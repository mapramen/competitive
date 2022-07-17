#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

char s[N];
int c[N], dp_cols[N], dp_rows[N];

void Solve(){
  int n, m;
  scanf("%d%d%s", &n, &m, s);

  for(int y = 0; y < m; ++y){
    dp_cols[y] = 0;
  }

  int ans_cols = 0, ans_rows = 0;
  for(int i = 1; i <= n * m; ++i){
    int z = s[i - 1] == '1';
    dp_cols[i % m] += z;
    ans_cols += (z == 1 && dp_cols[i % m] == 1);

    c[i] = c[i - 1] + (s[i - 1] == '1');
    
    int j = max(0, i - m);
    dp_rows[i] = dp_rows[j] + (c[i] - c[j] != 0);
    ans_rows = dp_rows[i];

    printf("%d ", ans_cols + ans_rows);
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
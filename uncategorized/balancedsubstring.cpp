#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

char s[N];
int p[N], c[2 * N];

int main(){
  int n, ans = 0;

  scanf("%d%s", &n, s);

  for(int i = 1; i <= n; ++i){
    char a = s[i - 1];
    if(a == '0')
      p[i] = 1 + p[i - 1];
    else
      p[i] = -1 + p[i - 1];
    int j = N + p[i];
    c[j] = max(c[j], i);
  }

  for(int i = 0; i <= n; ++i){
    int j = c[N + p[i]];
    ans = max(ans, j - i);
  }

  printf("%d\n", ans);

  return 0;
}

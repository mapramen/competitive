#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100000

char s[N + 1];
int a[N], b[N], p[N];

bool cmp(int i, int j){
  return 1ll * a[i] * b[j] > 1ll * a[j] * b[i];
}

int main(){
  int n;
  ll ans = 0;

  cin >> n;
  for(int i = 0; i < n; ++i){
    scanf("%s", s);
    for(int j = 0; s[j] != '\0'; ++j){
      char c = s[j];
      a[i] += (c == 's');
      b[i] += (c == 'h');
      if(c == 'h')
        ans += a[i];
    }
    p[i] = i;
  }

  sort(p, p + n, cmp);

  for(int j = 0, x = 0; j < n; ++j){
    int i = p[j];
    ans += 1ll * x * b[i];
    x += a[i];
  }

  cout << ans << '\n';

  return 0;
}

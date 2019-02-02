#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100002

char s[N], t[N];
int prefix[N], suffix[N];

int BinarySearch(int n, int k){
  int x = 0, y = n + 1, z = 0;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(suffix[mid] >= k)
      z = mid, x = mid + 1;
    else
      y = mid - 1;
  }
  return z;
}

int main(){
  int k;
  scanf("%d", &k);
  while(k--){
    scanf("%s%s", s, t);

    int n = strlen(s), m = strlen(t);
    ll ans = 0;

    for(int i = 1; i < N; ++i)
      prefix[i] = suffix[i] = 0;

    for(int i = 1; i <= n; ++i){
      char a = s[i - 1], b = t[prefix[i - 1]];
      prefix[i] = (a == b) + prefix[i - 1];
    }

    for(int i = n; i > 0; --i){
      char a = s[i - 1], b;
      if(suffix[i + 1] == m)
        b = '\0';
      else
        b = t[m - 1 - suffix[i + 1]];
      suffix[i] = (a == b) + suffix[i + 1];
    }

    prefix[n + 1] = prefix[n];
    suffix[0] = suffix[1];

    for(int i = 0; i <= n; ++i){
      int j = BinarySearch(n, m - prefix[i]);
      ans += max(0, j - i - 1);
    }

    printf("%lld\n", ans);
  }

  return 0;
}

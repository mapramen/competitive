#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001

char s[N], t[N];

int main(){
  int n, ans = 0;

  scanf("%d%s%s", &n, s, t);

  for(int i = 0; i < n - 1; ++i){
    if(s[i] == s[i + 1] || t[i] == t[i + 1] || s[i] == t[i]){
      continue;
    }
    swap(s[i], s[i + 1]);
    ++ans;
  }

  for(int i = 0; i < n; ++i){
    ans += (s[i] != t[i]);
  }

  printf("%d\n", ans);

  return 0;
}

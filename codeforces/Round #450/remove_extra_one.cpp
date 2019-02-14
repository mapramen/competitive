#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int c[N];

int main(){
  int n;
  set<int> s;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    auto it = s.upper_bound(x);
    if(it != s.end() && *s.rbegin() == *it && i != 2)
      ++c[*it];

    if(i != 1 && it == s.end())
      --c[x];

    if(i == 1 && x == 1)
      --c[x];
    s.insert(x);
  }

  int ans = 1;
  for(int i = 1; i <= n; ++i){
    if(c[i] > c[ans])
      ans = i;
  }

  printf("%d\n", ans);

  return 0;
}

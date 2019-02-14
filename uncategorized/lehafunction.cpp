#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector<int> a, b, c;

bool cmp(int i, int j){
  return MP(b[i], i) <= MP(b[j], j);
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);
    a.PB(x);
  }

  for(int i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);
    b.PB(x);
    c.PB(i);
  }

  sort(a.begin(), a.end(), greater<int>());
  sort(c.begin(), c.end(), cmp);

  vector<int> ans(n);

  for(int i = 0; i < n; ++i)
    ans[c[i]] = a[i];

  for(auto x : ans)
    printf("%d ", x);
  printf("\n");

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define B 256

char s[N];
int T[N], a[N];
set<int> M[B];

void Update(int i, int x){
  for( ; i < N; i += (i & -i))
    T[i] += x;
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i))
    ans += T[i];
  return ans;
}

int GetIndex(int k){
  int x = 1, y = N - 1, z = 0;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Query(mid) < k)
      x = mid + 1;
    else
      z = mid, y = mid - 1;
  }
  return z;
}

void PreProcess(int n){
  for(int i = 1; i <= n; ++i)
    Update(i, 1);

  for(int i = 1; i <= n; ++i)
    M[s[i - 1]].insert(i);
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  scanf("%s", s);

  PreProcess(n);

  while(q--){
    int l, r;
    char c;
    vector<int> v;

    scanf("%d %d %c", &l, &r, &c);
    l = GetIndex(l), r = GetIndex(r);

    for(auto it = M[c].lower_bound(l); it != M[c].end() && *it <= r; ++it)
      v.PB(*it);

    for(auto x : v){
      Update(x, -1);
      M[c].erase(x);
    }
  }

  for(int i = 1; i <= n; ++i){
    a[i] = Query(i);
    if(a[i] != a[i - 1])
      putchar(s[i - 1]);
  }
  putchar('\n');

  return 0;
}

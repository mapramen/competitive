#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000005

char s[N];
int a[N], L[N], R[N];

int Find(int P[], int i){
  if(P[i] == i)
    return i;
  else
    return (P[i] = Find(P, P[i]));
}

int main(){
  int n;
  vector<int> v, u;

  scanf("%s", s);
  n = strlen(s);

  for(int i = 1; i <= n; ++i){
    a[i] = s[i - 1] - 'a' + 1;
    L[i] = i;
    R[i] = i;
    v.PB(i);
  }

  a[0] = a[1], a[n + 1] = a[n];
  R[n + 1] = n + 1;

  int ans = 0;
  while(v.size()){
    u.clear();

    for(auto i : v){
      if(i == 0 || i == n + 1 || a[i] == 0)
        continue;

      int l = Find(L, i - 1), r = Find(R, i + 1);
      if((l != 0 && a[l] != a[i]) || (r != n + 1 && a[i] != a[r]))
        u.PB(i);
    }

    v.clear();

    if(u.size() == 0)
      break;

    ++ans;

    for(auto i : u){
      int l = Find(L, i - 1), r = Find(R, i + 1);
      L[i] = l;
      R[i] = r;
      a[i] = 0;

      if(v.size() == 0 || v.back() < l)
        v.PB(l);

      if(v.size() == 0 || v.back() < r)
        v.PB(r);
    }
  }

  printf("%d\n", ans);

  return 0;
}

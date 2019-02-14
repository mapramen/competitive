#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define M 300001

int D[N], a[M];
ll T[M];
set<int> S;

void Update(int i, int x){
  for( ; i < M; i += (i & -i))
    T[i] += x;
}

ll Query(int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i))
    ans += T[i];
  return ans;
}

void Initialise(){
  for(int i = 1; i < N; ++i)
    for(int j = i; j < N; j += i)
      ++D[j];
}

void PreProcess(int n){
  Initialise();
  for(int i = 1; i <= n; ++i){
    Update(i, a[i]);
    if(a[i] != D[a[i]])
      S.insert(i);
  }
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  PreProcess(n);

  while(q--){
    int t, l, r;

    scanf("%d%d%d", &t, &l, &r);

    if(t == 1){
      vector<int> v;

      for(auto it = S.lower_bound(l); it != S.end() && *it <= r; ++it){
        int i = *it;
        Update(i, -a[i]);
        a[i] = D[a[i]];
        Update(i, a[i]);
        if(a[i] == D[a[i]])
          v.PB(i);
      }

      for(auto x : v)
        S.erase(x);
    }
    else
      printf("%lld\n", Query(r) - Query(l - 1));
  }

  return 0;
}

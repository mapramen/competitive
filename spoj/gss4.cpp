#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100002

int parent[N];
ll a[N], T[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    T[i] = 0;
  }
  
  for(int i = 1; i <= n + 1; ++i){
    parent[i] = i;
  }

  a[n + 1] = 0;
}

void Update(int n, int i, ll x){
  for( ; i <= n; i += (i & -i)){
    T[i] += x;
  }
}

ll Query(int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int Find(int i){
  return parent[i] == i && a[i] != 1 ? i : parent[i] = Find(parent[i + 1]);
}

ll Sqrt(ll n){
  ll x = sqrt(n) - 1;
  while(x * x <= n){
    ++x;
  }
  return x - 1;
}

ll Query(int l, int r){
  return Find(l) > r ? r - l + 1 : Query(r) - Query(l - 1);
}

void Solve(int tc){
  int n;
  
  if(scanf("%d", &n) == EOF){
    exit(0);
  }

  if(tc != 1){
    printf("\n");
  }

  printf("Case #%d:\n", tc);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  Reset(n);

  for(int i = 1; i <= n; ++i){
    Update(n, i, a[i]);
  }

  int m;
  scanf("%d", &m);

  while(m--){
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);

    if(l > r){
      swap(l, r);
    }

    // l = max(1, l), r = min(n, r);

    if(t == 0){
      while(l <= r){
        l = Find(l);
        if(l > r){
          break;
        }

        ll x = a[l];
        x = Sqrt(x) - x;
        Update(n, l, x);
        a[l] += x;

        ++l;
      }
    }
    else{
      printf("%lld\n", Query(l, r));
    }
  }
}

int main(){
  for(int k = 1; ; ++k){
    Solve(k);
  }
  return 0;
}
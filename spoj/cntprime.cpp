#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define M 1000001
#define N 20001

bool is_prime[M];
map<int,pii> intervals;
ll T1[N], T2[N];

void Initialise(){
  for(int i = 2; i < M; ++i){
    is_prime[i] = true;
  }

  for(int i = 2; i * i < M; ++i){
    for(int j = 2 * i; j < M; j += i){
      is_prime[j] = false;
    }
  }
}

void Update(ll T[], int i, ll x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

ll Query(ll T[], int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

void Update(int l, int r, int x){
  Update(T1, l, x), Update(T1, r, -x);
  Update(T2, l, - (l - 1) * x), Update(T2, r, r * x);
}

int Query(int i){
  return i * Query(T1, i) + Query(T2, i);
}

int Query(int l, int r){
  return Query(r) - Query(l - 1);
}

void Reset(int n){
  for(int i = 1; i < N; ++i){
    T1[i] = 0, T2[i] = 0;
  }

  intervals.clear();
  intervals[1] = {n, 0};
  intervals[n + 1] = {n + 1, 0};
}

void SplitInterval(int i){
  auto it = prev(intervals.upper_bound(i));
  int l = it->first, r = it->second.first, x = it->second.second;

  intervals.erase(it);

  if(l != i){
    intervals[l] = {i - 1, x};
  }

  intervals[i] = {i, x};

  if(i != r){
    intervals[i + 1] = {r, x};
  }
}

void UpdateInterval(int l, int r, int x){
  SplitInterval(l), SplitInterval(r);

  while(true){
    auto it = intervals.lower_bound(l);
    if(it->first > r){
      break;
    }
    Update(it->first, it->second.first, -it->second.second);
    intervals.erase(it);
  }

  Update(l, r, is_prime[x]);
  intervals[l] = {r, is_prime[x]};
}

void Solve(){
  int n, q;
  scanf("%d%d", &n, &q);

  Reset(n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    UpdateInterval(i, i, x);
  }

  while(q--){
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);

    if(t == 0){
      int x;
      scanf("%d", &x);
      UpdateInterval(l, r, x);
    }
    else{
      printf("%d\n", Query(l, r));
    }
  }
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  
  for(int k = 1; k <= t; ++k){
    printf("Case %d:\n", k);
    Solve();
  }
  
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100005
#define LOGN 16

ll A[N], B[N], T[N], TA[N], TB[N], TC[N];

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

void Initialise(int n, int m){
  for(int i = 1; i <= m; ++i){
    Update(TC, i, 2 * B[i]);
  }

  for(int i = 2, d = 0; i <= m; ++i){
    int dx = B[i] - B[i - 1];
    Update(T, i, dx - d);
    d = dx;
  }
}

void UpdateA(int n, int k, int d){
  for(int i = n - k + 1, j = 1; i <= n; ++i, ++j){
    A[i] += 1ll * j * d;
  }
}

void UpdateB(int m, int k, int d){
  int i = m - k + 1;
  Update(T, max(2, i), d);

  Update(TA, i, d);
  Update(TB, i, 1ll * (3 - 2 * i) * d);
  Update(TC, i, 1ll * (i - 1) * (i - 2) * d);
}

ll DiffA(int n, int i){
  return i > n ? LLONG_MAX : A[i] - A[i - 1];
}

ll SumB(int i){
  return (Query(TA, i) * i * i + Query(TB, i) * i + Query(TC, i)) / 2;
}

ll SumB(int i, int j){
  return SumB(j) - SumB(i - 1);
}

int BinarySearch(int m, ll d){
  int i = 0;

  for(int k = LOGN; k != -1; --k){
    int ni = i + (1 << k);
    if(ni <= m && T[ni] <= d){
      d -= T[ni];
      i = ni;
    }
  }

  return i;
}

ll Query(int n, int m){
  ll ans = 0;

  int i = 1, j = 1;
  while(i <= n && j <= m){
    int nj = BinarySearch(m, DiffA(n, i + 1));

    if(nj == j){
      ans += A[i] + SumB(j, j);
      ++i;
      continue;
    }
    
    ans += (nj - j) * A[i] + SumB(j, nj - 1);
    j = nj;
  }
  
  return ans;
}

int main(){
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &A[i]);
  }

  for(int i = 1; i <= m; ++i){
    scanf("%lld", &B[i]);
  }

  Initialise(n, m);

  while(q--){
    int t, k, d;
    scanf("%d%d%d", &t, &k, &d);

    if(t == 1){
      UpdateA(n, k, d);
    }
    else{
      UpdateB(m, k, d);
    }

    printf("%lld\n", Query(n, m));
  }

  return 0;
}
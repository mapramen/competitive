#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 1000001

vector< vector< pii > > updates(N);
vector< vector<int> > queries(N);
int a[N], l[N], r[N];
ll T1[N], T2[N], ans[N];

void Update(ll T[], int i, ll x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

void Update(int l, int r, int x){
  Update(T1, l, x);
  Update(T1, r + 1, -x);
  Update(T2, l, -1ll * (l - 1) * x);
  Update(T2, r + 1, 1ll * r * x);
}

ll Query(ll T[], int i){
  ll ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

ll Query(int i){
  ll a = Query(T1, i), b = Query(T2, i);
  return a * i + b;
}

ll Query(int l, int r){
  return Query(r) - Query(l - 1);
}

void Solve(int n, int q){
  stack<int> S;
  for(int i = 1; i <= n; ++i){
    while(!S.empty() && a[S.top()] < a[i]){
      S.pop();
    }
    int j = S.empty() ? 1 : S.top() + 1;
    if(j < i){
      updates[i].push_back(make_pair(j, i - 1));
    }
    S.push(i);
  }

  for(int i = 1; i <= q; ++i){
    --l[i];
    queries[l[i]].push_back(i);
    queries[r[i]].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    for(pii p : updates[i]){
      Update(p.first, p.second, 1);
    }
    for(int x : queries[i]){
      ll ansx = Query(l[x] + 1, r[x]);
      if(l[x] == i){
        ansx = -ansx;
      }
      ans[x] += ansx;
    }
  }

  for(int i = 1; i <= q; ++i){
    ++l[i];
  }
}

void ReverseInput(int n, int q){
  for(int i = 1, j = n; i < j; ++i, --j){
    swap(a[i], a[j]);
  }

  for(int i = 1; i <= q; ++i){
    swap(l[i], r[i]);
    l[i] = n - l[i] + 1;
    r[i] = n - r[i] + 1;
  }

  for(int i = 1; i <= n; ++i){
    updates[i].clear();
    queries[i].clear();
    T1[i] = 0;
    T2[i] = 0;
  }
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= q; ++i){
    scanf("%d", &l[i]);
  }

  for(int i = 1; i <= q; ++i){
    scanf("%d", &r[i]);
  }

  Solve(n, q);
  ReverseInput(n, q);
  Solve(n, q);

  for(int i = 1; i <= q; ++i){
    printf("%lld ", ans[i] + r[i] - l[i] + 1);
  }
  printf("\n");

  return 0;
}
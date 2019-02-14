#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 194599
#define M 5032108
#define Q 1049658
#define B 15

vector< vector<int> > v(M), d(M);
vector< vector< pii > > queries(N);
int a[N], b[M], s[M], ans[Q], C[B];

void PreProcess(int n){
  for(int i = 1; i < M; ++i){
    s[i] = i;
  }

  for(int i = 2; i < M; ++i){
    if(b[i]){
      continue;
    }

    for(int j = i; j < M; j += i){
      int k = 0;
      while(s[j] % i == 0){
        s[j] /= i;
        ++k;
      }

      if(k % 2 == 1){
        s[j] *= i;
        ++b[j];
      }
    }
  }

  for(int i = 1; i < M; ++i){
    if(s[i] != i){
      continue;
    }

    int k = 0;
    for(int j = i; j < M; j += i){
      if(s[j] != j){
        continue;
      }
      v[j].PB(i);
      k = max(k, b[j] - b[i]);
    }

    d[i].resize(k + 1);
  }

  for(int i = 1; i <= n; ++i){
    a[i] = s[a[i]];
  }
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int x = 0; x < q; ++x){
    int l, r;
    scanf("%d%d", &l, &r);
    queries[r].PB(MP(l, x));
  }

  PreProcess(n);

  for(int i = 1; i <= n; ++i){
    for(auto j : v[a[i]]){
      int c = b[a[i]] - b[j];
      for(int x = 0; x < d[j].size(); ++x){
        int cx = c + x;
        C[cx] = max(C[cx], d[j][x]);
      }
      d[j][c] = i;
    }

    for(auto query : queries[i]){
      int j, x, k = B;
      tie(j, x) = query;
      for(int y = B - 1; y > -1; --y){
        if(C[y] >= j){
          k = y;
        }
      }
      ans[x] = k;
    }

    for(auto j : v[a[i]]){
      int c = b[a[i]] - b[j];
      d[j][c] = i;
    }
  }

  for(int x = 0; x < q; ++x){
    printf("%d\n", ans[x]);
  }

  return 0;
}

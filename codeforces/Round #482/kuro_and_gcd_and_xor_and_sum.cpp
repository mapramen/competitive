#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 17
#define N (1 << B)

int leftEnd[2 * N], rightEnd[2 * N], c[2 * N], bPos[2 * N], qt[N], qx[N], qk[N], qs[N], ans[N];
vector< vector<int> > v(N);

void Initialise(){
  for(int i = 0, j = N; i < N; ++i, ++j)
    leftEnd[j] = i, rightEnd[j] = i, bPos[j] = -1;

  for(int i = N - 1; i > 0; --i)
    leftEnd[i] = leftEnd[(i << 1)], rightEnd[i] = rightEnd[(i << 1) + 1], bPos[i] = 1 + bPos[(i << 1)];
}

void Add(int x, int val){
  int i = 1;
  while(true){
    c[i] += val;
    if(leftEnd[i] == rightEnd[i]){
      break;
    }
    i <<= 1;
    i += (x > rightEnd[i]);
  }
}

int Query(int i, int x, int s){
  if(s < leftEnd[i] || c[i] == 0){
    return (x ^ -1);
  }
  if(rightEnd[i] <= s){
    while(leftEnd[i] != rightEnd[i]){
      int k = bPos[i];
      i = (i << 1) + ((x & (1 << k)) == 0);
      i ^= (c[i] == 0);
    }
    return (x ^ leftEnd[i]);
  }
  else{
    return max(Query((i << 1), x, s), Query((i << 1) + 1, x, s));
  }
}

int main(){
  int q;

  scanf("%d", &q);

  for(int i = 1; i <= q; ++i){
    scanf("%d%d", &qt[i], &qx[i]);
    if(qt[i] == 2){
      scanf("%d%d", &qk[i], &qs[i]);
      v[qk[i]].PB(i);
    }
    else{
      v[qx[i]].PB(i);
    }
  }

  Initialise();

  for(int i = 1; i < N; ++i){
    for(int j = i + i; j < N; j += i){
      for(auto x : v[j]){
        if(qt[x] == 1)
          v[i].PB(x);
      }
    }

    sort(v[i].begin(), v[i].end());

    for(auto j : v[i]){
      if(qt[j] == 1){
        Add(qx[j], 1);
      }
      else{
        if(qx[j] % qk[j] != 0){
          ans[j] = -1;
        }
        else{
          ans[j] = (qx[j] ^ Query(1, qx[j], qs[j] - qx[j]));
        }
      }
    }

    for(auto j : v[i]){
      if(qt[j] == 1){
        Add(qx[j], -1);
      }
    }

    v[i].clear();
  }

  for(int i = 1; i <= q; ++i){
    if(qt[i] == 2){
      printf("%d\n", ans[i]);
    }
  }

  return 0;
}

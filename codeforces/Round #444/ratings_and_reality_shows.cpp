#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define LOGN 19

struct data{
	ll sum;
	ll ans;
};

int n, a[2][2], s, l, t[N], q[N];
data T1[LOGN][N], T2[LOGN][N];

data GetData(int i, int j){
	data x;
  if(i == 0){
    x.sum = 0;
    x.ans = 0;
  }
  else{
    x.sum = a[j][q[i]];
    x.ans = a[j][q[i]];
  }
	return x;
}

data CombineData(data a, data b){
	data d = GetData(0, 0);
	d.sum = a.sum + b.sum;
  d.ans = min(a.ans, a.sum + b.ans);
	return d;
}

void PreProcess(){
  for(int i = 0; i <= n; ++i){
    T1[0][i] = GetData(i, 0);
    T2[0][i] = GetData(i, 1);
  }

  for(int k = 1; k < LOGN; ++k){
    for(int i = 0, j = (1 << (k - 1)); j <= n; ++i, ++j){
      T1[k][i] = CombineData(T1[k - 1][i], T1[k - 1][j]);
      T2[k][i] = CombineData(T2[k - 1][i], T2[k - 1][j]);
    }
  }
}

data Query1(int i, int j){
  data d = GetData(0, 0);
  for(int k = LOGN - 1; i <= j; --k){
    if((1 << k) <= j - i + 1){
      d = CombineData(d, T1[k][i]);
      i += (1 << k);
    }
  }
  return d;
}

data Query2(int i, int j){
  data d = GetData(0, 0);
  for(int k = LOGN - 1; i <= j; --k){
    if((1 << k) <= j - i + 1){
      d = CombineData(d, T2[k][i]);
      i += (1 << k);
    }
  }
  return d;
}

int main(){
  scanf("%d", &n);

  for(int i = 0; i < 2; ++i)
    for(int j = 1; j > -1; --j){
      scanf("%d", &a[i][j]);
      if(j == 0)
        a[i][j] = -a[i][j];
    }

  scanf("%d%d", &s, &l);

  for(int i = 1; i <= n; ++i)
    scanf("%d%d", &t[i], &q[i]);

  PreProcess();

	t[0] = -1;
  for(int i = 1, j = 0; i <= n + 1; ++i){
    for(j = max(j, i); j <= n && t[j] - t[i - 1] - 1 <= l; ++j);
    --j;
    data d = CombineData(Query1(1, i - 1), Query2(i, j));
    if(s + d.ans >= 0){
      printf("%d\n", t[i - 1] + 1);
      return 0;
    }
  }

  printf("-1\n");
  return 0;
}

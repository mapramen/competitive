#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 500001

int a[N];

int main(){
  int q;
  scanf("%d", &q);

  vector<tiii> queries;
  for(int k = 1; k <= q; ++k){
    int t, i, j;
    scanf("%d%d", &t, &i);

    if(t == 2){
      scanf("%d", &j);
    }

    queries.push_back({t, i, j});
  }

  for(int i = 1; i < N; ++i){
    a[i] = i;
  }

  vector<int> v;
  for(int k = q; k != 0; --k){
    auto [t, i, j] = queries[k - 1];

    if(t == 2){
      a[i] = a[j];
    }
    else{
      v.push_back(a[i]);
    }
  }
  reverse(v.begin(), v.end());

  for(int x: v){
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}
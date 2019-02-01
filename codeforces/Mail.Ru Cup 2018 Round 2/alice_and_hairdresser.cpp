#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100002

int a[N], parent[N], l, ans;

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  if(a[i] <= l || a[j] <= l){
    return ;
  }

  i = Find(i), j = Find(j);

  if(i == j){
    return ;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  --ans;
}

int main(){
  int n, q;

  scanf("%d%d%d", &n, &q, &l);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    ans += (a[i] > l);
    parent[i] = i;
    Union(i - 1, i);
  }

  while(q--){
    int t;
    scanf("%d", &t);
    if(t == 0){
      printf("%d\n", ans);
    }
    else{
      int i, x;
      scanf("%d%d", &i, &x);
      if(a[i] > l){
        continue;
      }
      a[i] += x;
      ans += (a[i] > l);
      Union(i - 1, i);
      Union(i, i + 1);
    }
  }

  return 0;
}

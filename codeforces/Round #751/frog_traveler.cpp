#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001

int a[N], b[N], d[N], jumpParent[N], slipParent[N];
set<int> unvisited;
queue<int> Q;

void CheckAndPush(int i, int dx){
  int x = a[i];
  while(!unvisited.empty()){
    auto it = unvisited.upper_bound(i);
    if(it == unvisited.begin()){
      break;
    }
    it = prev(it);

    int j = *it;
    if(i - j > x){
      break;
    }

    unvisited.erase(it);
    int k = j + b[j];

    jumpParent[j] = i;

    if(d[k] == INT_MAX){
      d[k] = dx;
      Q.push(k);
      slipParent[k] = j;
    }
  }
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  for(int i = 0; i <= n; ++i){
    d[i] = INT_MAX;
    unvisited.insert(i);
  }

  CheckAndPush(n, 0);

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();
    CheckAndPush(i, d[i] + 1);
  }

  if(d[0] == INT_MAX){
    printf("-1\n");
    return 0;
  }

  vector<int> v;
  for(int i = 0; i != n; i = slipParent[jumpParent[i]]){
    v.push_back(i);
  }
  reverse(v.begin(), v.end());

  printf("%lu\n", v.size());
  for(int x: v){
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}
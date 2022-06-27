#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 150001

int parent[N], eats[N];

void Reset(int n){
  for(int i = 1; i <= 3 * n; ++i){
    parent[i] = i;
  }

  for(int x = 1, y = x + n, z = y + n; x <= n; ++x, ++y, ++z){
    eats[x] = y, eats[y] = z, eats[z] = x;
  }
}

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
}

int Eats(int x){
  return Find(eats[x]);
}

bool SameKindOperationValid(int x, int y){
  x = Find(x), y = Find(y);
  if(x == y){
    return true;
  }

  if(Eats(x) == y || Eats(y) == x){
    return false;
  }

  for(int k = 0; k < 3; ++k, x = eats[x], y = eats[y]){
    Union(x, y);
  }

  return true;
}

bool EatOperationValid(int x, int y){
  return SameKindOperationValid(x, eats[eats[y]]);
}

int Solve(){
  int n, q;
  scanf("%d%d", &n, &q);

  Reset(n);

  int ans = 0;
  while(q--){
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);

    if(x > n || y > n){
      ++ans;
      continue;
    }

    ans += !(t == 1 ? SameKindOperationValid(x, y) : EatOperationValid(x, y));
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}
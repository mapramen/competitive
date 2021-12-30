#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<int> imposters;

int Query(int a, int b, int c){
  printf("? %d %d %d\n", a, b, c);
  fflush(stdout);

  int x;
  scanf("%d", &x);
  return 1 - x;
}

pair<pii,pii> GetCheckpoints(pii a, pii b){
  auto [i, x] = a;
  auto [_, y] = b;

  if(Query(i + 1, i + 2, i + 3) != x){
    return {{i, x}, {i + 3, y}};
  }

  if(Query(i + 2, i + 3, i + 4) != x){
    return {{i + 1, x}, {i + 4, y}};
  }

  return {{i + 2, x}, {i + 5, y}};
}

void Set(int i, int x){
  if(x == 1){
    imposters.push_back(i);
  }
}

void CheckAndSet(int i, int k, int x, int y){
  int q1 = Query(i, i + 1, k);
  int q2 = Query(i + 1, i + 2, k);

  if(q1 == x && q2 == x){
    Set(i, x), Set(i + 1, x), Set(i + 2, x);
  }

  if(q1 == x && q2 == y){
    Set(i, x), Set(i + 1, x), Set(i + 2, y);
  }

  if(q1 == y && q2 == x){
    Set(i, y), Set(i + 1, x), Set(i + 2, x);
  }

  if(q1 == y && q2 == y){
    Set(i, x), Set(i + 1, y), Set(i + 2, x);
  }
}

void CheckAndSet(pii c, pii a, pii b){
  if(c.second != a.second){
    swap(a, b);
  }

  CheckAndSet(c.first, b.first, a.second, b.second);
}

void Solve(){
  int n;
  scanf("%d", &n);
  
  vector<pii> v;
  for(int i = 1; i <= n; i += 3){
    v.push_back({i, Query(i, i + 1, i + 2)});
  }

  pii a, b;
  for(int i = v.size() - 1; i > 0; --i){
    if(v[i].second != v[i - 1].second){
      tie(a, b) = GetCheckpoints(v[i - 1], v[i]);
      break;
    }
  }

  for(int i = v.size() - 1; i != -1; --i){
    CheckAndSet(v[i], a, b);
  }

  printf("! %lu ", imposters.size());
  for(int i: imposters){
    printf("%d ", i);
  }
  printf("\n");
  fflush(stdout);

  imposters.clear();
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}
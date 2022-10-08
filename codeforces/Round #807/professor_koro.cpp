#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N];
map<int,int> M;

void Insert(int l, int r){
  if(r < l){
    return;
  }
  M[l] = r;
}

void Merge(int x){
  int l = x, r = x;
  M.erase(x);

  auto lt = prev(M.upper_bound(x));
  if(lt->second == x - 1){
    l = lt->first;
    M.erase(lt);
  }

  auto rt = M.upper_bound(x);
  if(rt != M.end() && rt->first == x + 1){
    r = rt->second;
    M.erase(rt);
  }

  Insert(l, r);
}

void Add(int x){
  auto it = prev(M.upper_bound(x));
  if(it->second < x){
    Insert(x, x);
    Merge(x);
    return;
  }

  int l = it->first, r = it->second;
  M.erase(it);

  Insert(l, x - 1);
  Add(r + 1);
}

void Remove(int x){
  auto it = prev(M.upper_bound(x));
  if(x <= it->second){
    int l = it->first, r = it->second;
    M.erase(it);

    Insert(l, x - 1);
    Insert(x + 1, r);
    return;
  }

  it = next(it);
  int l = it->first, r = it->second;
  M.erase(it);

  Insert(x, l - 1);
  Insert(l + 1, r);
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  M[0] = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    Add(a[i]);
  }

  while(q--){
    int i, x;
    scanf("%d%d", &i, &x);

    Remove(a[i]);
    a[i] = x;
    Add(a[i]);

    printf("%d\n", M.rbegin()->second);
  }

  return 0;
}
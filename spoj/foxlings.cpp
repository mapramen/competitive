#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

map<int,int> parent;

int Find(int i){
  auto it = parent.find(i);
  return it == parent.end() || it->second == i ? i : parent[i] = Find(it->second);
}

bool Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return false;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  return true;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  int ans = n;
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    ans -= Union(i, j);
  }

  printf("%d\n", ans);
  
  return 0;
}
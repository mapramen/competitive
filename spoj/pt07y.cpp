#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001

int parent[N];

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
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

  if(m != n - 1){
    printf("NO\n");
    return 0;
  }

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    if(!Union(i, j)){
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");

  return 0;
}
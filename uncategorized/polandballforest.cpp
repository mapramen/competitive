#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 10001

int parent[N], cnt[N];

int FindSet(int i){
  if(parent[i] != i)
    parent[i] = FindSet(parent[i]);
  return parent[i];
}

void UnionSet(int i, int j){
  i = FindSet(i), j = FindSet(j);
  parent[i] = parent[j] = min(i, j);
}

int main(){
  int n, ans = 0;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    parent[i] = i;

  for(int i = 1; i <= n; i++){
    int j;
    scanf("%d", &j);
    UnionSet(i, j);
  }

  for(int i = 1; i <= n; i++){
    int j = FindSet(i);
    cnt[j] = 1;
  }

  for(int i = 1; i <= n; i++)
    ans += cnt[i];

  printf("%d\n", ans);
  
  return 0;
}

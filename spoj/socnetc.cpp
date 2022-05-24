#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 100001

char op[10];
int parent[N], sz[N];

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
}

void Union(int m, int i, int j){
  i = Find(i), j = Find(j);
  if(i == j || sz[i] + sz[j] > m){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  sz[i] += sz[j];
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    parent[i] = i, sz[i] = 1;
  }

  int q;
  scanf("%d", &q);

  while(q--){
    scanf("%s", op);

    if(op[0] == 'A'){
      int i, j;
      scanf("%d%d", &i, &j);
      Union(m, i, j);
    }
    else if(op[0] == 'E'){
      int i, j;
      scanf("%d%d", &i, &j);
      printf("%s\n", Find(i) == Find(j) ? "Yes" : "No");
    }
    else {
      int i;
      scanf("%d", &i);
      printf("%d\n", sz[Find(i)]);
    }
  }
  
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 26

char s[N], t[N];
int parent[B];

int Find(int i){
  return (parent[i] == i) ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i > j)
    swap(i, j);
  if(i == j)
    return ;
  parent[j] = i;
}

int main(){
  int n;

  scanf("%d%s%s", &n, s, t);

  for(int i = 0; i < B; ++i)
    parent[i] = i;

  for(int x = 1; x <= n; ++x){
    int i = s[x - 1] - 'a', j = t[x - 1] - 'a';
    Union(i, j);
  }

  vector< pii > v;
  for(int i = 0; i < B; ++i){
    if(Find(i) != i)
      v.PB(MP(i, parent[i]));
  }

  printf("%lu\n", v.size());
  for(auto p : v)
    printf("%c %c\n", 'a' + p.first, 'a' + p.second);

  return 0;
}

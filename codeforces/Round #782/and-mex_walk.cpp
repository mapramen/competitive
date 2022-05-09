#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define B 30

int k_bit_group[B][N];
bool k_bit_even[B][N];

int Find(int parent[], int i){
  return parent[i] == i ? i : parent[i] = Find(parent, parent[i]);
}

void SetEven(int parent[], bool even[], int i){
  even[Find(parent, i)] = true;
}

void Union(int parent[], bool even[], int i, int j){
  i = Find(parent, i), j = Find(parent, j);

  if(i == j){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  even[i] = even[i] || even[j];
}

int Query(int i, int j){
  for(int k = 0; k < B; ++k){
    if(Find(k_bit_group[k], i) == Find(k_bit_group[k], j)){
      return 0;
    }
  }

  for(int k = B - 1; k != 0; --k){
    if(k_bit_even[k][Find(k_bit_group[k], i)]){
      return 1;
    }
  }

  return 2;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int k = 0; k < B; ++k){
    for(int i = 1; i <= n; ++i){
      k_bit_group[k][i] = i, k_bit_even[k][i] = false;
    }
  }

  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);

    for(int k = 0; k < B; ++k){
      if(w % 2 == 0){
        SetEven(k_bit_group[k], k_bit_even[k], i);
        SetEven(k_bit_group[k], k_bit_even[k], j);
      }

      if((w & (1 << k)) == 0){
        continue;
      }

      Union(k_bit_group[k], k_bit_even[k], i, j);
    }
  }

  int q;
  scanf("%d", &q);

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    printf("%d\n", Query(i, j));
  }

  return 0;
}
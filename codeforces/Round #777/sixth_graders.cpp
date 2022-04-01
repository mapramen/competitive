#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define B 30

int a[N], b[N], finalPos[N], minIndex[N], inDegree[N], T[B][N];
set<int> S;

void PreProcess(int n){
  for(int k = 1; k < B; ++k){
    for(int i = 1; i <= n; ++i){
      T[k][i] = T[k - 1][T[k - 1][i]];
    }
  }
}

int Query(int x, int i){
  for(int k = 0; k < B; ++k){
    if((x & (1 << k)) == 0){
      continue;
    }
    i = T[k][i];
  }
  return i;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int p;
    scanf("%d", &p);
    T[0][i] = p, ++inDegree[p];
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int m = 0;
  for(int i = 1; i <= n; ++i){
    m += (inDegree[i] == 0);
  }

  m = (*max_element(a + 1, a + n + 1) - n) / m;

  PreProcess(n);

  for(int i = 1; i <= n; ++i){
    minIndex[i] = n + 1;
    S.insert(i);
  }

  for(int i = 1; i <= n; ++i){
    int k = Query(m, i);
    finalPos[i] = k;
    minIndex[k] = min(minIndex[k], i);
  }

  for(int i = 1; i <= n; ++i){
    if(a[i] > n){
      a[i] = 0;
      continue;
    }
    b[minIndex[i]] = a[i];
    S.erase(a[i]);
  }

  for(int i = 1; i <= n; ++i){
    if(b[i] != 0){
      continue;
    }
    int x = *S.lower_bound(a[finalPos[i]]);
    b[i] = x;
    S.erase(x);
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", b[i]);
  }
  printf("\n");

  return 0;
}
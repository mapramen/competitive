#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1300000

bool is_prime[N];
int parent[N], sz[N];
vector<int> primes;

void Initialize(){
  for(int i = 2; i < N; ++i){
    is_prime[i] = 1;
  }

  for(int i = 2; i * i < N; ++i){
    for(int j = i * i; j < N; j += i){
      is_prime[j] = 0;
    }
  }

  primes.push_back(-1);
  for(int i = 2; i < N; ++i){
    if(is_prime[i]){
      primes.push_back(i);
    }
  }
  primes[1] = -1;
}

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i, sz[i] = 1;
  }
}

int Find(int i){
  return parent[i] == i ? parent[i] : parent[i] = Find(parent[i]);
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
  sz[i] += sz[j];
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(n);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    Union(i, j);
  }

  return primes[*max_element(sz, sz + n + 1)];
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}
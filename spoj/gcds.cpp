#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000021

bool visited[N];
int a[N];
vector<int> primes;

void Initialize(){
  for(int i = 2; i < N; ++i){
    visited[i] = true;
  }

  for(int i = 2; i * i < N; ++i){
    if(!visited[i]){
      continue;
    }

    for(int j = i * i; j < N; j += i){
      visited[j] = false;
    }
  }

  for(int i = 1; i < N; ++i){
    if(visited[i]){
      primes.push_back(i);
      visited[i] = false;
    }
  }
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    visited[a[i]] = true;
  }

  int ans = 0;
  for(int i: primes){
    bool prime_visited = false;
    for(int j = i; j < N && !prime_visited; j += i){
      prime_visited = visited[j];
    }
    
    if(!prime_visited){
      ans = i;
      break;
    }
  }

  for(int i = 1; i <= n; ++i){
    visited[a[i]] = false;
  }

  return ans;
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
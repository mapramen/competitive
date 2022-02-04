#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000

vector<vector<int>> adj(N);
bool isPrime[N];
int d[N];
queue<int> Q;

vector<int> GetNeighbors(int n){
  vector<int> v;
  for(int i = 0, x = n; i < 4; ++i, x /= 10){
    v.push_back(x % 10);
  }

  vector<int> ans;
  for(int i = 0, p = 1; i < 4; ++i, p *= 10){
    int x = n - v[i] * p;
    for(int d = i == 3; d < 10; ++d){
      int y = x + d * p;
      if(y != n && isPrime[y]){
        ans.push_back(y);
      }
    }
  }
  
  return ans;
}

void Initialise(){
  for(int i = 2; i < N; ++i){
    isPrime[i] = true;
  }

  for(int i = 2; i < N; ++i){
    if(!isPrime[i]){
      continue;
    }

    for(int j = i * i; j < N; j += i){
      isPrime[j] = false;
    }
  }

  for(int i = 1000; i < N; ++i){
    adj[i] = GetNeighbors(i);
  }
}

int BFS(int s, int t){
  for( ; !Q.empty(); Q.pop());

  for(int i = 1000; i < N; ++i){
    d[i] = N;
  }

  d[s] = 0;
  Q.push(s);

  while(d[t] == N && !Q.empty()){
    int i = Q.front();
    Q.pop();

    for(int j: adj[i]){
      if(d[j] != N){
        continue;
      }
      d[j] = 1 + d[i];
      Q.push(j);
    }
  }

  return d[t];
}

string Solve(){
  int s, t;
  scanf("%d%d", &s, &t);

  int d = BFS(s, t);

  return d != N ? to_string(d) : "Impossible";
}

int main(){
  int t;
  scanf("%d", &t);
  Initialise();
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}
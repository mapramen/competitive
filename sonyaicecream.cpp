#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector< pii > > adj(N);
int K, degree[N], d[N];

bool Check(int n, int m){
  queue<int> Q;

  for(int i = 1; i <= n; ++i){
    d[i] = 0;
    degree[i] = adj[i].size();
    if(degree[i] == 1){
      Q.push(i);
    }
  }

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    bool cannotBeRemoved = 0;

    for(auto p : adj[i]){
      int k, x;
      tie(k, x) = p;

      if(degree[k] == 0){
        continue;
      }

      if(d[i] + x > m){
        cannotBeRemoved = 1;
        continue;
      }

      --degree[k];

      d[k] = max(d[k], d[i] + x);

      if(degree[k] == 1){
        Q.push(k);
      }
    }

    if(!cannotBeRemoved){
      degree[i] = 0;
    }
  }

  int k = K;
  for(int i = 1; i <= n; ++i){
    if(degree[i] == 0){
      continue;
    }

    if(degree[i] > 2){
      return 0;
    }
    --k;
  }

  return k >= 0;
}

int BinarySearch(int n){
  int x = 0, y = INT_MAX, z = y;
  while(x <= y){
    int mid = x + (y - x) / 2;
    if(Check(n, mid)){
      z = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return z;
}

int main(){
  int n;

  scanf("%d%d", &n, &K);

  for(int x = 1; x < n; ++x){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    adj[i].PB(MP(j, k));
    adj[j].PB(MP(i, k));
  }

  printf("%d\n", BinarySearch(n));

  return 0;
}

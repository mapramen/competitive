#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define B 20
#define M (1 << B)

vector< vector<int> > adj(N);
int a[N], s[N], d[N], c[M], rootMask;
ll ansx[N], ans[N];
bool visited[N];

void InitialiseSubtreeSizeDFS(int i, int p){
  s[i] = 0;
  for(auto k : adj[i]){
    if(k != p && visited[k] == 0){
      InitialiseSubtreeSizeDFS(k, i);
      s[i] += s[k];
    }
  }
  ++s[i];
}

int GetCentroid(int i){
  InitialiseSubtreeSizeDFS(i, 0);
  int treeSize = s[i], p = 0;

  while(true){
    int heavyChild = 0;
    for(auto k : adj[i]){
      if(k != p && visited[k] == 0 && s[k] > s[heavyChild])
        heavyChild = k;
    }
    if(2 * s[heavyChild] <= treeSize){
      break;
    }
    p = i, i = heavyChild;
  }

  return i;
}

void InitialiseMaskDFS(int i, int p){
  d[i] = a[i] ^ d[p];
  for(auto k : adj[i]){
    if(k != p && visited[k] == 0){
      InitialiseMaskDFS(k, i);
    }
  }
}

void UpdateMaskCountDFS(int i, int p, int x){
  for(auto k : adj[i]){
    if(k != p && visited[k] == 0){
      UpdateMaskCountDFS(k, i, x);
    }
  }
  c[d[i]] += x;
}

void CalculateAns(int i){
  int mask = (d[i] ^ rootMask);
  ansx[i] = 0;
  ansx[i] += c[mask];
  for(int x = 0; x < B; ++x)
    ansx[i] += c[(mask ^ (1 << x))];
}

void SolveDFS(int i, int p){
  CalculateAns(i);
  for(auto k : adj[i]){
    if(k != p && visited[k] == 0){
      SolveDFS(k, i);
      ansx[i] += ansx[k];
    }
  }
}

void UpdateAnsDFS(int i, int p){
  for(auto k : adj[i]){
    if(k != p && visited[k] == 0){
      UpdateAnsDFS(k, i);
    }
  }
  ans[i] += ansx[i];
  c[d[i]] = 0;
}

void Solve(int i){
  i = GetCentroid(i);
  InitialiseMaskDFS(i, 0);
  UpdateMaskCountDFS(i, 0, 1);

  rootMask = d[i];
  CalculateAns(i);

  for(auto k : adj[i]){
    if(visited[k] == 0){
      UpdateMaskCountDFS(k, i, -1);
      SolveDFS(k, i);
      UpdateMaskCountDFS(k, i, 1);
      ansx[i] += ansx[k];
    }
  }

  ansx[i] /= 2;
  ++ansx[i];

  UpdateAnsDFS(i, 0);

  visited[i] = 1;

  for(auto k : adj[i]){
    if(visited[k] == 0){
      Solve(k);
    }
  }
}

int main(){
  int n;
  string s;

  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  cin >> s;
  for(int i = 1; i <= n; ++i)
    a[i] = (1 << (s[i - 1] - 'a'));

  Solve(1);

  for(int i = 1; i <= n; ++i)
    printf("%lld ", ans[i]);
  printf("\n");

  return 0;
}

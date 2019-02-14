#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define B 26

vector< vector<int> > adj(N), subtree(N);
int T[N][B], c[N], a[N], h[N], subtreeSize[N], heavyChild[N], subtreeNo[N], nextIndex, cnt, ans, ansv;
string s;

int GetStringNo(int i, char c){
  int j = c - 'a';
  if(T[i][j] == 0) T[i][j] = ++nextIndex;
  return T[i][j];
}

void Initialise(int n){
  for(int i = 1; i <= n; i++){
    heavyChild[i] = i;
    subtreeNo[i] = i;
  }
}

void HeavyLightDFS(int i, int p){
  a[i] = GetStringNo(a[p], s[i - 1]);

  for(auto k : adj[i]){
    if(k == p)
      continue;

    HeavyLightDFS(k, i);
    heavyChild[i] = (subtreeSize[k] > subtreeSize[heavyChild[i]]) ? k : heavyChild[i];
    subtreeSize[i] += subtreeSize[k];
  }

  subtreeNo[i] = subtreeNo[heavyChild[i]];
  subtreeSize[i]++;
}

void ResetBag(int i){
  for(auto x : subtree[i])
    h[a[x]] = 0;
  cnt = 0;
}

void Update(int i){
  h[a[i]]++;
  cnt += (h[a[i]] == 1);
}

void CopyLightChild(int root, int child){
  for(auto k : subtree[child]){
    subtree[root].PB(k);
    Update(k);
  }
}

void DFS(int i, int p){
  for(auto k : adj[i]){
    if(k != p && k != heavyChild[i]){
      DFS(k, i);
      ResetBag(subtreeNo[k]);
    }
  }

  if(heavyChild[i] != i)
    DFS(heavyChild[i], i);

  for(auto k : adj[i]){
    if(k != p && k != heavyChild[i]){
      CopyLightChild(subtreeNo[i], subtreeNo[k]);
    }
  }

  Update(i);
  subtree[subtreeNo[i]].PB(i);

  c[i] += cnt;

  if(c[i] == ans)
    ansv++;
  else
    if(c[i] > ans)
      ans = c[i], ansv = 1;
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &c[i]);

  cin >> s;

  for(int k = 1; k < n; k++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  Initialise(n);
  HeavyLightDFS(1, 0);
  DFS(1, 0);

  printf("%d\n%d\n", ans, ansv);

  return 0;
}

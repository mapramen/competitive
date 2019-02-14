#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 8
#define MOD 5

vector< vector<int> > V, adj;
vector< map<int,int> > S(1);
int M, N;
vector<int> win, lose, outDegree, visited;

void InsertHand(vector<int>& v, int id){
  int k = 0;
  for(int i = 0; i < MOD - 1; ++i){
    if(S[k].find(v[i]) == S[k].end()){
      S[k][v[i]] = S.size();
      k = S.size();
      S.resize(S.size() + 1);
    }
    else
      k = S[k][v[i]];
  }
  S[k][v[MOD - 1]] = id;
}

void InitialiseHandSet(){
  int totalMasks = (int)pow(B + 1, MOD);
  for(int mask = 0; mask < totalMasks; ++mask){
    int t = 0;
    vector<int> v;
    for(int i = 0, x = mask; i < MOD; ++i, x /= (B + 1)){
      t += (x % (B + 1));
      v.PB(x % (B + 1));
    }
    if(t != 8)
      continue;
    InsertHand(v, V.size());
    V.PB(v);
  }
}

int GetHandMask(vector<int>& v){
  int k = 0;
  for(int i = 0; i < MOD; ++i)
    k = S[k][v[i]];
  return k;
}

int GetVertexMask(vector<int>& a, vector<int>& b){
  return GetHandMask(a) * M + GetHandMask(b);
}

int GetVertexMask(int a, int b){
  return a * M + b;
}

void InitialiseVertexAndAddEdges(vector<int>& a, vector<int>& b){
  int aMask = GetHandMask(a), bMask = GetHandMask(b), uMask = GetVertexMask(aMask, bMask);

  win[uMask] = (a[0] == B);
  lose[uMask] = (b[0] == B);

  if(a[0] == B && b[0] == B)
    win[uMask] = 0, lose[uMask] = 0;

  for(int i = 0; i < MOD; ++i){
    for(int j = 0; j < MOD; ++j){
      if(i == 0 || j == 0 || a[i] == 0 || b[j] == 0)
        continue;
      int k = (i + j) % MOD;
      --a[i], ++a[k];
      int _aMask = GetHandMask(a);
      int vMask = GetVertexMask(bMask, _aMask);
      adj[vMask].PB(uMask);
      ++outDegree[uMask];
      ++a[i], --a[k];
    }
  }
}

int GetResult(int v, int f = 0){
  int result = 2;

  if(win[v])
    result = 1;

  if(lose[v])
    result = 0;

  result ^= f;

  return result;
}

void Initialise(){
  InitialiseHandSet();
  M = V.size();
  N = M * M;
  adj.resize(N);
  win.resize(N);
  lose.resize(N);
  outDegree.resize(N);
  visited.resize(N);

  for(auto a : V)
    for(auto b : V)
      InitialiseVertexAndAddEdges(a, b);

  queue<int> Q;
  for(int i = 0; i < N; ++i){
    if(win[i] == 1 || lose[i] == 1){
      visited[i] = 1;
      Q.push(i);
    }
  }

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    if(win[i] == 0)
      lose[i] = 1;

    for(auto k : adj[i]){
      win[k] |= lose[i];
      --outDegree[k];
      if(visited[k] == 0 && (outDegree[k] == 0 || win[k] == 1)){
        visited[k] = 1;
        Q.push(k);
      }
    }
  }
}

void InputHand(vector<int>& v){
  for(int i = 0; i < MOD; ++i)
    v[i] = 0;

  for(int i = 0; i < B; ++i){
    int j;
    scanf("%d", &j);
    ++v[j];
  }
}

int main(){
  int t;
  vector<int> a(MOD), b(MOD);

  Initialise();

  scanf("%d", &t);
  while(t--){
    int f;
    scanf("%d", &f);
    InputHand(a);
    InputHand(b);

    if(f)
      swap(a, b);

    int result = GetResult(GetVertexMask(a, b), f);

    if(result == 1)
      printf("Alice\n");
    else if(result == 0)
      printf("Bob\n");
    else
      printf("Deal\n");
  }

  return 0;
}

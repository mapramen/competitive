#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001
#define MOD 1000000007
#define MAX_HASH 2

mt19937 rnd(random_device{}());
uniform_int_distribution<int> dis(100000000/2,1000000000/2);

vector<vector<int>> adj(N);
int dp1[N], dp2[N];
vector<int> primes(MAX_HASH);
map<vector<int>,int> hshMap;

bool IsPrime(int n){
  for(int x = 2; x * x <= n; ++x){
    if(n % x == 0){
      return false;
    }
  }
  return true;
}

int GetRandomPrime(){
  while(true){
    int n = 2 * dis(rnd) + 1;
    if(IsPrime(n)){
      return n;
    }
  }
  return -1;
}

void Initialize(){
  for(int i = 0; i < MAX_HASH; ++i){
    primes[i] = GetRandomPrime();
  }

  hshMap[vector<int>()] = 0;
}

int GetSubtreeNo(vector<int>& subtreeHash){
  auto it = hshMap.find(subtreeHash);
  if(it != hshMap.end()){
    return it->second;
  }
  
  hshMap.insert({subtreeHash, hshMap.size()});
  return hshMap.size() - 1;
}

int ComputeHash(vector<int>& v, int P){
  int hsh = 0;
  for(int x: v){
    hsh = (1ll * hsh * P + x) % MOD;
  }
  return hsh;
}

void DFS1(int i, int p){
  vector<int> v;

  for(auto k: adj[i]){
    if(k != p){
      DFS1(k, i);
      v.push_back(dp1[k]);
    }
  }

  sort(v.begin(), v.end());

  vector<int> subtreeHash;
  for(int P: primes){
    subtreeHash.push_back(ComputeHash(v, P));
  }

  dp1[i] = GetSubtreeNo(subtreeHash);
}

void DFS2(int i, int p){
  vector<pii> v{{dp2[i], p}};

  for(auto k: adj[i]){
    if(k != p){
      v.push_back({dp1[k], k});
    }
  }

  sort(v.begin(), v.end());

  vector<vector<int>> subtreeHashes(v.size(), vector<int>(MAX_HASH));

  for(int p = 0; p < MAX_HASH; ++p){
    int P = primes[p], prefixHash = 0;
    for(int x = 0; x < v.size(); x++){
      subtreeHashes[x][p] = prefixHash;
      prefixHash = (1ll * prefixHash * P + v[x].first) % MOD;
    }

    int suffixHash = 0, suffixHashPower = 1;
    for(int x = v.size() - 1; x > -1; x--){
      subtreeHashes[x][p] = (1ll * subtreeHashes[x][p] * suffixHashPower + suffixHash) % MOD;
      suffixHash = (1ll * v[x].first * suffixHashPower + suffixHash) % MOD;
      suffixHashPower = (1ll * P * suffixHashPower) % MOD;
    }
  }

  for(int x = 0; x < v.size(); ++x){
    if(v[x].second != p){
      dp2[v[x].second] = GetSubtreeNo(subtreeHashes[x]);
      DFS2(v[x].second, i);
    }
  }
}

int main(){
  int n;

  scanf("%d", &n);

  for(int k = 1; k < n; k++){
    int i, j;
    scanf("%d%d", &i, &j);
    ++i, ++j;
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  int root;
  for(root = 1; root <= n && adj[root].size() == 1; root++);

  Initialize();
  DFS1(root, 0);
  DFS2(root, 0);

  set<int> S;
  for(int i = 1; i <= n; ++i){
    if(adj[i].size() == 1){
      S.insert(dp2[i]);
    }
  }

  printf("%lu\n", S.size());

  return 0;
}

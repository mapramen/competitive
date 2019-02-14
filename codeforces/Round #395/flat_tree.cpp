#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define P 1000003
#define MOD 1000000007

vector< vector<int> > adj(N);
int dp1[N], dp2[N], freq[5 * N], distinctIsoCount;
map< ll, int > hshMap;
pii ans;

void PreProcess(int n){
  hshMap[1ll * INT_MAX] = 0;
}

int GetSubtreeNo(ll subtreeHash){
  auto it = hshMap.find(subtreeHash);

  if(it != hshMap.end())
    return it->second;
  else{
    hshMap.insert(MP(subtreeHash, hshMap.size()));
    return hshMap.size() - 1;
  }
}

void DFS1(int i, int p){
  vector<int> v;
  ll subtreeHash = 0;

  for(auto k : adj[i]){
    if(k != p){
      DFS1(k, i);
      v.PB(dp1[k]);
    }
  }

  if(v.size() == 0)
    v.PB(0);

  sort(v.begin(), v.end());

  for(auto x : v)
    subtreeHash = (subtreeHash * P + x) % MOD;

  dp1[i] = GetSubtreeNo(subtreeHash);
}

void DFS2(int i, int p){
  vector< pii > v;
  vector< ll > subtreeHashes;

  for(auto k : adj[i]){
    if(k != p)
      v.PB(MP(dp1[k], k));
  }

  v.PB(MP(dp2[i], p));
  sort(v.begin(), v.end());
  subtreeHashes.resize(v.size());

  ll prefixHash = 0;
  for(int x = 0; x < v.size(); x++){
    subtreeHashes[x] = prefixHash;
    prefixHash = (prefixHash * P + v[x].first) % MOD;
  }

  ll suffixHash = 0, suffixHashPower = 1;
  for(int x = v.size() - 1; x > -1; x--){
    subtreeHashes[x] = (subtreeHashes[x] * suffixHashPower + suffixHash) % MOD;
    suffixHash = (v[x].first * suffixHashPower + suffixHash) % MOD;
    suffixHashPower = (P * suffixHashPower) % MOD;

    if(v[x].second != p){
      dp2[v[x].second] = GetSubtreeNo(subtreeHashes[x]);
      DFS2(v[x].second, i);
    }
  }
}

void IncrementSubtreeFreq(int subtreeNo){
  freq[subtreeNo]++;
  distinctIsoCount += (freq[subtreeNo] == 1);
}

void DecrementSubtreeFreq(int subtreeNo){
  freq[subtreeNo]--;
  distinctIsoCount -= (freq[subtreeNo] == 0);
}

void DFS(int i, int p){
  DecrementSubtreeFreq(dp1[i]);
  for(auto k : adj[i]){
    if(k != p){
      IncrementSubtreeFreq(dp2[k]);
      DFS(k, i);
      DecrementSubtreeFreq(dp2[k]);
    }
  }

  ans = max(ans, MP(distinctIsoCount, -i));
  IncrementSubtreeFreq(dp1[i]);
}

int main(){
  int n, root;

  scanf("%d", &n);

  for(int k = 1; k < n; k++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  for(root = 1; root <= n && adj[root].size() > 1; root++);

  PreProcess(n);
  DFS1(root, 0);
  DFS2(root, 0);

  for(int i = 1; i <= n; i++)
    IncrementSubtreeFreq(dp1[i]);

  DFS(root, 0);

  printf("%d\n", max(1, -ans.second));

  return 0;
}

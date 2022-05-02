#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 26
#define N 101

vector<vector<pii>> adj(B);
int in_degree[B], cnt[B], start_index[B], end_index[B];
string towers[N];

void Reset(int n){
  for(int k = 0; k < B; ++k){
    adj[k].clear();
    in_degree[k] = 0;
    cnt[k] = 0;
  }
}

bool IsSingleCharacter(string& s){
  char d = s.front();
  for(char c: s){
    if(c != d){
      return false;
    }
  }
  return true;
}

void AppendWord(int i, string& ans){
  for(char c: towers[i]){
    ans.push_back(c);
  }
}

void DFS(int i, string& ans){
  while(cnt[i] > 0){
    ans.push_back('A' + i);
    --cnt[i];
  }

  while(!adj[i].empty()){
    auto [j, e] = adj[i].back();
    adj[i].pop_back();
    AppendWord(e, ans);
    DFS(j, ans);
  }
}

bool Check(int n, string& ans){
  int l = 0;
  for(int i = 1; i <= n; ++i){
    l += towers[i].size();
  }

  if(ans.size() != l){
    return false;
  }

  for(char c: ans){
    ++cnt[c - 'A'];
  }

  for(int i = 0; i < l; ++i){
    end_index[ans[i] - 'A'] = i;
  }

  for(int i = l - 1; i > -1; --i){
    start_index[ans[i] - 'A'] = i;
  }

  for(int k = 0; k < B; ++k){
    if(cnt[k] != 0 && start_index[k] + cnt[k] - 1 != end_index[k]){
      return false;
    }
  }

  return true;
}

string Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int i = 1; i <= n; ++i){
    cin >> towers[i];
    
    int k1 = towers[i].front() - 'A', k2 = towers[i].back() - 'A';
    if(IsSingleCharacter(towers[i])){
      cnt[k1] += towers[i].size();
    } 
    else{
      ++in_degree[k2];
      adj[k1].push_back({k2, i});
    }
  }

  string ans;
  for(int k = 0; k < B; ++k){
    if(in_degree[k] == 0){
      DFS(k, ans);
    }
  }

  return Check(n, ans) ? ans : "IMPOSSIBLE";
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %s\n", k, Solve().c_str());
  }
  return 0;
}
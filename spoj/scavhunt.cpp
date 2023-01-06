#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

map<string,string> next_step;
set<string> start_step;

vector<string> Solve(){
  int n;
  scanf("%d", &n);

  while(--n){
    string s, t;
    cin >> s >> t;

    next_step[s] = t;
    start_step.insert(s);
  }

  for(pair<string,string> kvp: next_step){
    start_step.erase(kvp.second);
  }

  vector<string> ans {*start_step.begin()};
  while(true){
    string s = ans.back();
    auto it = next_step.find(s);
    if(it == next_step.end()){
      break;
    }
    ans.push_back(it->second);
  }

  next_step.clear();
  start_step.clear();

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Scenario #%d:\n", k);
    for(string& s: Solve()){
      printf("%s\n", s.c_str());
    }
    printf("\n");
  }
  return 0;
}
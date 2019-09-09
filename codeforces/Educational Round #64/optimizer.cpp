#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair< int, int >
#define pll pair< ll, ll >
#define tcii tuple< char, int, int >
#define N 3001
 
int totalVariables, parent[N];
vector< vector<int> > adj(N);
set<char> operators{'#', '$', '^', '&'};
char operations[N];
map<string,int> variableIndex;
map<tcii,int> operationsIndex;
string variables[N];
bool visited[N];
vector<string> ans;
 
int AddVariable(string s){
  variableIndex[s] = totalVariables;
  variables[totalVariables] = s;
  return totalVariables++;
}
 
int GetVariableIndex(string s){
  auto it = variableIndex.find(s);
  if(it != variableIndex.end()){
    return it->second;
  }
  return AddVariable(s);
}
 
int GetOperationsIndex(char c, int i, int j, int k){ 
  tcii t = make_tuple(c, i, j);
  auto it = operationsIndex.find(t);
  if(it != operationsIndex.end()){
    return it->second;
  }
  
  operationsIndex[t] = k;
  return k;
}
 
void DFS(int i){
  visited[i] = true;
 
  if(adj[i].empty()){
    return ;
  }
 
  for(int j : adj[i]){
    if(visited[j]){
      continue;
    }
    DFS(j);
  }
 
  int j = adj[i][0], k = adj[i].back();
 
  if(operations[i] == '='){
    parent[i] = parent[j];
    return ;
  }
 
  j = parent[j], k = parent[k];
 
  parent[i] = GetOperationsIndex(operations[i], j, k, i);
 
  if(parent[i] != i){
    return ;
  }
 
  string a = variables[i], b = variables[j], c = variables[k];
  string ansx = a + "=" + b + string(1, operations[i]) + c;
  ans.push_back(ansx);
}
 
int main(){
  int n;
 
  cin >> n;
  while(n--){
    string s;
    cin >> s;
 
    int x = 0;
    for( ; x < s.size() && s[x] != '='; ++x);
 
    int y = x + 1;
    for( ; y < s.size() && operators.count(s[y]) == 0; ++y);
    int k = y == s.size() ? -1 : GetVariableIndex(string(s, y + 1));
 
    int j = GetVariableIndex(string(s, x + 1, y - x - 1));
    int i = AddVariable(string(s, 0, x));
 
    operations[i] = k >= 0 ? s[y] : '=';
    adj[i].push_back(j);
    if(k >= 0){
      adj[i].push_back(k);
    }
  }
 
  if(variableIndex.count("res") == 0){
    printf("0\n");
    return 0;
  }

  int root = variableIndex["res"];
  for( ; adj[root].size() == 1 && !adj[adj[root].back()].empty(); root = adj[root].back());
  variables[root] = "res";
 
  for(int i = 0, t = 0; i < totalVariables; ++i){
    parent[i] = i;

    if(adj[i].empty() || i == root){
      continue;
    }

    string s;
    while(true){
      for(int x = t, i = 0; i < 3; ++i, x /= 26){
        s.push_back('a' + (x % 26));
      }
      ++t;
      if(variableIndex.count(s)){
        s.clear();
      }
      else{
        break;
      }
    }
  
    variables[i] = s;
  }
 
  DFS(root);
 
  if(parent[root] != root && variables[root] != variables[parent[root]]){
    ans.push_back(variables[root] + "=" + variables[parent[root]]);
  }
 
  cout << ans.size() << '\n';
  for(string s : ans){
    cout << s << '\n';
  }
 
  return 0;
}
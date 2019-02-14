#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int i;
string s;
vector< vector<string> > v;

void DFS(int d){
  int j, k;

  for(j = i; j < s.size() && s[j] != ','; j++);

  if(v.size() < d + 1)
    v.resize(d + 1);

  v[d].PB(string(s, i, j - i));

  for(i = j + 1, j = i; j < s.size() && s[j] != ','; j++);
  k = stoi(string(s, i, j - i));
  i = j + 1;

  while(k--)
    DFS(d + 1);
}

int main(){
  cin >> s;

  while(i < s.size())
    DFS(0);

  cout << v.size() << '\n';

  for(int j = 0; j < v.size(); j++){
    for(auto k : v[j])
      cout << k << ' ';
    cout << '\n';
  }

  return 0;
}

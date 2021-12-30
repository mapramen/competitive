#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 26

int c[B];
string ans;

void Append(char x){
  int k = x - 'a';
  while(c[k]--){
    ans.push_back(x);
  }
  c[k] = 0;
}

string Solve(){
  string s, t;
  cin >> s >> t;

  for(char x: s){
    ++c[x - 'a'];
  }

  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());

  while(!s.empty() && s.back() > 'c'){
    s.pop_back();
  }

  do{
    if(s != t){
      break;
    }
  } while(next_permutation(s.begin(), s.end()));

  ans.clear();
  for(char x: s){
    Append(x);
  }

  for(char x = 'd'; x <= 'z'; ++x){
    Append(x);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    cout << Solve() << '\n';
  }
  return 0;
}
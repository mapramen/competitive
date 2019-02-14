#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 26

int c[B];
queue<int> Q;

int main(){
  string s, t;

  cin >> s >> t;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '?')
      Q.push(i);
    else
      c[s[i] - 'a']++;
  }

  while(!Q.empty()){
    for(int i = 0; i < t.size() && !Q.empty(); i++){
      int j = t[i] - 'a';
      if(c[j])
        c[j]--;
      else{
        s[Q.front()] = 'a' + j;
        Q.pop();
      }
    }
  }

  cout << s << '\n';

  return 0;
}

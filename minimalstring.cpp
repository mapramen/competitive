#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 26

int c[B];

bool ToBePopped(char s){
  int i = s - 'a';
  bool toBePopped = 1;

  for(int j = 0; j < i && toBePopped == 1; j++)
    toBePopped = (c[j] == 0);

  return toBePopped;
}

int main(){
  string s, ans;
  stack<char> t;

  cin >> s;

  for(int i = 0; i < s.size(); i++){
    int j = s[i] - 'a';
    c[j]++;
  }

  for(int i = 0; i < s.size(); i++){
    t.push(s[i]);

    int j = s[i] - 'a';
    c[j]--;

    while(!t.empty() && ToBePopped(t.top()) == 1){
      ans.PB(t.top());
      t.pop();
    }
  }

  cout << ans << '\n';
  
  return 0;
}

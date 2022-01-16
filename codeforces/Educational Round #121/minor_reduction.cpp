#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string OneString(string s){
  int x = (s[0] - '0') + (s[1] - '0');

  reverse(s.begin(), s.end());
  s.pop_back(), s.pop_back();
  s.push_back('0' + x);
  reverse(s.begin(), s.end());

  return s;
}

string TwoString(string s){
  int n = s.size(), k = -1;
  for(int i = 1; i < n; ++i){
    int x = (s[i] - '0') + (s[i - 1] - '0');

    if(x <= 9){
      continue;
    }

    k = i;
  }

  int x = (s[k] - '0') + (s[k - 1] - '0');
  s[k - 1] = '0' + (x / 10);
  s[k] = '0' + (x % 10);
  
  return s;
}

string Solve(){
  string s;
  cin >> s;

  int n = s.size();
  for(int i = 1; i < n; ++i){
    int x = (s[i - 1] - '0') + (s[i] - '0');
    if(x > 9){
      return TwoString(s);
    }
  }

  return OneString(s);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}
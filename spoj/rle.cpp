#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  string s;
  if(!(cin >> s)){
    exit(0);
  }

  string ans;
  for(int n = s.size(), i = 0; i < n; ){
    char c = s[i];
    int k = 0;

    for( ; i < n && s[i] == c; ++i, ++k);

    if(k > 3){
      for(char d: to_string(k)){
        ans.push_back(d);
      }
      ans.push_back('!');
      ans.push_back(c);
    }
    else{
      while(k--){
        ans.push_back(c);
      }
    }
  }

  return ans;
}

int main(){
  while(true){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}
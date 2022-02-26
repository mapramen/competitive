#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string GetString(int n, bool power2 = false){
  if(n == 0 && power2){
    return "2(0)";
  }

  if(n == 1 && power2){
    return "2";
  }

  vector<int> v;
  for(int p = 0; n > 0; n /= 2, ++p){
    if(n % 2 == 0){
      continue;
    }
    v.push_back(p);
  }
  reverse(v.begin(), v.end());

  string s;
  for(int p: v){
    if(!s.empty()){
      s += "+";
    }
    s += GetString(p, true);
  }

  return power2 ? "2(" + s + ")" : s;
}

int main(){
  vector<int> a {137, 1315, 73, 136, 255, 1384, 16385};
  for(int n: a){
    printf("%d=%s\n", n, GetString(n).c_str());
  }
  return 0;
}
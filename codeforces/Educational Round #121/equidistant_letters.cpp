#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 26

int c[B];

void AddChars(string& s, int k){
  for(int i = 0; i < B; ++i){
    if(c[i] != k){
      continue;
    }
    --c[i];
    s.push_back('a' + i);
  }
}

string Solve(){
  string s;
  cin >> s;

  for(char x: s){
    ++c[x - 'a'];
  }

  string ans;
  AddChars(ans, 1);
  AddChars(ans, 2);
  AddChars(ans, 1);

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define B 26

char s[N];

vector<int> ReadString(){
  if(scanf("%s", s) == EOF){
    exit(0);
  }

  vector<int> v(B);
  for(int i = 0; s[i] != '\0'; ++i){
    ++v[s[i] - 'a'];
  }

  return v;
}

string Solve(){
  vector<int> a = ReadString();
  vector<int> b = ReadString();

  string ans;
  for(int i = 0; i < B; ++i){
    int x = min(a[i], b[i]);
    while(x--){
      ans.push_back('a' + i);
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
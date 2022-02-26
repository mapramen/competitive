#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

string Solve(){
  int n;
  scanf("%d", &n);

  string s;
  while(n--){
    int d;
    scanf("%d", &d);
    s.push_back('0' + d);
  }

  if(next_permutation(s.begin(), s.end())){
    return s;
  }

  return "-1";
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}
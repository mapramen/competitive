#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  string s;

  cin >> s;
  int n = s.size();
  for(int i = 0; i < n; ){
    int j = i + 1, k = 0;
    for( ; j < n && s[j] == s[i]; ++j, ++k);
    while(k--){
      cout << "0 ";
    }
    if(j < n || s[i] == 'a'){
      cout << "1 ";
    }
    else{
      cout << "0 ";
    }
    i = j;
  }
  cout << '\n';

  return 0;
}

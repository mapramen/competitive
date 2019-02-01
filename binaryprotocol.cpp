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
  cin >> s;
  for(int i = 0; i < s.size(); i++){
    int k = 0;
    for( ; i < s.size() && s[i] == '1'; i++, k++);
    cout << k;
  }
  if(s[s.size() - 1] == '0')
    cout << '0';
  cout << '\n';

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
  int n;
  string s;
  char p = 'z';
  set<char> vowels({'a', 'e', 'i', 'o', 'u', 'y'});

  cin >> n >> s;
  for(int i = 0; i < n; ++i){
    char c = s[i];
    if(vowels.count(c) == 0 || vowels.count(p) == 0){
      putchar(c);
    }
    p = c;
  }
  putchar('\n');

  return 0;
}

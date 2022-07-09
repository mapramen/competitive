#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 26

char ch[2];
bool is_special_character[B];

void ReadSpecialCharacter(){
  int k;
  scanf("%d", &k);

  for(int i = 0; i < B; ++i){
    is_special_character[i] = false;
  }

  while(k--){
    scanf("%s", ch);
    is_special_character[ch[0] - 'a'] = true;
  }
}

int Solve(){
  int n;
  scanf("%d", &n);

  string s;
  cin >> s;

  ReadSpecialCharacter();

  int ans = 0;
  for(int i = 0, j = 0; i < n; ++i){
    if(!is_special_character[s[i] - 'a']){
      continue;
    }
    ans = max(ans, i - j);
    j = i;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}
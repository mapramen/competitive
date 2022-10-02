#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

char s[N];

void Solve(){
  int p;
  scanf("%s%d", s, &p);

  int n = strlen(s);
  for(int i = 0; s[i] != '\0'; ++i){
    p -= (s[i] - 'a' + 1);
  }

  for(char c = 'z'; p < 0 && c >= 'a'; --c){
    for(int i = 0; i < n && p < 0; ++i){
      if(s[i] == c){
        s[i] = '\0', p += (c - 'a' + 1);
      }
    }
  }

  for(int i = 0; i < n; ++i){
    if(s[i] != '\0'){
      putchar(s[i]);
    }
  }
  putchar('\n');
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}
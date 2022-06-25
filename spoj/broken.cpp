#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001
#define MAX_CHARS 256

char s[N];
int c[MAX_CHARS];

void Reset(){
  for(int i = 0; i < MAX_CHARS; ++i){
    c[i] = 0;
  }
}

void ReadString(){
  getchar();
  int i = 0;
  while(true){
    char c = getchar();
    if(c == '\n'){
      break;
    }
    s[i++] = c;
  }
  s[i] = '\0';
}

int Solve(){
  int m;
  scanf("%d", &m);

  if(m == 0){
    exit(0);
  }

  Reset();
  ReadString();

  int n = strlen(s), ans = 0;
  for(int i = 0, j = 0; j < n; ++i){
    for( ; j < n && m > -1; ++j){
      m -= (++c[s[j]] == 1);
    }
    
    int ansx = j - i - (m < 0);
    ans = max(ans, ansx);

    m += (--c[s[i]] == 0);
  }

  return ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}
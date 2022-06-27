#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 301
#define M 2001
#define HASH_BASE 31
#define MAXHASH 1

char P[M][M], T[M][M];
int hashes[M][M];
bool match[M][M];

bool IsPrime(int n){
  for(int x = 2; x * x <= n; ++x){
    if(n % x == 0){
      return false;
    }
  }
  return true;
}

vector<int> GetRandomPrimes(){
  mt19937 rnd(random_device{}());
  uniform_int_distribution<int> dis(100000000/2,1000000000/2);

  vector<int> primes;
  while(primes.size() < MAXHASH){
    int n = 2 * dis(rnd) + 1;
    if(IsPrime(n)){
      primes.push_back(n);
    }
  }

  return primes;
}

pii ReadMatrix(char S[M][M]){
  int n1, n2;
  scanf("%d%d", &n1, &n2);

  for(int x = 0; x < n1; ++x){
    scanf("%s", S[x]);
  }

  return {n1, n2};
}

int GetPatternHash(int n1, int n2, int mod){
  int hsh = 0;
  for(int x = 0; x < n1; ++x){
    for(int y = 0; y < n2; ++y){
      hsh = (1ll * hsh * HASH_BASE + (P[x][y] - 'a' + 1)) % mod;
    }
  }
  return hsh;
}

int GetPower(int a, int n, int mod){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * ans * a) % mod;
    }
    a = (1ll * a * a) % mod;
  }
  return ans;
}

void UpdateMatch(int n1, int n2, int m1, int m2, int mod){
  int pn1 = GetPower(HASH_BASE, n1, mod), pn2 = GetPower(HASH_BASE, n2, mod);

  for(int x = 0; x < m1; ++x){
    int hsh = 0;
    for(int y = 0; y < m2; ++y){
      hsh = (1ll * hsh * HASH_BASE + (T[x][y] - 'a' + 1)) % mod;
      if(y >= n2){
        hsh = (hsh - 1ll * pn2 * (T[x][y - n2] - 'a' + 1)) % mod;
      }
      hashes[x][y] = hsh;
    }
  }

  int pattern_hash = GetPatternHash(n1, n2, mod);
  int pn12 = GetPower(HASH_BASE, n1 * n2, mod);

  for(int y = 0; y < m2; ++y){
    int hsh = 0;
    for(int x = 0; x < m1; ++x){
      hsh = (1ll * hsh * pn2 + hashes[x][y]) % mod;
      if(x >= n1){
        hsh = (hsh - 1ll * pn12 * hashes[x - n1][y]) % mod;
      }

      hsh = (mod + hsh) % mod;
      match[x][y] = match[x][y] && (hsh == pattern_hash);
    }
  }
}

int main(){
  int n1, n2;
  tie(n1, n2) = ReadMatrix(P);

  int m1, m2;
  tie(m1, m2) = ReadMatrix(T);

  for(int x = 0; x < m1; ++x){
    for(int y = 0; y < m2; ++y){
      match[x][y] = true;
    }
  }

  for(int mod: GetRandomPrimes()){
    UpdateMatch(n1, n2, m1, m2, mod);
  }

  bool match_found = false;
  for(int x = n1 - 1; x < m1; ++x){
    for(int y = n2 - 1; y < m2; ++y){
      if(match[x][y]){
        match_found = true;
        printf("(%d,%d)\n", x + 2 - n1, y + 2 - n2);
      }
    }
  }

  if(!match_found){
    printf("NO MATCH FOUND...\n");
  }

  return 0;
}
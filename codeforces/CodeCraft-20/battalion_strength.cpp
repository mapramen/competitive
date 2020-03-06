#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 300001
#define B 20
#define M (1 << B)
#define P 2
#define INVP 500000004
#define MOD 1000000007

int a[N], p[N], invp[N];
pii queries[N];
vector<int> C;

void ModularAdd(int &ans, ll x){
  ans = (ans + x) % MOD;
  if(ans < 0){
    ans += MOD;
  }
}

class TreeNode {
  private:
    int leftEnd;
    int rightEnd;
    int count;
    int leftPart;
    int rightPart;
    int ans;
    TreeNode *leftChild;
    TreeNode *rightChild;

    void RefreshValues(){
      if(this->leftChild == NULL){
        return;
      }

      const int x = this->leftChild->count;

      this->count = x + this->rightChild->count;

      this->leftPart = (this->leftChild->leftPart + 1ll * p[x] * this->rightChild->leftPart) % MOD;
      this->rightPart = (this->leftChild->rightPart + 1ll * invp[x] * this->rightChild->rightPart) % MOD;

      this->ans = (this->leftChild->ans + this->rightChild->ans + 1ll * this->leftChild->leftPart * ((1ll * invp[x] * this->rightChild->rightPart) % MOD)) % MOD;
    }
  
  public:
    TreeNode(int leftEnd, int rightEnd){
      this->leftEnd = leftEnd;
      this->rightEnd = rightEnd;
      
      this->count = 0;
      this->leftPart = 0;
      this->rightPart = 0;
      this->ans = 0;

      this->leftChild = NULL;
      this->rightChild = NULL;
    }

    int Ans(){
      return this->ans;
    }

    void Update(int i, int x){
      if(this->leftEnd == i && this->rightEnd == i){
        this->count += x;

        this->leftPart = 0;
        this->rightPart = 0;
        this->ans = 0;

        if(this->count > 0){
          ModularAdd(this->leftPart, 1ll * C[i] * (p[this->count] - 1));
          ModularAdd(this->rightPart, 1ll * C[i] * (1 - invp[this->count]));

          int c = (1ll * C[i] * C[i]) % MOD;
          c = (1ll * INVP * c) % MOD;

          ModularAdd(this->ans, 1ll * c * (this->count - 2 + invp[this->count - 1]));
        }

        return;
      }

      if(this->leftChild == NULL){
        int mid = (this->leftEnd + this->rightEnd) / 2;
        this->leftChild = new TreeNode(this->leftEnd, mid);
        this->rightChild = new TreeNode(mid + 1, this->rightEnd);
      }

      if(i <= this->leftChild->rightEnd){
        this->leftChild->Update(i, x);
      }
      else{
        this->rightChild->Update(i, x);
      }

      this->RefreshValues();
    }
};

int GetCompressedValue(int x){
  return lower_bound(C.begin(), C.end(), x) - C.begin();
}

TreeNode* PreProcess(int n, int q){
  p[0] = 1, invp[0] = 1;
  for(int i = 1; i <= n; ++i){
    p[i] = (1ll * P * p[i - 1]) % MOD;
    invp[i] = (1ll * INVP * invp[i - 1]) % MOD;
  }

  for(int i = 1; i <= n; ++i){
    C.push_back(a[i]);
  };

  for(int i = 1; i <= q; ++i){
    C.push_back(queries[i].second);
  }

  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  for(int i = 1; i <= n; ++i){
    a[i] = GetCompressedValue(a[i]);
  }

  for(int i = 1; i <= q; ++i){
    queries[i].second = GetCompressedValue(queries[i].second);
  }

  TreeNode *root = new TreeNode(0, C.size() - 1);

  for(int i = 1; i <= n; ++i){
    root->Update(a[i], 1);
  }

  printf("%d\n", root->Ans());

  return root;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  int q;
  scanf("%d", &q);

  for(int i = 1; i <= q; ++i){
    scanf("%d%d", &queries[i].first, &queries[i].second);
  }

  TreeNode *root = PreProcess(n, q);

  for(int p = 1; p <= q; ++p){
    int i, x;
    tie(i, x) = queries[p];

    root->Update(a[i], -1);
    root->Update(x, 1);
    a[i] = x;

    printf("%d\n", root->Ans());
  }

  return 0;
}
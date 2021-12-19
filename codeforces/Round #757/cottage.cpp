#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000001

class Node{
  public:
  Node(int _l, int _r){
    l = _l, r = _r;
    lazyUpdate = 0;
    minValue = l, maxValue = r;

    leftChild = NULL;
    rightChild = NULL;
  }

  void Update(int t){
    if(maxValue < t){
      UpdateNode(1);
      return;
    }

    if(minValue > t){
      UpdateNode(-1);
      return;
    }

    if(minValue == t && maxValue == t){
      return;
    }

    LazyUpdateChildren();

    leftChild->Update(t);
    rightChild->Update(t);

    Combine();
  }

  int Query(int x){
    if(l == x && r == x){
      return x + lazyUpdate;
    }

    LazyUpdateChildren();

    int ans = (x <= leftChild->r) ? leftChild->Query(x) : rightChild->Query(x);
    
    Combine();
    return ans;
  }

  private:
  int l;
  int r;
  int lazyUpdate;
  int minValue;
  int maxValue;

  Node* leftChild;
  Node* rightChild;

  void UpdateNode(int update){
    lazyUpdate += update, minValue += update, maxValue += update;
  }

  void LazyUpdateChildren(){
    CreateChildrenIfNeeded();
    
    if(lazyUpdate == 0){
      return;
    }

    leftChild->UpdateNode(lazyUpdate);
    rightChild->UpdateNode(lazyUpdate);

    lazyUpdate = 0;
    Combine();
  }

  void Combine(){
    minValue = leftChild->minValue;
    maxValue = rightChild->maxValue;
  }
  
  void CreateChildrenIfNeeded(){
    if(leftChild != NULL){
      return;
    }

    int mid = l + (r - l) / 2;
    leftChild = new Node(l, mid);
    rightChild = new Node(mid + 1, r);
  }
};

int main(){
  int n;
  scanf("%d", &n);

  Node* root = new Node(0, MOD);

  int ans = 0;
  while(n--){
    int t;
    scanf("%d", &t);
    
    root->Update(t);

    int k;
    scanf("%d", &k);

    while(k--){
      int x;
      scanf("%d", &x);
      x = (ans + x) % MOD;
      x = (x + MOD) % MOD;

      ans = root->Query(x);
      printf("%d\n", ans);
    }
  }

  return 0;
}
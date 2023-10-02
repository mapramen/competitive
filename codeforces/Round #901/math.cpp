#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int uint;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define K 30
#define TOTAL_CD 4
#define ALL_CD_MASK ((1 << TOTAL_CD) - 1)
#define TOTAL_ABM 8

unordered_map<uint, vector<int>> adj;
unordered_map<uint, int> dis;
queue<uint> Q;

bool IsValid(uint mask) {
  for (uint abm = 0; abm < TOTAL_ABM; ++abm, mask >>= TOTAL_CD) {
    if (__builtin_popcount(mask & ALL_CD_MASK) > 1) {
      return false;
    }
  }
  return true;
}

void AndFunction(uint& a, uint& b, uint& m) {
  a &= b;
}

void OrFunction(uint& a, uint& b, uint& m) {
  a |= b;
}

void XorFunction(uint& a, uint& b, uint& m) {
  b ^= a;
}

void XorMFunction(uint& a, uint& b, uint& m) {
  b ^= m;
}

uint Operate(uint mask, function<void(uint&, uint&, uint&)> func) {
  uint ans = 0;
  for (uint abm = 0; abm < TOTAL_ABM; ++abm, mask >>= TOTAL_CD) {
    uint cd_mask = mask & ALL_CD_MASK;
    if (cd_mask == 0) {
      continue;
    }

    uint a = (abm & 4) >> 2, b = (abm & 2) >> 1, m = abm & 1;
    func(a, b, m);

    uint ans_abm = (a << 2) | (b << 1) | m;
    ans |= (cd_mask << (ans_abm * TOTAL_CD));
  }
  return ans;
}

void OperateValidateAndAdd(uint mask, function<void(uint&, uint&, uint&)> func) {
  uint ans = Operate(mask, func);
  if (ans != mask && IsValid(ans)) {
    adj[ans].push_back(mask);
  }
}

bool IsStartingPoint(uint mask) {
  for (uint abm = 0; abm < TOTAL_ABM; ++abm, mask >>= TOTAL_CD) {
    uint cd_mask = mask & ALL_CD_MASK;
    if (cd_mask == 0) {
      continue;
    }

    cd_mask = __builtin_ctz(cd_mask);
    uint c = cd_mask >> 1, d = cd_mask & 1;

    uint a = (abm & 4) >> 2, b = (abm & 2) >> 1, m = abm & 1;

    if (a != c || b != d) {
      return false;
    }
  }
  return true;
}

void CheckAndPush(uint mask, int d) {
  if (dis.count(mask) == 0) {
    dis[mask] = d;
    Q.push(mask);
  }
}

void Initialize() {
  vector<uint> cd_masks, masks(1);
  for (uint cd = 0; cd < TOTAL_CD; ++cd) {
    cd_masks.push_back(1 << cd);
  }

  for (uint abm = 0; abm < TOTAL_ABM; ++abm) {
    for (int i = masks.size() - 1; i > -1; --i) {
      for (uint cd_mask : cd_masks) {
        masks.push_back((cd_mask << (TOTAL_CD * abm)) | masks[i]);
      }
    }
  }

  for (uint mask : masks) {
    if (IsStartingPoint(mask)) {
      CheckAndPush(mask, 0);
    }

    OperateValidateAndAdd(mask, AndFunction);
    OperateValidateAndAdd(mask, OrFunction);
    OperateValidateAndAdd(mask, XorFunction);
    OperateValidateAndAdd(mask, XorMFunction);
  }

  while (!Q.empty()) {
    uint mask = Q.front();
    Q.pop();

    int d = 1 + dis[mask];
    for (uint next_mask : adj[mask]) {
      CheckAndPush(next_mask, d);
    }
  }
}

uint GetMask(int a, int b, int m, int c, int d) {
  uint mask = 0;
  for (int k = 0; k < K; ++k) {
    uint ak = (a >> k) & 1, bk = (b >> k) & 1, mk = (m >> k) & 1, ck = (c >> k) & 1, dk = (d >> k) & 1;
    uint cd_mask = (ck << 1) | dk;
    cd_mask = (1 << cd_mask);

    uint abm = (ak << 2) | (bk << 1) | mk;
    mask |= (cd_mask << (abm * TOTAL_CD));
  }
  return mask;
}

int Solve() {
  int a, b, c, d, m;
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &m);
  uint mask = GetMask(a, b, m, c, d);

  if (!IsValid(mask) || dis.count(mask) == 0) {
    return -1;
  }

  return dis[mask];
}

int main() {
  Initialize();
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define point3d tuple<int, int, int>

vector<pair<point3d, point3d>> ReadBlocks() {
  vector<pair<point3d, point3d>> blocks;
  while (true) {
    int x1, y1, z1, x2, y2, z2;
    if (scanf("%d,%d,%d~%d,%d,%d", &x1, &y1, &z1, &x2, &y2, &z2) == EOF) {
      break;
    }
    blocks.push_back({{x1, y1, z1}, {x2, y2, z2}});
  }
  return blocks;
}

int GetMaxCoordinate(vector<pair<point3d, point3d>>& blocks) {
  int max_coordinate = 0;
  for (auto& block : blocks) {
    auto [x2, y2, z2] = block.second;
    max_coordinate = max(max_coordinate, max({x2, y2, z2}));
  }
  return max_coordinate;
}

void AddSupports(vector<set<int>>& supports, vector<set<int>>& supported_by, int i, int j) {
  if (i == -1) {
    return;
  }

  supports[i].insert(j);
  supported_by[j].insert(i);
}

int CalculateDisintegratingPower(vector<set<int>>& supported_by, int i) {
  set<int> S{i};
  for (int n = supported_by.size(); i < n; ++i) {
    if (supported_by[i].empty()) {
      continue;
    }

    bool can_be_disintegrated = true;
    for (int j : supported_by[i]) {
      if (S.find(j) == S.end()) {
        can_be_disintegrated = false;
        break;
      }
    }
    if (can_be_disintegrated) {
      S.insert(i);
    }
  }
  return S.size() - 1;
}

int main() {
  vector<pair<point3d, point3d>> blocks = ReadBlocks();
  sort(blocks.begin(), blocks.end(), [](const auto& lhs, const auto& rhs) { return get<2>(lhs.first) < get<2>(rhs.first); });

  int n = blocks.size();
  int m = GetMaxCoordinate(blocks);

  vector<vector<vector<int>>> grid(m + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, -1)));

  vector<set<int>> supports(n);
  vector<set<int>> supported_by(n);

  for (int i = 0; i < n; ++i) {
    auto [x1, y1, z1] = blocks[i].first;
    auto [x2, y2, z2] = blocks[i].second;

    vector<pii> xys;
    if (z1 != z2) {
      xys.push_back({x1, y1});
    } else {
      for (int x = x1; x <= x2; ++x) {
        for (int y = y1; y <= y2; ++y) {
          xys.push_back({x, y});
        }
      }
    }

    int z = z1;
    for (; z > 0; --z) {
      bool can_be_placed = true;
      for (auto [x, y] : xys) {
        if (grid[x][y][z] != -1) {
          can_be_placed = false;
          break;
        }
      }

      if (!can_be_placed) {
        break;
      }
    }
    ++z;

    if (z1 != z2) {
      AddSupports(supports, supported_by, grid[x1][y1][z - 1], i);
      for (int k = z2 - z1 + 1; k > 0; --k, ++z) {
        grid[x1][y1][z] = i;
      }
    } else {
      for (int x = x1; x <= x2; ++x) {
        for (int y = y1; y <= y2; ++y) {
          grid[x][y][z] = i;
          AddSupports(supports, supported_by, grid[x][y][z - 1], i);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += CalculateDisintegratingPower(supported_by, i);
  }
  printf("%d\n", ans);

  return 0;
}
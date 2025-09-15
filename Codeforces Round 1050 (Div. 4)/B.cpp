#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, x, y, temp;  // temp 사용할 일 없음
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; ++i) cin >> temp;
    for (int i = 0; i < m; ++i) cin >> temp;
    cout << n + m << '\n';
  }
  return 0;
}

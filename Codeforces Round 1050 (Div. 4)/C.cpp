#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;

    int px = 0;  // previous x
    int py = 0;  // previous y
    int points = 0;

    /* core logic

    When can we run every minute?
    -> only if (a_i+1 - a_i) and |b_i+1 - b_i| hvae the same "parity".
    */

    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;

      points += (x - px);  // running every minute

      int x_parity = (x - px) % 2;
      int y_parity = (y - py + 2) % 2;  // +2: (y - py) could be < 0

      if (x_parity != y_parity) points--;

      // update px and py
      px = x;
      py = y;
    }

    // 마지막 지정 위치 이후에는 항상 달릴 수 있음
    if (px != m) points += (m - px);

    cout << points << '\n';
  }
  return 0;
}

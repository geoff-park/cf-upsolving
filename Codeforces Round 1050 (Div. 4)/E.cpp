// E. Split
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);         // 원본 배열 (0-based index)
    vector<int> freq(n + 1);  // 빈도 배열 (1-based index)
    for (int i = 0; i < n; ++i) {
      int ai;
      cin >> ai;
      a[i] = ai;
      freq[ai]++;
    }

    // 모든 원소의 빈도수는 % k == 0 이어야 한다.
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
      if (freq[i] % k != 0) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << 0 << '\n';
      continue;
    }

    vector<int> cap(n + 1, 0);
    for (int i = 1; i <= n; ++i) cap[i] = freq[i] / k;

    // 모든 값의 빈도가 cap[i] 이하라면, 조건 만족 (이후에는 자유롭게 넣을 수 있으므로)
    // 투 포인터 사용

    long long ans = 0;
    vector<int> curr(n + 1, 0);

    int L = 0;
    for (int R = 0; R < n; ++R) {
      int x = a[R];
      curr[x]++;

      // L을 당겨서 위반 해소
      while (curr[x] > cap[x]) {
        int y = a[L];
        curr[y]--;
        L++;
      }

      ans += (R - L + 1);  // [L..R] 부터 [R..R] 까지: [L..R] 은 상한, 부분배열은 자동으로 조건 만족
    }

    cout << ans << '\n';
  }
  return 0;
}

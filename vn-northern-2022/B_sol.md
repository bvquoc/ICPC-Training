# Bài B:

### Nhận xét

Vì $s_j = (s_{j-1} * a_i + b_i) \% m$ nên mọi $s_j$ sẽ nằm trong khoảng $(0,m)$

Nhận thấy đây là một bài BFS cơ bản với các đỉnh được đánh số từ 0 đến m-1.

Xây dựng đồ thị từ đỉnh có nhãn là $s_0$
Với mỗi đỉnh $u$ sẽ có cạnh nối đến các đỉnh $v = (u * a[i] + b[i]) \% m$.
Đường đi ngắn nhất từ đỉnh $s_0$ đến đỉnh $0$ là kết quả bài toán.

### Source code (BFS):

```cpp
queue <ii> q;
q.push({S, 0});
while (q.size()) {
  int u = q.front().first;
  int d = q.front().second;
  if (u == 0) {
    cout << d;
    exit(0);
  }
  q.pop();
  mark[u] = true;

  for (int i = 1; i <= n; i++) {
    int v = nxtVertex(u, i);
    if (mark[v]) continue;
    q.push({v, d+1});
  }
}
cout << "-1";
```

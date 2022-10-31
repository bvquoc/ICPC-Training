# Bài D:

### Nhận xét

```
f(x) = x! với (0 <= x <= 9)
f(x) = f(x%10) + f([x/10]) (với x > 9)
```

Dễ dàng thấy được `f(x)` đúng bằng tổng giai thừa các chữ số của `x`
Ví dụ: f[9123] = 3! + 2! + 1! + 9!

### Giải thuật

Khởi tạo mảng `f` với `f[i] = i!` (i = 0 -> 9)

Với `f[x] = y`
Để `x` min thì số lượng chữ số của `x` phải là ít nhất.
Sử dụng giải thuật Tham lam (greedy) để xây dựng các chữ số theo thứ tự từ 9 -> 1
Sắp xếp lại các chữ số theo thứ tự tăng dần để được kết quả nhỏ nhất.
Lưu ý với trường hợp `y = 1` thì kết quả là `0`

```cpp
int f[10];
void init_f() {
  f[0] = 1;
  for (int i = 1; i <= 9; i++)
    f[i] = f[i-1] * i;
}

void greedy(int n) {
  string ans = "";
  int x = 9;
  while (x >= 1) {
    while (n >= f[x]) {
        n -= f[x];
        ans.push_back('0' + x);
    }
    x--;
  }

  sort(ans.begin(), ans.end());
  cout << ans;
}
```

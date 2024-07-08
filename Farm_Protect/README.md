﻿# Bảo vệ nông trang

Nông trang có rất nhiều ngọn đồi núi, để bảo vệ nông trang nông dân John muốn đặt người canh gác trên các ngọn đồi này.

Anh ta băn khoăn không biết sẽ cần bao nhiêu người canh gác nếu như anh ta muốn đặt 1 người canh gác trên đỉnh của mỗi đồi.

Anh ta có bản đồ của nông trang là một ma trận gồm `N` (`1 < N <= 700`) hàng và `M` (`1 < M <= 700`) cột.
Mỗi phần tử của ma trận là độ cao `H_ij` so với mặt nước biển (`0 <= H_ij <= 10,000`) của ô `(i, j)`.
Hãy giúp anh ta xác định số lượng đỉnh đồi trên bản đồ.

Đỉnh đồi là 1 hoặc nhiều ô nằm kề nhau của ma trận có cùng độ cao được bao quanh bởi cạnh của bản đồ hoặc bởi các ô có độ cao nhỏ hơn.
Hai ô gọi là kề nhau nếu độ chênh lệch giữa tọa độ `X` không quá 1 và chênh lệch tọa độ `Y` không quá 1.

## Input

- Dòng 1: Số lượng mẫu

- Dòng 2: Hai số nguyên cách nhau bởi dấu cách: `N` và `M`

- Dòng 3: `N+1`: Dòng `i+1` mô tả hàng `i` của ma trận với `M` số nguyên cách nhau bởi dấu cách: `H_ij`

```
3
8 7
4 3 2 2 1 0 1
3 3 3 2 1 0 1
2 2 2 2 1 0 0
2 1 1 1 1 0 0
1 1 0 0 0 1 0
0 0 0 1 1 1 0
0 1 2 2 1 1 0
0 1 1 1 2 1 0
8 7
4 3 2 2 1 1 1
3 3 3 2 1 0 1
2 2 2 2 1 0 0
2 1 1 1 1 0 0
1 1 0 0 0 1 0
0 0 0 1 1 1 0
0 1 2 2 1 1 0
0 1 1 1 2 1 0
8 7
4 3 2 2 1 1 1
3 3 3 2 1 0 1
2 2 2 2 1 0 0
2 1 1 2 1 0 0
1 1 2 2 0 1 0
0 0 0 2 1 1 0
0 1 2 2 1 1 0
0 1 1 1 2 1 0
```

## Output

- Dòng 1: Một số nguyên duy nhất là số lượng đỉnh đồi.

```
#1 3
#2 2
#3 1
```
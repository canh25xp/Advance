# Hugo Giao Hàng
>
> Level 4

Hugo đang làm việc cho công ty Samsung, tuy mức lương ở Samsung không hề nhỏ nhưng vì Hugo là lao động duy nhất trong nhà, vợ của Hugo mới sinh em bé.
Hugo muốn kiếm them thu nhập để có thể có thêm tiền sữa, bỉm cho con.
Hugo quyết định nhận giao bánh pizza ngoài giờ làm.
Mỗi ngày, sau khi tan ca Hugo sẽ nhận N chiếc bánh pizza để giao tới N địa điểm khác nhau sau đó trở về nhà.
Tuy nhiên do giá xăng dầu đang leo thang, Hugo cần phải giảm tối đang lượng xăng phải tiêu thụ, vì vậy Hugo muốn tính toán xem quãng đường đi giao bánh pizza từ công ty sau đó về nhà là ngắn nhất.
Hãy giúp Hugo với nhé.

## Input

`T` test case `T <= 50`

Dòng đầu tiên chưa 4 số `Sx, Sy, Dx, Dy` tương ứng là vị trí của công ty và nhà của Hugo trên hệ trục tọa độ Oxy

Dòng tiếp theo bao gồm số `N` và `N` cặp số liên tiếp tương ứng là tọa độ các điểm mà Hugo cần giao pizza. `N <= 10`

Cách tính khoảng cách giữa 2 điểm $(x_1, y_1)$, $(x_2, y_2)$

$$ D = |x_1-x_2| + |y_1-y_2| $$

```
10
57 61 50 61
5 86 53 4 104 27 3 55 34 69 0
96 47 60 28
5 0 6 43 84 84 35 44 57 95 50
48 32 67 42
5 53 51 92 1 48 19 8 3 82 37
97 28 66 41
5 93 72 9 79 46 31 12 66 54 11
38 62 93 86
5 87 83 40 83 83 26 98 11 74 103
23 42 71 16
5 12 76 47 74 24 5 88 82 45 85
96 85 14 6
5 86 91 104 60 72 35 59 22 58 39
99 49 68 1
5 48 80 96 101 56 88 75 56 25 81
51 14 75 51
5 29 62 103 15 75 84 67 94 96 57
87 39 57 77
5 105 85 31 40 1 88 83 89 29 18
```

## Output

In ra quãng đường ngắn nhất Hugo di chuyển từ công ty để giao bánh sau đó trở về nhà.

```
Case #1 393
Case #2 323
Case #3 267
Case #4 294
Case #5 281
Case #6 300
Case #7 219
Case #8 283
Case #9 295
Case #10 344
```
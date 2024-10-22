# Map Coloring
>
> Level 4

We consider a geographical map with `N` countries numbered from 1 to N (`1 <= N <=  1000`).
For every country we know the numbers of other countries which are connected with its border.
From every country we can reach to any other one, eventually crossing some borders.
Write a program which determines whether it is possible to color the map only in two colors-red and blue in such a way that if two countries are connected their colors are different.
The color of the first country is red.
Your program must output one possible coloring for the other countries, or show, that such coloring is impossible.

## Input
The first line is the total number of test cases `T`.

Each test case has two lines:
- The first line has `N` (the number of countries) and `E` (the number of border) separated by a space.
- The next line enumerates `E` border.
A border consists of the two countries it connects.
For example, the border connecting countries 5 and 28 is represented by `5 28` or `28 5`.
The indices of countries are 1 through N.
All adjacent numbers in a line are each separated by a space.

```
1           <-- Total test case T
3 2         <-- Starting test case 1
1 2 2 3
```

## Output

Output the each answer in 1 line.
Each line starts with `#x`, where `x` means the index of a test case, and puts a space, and prints the answer.

If the coloring is possible, this answer must contain a list of zeros and ones, without any separators between them.
The `i-th` digit in this sequence is the color of the `i-th` country.
`0` corresponds to `red` color, and `1` - to `blue` color.
If a coloring is not possible, output the integer `−1`.

```
#1 010
```

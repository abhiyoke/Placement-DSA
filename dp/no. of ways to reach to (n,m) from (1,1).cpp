/*
Problem: The King's Walk
Given an n x m Chess Board, write a program to find the number of distinct paths a King can take to travel from the left bottom square (1, 1), which is the source, to the top
right square (n, m), which is the destination, such that on every move the King gets closer to the destination.

Input Format
There is a single line of input containing 2 space-separated non-zero positive integers r and c. The first integer represents the number of rows on the 
chessboard and the second integer represents the number of columns on the chessboard.
Constraints
0 < r <= 10
0 < c <= 10
Output Format
The program must output a single integer signifying the number of distinct paths the King can take.
Sample Input 0
2 2
Sample Output 0
3
Explanation 0
On a 2x2 chessboard, there are 3 distinct paths the King can take to move from (1, 1) to (2, 2):
Right -> Up
Up -> Right
Diagonally right-up
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[5000+5][5000+5];
 int main() {
ll n; lll m; cin>>n; cin>>m;
ll i =1;
while(i<=n){
ll j-1;
 while(j<=m){
dp[i][j] -dp[i-1][j] + dp[i][j-1];
 if(i=-1 && j=1){ I
dp[i][j] = 1;
}
j++;
}
i++;
}
cout<<dp[n][m] ;
return 0;
}

/*
Dynamic Programming Approach:

DP Array Setup:
Create empty DP arrays.
Fill answers for small indices.
Develop a formula to solve the problem.
Movement Restrictions:
Only right and down moves are allowed.
DP[1, 1] is always 1 since it's the starting point.
Matrix Navigation:

Example:
To reach index (2, 2), there are two ways: right then down, or down then right.
Base case DP[1, 1] is set to 1.
Use common sense to determine ways for other indices, e.g., DP[2, 3].
Formula Development:

To reach a block (i, j):
Add ways from the upper block and left side.
E.g., DP[i, j] = DP[i-1, j] + DP[i, j-1].
Nested Loops for DP Array:

Two nested loops:
Outer loop runs from 1 to n for i.
Inner loop runs from 1 to m for j.
Special condition when i is 1.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int profit(int n, int W, int* w, int* v, int **arr)
{
	if (n == -1 || W == 0)
		return 0;
	if (arr[n + 1][W] != 9999999)
	{
		return arr[n + 1][W];
	}
	else if (w[n] > W)
	{
		arr[n + 1][W] = profit(n - 1, W, w, v, arr);
	}
	else
	{
		arr[n + 1][W] = max(profit(n - 1, W - w[n], w, v, arr) + v[n], profit(n - 1, W, w, v, arr));
	}
	return arr[n + 1][W];
}
void print(int **arr, int i, int j, int* v, int* w)
{
	if (i == 0 || j == 0 || arr[i][j] == 0)
		return;
	if (arr[i][j] == arr[i - 1][j])
	{
		print(arr, i - 1, j, v, w);
	}
	else
	{
		print(arr, i - 1, j - w[i - 1], v, w);
		cout << i - 1 << endl;
	}
}
int main()
{
	const int n = 4;
	int W = 10;
	int v[n] = { 10, 40, 30, 50 };
	int w[n] = { 5, 4, 6, 3 };
	int **arr = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		arr[i] = new int[W + 1];
		for (int j = 0; j < W + 1; j++)
			arr[i][j] = 9999999;
	}
	cout << "Max Profit = " << profit(n - 1, W, w, v, arr) << endl;
	print(arr, 4, 10, v, w);
	system("pause");
}
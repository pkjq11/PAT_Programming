/*
根据维基百科的定义：

插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。

归并排序进行如下迭代操作：首先将原始序列看成N个只包含1个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下1个有序的序列。

现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？

输入格式：

输入在第一行给出正整数N (<=100)；随后一行给出原始序列的N个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。

输出格式：

首先在第1行中输出“Insertion Sort”表示插入排序、或“Merge Sort”表示归并排序；然后在第2行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行末不得有多余空格。
输入样例1：
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
输出样例1：
Insertion Sort
1 2 3 5 7 8 9 4 6 0
输入样例2：
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
输出样例2：
Merge Sort
1 2 3 8 4 5 7 9 0 6
*/
#include <iostream>
using namespace std;

bool isfound(int *list,int start,int end,int purpose)
{
	while(start <= end)
		if(list[start] == purpose)
			break;
		else start++;
	return start>end?false:true;
}

void InsertSort(int *list,int param)
{
	int temp = list[param];
	int i = param - 1;
	for (; i >= 0; --i)
	{
		if (list[i] > temp)
			list[i+1] = list[i];
		else break;
	}
	list[i+1] = temp;
}

void Merge(int *list,int low,int middle,int high)
{
	int *temp = new int[high-low+1]();
	for (int m = low; m <= high; ++m)
		temp[m-low] = list[m];
	int i,j,k;
	for (i = 0,j = middle - low + 1,k = low; i <= (middle - low) && j <= (high - low); ++k)
	{
		if(temp[i]<=temp[j])
			list[k] = temp[i++];
		else list[k] = temp[j++];
	}
	while(i <= (middle - low)) list[k++] = temp[i++];
	while(j <= (high - low)) list[k++] = temp[j++];
	delete temp;
}

int main(int argc, char const *argv[])
{
	int num;
	cin>>num;
	int *source = new int[num]();
	int *sorted = new int[num]();
	for (int i = 0; i < num; ++i)
		cin>>source[i];
	for (int i = 0; i < num; ++i)
		cin>>sorted[i];
	int sorted_num = 1;
	for (int i = 1; i < num; ++i)
	{
		if (sorted[i]>sorted[i-1])
			sorted_num++;
		else break;
	}
	int temp1 = sorted_num - 1;
	int temp2 = temp1;
	bool isinsert = true;
	while(temp1>0)
	{
		while(temp2 >= 0)
			if (isfound(source, 0, temp1, sorted[temp2]))
				temp2--;
			else break;
		if(temp2 < 0)
			break;
		else
		{
			temp1 = temp2 - 1;
			temp2 = temp2 - 1;
		}

	}
	for (int i = temp1+1; i < num; i++)
	{
		if(source[i] != sorted[i])
		{
			isinsert = false;
			break;
		}
	}
	if (isinsert)
	{
		cout<<"Insertion Sort"<<endl;
		InsertSort(sorted, temp1+1);
		for (int i = 0; i < num-1; ++i)
			cout<<sorted[i]<<" ";
		cout<<sorted[num-1];
	}
	else
	{
		cout<<"Merge Sort"<<endl;
		int sublistlong = temp1+1;
		while(sublistlong > 1)
		{
			int i;
			for (i = 0; i < num; i = i+sublistlong)
			{
				int j;
				for (j = i; j < i+sublistlong-1 && j < num; ++j)
				{
					if(sorted[j]>sorted[j+1])
						break;
				}
				
				if(j < i+sublistlong-1 && j < num)
					break;
			}
			
			if(i<num)
				sublistlong--;
			else break;
		}

		int m;
		for (m = 0; m+2*sublistlong-1 < num; m = m + 2 * sublistlong)
			Merge(sorted, m, m+sublistlong-1, m+2 * sublistlong -1);
		m = m - sublistlong;
		if(m < num -1 )
			Merge(sorted, m - sublistlong, m - 1, num -1);
		for (int i = 0; i < num-1; ++i)
			cout<<sorted[i]<<" ";
		cout<<sorted[num-1];
	}
	delete source;
	delete sorted;
	return 0;
}
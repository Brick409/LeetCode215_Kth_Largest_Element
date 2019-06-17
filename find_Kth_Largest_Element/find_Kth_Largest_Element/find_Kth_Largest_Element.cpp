// find_Kth_Largest_Element.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>  //包括min和max函数

using namespace std;
/*
寻找一个数组中第k大的元素，并输出该元素
Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
*/

/* 解法1：先对原数组进行从大到小排序，输出对应第K个元素 */
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		//直接插入排序,从小到大排序
		int i = 0,j = 0;

		for (i=1;i<nums.size();i++)
		{
			int val = nums[i];
			//注意此处循环条件，必须为j>0&&nums[j]>val，否则会出问题
			for (j=i-1;j>=0&& nums[j] > val;j--)
			{
				nums[j + 1] = nums[j];
			}

			nums[j+1] = val;
		}

		return nums[nums.size()-k];
	}
};


int main()
{
	int a[] = { 3,2,3,1,2,4,5,5,6 };
	int k = 4;

	vector<int> vec(a, a + sizeof(a) / sizeof(a[0]));

	int res=Solution().findKthLargest(vec, k);
	cout << res << endl;

    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

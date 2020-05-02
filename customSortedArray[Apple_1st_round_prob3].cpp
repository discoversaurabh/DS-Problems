#if 1
// Problem statement screenshot has been posted on git hub with the same name as that of this code file but extension is png
#include"AllHeader.h"

class Solution
{
public:

	void numSwap(int &a, int &b)
	{
		int tmp;
		tmp = a;
		a = b;
		b = tmp;
	}

	void customSort(vector<int> &nums)
	{
		int size = nums.size();
		int i = 0, j = size - 1;
		// for (int i = 0, j = size - 1; i < j; i++, j--)
		while(i < j)
		{
			while(i < size && (nums[i] & 1) == 0)	//	SAURABH - Initially I did not put bracket in this condition : "nums[i] & 1 == 0" and it took hell lot of time to understad what was wrong.
				i++;

			while (j >= 0 && nums[j] & 1)
				j--;

			if (i < j)
			{
				numSwap(nums[i], nums[j]);
				i++;
				j--;
			}
		}
	}
};

int main()
{
	vector<int> nums = { 6, 3, 4, 5 };
	Solution s;
	cout << "Custom Sorted Array: " << endl;
	s.customSort(nums);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
	return 0;
}
#endif
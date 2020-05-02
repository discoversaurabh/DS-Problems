// Problem statement screenshot has been posted on git hub with the same name as that of this code file but extension is png
#include"AllHeader.h"

class Solution
{
public:
	int minimumSum(vector<int> &nums, int k)
	{
		int tmp = 0, sum = 0;
		int size = nums.size();
		//this is for min heap
		//priority_queue<int, vector<int>, greater<int>> pq;

		//default is max heap
		priority_queue<int> maxHeap;	//stands for max heap

		//prepare heap
		for (int i = 0; i < size; i++)
		{
			sum += nums[i];
			maxHeap.push(nums[i]);
		}
		
		tmp = maxHeap.top();
		/**
		* SAURABH NOTE:
		* very important step -> as K varies from 0 to 10^7 while n varies till 10^5, 
		* chances are that k coul be very high and n can have very few elements e.g.,
		* just 4 elements. So we need not do k number of operations on max heap. 
		* We will stop when top element of heap reaches 1. 
		* (note: heap will never reach 0 a we have to take ceiling always after division by 2)
		*/
		while (tmp != 1 && k > 0)	
		{
			//tmp = maxHeap.top();
			sum -= tmp;
			tmp = (tmp & 1) ? (tmp + 1) / 2 : tmp / 2;
			maxHeap.pop();
			maxHeap.push(tmp);
			sum += tmp;
			tmp = maxHeap.top();
			k--;
		}
		return sum;
	}
};

int main()
{
	vector<int> nums = {10, 20, 7};
	Solution s;
	cout<<"Min Sum: "<< s.minimumSum(nums, 4) <<endl;
	return 0;
}
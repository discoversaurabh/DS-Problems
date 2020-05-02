#if 1
// Problem statement screenshot has been posted on git hub with the same name as that of this code file but extension is jpeg
#include"AllHeader.h"

class Solution
{
public:
	void createHashSet(vector<int> &vec, int size, unordered_map<int, int> &hashMap)
	{
		for (int i = 0; i < size; i++)
		{
			hashMap[vec[i]]++;
		}
	}
	void createGeologicalData(vector<int> &vec, int size, unordered_map<int, int> &hashMap, vector<int> &result)
	{
		for (int i = 0; i < size; i++)
		{
			auto a = hashMap.find(vec[i]);

			if (a != hashMap.end())
			{
				if (a->second >= 1)
				{
					result.push_back(vec[i]);
					a->second -= 1;
				}
			}
		}
	}
	vector<int> geologicalSort(vector<int> &v, vector<int> &nv)
	{
		vector<int> result;
		bool isFirst = false;
		int size1 = v.size();
		int size2 = nv.size();

		unordered_map<int, int> hashMap;
		if (size1 > size2)
			isFirst = false;
		else
			isFirst = true;

		if (isFirst)
		{
			createHashSet(v, size1, hashMap);
			createGeologicalData(nv, size2, hashMap, result);
		}
		else
		{
			createHashSet(nv, size2, hashMap);
			createGeologicalData(v, size1, hashMap, result);
		}
		sort(result.begin(), result.end(), greater<int>());
		return result;
	}
};

int main()
{
	vector<int> v = { 7000, 13400, 7000, 14000 };
	vector<int> nv = { 7000, 13400, 150000, 7000 };
	Solution s;
	vector<int> result;
	cout << "Custom Sorted Array: " << endl;
	result = s.geologicalSort(v, nv);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}
#endif
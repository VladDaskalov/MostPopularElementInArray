#include <iostream>
#include <unordered_map>
using namespace std;

/// <summary>
/// Function to find most popular number in an array using recursion
/// </summary>
/// <param name="sourceArr">Source array that contains the numbers</param>
/// <param name="pos">Array position to start the search</param>
/// <param name="size">Size of source array</param>
/// <param name="hash">Map, where unique numbers and there count will be stored temporarily during processing</param>
/// <param name="maxCount">Max Count output variable</param>
/// <param name="mostFreq">Most frequent number output variable</param>
/// <returns>Most frequent number</returns>
int FindMostPopularElement (int sourceArr[], int pos, int size, unordered_map<int,int> &hash, int &maxCount, int &mostFreq)
{
	int currentNum = sourceArr[pos];
	if (pos >= size)
		return mostFreq;
	else
		if (hash.find(currentNum) == hash.end())
		{
			hash.insert(pair<int,int>(currentNum,1));
		}
		else
		{
			hash[currentNum]++;
			if (hash[currentNum]>=maxCount)
			{
				maxCount = hash[currentNum];
				mostFreq = currentNum;
			}
		}
		return FindMostPopularElement(sourceArr,pos+1,size,hash,maxCount,mostFreq);
}

int main(int argc, char* argv[])
{

	int array[] = {1,2,3,1,2,3,2,3,3,4,5,7,7,7,7};
	int size = sizeof(array)/sizeof(array[0]);
	unordered_map<int,int> tmpMap;
	int tmpCompare = 0;
	int mostFrequent = 0;

	FindMostPopularElement(array,0,size,tmpMap,tmpCompare,mostFrequent);

	cout << "Array size:" << size << endl;
	cout << "Most Frequent element: " << mostFrequent << endl;

	return 0;
}



#include<iostream>
#include<vector>
#include<stack>
#include<climits>
#define FOR(i,n) for(int i = 0; i < n; i++)

using namespace std;

int gMaxAreaOfHistogram(int xArray[], int n)
{
	int lMaxArea = INT_MIN;
	stack<int> lStack;
	FOR(i, n) 
	{
		if (lStack.empty())
		{
			lStack.push(i);
		}
		else 
		{
			int lCurrTopIndex = lStack.top();
			int lCurrTop = xArray[lCurrTopIndex];
			if (lCurrTop <= xArray[i])
				lStack.push(i);
			else 
			{
				while(!lStack.empty() && lCurrTop > xArray[i]) 
				{
					int lArea = 0;
					lStack.pop();
					if (lStack.empty()) 
					{
						lArea = i * lCurrTop; 
					} 
					else 
					{ 
						lCurrTopIndex = lStack.top();
						while(xArray[lCurrTopIndex] == lCurrTop && !lStack.empty()) 
						{
							lCurrTopIndex = lStack.top();
						}
						lArea = (i - lCurrTopIndex - 1) * lCurrTop;
						lCurrTop = xArray[lCurrTopIndex];
					}
					lMaxArea = lArea > lMaxArea ? lArea : lMaxArea; 
				}
				lStack.push(i);
			}
		}
	}
	
	while (!lStack.empty()) 
	{
		int lCurrTopIndex = lStack.top();
		int lCurrTop = xArray[lCurrTopIndex];
		lStack.pop();
		int lArea = 0;
		if (lStack.empty()) 
		{
			lArea = n*lCurrTop;
		}
		else 
		{
			lArea = (n - lCurrTopIndex) * lCurrTop;
		}
		lMaxArea = lArea > lMaxArea ? lArea : lMaxArea; 
	}
	return lMaxArea;
}

int main() 
{
	std::ios_base::sync_with_stdio(false);
	int lTests;
	cin>>lTests;
	FOR(i, lTests) 
	{
		int lSize;
		cin>>lSize;
		//vector<int> lVec(lSize, -1);		
		int lVec[lSize];
		FOR(j, lSize) 
			cin>>lVec[j];
		cout<<gMaxAreaOfHistogram(lVec, lSize)<<"\n";
	}
}

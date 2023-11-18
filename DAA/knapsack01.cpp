#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;
int solve(int index,int w,vector<int>&weight,vector<int>&value,vector<vector <int> > &dp)
{
	//base condition
	if(index==0)
	{
		if(w-weight[0]>=0)
			return value[0];
		else
			return 0;
	}
	if(dp[index][w]!=-1)
	{
		return dp[index][w];
	}
	int nonTake,take=INT_MIN;
	nonTake=0+solve(index-1,w,weight,value,dp);
	if(w-weight[index]>=0)
	{
		take=value[index]+solve(index-1,w-weight[index],weight,value,dp);
	}
	return dp[index][w]=max(nonTake,take);
}
int main() {
	int n,wt;
	cout<<"Enter number of items\n";
	cin>>n;
	cout<<"\nEnter weight of bag\n";
	cin>>wt;
	vector<int>weight(n),value(n);
	vector<vector< int > > dp(n,vector<int>(wt+1,-1));
	for(int i=0;i<n;i++)
	{
		cin>>weight[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>value[i];
	}
//	cout<<solve(n-1,wt,weight,value,dp);
//	return 0;
	high_resolution_clock::time_point start_time = high_resolution_clock::now(); // Start measuring time
	    int result = solve(n - 1, wt, weight, value, dp);
	    high_resolution_clock::time_point stop_time = high_resolution_clock::now(); // Stop measuring time
	    microseconds duration = duration_cast<microseconds>(stop_time - start_time);

	    cout << "Maximum value: " << result << "\n";
	    cout << "Time taken: " << duration.count() << " microseconds\n";

	    // Space complexity estimation (a rough estimate)
	    size_t space_used = sizeof(int) * 4 + sizeof(char) + sizeof(n) + sizeof(wt) + sizeof(weight) + sizeof(value) + sizeof(dp);
	    cout << "Space used by the program: " << space_used << " bytes\n";

	    return 0;








}

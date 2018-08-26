#include<iostream>
#include<vector>
using namespace std;
int main()
{

	vector<int> cost{1,100,1,1,1,100,1,1,100,1};
	if(cost.size()==2)
	{
			  //cout<<"cost= 0"<<endl;
			  return 0;
	}

	int c[cost.size()+1];
	c[0]=0;
	for(int i=1;i<=cost.size();i++)
	{
			  c[i]=cost[i-1];
			  //cout<<c[i]<<" "<<endl;
	}
	int n=cost.size()+1;
	//cout<<"n="<<n<<endl;
	int costResult[n+1];
	costResult[1]=0;
	costResult[2]=0;
	for(int i=3;i<=n;i++)
	{
		int first=costResult[i-1]+c[i-1];
		int sec=costResult[i-2]+c[i-2];
		//cout<<"first="<<first<<endl;
		//cout<<"second="<<sec<<endl;
		costResult[i]=first<sec?first:sec;
		//cout<<"costResult="<<costResult[i]<<endl;
	}
	cout<<"cost="<<costResult[n]<<endl;

	
} 

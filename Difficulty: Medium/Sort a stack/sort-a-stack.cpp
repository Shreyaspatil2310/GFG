//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends

void SortedStack :: sort()
{
   vector<int>v;
   while(s.empty()==false)
   {
       v.push_back(s.top());
       s.pop();
   }
   std::sort(v.begin(),v.end());
   int n=v.size();
   for(int i=0;i<n;i++)
   {
       s.push(v[i]);
   }
}
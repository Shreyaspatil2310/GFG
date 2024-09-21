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

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
/* The below method sorts the stack s 
you are required to complete the below method */
  void insert_right(int x,stack<int>&s){
    if(s.size()==0 || s.top()<x) 
    {
        s.push(x);
        return;
    }
     int a=s.top();
     s.pop();
     insert_right(x,s);
     s.push(a);
    }
  void reverse(stack<int>&s){
    if(s.size()==0){
        return ;
    }
    
    int x=s.top();
    s.pop();
    reverse(s);
    insert_right(x,s);
   }
   void SortedStack :: sort(){
       reverse(s);
   }
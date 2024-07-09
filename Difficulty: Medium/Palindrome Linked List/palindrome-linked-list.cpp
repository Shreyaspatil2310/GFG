//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution {
public:
    bool isPalindrome(Node* head) {
        Node* slow = head;
        Node* fast = head;
        int len = 0;
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            len++;
        }
        // Get hold of the mid of the linked list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (len % 2 != 0) slow = slow->next;
        Node* secondHlfHead = reverse(slow);
        while (head != nullptr && secondHlfHead != nullptr) {
            if (head->data != secondHlfHead->data) return false;
            head = head->next;
            secondHlfHead = secondHlfHead->next;
        }
        return true;
    }
    
private:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};


//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends
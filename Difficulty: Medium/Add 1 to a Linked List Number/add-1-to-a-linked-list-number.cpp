//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

class Solution
{
    public:
Node* reverse(Node *head){
    Node* prev = NULL;
    Node* curr = head; 
    while(curr!=NULL){
        Node* nxt = curr->next ; 
        curr->next  = prev ;
        prev = curr;
        curr = nxt ; 
    }
    return prev; 
}

Node* addOne(Node *head) {
    head = reverse(head); 
    Node* temp = head ; 
    int carry = 1; // Initial carry is 1 because we are adding 1
    
    while(temp != NULL){
        int totalsum = temp->data + carry; 
        int digit = totalsum % 10 ; 
        carry = totalsum / 10;
        temp->data = digit; 
        // Move to the next node
        if(temp->next == NULL && carry != 0){
            // If we reach the last node and there is still a carry, add a new node
            Node* newnode = new Node(carry);
            temp->next = newnode;
            break;
        }
        
        temp = temp->next ; 
    }
    // Reverse the linked list back to its original order
    head = reverse(head); 
    
    return head; // Return the head of the list after adding one
}


};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
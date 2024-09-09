#include<iostream>
#include<string>

using namespace std;


struct node
{
    int val;
    node* left;
    node* right;

    node(int value)
    {
        val = value;
        left = nullptr;
        right = nullptr;
    }
    node(node*l, int value, node* r = nullptr)
    {
        val = value;
        left = l;
        right = r;
    }
};

int main()
{
    node* head = new node(1);
    head->right = new node(head->right, 2);

    node* temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->val<<endl;
        temp = temp->right;    
    }
}



#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};
class Solution {
public:
    Node* removeDuplicates(Node* head)
    {
        vector<int> v;
        Node* save = head;
        Node* Start = nullptr;
        Node* answer=nullptr;
        while(save!=NULL)
        {
            v.push_back(save->data);
            save=save->next;
        }

        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                if (v[i] == v[j])
                {
                    v.erase(v.begin() + j, v.begin() + j + 1);
                    j--;
                }
            }
        }
        Start = new Node(v[0]);
        answer = new Node(v[0]);
        for (int i = 1; i < v.size(); i++)
        {
            answer=insert(Start, v[i]);
        }
        return answer;
    }

    Node* insert(Node* head, int data)
    {
        Node* p = new Node(data);
        if (head == NULL) {
            head = p;

        }
        else if (head->next == NULL) {
            head->next = p;

        }
        else {
            Node* start = head;
            while (start->next != NULL) {
                start = start->next;
            }
            start->next = p;

        }
        return head;


    }
    void display(Node* head)
    {
        Node* start = head;
        while (start)
        {
            cout << start->data << " ";
            start = start->next;
        }
    }
};

int main()
{
    Node* head = NULL;
    Solution mylist;
    int T, data;
    cin >> T;
    while (T-- > 0) {
        cin >> data;
        head = mylist.insert(head, data);
    }
    head = mylist.removeDuplicates(head);

    mylist.display(head);

}
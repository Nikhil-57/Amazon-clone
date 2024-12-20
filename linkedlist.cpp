#include <iostream>
#include<vector>
using namespace std;

class Node{//here we can use both struct as well class
    public://In struct members are public by default but in class members are private by default so we make public(public:)
    int data; // int data ; Node* next; Node(int data1 , Node* next1); data = data 1;next = next1;
    Node* next;
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    } 
};
Node* ConvertArrToLL(vector<int>arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 0; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
//Search the Element
    int ToCheckIfPresent(Node* head, int val){
        Node* temp = head;
        while(temp != NULL){
            if(temp -> data == val)return 1;
            temp = temp -> next;
        }
        return 0;
    }
    void print(Node* head){
        while(head != NULL){
            cout<< head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    Node* removeshead(Node* head){
        if(head == NULL)return head;
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* removetail(Node* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* temp= head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        
        return head;
    }

    //Removing the k position
    Node* removeK(Node* head, int k){
        if(head == NULL) return head;
        if(k==1){
            Node* temp = head;
            head = head -> next;
            delete(temp);
            return head;
        }
        int cnt = 0;
        Node* temp = head;
        Node* prev = NULL;
        while(temp != NULL){
            cnt++;
            if(cnt == k){
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp -> next;
        }
        return head;
    }

    //Removing the value
    Node* removeElement(Node* head, int el){
        if(head == NULL) return head;
        if(head->data == el){
            Node* temp = head;
            head = head -> next;
            delete(temp);
            return head;
        }
        int cnt = 0;
        Node* temp = head;
        Node* prev = NULL;
        while(temp != NULL){
            cnt++;
            if(cnt == el){
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp -> next;
        }
        return head;
    }

    //Insertion of head
    Node* inserthead(Node* head , int val){
       // Node* temp = new Node(val, head);
       return new Node(val, head); //or we can also write this
       // return temp;
    }

    //Insertion of tail
    Node* inserttail(Node* head, int val){
        if(head == NULL)return new Node(val);

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        Node* newNode = new Node(val);//pointing to NULL
        temp->next = newNode;
        return head;
    }

    //Insert at kth position
    Node* insertposition(Node* head, int k, int el){
        if(head==NULL){
            if(k==1){
                return new Node(el);
            }
            else{
                return head;
            }
        }
        if(k == 1){
           Node* x = new Node(el, head);
           return x;
        }
        int cnt = 0; 
        Node* temp = head;
        while(temp != NULL){
            cnt++;
            if(cnt == (k-1)){
                Node* y = new Node (el, temp->next);
                temp->next = y;
                break;
            }
            temp = temp -> next;
        }
        return head;
    }
    //Insert before value
    Node* insertElbeforeValue(Node* head, int el, int val){
        if(head==NULL){
            return NULL;
        }
        if(head->data == val){
            return new Node(el, head);
        }

        Node* temp = head;
        while(temp->next != NULL){
            if(temp->next->data == val){
                Node* y = new Node (el, temp->next);
                temp->next = y;
                break;
            }
            temp = temp -> next;
        }
        return head;
    }



int main(){
     /*Node* y = new Node{arr[0]};
     Node* x = new Node{arr[3]};
     cout<< y->data;
     cout<< x->data;
     return 0;
     Node* head = ConvertArrToLL(arr);
     cout << head -> data;
     //Traversing the LinkedLisrt
     Node* temp = head;
     while(temp != NULL){
         cout << temp -> data << " ";
         temp = temp -> next;
     }
    
    */
     vector<int> arr = {2, 5, 6, 3};
     Node* head = ConvertArrToLL(arr);
     head = insertposition(head,100,2);
     print(head);
     
}
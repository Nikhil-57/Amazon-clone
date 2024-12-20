#include <iostream>
#include<vector>
using namespace std;

class Node{//here we can use both struct as well class
    public://In struct members are public by default but in class members are private by default so we make public(public:)
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    } 
};

Node* convertArrToDLL(vector<int>arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);//new Node(val, next, prev)
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node* head){
    while(head!=NULL){
        cout << head->data<< " ";
        head = head->next;
    }
}
Node* deleteHead(Node* head){
    if(head==NULL || head->next == NULL) return head;
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL || head->next == NULL) return head;
    Node* tail = head;

    while(tail->next !=NULL){
        tail = tail->next; // we are reaching to the tail
    }
    Node* newTail =  tail->back;
    newTail->next = nullptr;

    tail->back = nullptr;
    delete tail;
    return head;
}

Node* removeElementK(Node* head, int k){
    int cnt = 0;
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        
        temp = temp->next;
        
    }

    Node* front = temp->next;
    Node* prev = temp->back;

    if(prev == NULL){
        return deleteHead(head);
    }
    else if(front == NULL){
        return deleteTail(head);
    }
    else if(prev == NULL && front == NULL){
        return NULL;
    }
    else{ // then this is the k element

        prev->next = front;
        front->back = prev;

        temp->next = nullptr;
        temp->back = nullptr;
        delete temp;
    }
    return head;
}

void deleteNode(Node* head){
    Node* temp = head;
    Node*front = temp->next;
    Node*prev = temp->back;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
    
        free(temp);// OR delete(temp);
        return; /// void funtion
    }

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    free(temp);

}

Node* insertbeforehead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);  // newHead  next to head and back to nullptr
    head->back = newHead;
    //newHead->next = head; // this is not necessary 
    return newHead;
}

Node* insertbeforetail(Node* head, int val){
    if(head->next == NULL){
        return insertbeforehead(head, val);
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}
Node* insertbeforeK_El(Node* head , int val, int k){
    if(k == 1){
        return insertbeforehead(head,val);
    }
    int cnt = 0; 
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        
        temp = temp->next;
    }
    Node* prev = temp->back ;
    Node* Newhead = new Node(val, temp, prev);
    prev->next = Newhead;
    temp->back = Newhead;
    return head;
}

void insertbeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newnode = new Node(val, node, prev);
    prev->next = newnode;
    node->back = newnode;
}

Node* ReverseDLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* prev = NULL;
    Node* current = head;
    while(current != NULL){
        prev = current->back;
        current->back = current->next;
        current->next = prev;

        current = current->back;
    }
    return prev->back;
}
Node* AddTwoNumbers(Node* head, int val1, int val2){
    
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
    }
    Node* prev = temp-> back;
    Node* firstNum = new Node(val1,nullptr,temp);
    Node* secondNum = new Node(val2,nullptr,firstNum);
    temp->next = firstNum;
    temp = firstNum->back;
    firstNum->next = secondNum;

    secondNum->back = firstNum;
    secondNum->next = nullptr;
    return head;
    
}

Node* allTwoLL(Node* num1, Node* num2){
    Node* dummyHead = new Node(-1);
    Node* curr = dummyHead;
    Node* temp1 = num1;
    Node* temp2 = num2;
    int carry = 0;
    while(temp1 != NULL || temp2 != NULL){
        int sum = carry;
        if(temp1) sum += temp1->data;
        if(temp2) sum += temp2->data;
        Node* newNode = new Node(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyHead->next;
}

int main(){
    vector<int>arr = {12, 5, 7, 8};
    vector<int>arr1 = {12, 9, 9, 9};
    Node* head1 = convertArrToDLL(arr);
    Node* head2 = convertArrToDLL(arr1);
    head1 = allTwoLL(head1, head2); 
    print(head1);
    return 0;
}
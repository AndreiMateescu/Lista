#include <iostream>

using namespace std;


class Node{
    int val;
    Node* next;
public:
    Node(int v, Node *p=0): val(v), next(p){}
    ~Node() {next = 0;}
    int Val() const {return val;}
    void Print() const {cout<<val<<endl;}

    friend class List;
    friend class ListIterator;
};

class List{
    Node *first;
    void Copy(Node *p);

    void Delete(){
        Node *p;
        Node *q;
        p = first;
        while(p != NULL){
            p = p->next;
            q = p;
            delete q;
        }
    };
public:
    List() {first = 0;}
    List(List& l):first(0) { Copy(l.first); }
    ~List() { Delete(); first = 0;}

    void Add(int k){
        Node *p = new Node(k);
        p->next = first;
        first = p;
    }
    friend class ListIterator;
};

class ListIterator{
    List l;
    Node *current;
public:
    ListIterator(List& l1):l(l1),current(l.first) {}
    Node *operator->() const {return current;}
    Node *operator++() {
        current = current->next;
        return current;
    }
    Node *operator++(int){
        Node *p = current;
        current = current ->next;
        return p;
    }
    void BeginIterator(){
        current = l.first;
    }
};
int main()
{
    List l;
    l.Add(3);
    l.Add(7);
    l.Add(5);

    ListIterator it(l);
    return 0;
}

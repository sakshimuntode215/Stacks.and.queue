#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node*next;

    node(int x){
        data=x;
        next=NULL;
    }
};

class stack{
    private:
    node*top;
    public:
    stack(){
        top=NULL;
    }

    int empty(){
        if(top==NULL){
            return 1;
        }else{

            return 0;
        }
    }
    void push(int x){
        node*p=new node(x);
        p->next=top;
        top=p;
    }

    int pop(void){
        int x=top->data;
        node*p=top;
        top=top->next;
        delete p;
        return x;
    }

    int peek(){
        return top->data;
    }

    void display(){
        node*q=top;
        while(q!=NULL){
            cout<<endl<<q->data;
            q=q->next;
        }
    }
};

int main(){
    int x;
    stack s;

    s.push(340);
    s.push(550);
    s.push(610);
    s.push(789);
    s.push(567);
    s.push(489);

    s.display();

    if(!s.empty()){
        x=s.pop();
        cout<<endl<<"Removed"<<x;

    }

    s.display();

    x=s.peek();
    cout<<endl<<"Top Element is:"<<x;

    return 0;

}


/*
PS D:\sakshi muntode 215> cd "d:\sakshi muntode 215\" ; if ($?) { g++ stackusinglinkedlist.cpp -o stackusinglinkedlist } ; if ($?) { .\stackusinglinkedlist }

489
567
789
610
550
340
Removed489
567
789
610
550
340
Top Element is:567
PS D:\sakshi muntode 215> 


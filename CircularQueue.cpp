#include<iostream>
#include<cassert>

using namespace std;

template<class type>
class C_Queue{
    private:
    type *elements;
    int rear;
    int front;
    int size;
    int counter;
    public:
    C_Queue(int size)
    {
        elements=new type[size];
        this->size=size;
        rear=front=-1;
        counter=0;
    }
    bool IsFull(){return (counter==size);}
    bool IsEmpty(){return (counter==0);}

    int GetSize(){return size;}

    void Enqueue(type e)
    {
        if (IsFull())
        {
            cout<<"Queue is full.."<<endl;assert(0);
        }

        // if(rear==size-1){
        //     rear=0;
        // }
        // else
        // {
        //     rear++;
        //     elements[rear]=e;
        // }
        rear=(rear+1)%size; //-> this statement equal (if else)statments  
        elements[rear]=e;
        counter++;


    }

    type Dequeue()
    {
        if(IsEmpty())
        {
            cout<<"Queue is empty"<<endl;assert(0);
        }
        front=(front+1)%size;
        counter--;
        return elements[front];

    }
    type Getfront() {return Dequeue();}

    void print()
    {
        for(int i=0;i<counter;i++)
            cout<<elements[i]<<" ";

    }
  
};
int main()
{
C_Queue<int> q(3);
q.Enqueue(4);
q.Enqueue(8);
q.Enqueue(12);
q.print();cout<<endl;
cout<<q.Dequeue()<<endl;
cout<<q.Dequeue()<<endl;
cout<<q.Dequeue()<<endl;
q.Enqueue(16);
q.Enqueue(16);
q.print();
}
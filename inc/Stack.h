#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H
#include <iostream>

template <class Type>
struct Node
{
	Type data;
	Node *next;
};

template <class Type>
class Stack;

template <class Type>
std::ostream& operator<<(std::ostream&, const Stack<Type>& stack);


template <class Type>
class Stack
{
public:
	Stack();
	Stack(const Stack& other);
	Stack<Type>& operator=(const Stack<Type>& other);
	~Stack();

        int size() const;
        bool empty() const;
	Type top() const;
	void push(const Type&);
	void pop();
        void pop(int);
        Type topPop();
        void clear();
        friend std::ostream& operator<< <>(std::ostream&, const Stack<Type>& list);

protected:
    Node<Type>* front;                                   //the essentials, used in the last few assignments on linkedLists
    Node<Type>* back;
    int count;
};

template <class Type>
Stack<Type>::Stack()
{
    front = nullptr;                                                       //default constructor, initializes to nullptr's and count = 0
    back = nullptr;
    count = 0;
}

template <class Type>
Stack<Type>::Stack(const Stack<Type>& other)              //copy constructor is a modification of the << operator overload
{
    this->count = 0;
    front = nullptr;
    back = nullptr;
    int loopCounter = 0;

    int backCount = other.count;


    while(backCount != 0)                         //while current node exists
    {
        auto currentNode = other.front;
        for (int i = 0; i < backCount - 1; i++)              //increment the list
        {
            currentNode = currentNode->next;
        }
        Node <Type>* temp = new Node <Type>();                              //create the new node
        temp->data = currentNode->data;
        this->push(temp->data);                                          //use  push to insert the copied node


        backCount--;                                      //incrementing it down

        /*
       {
           currentNode = currentNode->next;
       }
        out << currentNode->data;                //adds the currentNode's data to the outstream
        if (currentNode->next)                    //if currentNode->next exists
        {
            out << "->";                          //adds the arrow as specified in between each data member of ostream
        }
        currentNode = currentNode->next; */         //cycle to the next node
    }


    /*

    auto currentNode = other.front;
    while(currentNode && loopCounter < other.count)                           //while current node exists and loopcounter is less than count, helps catch the back
    {
        Node <Type>* temp = new Node <Type>();                              //create the new node
        temp->data = currentNode->data;
        this->push(temp->data);                                          //use  push to insert the copied node

        currentNode = currentNode->next;
        loopCounter++;
    }   */
}

template <class Type>
Stack<Type>& Stack<Type>::operator=(const Stack& other)
{
    this->clear();                                 //clears the list so it can copy the other linkedlist
    this->count = 0;
    front = nullptr;
    back = nullptr;
    int loopCounter = 0;

    int backCount = other.count;


    while(backCount != 0)                         //while current node exists
    {
        auto currentNode = other.front;
        for (int i = 0; i < backCount - 1; i++)              //increment the list
        {
            currentNode = currentNode->next;
        }
        Node <Type>* temp = new Node <Type>();                              //create the new node
        temp->data = currentNode->data;
        this->push(temp->data);                                          //use  push to insert the copied node


        backCount--;                                      //incrementing it down

        /*
       {
           currentNode = currentNode->next;
       }
        out << currentNode->data;                //adds the currentNode's data to the outstream
        if (currentNode->next)                    //if currentNode->next exists
        {
            out << "->";                          //adds the arrow as specified in between each data member of ostream
        }
        currentNode = currentNode->next; */         //cycle to the next node
    }


    /*

    auto currentNode = other.front;
    while(currentNode && loopCounter < other.count)                           //while current node exists and loopcounter is less than count, helps catch the back
    {
        Node <Type>* temp = new Node <Type>();                              //create the new node
        temp->data = currentNode->data;
        this->push(temp->data);                                          //use  push to insert the copied node

        currentNode = currentNode->next;
        loopCounter++;
    }   */
return *this;
}

template <class Type>
Stack<Type>::~Stack()
{
    Node<Type>* temp = front;        //copied the destructor from the learning activity from module 3, essentially the same as clear
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <class Type>
int Stack<Type>::size() const
{
return count;
}

template <class Type>
bool Stack<Type>::empty() const
{
if (count == 0)
{
    return true;                                   // checks if count is not 0, means the stack is not empty
}
else
{
    return false;
}
}

template <class Type>
Type Stack<Type>::top() const
{
   if (count > 0)
   {
       Type ret = this->front->data;
       return ret;
   }
   else
   {
       throw std::logic_error("Stack is empty");
   }

}

template <class Type>
void Stack<Type>::push(const Type& item)
{
    Node<Type>* temp = new Node <Type>();
    temp->data = item;

    if (count == 0)                                   //checks if the stack is empty
    {
        this->front = temp;
        this->back = temp;                            //establishes this node as the front and back since the linkedlist is empty in this case
        temp->next = nullptr;

    }
    else                                              //adding items onto the stack when it's not empty
    {
        temp->next = this->front;                    //adds the node to the top of the stack, front/head
        this->front = temp;

    }
    count++;
}

template <class Type>
void Stack<Type>::pop()
{
    if (count == 0)
    {
        return;                          //checks if it is empty, returns if true
    }
    if (count == 1)                      //check if there is only one member inside of the list
    {
        Node<Type>* temp = front;
        this->front = nullptr;
        this->back = nullptr;
        delete temp;                    //pops the only member that was in the stack
        count--;
    }
    else                              //if there is more than one member inside of the stack
    {
        Node<Type>* temp = front;
        this->front = front->next;
        delete temp;                 //pops front member of the linkedlist
        count--;
    }
}

template <class Type>
void Stack<Type>::pop(int count)
{
     for (int i = 0; i < count; i++)                 //loop that calls pop however many times based on count
     {
         this->pop();                               //calls pop function for this stack, removes top of the stack once each iteration
     }


}

template <class Type>
Type Stack<Type>::topPop()
{
    if (count == 0)
    {
        throw std::logic_error("nothing to pop");                          //checks if it is empty, returns if true
    }
    if (count == 1)                      //check if there is only one member inside of the list
    {
        Node<Type>* temp = front;
        auto ret = front->data;
        this->front = nullptr;
        this->back = nullptr;
        delete temp;                    //pops the only member that was in the stack
        count--;
        return ret;
    }
    else                              //if there is more than one member inside of the stack
    {
        Node<Type>* temp = front;
        auto ret = front->data;
        this->front = front->next;
        delete temp;                 //pops front member of the linkedlist
        count--;
        return ret;
    }
    //Type ret;
   //return ret;
}

template <class Type>
void Stack<Type>::clear()
{
    Node<Type>* temp = front;
    while (front != nullptr)              //while the front does not equal null
    {
        temp = front;
        front = front->next;              //deleting that node
        delete temp;
    }
    count = 0;
}

template <class Type>
std::ostream& operator<<(std::ostream& out, const Stack<Type>& list)
{

    int backCount = list.count;
    if (list.count == 1)                                 //checks if there is only one node in the linkedList
    {
        auto currentNode = list.front;
        out << currentNode->data;
        return out;                                      //returns out, stops this function
    }
    while(backCount != 0)                         //while current node exists
    {
        auto currentNode = list.front;
        for (int i = 0; i < backCount - 1; i++)              //increment the list
        {
            currentNode = currentNode->next;
        }
        out << currentNode->data;                           //send the data to the ostream
        if (backCount != 1)                                 //check if we need to add the -> to the ostream
        {
            out << "->";
        }
        backCount--;                                      //incrementing it down

        /*
       {
           currentNode = currentNode->next;
       }
        out << currentNode->data;                //adds the currentNode's data to the outstream
        if (currentNode->next)                    //if currentNode->next exists
        {
            out << "->";                          //adds the arrow as specified in between each data member of ostream
        }
        currentNode = currentNode->next; */         //cycle to the next node
    }
    return out;
}
#endif

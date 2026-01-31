/////////////////////////////////////////
//Generalized Data Structure Library
/////////////////////////////////////////

/*
--------------------------------------------------------------------------------------------
Type                     Name of class for node             Name of class for Funtionality
--------------------------------------------------------------------------------------------
Singly Linear            SinglyLLLnode                           SinglyLLL              Done
Singly Circular          SinglyCLLnode                           SinglyCLL              Done
Doubly Linear            DoublyLLLnode                           DoublyLLL              Done
Doubly Circular          DoublyCLLnode                           DoublyCLL              Done
Stack                    Stacknode                               Stack                  Done
Queue                    Queuenode                               Queue
--------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////
//              Singly Linear LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data=no;
            this->next=NULL;
        }
};

template<class T>
class SinglyLLL
{
private:        
    SinglyLLLnode<T> * first;
    int iCount;

public:
    SinglyLLL();
    void InsertFirst(T);       
    void InsertLast(T);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T,int);
    void DeleteAtPos(int);
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout <<"Objet of singlyLL gets created\n";
    this->first = NULL;
    this->iCount = 0;
}   

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertFirst
//  Input :                 Data of node
//  Output :                Nothing
//  Description :           Used to insert node at first position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)        
{
    SinglyLLLnode<T> * newn = NULL;
    newn = new SinglyLLLnode<T>(no);
    
    newn -> next = this->first;
    this->first = newn;
    
    this->iCount++;

}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertLast
//  Input :                 Data of node
//  Output :                Nothing
//  Description :           Used to insert node at last position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode <T>* newn = NULL;
    newn = new SinglyLLLnode<T>(no);

    SinglyLLLnode <T> * temp = this->first;
    
    if(this->iCount == 0)     
    {
        this->first = newn;
    }
    else
    {
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteFirst
//  Input :                 Data of node
//  Output :                Nothing
//  Description :           Used to delete node at first position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode <T>* temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first -> next == NULL)      
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteLast
//  Input :                 Data of node
//  Output :                Nothing
//  Description :           Used to delete node at last position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode <T>* temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first -> next == NULL)      
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
            delete temp -> next;
            temp -> next = NULL;
        
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Display
//  Input :                 Nothing
//  Output :                Displays all elements
//  Description :           Used to traverses the list from first to last 
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode <T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt  <= this->iCount; iCnt++)      
    {
        cout << "| " << temp -> data << "|->  ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Count
//  Input :                 Nothing
//  Output :                Integer
//  Description :           Returns number of nodes in list
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertAtPos
//  Input :                 Data of node, position
//  Output :                Nothing
//  Description :           Used to insert a node at the specified position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
//////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL <T> :: InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * newn = NULL;
    newn = new SinglyLLLnode<T>(no);

if(pos < 1 || pos > this->iCount + 1)
{
    cout<<"Invalid Position.\n";
    return;
}
if(pos == 1)
{
    this->InsertFirst(no);
}
else if(pos == this->iCount + 1)
{
    this->InsertLast(no);
}
else
{
    SinglyLLLnode<T>* temp = this->first;

    for(int i = 0; i < pos - 1; i++)
    {
        temp = temp -> next;
    }
        newn ->next = temp ->next;
        temp ->next = newn;
        this->iCount++;
}
}

//////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteAtPos
//  Input :                 Data of position
//  Output :                Nothing
//  Description :           Used to delete a node at the specified position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
//////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid Position.\n";
        return;
    }
    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
    SinglyLLLnode<T>* temp = this->first;
    SinglyLLLnode<T>* target = NULL;

    for(int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    target = temp->next;
    temp->next = target->next;
    delete target;
    this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////
//              Doubly Linear LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private:   
        DoublyLLLnode <T> *first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template <class T>
DoublyLLL <T> :: DoublyLLL()
{
    cout<<"Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertFirst
//  Input :                 Data of node
//  Output :                Nothing
//  Description :           Used to insert node at first position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next=this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertLast
//  Input :                 Data of node
//  Output :                Nothing
//  Description :           Used to insert node at last position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode <T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {   
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp ->next = newn;
        newn ->prev = temp;
    }
    this->iCount++;  
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertAtPos
//  Input :                 Data of node, position
//  Output :                Nothing
//  Description :           Used to insert node at specified position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T> :: InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);
        temp = this->first;

        for(iCnt=1; iCnt<pos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteFirst
//  Input :                 Nothing
//  Output :                Nothing
//  Description :           Used to delete node from list
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T> ::  DeleteFirst()
{

    if(this->first == NULL)     //LL is empty (type 1)
    {
        return;
    }
    else if(this->first->next == NULL)       //LL contains 1 node(type 2)
    {
        delete this->first;
        this->first = NULL;
    }
    else        //LL contains more than 1 node(type 3)
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteLast
//  Input :                 Nothing
//  Output :                Nothing
//  Description :           Used to delete node from list
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T> :: DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)     //LL is empty (type 1)
    {
        return;
    }
    else if(this->first->next == NULL)       //LL contains 1 node(type 2)
    {
        delete this->first;
        this->first = NULL;
    }
    else        //LL contains more than 1 node(type 3)
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--; 
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteAtPos
//  Input :                 Data of position
//  Output :                Nothing
//  Description :           Used to delete node at specified position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt=1; iCnt<pos - 1; iCnt++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Display
//  Input :                 Nothing
//  Output :                Displays all elements
//  Description :           Used to traverses the list from first to last 
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL <T> :: Display()
{
    DoublyLLLnode<T> *temp = NULL;
    temp = this->first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Count
//  Input :                 Nothing
//  Output :                Integer
//  Description :           Used to returns number of nodes in list
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL <T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////
//            Singly Circular LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyCLLnode 
{
    public:
        T data;
        SinglyCLLnode<T> *next;

    SinglyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T>  *  first;
        SinglyCLLnode<T>  * last;
        int iCount;

    public:
        SinglyCLL(); 

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template <class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout <<" SinglyCLL gets created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}   

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertFirst
//  Input :                 Data of node
//  Output :                Nothing
//  Description :           Used to insert node at first position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL <T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = new SinglyCLLnode<T> (no);

    if(this->first == NULL)
    {
        this -> first = this -> last = newn;
        this-> last -> next = this -> first;
    }
    else
    {
        newn -> next = this -> first;
        this -> first = newn;
        this -> last -> next = this -> first;
    }
    this -> iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertLast
//  Input :                 Data of node
//  Output :                Nothing
//  Description :           Used to insert node at last position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL <T> :: InsertLast(T no)
{
    SinglyCLLnode<T> * newn = new SinglyCLLnode<T>(no);

    if(this -> first == NULL)
    {
        this -> first = this -> last = newn;
        this -> last -> next = this -> first;
    }
    else
    {
        this -> last -> next = newn;
        this -> last = newn;
        this -> last -> next = this ->first;
    }
    this -> iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertAtPos
//  Input :                 Data of node, position
//  Output :                Nothing
//  Description :           Used to insert node at specified position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL <T> :: InsertAtPos(T no, int pos)
{
    
if(pos < 1 || pos > this->iCount + 1)
{
    return;
}

if(pos == 1)
{
    this->InsertFirst(no);
}
else if(pos == this->iCount + 1)
{
    this->InsertLast(no);
}
else
{
    SinglyCLLnode<T> * newn = new SinglyCLLnode<T>(no);
    newn->data = no;

    SinglyCLLnode<T> * temp = this->first;
    for(int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newn->next = temp->next;
    temp->next = newn;
    this->iCount++;
}
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteFirst
//  Input :                 Nothing
//  Output :                Nothing
//  Description :           Used to delete first node from list
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL <T> :: DeleteFirst()
{
    if(this->first == NULL)
    {
        return;
    }
    else if(this->first == this -> last)
    {
        delete this -> first;
        this -> first = this -> last = NULL;
    }   
    else
    {
        SinglyCLLnode<T> * temp = this -> first;
        this -> first = this -> first -> next;
        delete temp;
        this -> last -> next = this -> first;
    }
    this -> iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteLast
//  Input :                 Nothing
//  Output :                Nothing
//  Description :           Used to delete last node from list
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T> :: DeleteLast()
{
    if(this -> first == NULL)
    {
        return;
    }
    else
    {
        SinglyCLLnode<T> * temp = this -> first;
        while(temp->next != this-> last)
        {
            temp = temp -> next;
        }
        delete this->last;
        this->last=temp;
        this->last->next=this->first;
    }
    this -> iCount--;

}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteAtPos
//  Input :                 Position
//  Output :                Nothing
//  Description :           Used to delete node at specified position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL <T> :: DeleteAtPos(int pos)
{

if(pos < 1 || pos > this->iCount)
{
    return;
}

if(pos == 1)
{
    this->DeleteFirst();
}
else if(pos == this->iCount)
{
    this->DeleteLast();
}
else
{
    SinglyCLLnode<T>* temp = this->first;
    for(int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    SinglyCLLnode<T>* targ = temp->next;
    temp->next = targ->next;
    delete targ;
    this->iCount--;
}
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Display
//  Input :                 Position
//  Output :                Display all nodes of list
//  Description :           Used to display the list
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL <T> :: Display()
{
if(this->first == NULL)
{
    return;
}

SinglyCLLnode<T>* temp = this->first;
cout << "<=> ";
do
{
    cout << temp->data << " <=> ";
    temp = temp->next;
} while(temp != this->first);
cout << "NULL\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Count
//  Input :                 Nothing
//  Output :                Integer
//  Description :           Used to return numbers from list
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////
//            Doubly Circular LinkedList using Generic Approach
///////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

    DoublyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyCLL
{
private:
    DoublyCLLnode<T> * first;
    DoublyCLLnode<T> * last;
    int iCount;

public:
    DoublyCLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};

template <class T>
DoublyCLL <T> :: DoublyCLL()
{
cout << "DoublyCLL gets created\n";
this->first = NULL;
this->last = NULL;
this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertFirst
//  Input :                 Data of node
//  Output :                Nothing
//  Description :           Used to insert node at first position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL <T> :: InsertFirst(T no)
{

DoublyCLLnode<T> * newn = new DoublyCLLnode<T> (no);

if(this->first == NULL)
{
    this->first = this->last = newn;
    newn->next = newn;
    newn->prev = newn;
}
else
{
    newn->next = this->first;
    newn->prev = this->last;

    this->first->prev = newn;
    this->last->next = newn;

    this->first = newn;
}
this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertLast
//  Input :                 Data of node
//  Output :                Nothing
//  Description :           Used to insert node at last position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL <T> ::InsertLast(T no)
{
DoublyCLLnode<T>* newn = new DoublyCLLnode<T>(no);

if(this->first == NULL)
{
    this->first = this->last = newn;
    newn->next = newn;
    newn->prev = newn;
}
else
{
    newn->next = this->first;
    newn->prev = this->last;

    this->last->next = newn;
    this->first->prev = newn;

    this->last = newn;
}
this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         InsertAtPos
//  Input :                 Data of node, position
//  Output :                Nothing
//  Description :           Used to insert node at specified position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL <T> :: InsertAtPos(T no, int pos)
{
if(pos < 1 || pos > this->iCount + 1)
{
    return;
}

if(pos == 1)
{
    this->InsertFirst(no);
}
else if(pos == this->iCount + 1)
{
    this->InsertLast(no);
}
else
{
    DoublyCLLnode<T>* newn = new DoublyCLLnode<T>(no);
    newn->data = no;

    DoublyCLLnode<T>* temp = this->first;
    for(int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newn->next = temp->next;
    newn->prev = temp;

    temp->next->prev = newn;
    temp->next = newn;

    this->iCount++;
}
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteFirst
//  Input :                 Data of node
//  Output :                Nothing
//  Description :           Used to delete node at first position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL <T> :: DeleteFirst()
{
if(this->first == NULL)
{
    return;
}
else if(this->first == this->last)
{
    delete this->first;
    this->first = this->last = NULL;
}
else
{
    DoublyCLLnode<T> * temp = this->first;

    this->first = this->first->next;
    this->first->prev = this->last;
    this->last->next = this->first;

    delete temp;
}
this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteLast
//  Input :                 Nothing
//  Output :                Nothing
//  Description :           Used to delete node at last position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL <T> :: DeleteLast()
{
if(this->first == NULL)
{
    return;
}
else if(this->first == this->last)
{
    delete this->first;
    this->first = this->last = NULL;
}
else
{
    DoublyCLLnode<T> * temp = this->last;

    while(temp->next != this-> last)
    {
        temp = temp -> next;
    }

    this->last = this->last->prev;
    this->last->next = this->first;
    this->first->prev = this->last;

    delete temp;
}
this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         DeleteAtPos
//  Input :                 Position
//  Output :                Nothing
//  Description :           Used to delete node at specified position
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL <T> :: DeleteAtPos(int pos)
{
if(pos < 1 || pos > this->iCount)
{
    return;
}

if(pos == 1)
{
    this->DeleteFirst();
}
else if(pos == this->iCount)
{
    this->DeleteLast();
}
else
{
    DoublyCLLnode<T> * temp = this->first;
    for(int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    this->iCount--;
}
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Display
//  Input :                 Nothing
//  Output :                display all nodes from list
//  Description :           Used to display the nodes
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL <T> :: Display()
{
if(this->first == NULL)
{
    return;
}

DoublyCLLnode<T>* temp = this->first;
cout << "<=> ";
do
{
    cout << temp->data << " <=> ";
    temp = temp->next;
} while(temp != this->first);
cout << "(First)\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :         Count
//  Input :                 Nothing
//  Output :                Integer
//  Description :           Used to returns number of nodes in list
//  Author :                Akshata Dhananjay Deole
//  Date :                  06/01/2026       
//
////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCLL <T> :: Count()
{
return this->iCount;
}

///////////////////////////////////////////////////////////////////
//              Stack using Generic Approach
///////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Stacknode
{
    public:
        T data;
        Stacknode *next;

        Stacknode(T no)
        {
            this->data= no;
            this->next= NULL;
        }

};

template <class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();

        void push(T);     
        T pop();          
        T peep();
        void Display();
        int Count();
};

template <class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets created successfully...\n";

    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> *newn = NULL;
    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template <class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return Value;
}

template <class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;
    return Value;
}

template <class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

template <class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////// End of Library /////////////////////////////////////////
int main()
{
    SinglyLLL<int> *obj = new SinglyLLL<int>();

    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    iRet = obj->Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    obj->DeleteFirst();

    obj->Display();
    iRet = obj->Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    obj->DeleteLast();

    obj->Display();
    iRet = obj->Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    obj->InsertAtPos(105,4);

    obj->Display();
    iRet = obj->Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    obj->DeleteAtPos(4);

    
    obj->Display();
    iRet = obj->Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    delete obj;

    ////////////////////////////////////////////////////////////////////////////

    DoublyLLL <char> *cobj = new DoublyLLL <char>();

    cobj->InsertFirst('A');
    cobj->InsertFirst('B');
    cobj->InsertFirst('C');

    cobj->Display();

    cout<<"Number of elements are:"<<cobj->Count()<<"\n";

    cobj->InsertLast('X');
    cobj->InsertLast('Y');
    cobj->InsertLast('Z');

    cobj->Display();

    cout<<"Number of elements are :"<<cobj->Count()<<"\n";

    cobj->DeleteFirst();

    cobj->Display();

    cout<<"Number of elements are :"<<cobj->Count()<<"\n";

    cobj->DeleteLast();

    cobj->Display();

    cout<<"Number of elements are :"<<cobj->Count()<<"\n";

    cobj->InsertAtPos('$',4);

    cobj->Display();

    cout<<"Number of elements are :"<<cobj->Count()<<"\n";

    cobj->DeleteAtPos(4);

    cobj->Display();

    cout<<"Number of elements are :"<<cobj->Count()<<"\n";

    delete cobj;

    ////////////////////////////////////////////////////////////////////////////
    
    SinglyCLL<float> *fobj = new SinglyCLL<float>();
    int fRet = 0;

    fobj ->InsertFirst(100.1);
    fobj ->InsertFirst(200.2);
    fobj ->InsertFirst(300.3);

    fobj ->Display();
    fRet = fobj ->Count();

    cout<<"Number of nodes are :" <<fRet<<"\n";

    fobj ->InsertLast(400.4);
    fobj ->InsertLast(500.5);
    fobj ->InsertLast(600.6);

    fobj ->Display();
    fRet = fobj ->Count();

    cout<<"Number of nodes are :" <<fRet<<"\n";

    fobj ->InsertAtPos(450.4,4);

    fobj ->Display();
    fRet = fobj ->Count();

    cout<<"Number of nodes are :" <<fRet<<"\n";

    fobj ->DeleteFirst();

    fobj ->Display();
    fRet = fobj ->Count();

    cout<<"Number of nodes are :" <<fRet<<"\n";

    fobj ->DeleteLast();

    fobj ->Display();
    fRet = fobj ->Count();

    cout<<"Number of nodes are :" <<fRet<<"\n";

    fobj ->DeleteAtPos(4);

    
    fobj ->Display();
    fRet = fobj ->Count();

    cout<<"Number of nodes are :" <<fRet<<"\n";

    delete fobj;

    ////////////////////////////////////////////////////////////////////////////

    DoublyCLL <double> *dobj = new DoublyCLL<double>();
    int dRet = 0;

    dobj->InsertFirst(120.56789);
    dobj->InsertFirst(240.45678);
    dobj->InsertFirst(360.78246);

    dobj->Display();
    cout << "Number of nodes are : " << dobj->Count() << "\n";

    dobj->InsertLast(480.23456);
    dobj->InsertLast(600.67389);
    dobj->InsertLast(720.45367);

    dobj->Display();
    cout << "Number of nodes are : " << dobj->Count() << "\n";

    dobj->InsertAtPos(500.78390,4);

    dobj->Display();
    cout << "Number of nodes are : " << dobj->Count() << "\n";

    dobj->DeleteFirst();

    dobj->Display();
    cout << "Number of nodes are : " << dobj->Count() << "\n";

    dobj->DeleteLast();

    dobj->Display();
    cout << "Number of nodes are : " << dobj->Count() << "\n";

    dobj->DeleteAtPos(4);
    
    dobj->Display();
    cout << "Number of nodes are : " << dobj->Count() << "\n";
    
    delete dobj;

    ////////////////////////////////////////////////////////////////////////////

    Stack<char> *sobj = new Stack<char>();

    sobj->push('a');
    sobj->push('b');
    sobj->push('c');
    sobj->push('d');

    sobj->Display();

    cout<<"Numbers of elements in stack are: "<<sobj->Count()<<"\n";

    cout<<"Return value of peep is :"<<sobj->peep()<<"\n";

    sobj->Display();

    cout<<"Numbers of elements in stack are: "<<sobj->Count()<<"\n";

    cout<<"Poped element is :"<<sobj->pop()<<"\n";

    sobj->Display();

    cout<<"Numbers of elements in stack are: "<<sobj->Count()<<"\n";

    cout<<"Poped element is :"<<sobj->pop()<<"\n";

    sobj->Display();

    cout<<"Numbers of elements in stack are: "<<sobj->Count()<<"\n";

    sobj->push('e');

    sobj->Display();

    cout<<"Numbers of elements in stack are: "<<sobj->Count()<<"\n";

    delete sobj;

    ////////////////////////////////////////////////////////////////////////////

    return 0;
}
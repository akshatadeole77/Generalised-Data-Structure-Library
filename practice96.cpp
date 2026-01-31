/////////////////////////////////////////
//Generalized Data Structure Library
/////////////////////////////////////////

/*
--------------------------------------------------------------------------------------------
Type                     Name of class for node             Name of class for Funtionality
--------------------------------------------------------------------------------------------
Singly Linear            SinglyLLLnode                           SinglyLLL
Singly Circular          SinglyCLLnode                           SinglyCLL
Doubly Linear            DoublyLLLnode                           DoublyLLL
Doubly Circular          DoublyCLLnode                           DoublyCLL
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

    DoublyLLL <char> *dobj = new DoublyLLL <char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();

    cout<<"Number of elements are:"<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();

    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    dobj->DeleteFirst();

    dobj->Display();

    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    dobj->DeleteLast();

    dobj->Display();

    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$',4);

    dobj->Display();

    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);

    dobj->Display();

    cout<<"Number of elements are :"<<dobj->Count()<<"\n";

    delete dobj;

    ////////////////////////////////////////////////////////////////////////////
    
    SinglyCLL<float> *obj = new SinglyCLL<float>();
    int iRet = 0;

    obj->InsertFirst(100.1);
    obj->InsertFirst(200.2);
    obj->InsertFirst(300.3);

    obj->Display();
    iRet = obj->Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    obj->InsertLast(400.4);
    obj->InsertLast(500.5);
    obj->InsertLast(600.6);

    obj->Display();
    iRet = obj->Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    obj->InsertAtPos(450.4,4);

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

    obj->DeleteAtPos(4);

    
    obj->Display();
    iRet = obj->Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    delete obj;

    ////////////////////////////////////////////////////////////////////////////

    DoublyCLL <double> *obj = new DoublyCLL<double>();
    int iRet = 0;

    obj->InsertFirst(120.56789);
    obj->InsertFirst(240.45678);
    obj->InsertFirst(360.78246);

    obj->Display();
    cout << "Number of nodes are : " << obj->Count() << "\n";

    obj->InsertLast(480.23456);
    obj->InsertLast(600.67389);
    obj->InsertLast(720.45367);

    obj->Display();
    cout << "Number of nodes are : " << obj->Count() << "\n";

    obj->InsertAtPos(500.78390,4);

    obj->Display();
    cout << "Number of nodes are : " << obj->Count() << "\n";

    obj->DeleteFirst();

    obj->Display();
    cout << "Number of nodes are : " << obj->Count() << "\n";

    obj->DeleteLast();

    obj->Display();
    cout << "Number of nodes are : " << obj->Count() << "\n";

    obj->DeleteAtPos(4);
    
    obj->Display();
    cout << "Number of nodes are : " << obj->Count() << "\n";
    
    delete obj;

    return 0;
}


#include<iostream>
using namespace std;

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

template <class T>
int DoublyCLL <T> :: Count()
{
return this->iCount;
}


int main()
{
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
    return 0;
}

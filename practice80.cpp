//Singly Circular

#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        SinglyCL()
        {
            cout <<"Objet of singlyCL gets created\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }   

        void InsertFirst(int no)
        {
            PNODE newn = new NODE;
            newn -> data = no;
            newn -> next = NULL;

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

        void InsertLast(int no)
        {
            PNODE newn = new NODE;
            newn -> data = no;
            newn -> next = NULL;

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

        void InsertAtPos(int no, int pos)
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
            PNODE newn = new NODE;
            newn->data = no;

            PNODE temp = this->first;
            for(int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next = newn;
            this->iCount++;
        }
        }

        void DeleteFirst()
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
                PNODE temp = this -> first;
                this -> first = this -> first -> next;
                delete temp;
                this -> last -> next = this -> first;
            }
            this -> iCount--;
        }

        void DeleteLast()
        {
            if(this -> first == NULL)
            {
                return;
            }
            else
            {
                PNODE temp = this -> first;
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

        void DeleteAtPos(int pos)
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
            PNODE temp = this->first;
            for(int i = 1; i < pos - 1; i++)
            {
                temp = temp->next;
            }

            PNODE targ = temp->next;
            temp->next = targ->next;
            delete targ;
            this->iCount--;
        }
        }

        void Display()
        {
        if(this->first == NULL)
        {
            return;
        }

        PNODE temp = this->first;
        cout << "<=> ";
        do
        {
            cout << temp->data << " <=> ";
            temp = temp->next;
        } while(temp != this->first);
        cout << "NULL\n";
        }

        int Count()
        {
            return this->iCount;
        }
};


int main()
{   
    SinglyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    obj.InsertAtPos(105,4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    obj.DeleteAtPos(4);

    
    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";
    return 0;
}

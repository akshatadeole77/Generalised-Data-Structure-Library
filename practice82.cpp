//Doubly Linear

#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        DoublyLL()
        {
            cout <<"Objet of  DoublyLL gets created\n";
            this->first = NULL;
            this->iCount = 0;
        }   

        void InsertFirst(int no)
        {
            PNODE newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;
            newn -> prev = NULL;

            if(this->first == NULL)
            {
                this->first = newn;
            }
            else
            {
                newn -> next = this->first;
                this->first -> prev = newn;
                this->first = newn;
            }
            this->iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;
            newn -> prev = NULL;

            if(this->first == NULL)
            {
                this->first = newn;
            }
            else
            {
               PNODE temp = this->first;
               while(temp->next != NULL)
               {
                temp = temp -> next;
               }
               temp -> next = newn;
               newn -> prev = temp;
            }
            this->iCount++;
        }

        void InsertAtPos(int no, int pos)
        {
           int iCnt = 0;
           if(pos < 1 || pos > iCount + 1)
           {
            return;
           } 

           if(pos == 1)
           {
            InsertFirst(no);
           }
           else if(pos == iCount + 1)
           {
            InsertLast(no);
           }
           else
           {
            PNODE newn = new NODE;
            newn -> data = no;

            PNODE temp = this->first;
            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp -> next;
            }
            newn -> next = temp -> next;
            newn -> prev = temp;
            temp -> next -> prev = newn;
            temp -> next = newn;

            this->iCount++;
           }
        }

        void DeleteFirst()
        {
            if(this->first == NULL)
            {
                return;
            }
            else if(this->first -> next ==  NULL)
            {
                delete this->first;
                this->first = NULL;
            }
            else
            {
                PNODE temp = this->first;

                this->first = this->first -> next;
                this->first -> prev = NULL;
                delete temp;
            }
            this->iCount--;
        }

        void DeleteLast()
        {
            if(this->first == NULL)
            {
            return;
            }
            else if(this->first->next == NULL)
            {
            delete this->first;
            this->first = NULL;
            }
            else
            {
            PNODE temp = this->first;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete temp;
            }
            this->iCount--;
        }

        void DeleteAtPos(int pos)
        {
        if(pos < 1 || pos > iCount)
        {
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            PNODE temp = this->first;
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

        void Display()
        {
        PNODE temp = this->first;
        cout << "NULL <=> ";
        while(temp != NULL)
        {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
        }

        int Count()
        {
            return iCount;
        }
};


int main()
{   
    DoublyLL obj;
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



    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";
    
    obj.InsertAtPos(105,4);

    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";

    obj.DeleteAtPos(4);

    
    obj.Display();
    iRet = obj.Count();

    cout<<"Number of nodes are :" <<iRet<<"\n";
    return 0;
}

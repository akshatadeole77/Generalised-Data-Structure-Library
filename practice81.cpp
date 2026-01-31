// Doubly Circular Linked List

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

class DoublyCL
{
private:
    PNODE first;
    PNODE last;
    int iCount;

public:
    DoublyCL()
    {
        cout << "Object of DoublyCL gets created\n";
        this->first = NULL;
        this->last = NULL;
        this->iCount = 0;
    }

    void InsertFirst(int no)
    {
        PNODE newn = new NODE;
        newn->data = no;

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

    void InsertLast(int no)
    {
        PNODE newn = new NODE;
        newn->data = no;

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
            newn->prev = temp;

            temp->next->prev = newn;
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
        else if(this->first == this->last)
        {
            delete this->first;
            this->first = this->last = NULL;
        }
        else
        {
            PNODE temp = this->first;

            this->first = this->first->next;
            this->first->prev = this->last;
            this->last->next = this->first;

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
        else if(this->first == this->last)
        {
            delete this->first;
            this->first = this->last = NULL;
        }
        else
        {
            PNODE temp = this->last;

            this->last = this->last->prev;
            this->last->next = this->first;
            this->first->prev = this->last;

            delete temp;
        }
        this->iCount--;
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
        cout << "(First)\n";
    }

    int Count()
    {
        return this->iCount;
    }
};

int main()
{
    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    cout << "Number of nodes are : " << obj.Count() << "\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    cout << "Number of nodes are : " << obj.Count() << "\n";

    obj.InsertAtPos(105,4);
    obj.Display();

    obj.DeleteFirst();
    obj.Display();

    obj.DeleteLast();
    obj.Display();

    obj.DeleteAtPos(4);
    obj.Display();

    cout << "Number of nodes are : " << obj.Count() << "\n";
    return 0;
}

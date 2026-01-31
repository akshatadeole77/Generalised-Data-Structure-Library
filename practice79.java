//Doubly Circular
class node
{
    public int data;
    public node next;
    public node prev;

    public node (int no)
    {
        this.data=no;
        this.next=null;
        this.prev=null;
    }
}

class DoublyCL
{
    private node first;
    private node last;
    private int iCount;

    public DoublyCL()
    {
        System.out.println("Object of DoublyCL get created");
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }
    
    public void InsertFirst(int no)
    {
        node newn = null;
        newn = new node(no);

        if(this.first == null)
        {
            this.first = newn;
            this.last = newn;
            this.first.next = this.first;
            this.first.prev = this.first;
        }
        else
        {
            newn.next = this.first;
            newn.prev = this.last;
            this.first.prev = newn;
            this.last.next = newn;
            this.first = newn;
        }
        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        newn = new node(no);

        if(this.first == null)
        {
            this.first = newn;
            this.last = newn;
            this.first.next = this.first;
            this.first.prev = this.first;
        }
        else
        {
            newn.prev = this.last;
            newn.next = this.first;
            this.last.next = newn;
            this.first.prev = newn;
            this.last = newn;
        }
        this.iCount++;   
    }

    public void InsertAtPos(int no, int pos)
    {
        if(pos < 1 || pos > iCount + 1)
        {
            System.out.print("Invalid Position");
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
            node newn = null;
            newn = new node(no);

            node temp = null;
            temp = this.first;

            int iCnt = 0;

            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
            newn.prev = temp;
            temp.next.prev = newn;
            temp.next = newn;

            this.iCount++;
        }
    }

    public void DeleteFirst()
    {
        if(this.first == null)
        {
            return;
        }

        if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            this.first = this.first.next;
            this.first.prev = this.last;
            this.last.next = this.first;
        }
        this.iCount--;
    }

    public void DeleteLast()
    {
        if(this.first == null)
        {
            return;
        }

        if(this.first == this.last)
        {
            this.first = null;
            this.last = null;
        }
        else
        {
            this.last = this.last.prev;
            this.last.next = this.first;
            this.first.prev = this.last;

        }
        this.iCount--;
    }

    public void DeleteAtPos(int pos)
    {
        if(pos < 1 || pos > iCount)
        {
            System.out.print("Invalid Position");
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
            node temp = null;
            temp = this.first;

            int iCnt = 0;

            for(iCnt = 1; iCnt < pos; iCnt++)
            {
                temp = temp.next;
            }
            temp.prev.next = temp.next;
            temp.next.prev = temp.prev;

            this.iCount--;
        }    
    }

    public void Display()
    {
        node temp = null;
        temp = this.first;

        if(this.first == null)
        {
            return;
        }

        do
        {
            System.out.print("|" +temp.data+ "|<->");
            temp = temp.next;
        }while(temp != this.first);

        System.out.println("(first)");


    }

    public int Count()
    {
        return this.iCount;
    }


}

class program449
{
    public static void main(String A[])
    {
        DoublyCL obj = null;
        int iRet = 0;

        obj = new DoublyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Numbers of nodes are : " + iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Numbers of nodes are : " + iRet);

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();
        System.out.println("Numbers of nodes are : " + iRet);

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();
        System.out.println("Numbers of nodes are : " + iRet);

        obj.InsertAtPos(105,4);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Numbers of nodes are : " + iRet);

        obj.DeleteAtPos(4);

        obj.Display();

        iRet = obj.Count();
        System.out.println("Numbers of nodes are : " + iRet);



        

        //IMPORTANT FOR MEMOERY DEALLOCATION
        obj = null;
        System.gc();
        
    }
}
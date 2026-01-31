//Singly Circular
class node
{
    public int data;
    public node next;

    public node (int no)
    {
        this.data=no;
        this.next=null;
    }
}

class SinglyCL
{
    private node first;
    private node last;
    private int iCount;

    public SinglyCL()
    {
        System.out.println("Object of SinglyCL get created");
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }
    
    public void InsertFirst(int no)
    {
        node newn = null;
        newn = new node(no);
        if(first == null)
        {
            this.first = newn;
            this.last = newn;
            this.last.next= this.first;
        }
        else
        {
            newn.next=this.first;
            this.first = newn;
            this.last.next = this.first;
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
            this.last.next = this.first;
        }
        else
        {
            this.last.next = newn;
            this.last = newn;
            this.last.next = first;
        }

        this.iCount++;
        
    }

    public void InsertAtPos(int no, int pos)
    {
        node newn = null;
        node temp = null;

        newn = new node(no);
        temp = this.first;

        int iCnt = 0;

        if(pos < 1 || pos > iCount + 1)
        {
            System.out.println("Invalid Position");
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
            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }
            newn.next = temp.next;
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
            this.last.next = this.first;
        }
        this.iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;
        temp = this.first;
        
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
            while(temp.next != this.last)
            {
                temp = temp.next;
            }
            this.last = temp;
            this.last.next = this.first;
        }
        this.iCount--;   
    }

    public void DeleteAtPos(int pos)
    {
        node temp = null;
        temp = this.first;

        int iCnt = 0;

        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid Position");
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
            for(iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp.next;
            }
            temp.next = temp.next.next;

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
            System.out.print("|" + temp.data + "|<->");
            temp = temp.next;
        }while(temp != this.first);
        System.out.println("(first)");

    }

    public int Count()
    {
        return this.iCount;
    }


}

class program447
{
    public static void main(String A[])
    {
        SinglyCL obj = null;
        int iRet = 0;

        obj = new SinglyCL();

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
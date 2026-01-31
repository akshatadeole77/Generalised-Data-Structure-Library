

class node
{
    public int data;
    public node next;

    //Important
    public node (int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyLL
{
    public node first;
    public int iCount;

    public SinglyLL()
    {
        System.out.println("Object of SinglyLL get created");
        this.first = null;
        this.iCount = 0;
    }
    
    public void InsertFirst(int no)
    {
        node newn = null;

        //Change Code 
        newn = new node(no);



        newn.next = this.first;
        this.first = newn;

        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        node temp = null;

        temp = this.first;

        //Change Code 
        newn = new node(no);

        if(this.iCount == 0)
        {
            this.first=newn;
        }
        else
        {
            while (temp.next != null)
            {
                temp = temp.next;
            }
                temp.next=newn;
        }

        this.iCount++;   
    }

    public void InsertAtPos(int no, int pos)
    {
        
    }

    public void DeleteFirst()
    {
        node temp = null;

        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;

        }
        else
        {
            this.first = this.first.next;
        }
        System.gc();
        this.iCount--;

    }

    public void DeleteLast()
    {
       node temp = null;

        if(this.first == null)
        {
            return;
        }
        else if(this.first.next == null)
        {
            this.first = null;

            

        }
        else
        {
            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
        }
        System.gc();
        this.iCount--; 
    }

    public void DeleteAtPos(int pos)
    {
        
    }

    public void Display()
    {
        node temp = null;
        temp = this.first;

        while(temp != null)
        {
            System.out.print("| " + temp.data + "| ->");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public int Count()
    {
        return this.iCount;
    }


}

class program445
{
    public static void main(String A[])
    {
        SinglyLL obj = null;
        int iRet = 0;

        obj = new SinglyLL();

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



        

        //IMPORTANT FOR MEMOERY DEALLOCATION
        obj = null;
        System.gc();
        
    }
}
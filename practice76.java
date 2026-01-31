

class node
{
    public int data;
    public node next;
    public node prev;

    //Important
    public node (int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLL
{
    public node first;
    public int iCount;

    public DoublyLL()
    {
        System.out.println("Object of DoublyLL get created");
        this.first = null;
        this.iCount = 0;
    }
    
    public void InsertFirst(int no)
    {
        node newn = null;

        //Change Code 
        newn = new node(no);

        if(first != null)
        {
        newn.next = this.first;
        this.first.prev = newn; 
        }
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

        if(this.first == null)
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
                newn.prev = temp;
        }
        this.iCount++;   
    }
    
    public void DeleteFirst()
    {
        node temp = null;

        if(this.first == null)
        {
            return;
        }

        if(this.first == null)
        {
            this.first = null;
        }
        else
        {
            this.first = this.first.next;
            this.first.prev = null;
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
            temp = this.first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.prev.next = null;
        }
        System.gc();
        this.iCount--; 
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

    public void InsertAtPos(int no, int pos)
    {

        node temp = null;
        node newn = null;


        int iCnt = 0;

       if(pos < 1 || pos > this.iCount+1)
        {
            System.out.println("Invalid Position");
            return;
        }  

        if(pos == 1)
        {
            this.InsertFirst(no);
        }
        else if(pos == this.iCount+1)
        {
            InsertLast(no);
        }
        else
        {
            newn = new node(no);
            temp = this.first;

            for(iCnt = 1;iCnt < pos-1; iCnt++)
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

    
    public void DeleteAtPos(int pos)
    {
    
        node temp = null;
        
        int iCnt = 0;

       if(pos < 1 || pos > this.iCount)
        {
            System.out.println("Invalid Position");
            return;
        }  

        if(pos == 1)
        {
            this.DeleteFirst();
        }
        else if(pos == this.iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = this.first;

            for(iCnt = 1;iCnt < pos; iCnt++)
            {
                temp = temp.next;
            }
            temp.prev.next = temp.next;
            temp.next.prev = temp.prev;

            System.gc();
            this.iCount--;
            
        } 
    }


}

class program446
{
    public static void main(String A[])
    {
        DoublyLL obj = null;
        int iRet = 0;

        obj = new DoublyLL();

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
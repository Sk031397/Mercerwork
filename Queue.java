
public class Queue implements QueueInterface {
  private Node lastNode;
  
  public Queue() {
    lastNode = null;   
  }  // end default constructor
  
  // queue operations:
  public boolean isEmpty() {
        return (lastNode == null);
  }  // end isEmpty

  public void dequeueAll() {
    lastNode = null; 

  }  // end dequeueAll

  public void enqueue(Object newItem) {
    
    Node local = new Node(newItem); 
    if (isEmpty()) {
      // insertion into empty queue
     local.setNext(local); 

    }
    else {
      // insertion into nonempty queue
      local.setNext(lastNode.getNext()); 
      lastNode.setNext(local); 
    }  // end if
   lastNode = local; 

  }  // end enqueue

  public Object dequeue()
    throws QueueException
  {
    if (!isEmpty())
    {
      Node localNode = lastNode.getNext();
      if (localNode ==lastNode) {
        this.lastNode = null;
      } else {
        lastNode.setNext(localNode.getNext());
      }
      return localNode.getItem();
    }
    throw new QueueException("QueueException on dequeue:queue empty");
  }

  public Object front() throws QueueException {
    if (!isEmpty()) {
      Node firstNode = lastNode.getNext();
      return firstNode.getItem(); 
    }
    else {
      throw new QueueException("QueueException on front:"
                             + "queue empty");
    }
 
  }

  public Object clone() throws CloneNotSupportedException
  {
	boolean copied = false;
        Queue copy = new Queue();
        Node curr = lastNode, prev = null;
        while ( (! copied) && (lastNode != null) )
        {
                Node temp = new Node(curr.getItem());
                if (prev == null)
                        copy.lastNode = temp;
                else
                        prev.setNext(temp);
                prev = temp;
                curr = curr.getNext();
		copied = (lastNode == curr);
        }
	prev.setNext(copy.lastNode);
        return copy;
  }
} // end Queue

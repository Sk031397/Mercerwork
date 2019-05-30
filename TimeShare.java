//Utilies and Input/Output are imported 
import java.io.BufferedReader; 
import java.io.FileReader; 
import java.io.IOException;
import java.io.PrintStream;
import java.util.StringTokenizer;


public class TimeShare
{
  public static void main(String[] args) throws IOException, CloneNotSupportedException
  {
// Two queues are created and an array of integers that holds two integers is created 
    Queue q = new Queue();
    Queue q2 = new Queue();
    int[] arr1 = new int[2];
    
    inputQ(q, args);
    processJob(q, q2, arr1);
    summary(q2, arr1[0], arr1[1]);
  }
  /*
	@param a reference to the main queue used throughout the program and 
	@param a reference to the main string array 
*/
  public static void inputQ(Queue q, String[] s) throws IOException
  {
    if (s.length == 0)
    {
      System.out.println("Error : Filename Not Provided");
      System.exit(-1);
    }
// FileReader and BufferedReader are created so that the file can be read
// FileReader holds the first slot of the main string array 
// BufferedReader has the file as a parameter so that it can read it in 
   FileReader file = new FileReader(s[0]); 
   BufferedReader buff = new BufferedReader(file);  
   Job lj = null;
// A for-loop can be created with two semicolons if you do not know what expressions you want to put inside it 
    for (;;)
    {
// The file is read and stored into a string 
      String s1 = buff.readLine();
// If the read in string is empty the loop will break 
      if (s1 == null) {
        break;
      }
// The inputJob function returns Job and must be stored in variable lj because it holds the type Job also
      lj = inputJob(s1);
// The queue then enqueues the job 
      q.enqueue(lj);
    }
  }
  /* @param a reference to both queues created in main are created and
  a reference is made to the main array 
*/
  public static void processJob(Queue q, Queue q2, int[] num)throws CloneNotSupportedException
  {
    int first = 1;
    int second = 0;
    int third = 0;
// A local queue is created 
    Queue q1 = new Queue();
    while((!q.isEmpty())||(!q1.isEmpty())) 
    {
// If one of the main queues is not empty 
      if (!q.isEmpty())
      {
// The front of the queue is casted as a Job and stored in a varable of type job 
        Job job = (Job)q.front();
	// If the job arrival equals 1 
        if (job.arrivalTime == first)
        {
	// The local queue enqueues the job 
          q1.enqueue(job);
	// The main queue dequeues 
          q.dequeue();
        }
      }
// The local queue is not empty 
      if (!q1.isEmpty())
      {
	// The front of the local queue is picked off and converted to a Job
        Job localJ1 = (Job)q1.front();
	// if the jobs startime does not equal -1(i.e the end) and if i(1) minus the startTime equals the jobs RumTime
        if ((localJ1.startTime != -1) && (first - localJ1.startTime == localJ1.runTime))
        {
	// The jobs turnTime equals i minus the job arrival time
          localJ1.turnTime = (first - localJ1.arrivalTime);
          // The job is enqueued into the second main queue 
          q2.enqueue(localJ1);
	  // The first queue is dequeued 
          q1.dequeue();
        }
      }
	// if the local queue is not empty 
      if (!q1.isEmpty())
      {
	// The front of the local queue is converted to Job 
        Job localJ3 = (Job)q1.front();
	// if the jobs arrival time is less than or equal to i(1) and if the job has not started yet 
        if ((localJ3.arrivalTime <= first) && (!Started(q1, localJ3)))
        {
	// The front of the queue is converted to a job and the jobs startTime is equal to i (1)
          ((Job)q1.front()).startTime = first;
	// and the jobs waitTime is equal to i(1) minus the persons arrivalTime to work 
          ((Job)q1.front()).waitTime = (first - localJ3.arrivalTime);
        }
      }
	// If local queue is empty and if the main queue is not empty 
      if ((q1.isEmpty()) && (!q.isEmpty())) {
	// Increment j 
        second++;
	// if the local queue is not empty 
      } else if (!q1.isEmpty()) {
	// increment k 
        third++;
      }
	// increment i 
      first++;
	// All the functions above are done as long as the local and main queues are not empty 
    } 

	// The first index of the integer array is set equal to j 
    num[0] = second;
	// The second index of the array is set equal to k 
    num[1] = third;
  }
  /* @ param a reference is made to main queue and a job 
*/
  public static boolean Started(Queue q, Job j)throws CloneNotSupportedException
  {
	// A deep copy is made of the main queue 
    Queue q1 = (Queue)q.clone();
	// while the queue is not empty 
    while (!q1.isEmpty())
    {
	// The front of the queue is converted to a job and the jobName is shown 
      String s2 = ((Job)q1.front()).jobName;
	// if the the jobName equals the jobName shown and if the startTime does not equal the end 
	//@return true 
      if ((s2.equals(j.jobName)) && (j.startTime != -1)) {
        return true;
      }
	// dequeue from the queue 
      q1.dequeue();
    }
	//@return false 
    return false;
  }
  /*@ param reference to the main queue 
	Two integers variables are created 
	*/
  public static void summary(Queue q, int first, int second)throws CloneNotSupportedException
  {
    int clock = 0;
    int fname = 0;
    
    System.out.println("\tJob Control Analysis : Summary Report");
    System.out.println("\t*****************************\n");
    System.out.print("\t");
    System.out.println("job id\tarrival\tstart\trun\twait\tturnaround");
    
    System.out.print("\t");
    System.out.println("      \ttime   \ttime \ttime\ttime\ttime      ");
    
    System.out.print("\t");
    System.out.println("******\t******\t*******\t*****\t*****\t*********");
    // The summary is printed 
    printQ(q);
	// A deep copy of the main queue is made 
    Queue q1 = (Queue)q.clone();
	// The queue is not empty 
    while (!q1.isEmpty())
    {
	// The front of the queue is converted to a job 
      Job job = (Job)q1.front();
      fname+=job.waitTime;
      clock++;
      q1.dequeue();
    }
    System.out.println("\n");
    System.out.println("\t\tAverage Wait Time >> " + Math.round((double)fname / clock * 100.00)/100.00);
    
    System.out.println("\t\tCPU Usage >> " + (double)second);
    System.out.println("\t\tCPU Idle >> " + (double)first);
	 System.out.println("\t\tCPU Usage (%) >> " + Math.round((double)second / (double)(second + first) * 100.0D * 100.0D) / 100.0D + "%\n");
    

    
    System.out.println("\t*********************************************");
  }
  /* @ param reference to main queue 
	*/
  public static void printQ(Queue q) throws CloneNotSupportedException
  {
	//A deep copy of the main queue is made 
    Queue q1 = (Queue)q.clone();
	// while the queue is not empty 
    while (!q1.isEmpty())
    {
	// The queue's front is converted to a Job 
      Job job = (Job)q1.front();
      System.out.println("\t" + job);
	// Dequeue the queue 
      q1.dequeue();
    }
  }
 /* @ param name of type String 
	*/ 
  public static Job inputJob(String name)throws IOException
  {
	// A String Tokenizer helps the seperation of the name 
    StringTokenizer token = new StringTokenizer(name);
    String s3 = token.nextToken();
	// The tokenized word is parsed to a integer 
    int ftoken = Integer.parseInt(token.nextToken());
    int ltoken = Integer.parseInt(token.nextToken());
    return new Job(s3, ftoken, ltoken);
  }
}

using System; 
using System.Collections;
using System.Collections.Generic; 
// C# checked on 10/20/17

public class MemTest
{
static public void Main(string [] args)
{   Console.WriteLine("How big is the cube?"); 
    int maxsize = Convert.ToInt32(Console.ReadLine());       
    double[,,] A = new double[maxsize,maxsize,maxsize]; 
    // Zero out the 3D array 
    for (int i =0;i< maxsize;i++)
    {
        for(int j =0;j<maxsize;j++)
        {
            for(int k =0;k<maxsize;k++)
            {
                A[i,j,k] = 0.0; 
            }
        }
    } 
    calculateDiffusion(maxsize,A); 
     
}
/* calculates the diffusion process
 * @param the size of the cube and the 3D array that holds each cube 
 * */
static public void calculateDiffusion(long maxsize, double[,,] A )
{
    double diffusion_coeffcient = 0.175;
    double room = 5.0; 
    double speed_of_gas = 250.0;
    double timestep = (room /speed_of_gas) /maxsize;
    double distance = room /maxsize;
    double Dterm = diffusion_coeffcient * timestep / (distance*distance); 
    
    A[0,0,0] = 1.0e21;

    double time = 0.0;
    double ratio = 0.0;
    int mid = Convert.ToInt32(maxsize) / 2; 
    Console.WriteLine("Do you want to add a partition?\n1:Yes\n2:No\n");
    int c= Convert.ToInt32(Console.ReadLine()); 
    DateTime Debut = DateTime.Now;
    // flag that checks to see if the partition is turned on 
    if(c==1) 
    {
    for(int i = 0; i < maxsize;i++)
    {
        for(int j = 0; j < maxsize; j++)
        {
            for(int k = 0; k < maxsize;k++)
            {
            if(( i == mid - 1) && (j>= mid -1 ) ) 
            {
                A[i,j,k] = -1.0; 
            } 
            }
        }
    } 
  }   
// loop through each cube until 99% of the room is filled    
    do{
// loop through each cube to see if they are not the same 
        for(int i =0; i < maxsize;i++)
            {
                for(int j=0;j<maxsize;j++)
                {
                    for(int k =0;k<maxsize;k++) 
                    { 
                    if(A[i,j,k]!=-1.0)
                    {         
                      if(i!=0 && A[i-1,j,k]!=-1.0)
                      {
                        double change = (A[i,j,k] - A[i-1,j,k] ) * Dterm;
                        A[i,j,k] = A[i,j,k] - change;
                        A[i-1,j,k] = A[i-1,j,k] + change; 
                      }
                      if(j!=0 && A[i,j-1,k]!=-1.0)
                      {
                        double change = (A[i,j,k] - A[i,j-1,k] ) * Dterm;
                        A[i,j,k] = A[i,j,k] - change;
                        A[i,j-1,k] = A[i,j-1,k] + change;
                      }
                      if(k!=0 && A[i,j,k-1]!=-1.0)
                      {
                        double change = (A[i,j,k] - A[i,j,k-1] ) * Dterm;
                        A[i,j,k] = A[i,j,k] - change;
                        A[i,j,k-1] = A[i,j,k-1] + change;
                      }
                      if(i!=maxsize-1 && A[i+1,j,k]!=-1.0)
                      {
                        double change = (A[i,j,k] - A[i+1,j,k] ) * Dterm;
                        A[i,j,k] = A[i,j,k] - change;
                        A[i+1,j,k] = A[i+1,j,k] + change;
                      }
                      if(j!=maxsize-1 && A[i,j+1,k]!=-1.0)
                      {
                        double change = (A[i,j,k] - A[i,j+1,k] ) * Dterm;
                        A[i,j,k] = A[i,j,k] - change;
                        A[i,j+1,k] = A[i,j+1,k] + change;
                      } 
                      if(k!=maxsize-1 && A[i,j,k+1]!=-1.0)
                      {
                        double change = (A[i,j,k] - A[i,j,k+1] ) * Dterm;
                        A[i,j,k] = A[i,j,k] - change;
                        A[i,j,k+1] = A[i,j,k+1] + change;
                      }
                    }
                }
            }
        }
      time = time + timestep;
    // mass consistency 

    double sumval = 0.0;
    double maxval = A[0,0,0];
    double minval = A[0,0,0];
    for(int i =0;i<maxsize;i++)
    {
        for(int j =0;j<maxsize;j++)
        {
            for(int k=0;k<maxsize;k++)
            {
             // get the maximum and minimum of each cube
            if(A[i,j,k]!=-1.0)
            {
                maxval = Math.Max(A[i,j,k],maxval);
                minval = Math.Min(A[i,j,k],minval);
                sumval+=A[i,j,k];
            }
        }
        }
    }
    ratio = minval / maxval;
    Console.WriteLine("sumval is " + string.Format("{0:N2}",sumval) + " ratio is " + string.Format("{0:N2}",ratio) + " maxval is " + string.Format("{0:N2}",maxval) + " minval is " +string.Format("{0:N2}",minval));    
} while (ratio <=0.99);
    Console.WriteLine("Box equilibrated in " + string.Format("{0:N2}",time));
    TimeSpan wall = DateTime.Now - Debut; 
    Console.WriteLine("Wall Time " + wall);
}

}

#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#include <stddef.h> 
#include <sys/time.h>
// C code checked on 10/20/17
// Function Protypes   
void calculateDiffusion(double ***A,int maxsize);  
double walltime_(); 
int main()
{
    int maxsize;
    double wall,cpu;
    printf("How big is the cube?\n"); 
    scanf("%d",&maxsize);  
    double ***A = malloc(maxsize*sizeof(double **));
    // zeros out the indexs
    for(int i=0;i<maxsize;i++)
    {   // Allocate Memory to the one and two d arrays 
        A[i] = malloc(maxsize*sizeof(double *));
        for(int j=0;j<maxsize;j++)
        {
            A[i][j] = malloc(maxsize*sizeof(double));
        }
    }
    // Zero out cubes 
    for(int i=0;i<maxsize;i++)
    {
        for(int j=0;j<maxsize;j++)
        {
            for(int k=0;k<maxsize;k++)
            {
                A[i][j][k] = 0.0;
            }
        }
    }
    calculateDiffusion(A,maxsize);  
    free(A);
}
// calculates the real time from running the diffusion code 
double walltime_() 
{
    
    double factor = 1.0e-6;
    struct timeval tp;
    int rtn;
    double seconds;

    rtn=gettimeofday(&tp, NULL);

    seconds = tp.tv_sec + factor * tp.tv_usec;

    return  seconds ; 
}
    /* calculates the amount of time needed to diffuse the room 
 *@parm the 3D array and the size of the cube 
 * */
    void calculateDiffusion(double ***A
            ,int maxsize)
    {
        double diffusion_coeffcient = 0.175; 
        double room = 5.0;  
        double speed_of_gas = 250.0; 
        double timestep = (room / speed_of_gas) / maxsize;
        double distance = room / maxsize;
        double Dterm = diffusion_coeffcient * timestep / (distance*distance); 
        A[0][0][0] = 1.0e21; 
        double time = 0.0; 
        double ratio = 0.0;
        double change; 
        double wall; 
        // Asks if the user want to add a partition or not  
        printf("Do you want to add a partition?\n1:Yes\n2:No\n");  
        int c; 
        // divides the partiton in half 
        int mid = maxsize / 2; 
        scanf("%d",&c); 
        wall = walltime_(); 
        // if user enters in 1 then the partition is handled  
        if( c == 1)
        {
            for(int i = 0; i < maxsize;i++)
            {
                for(int j = 0; j < maxsize;j++)
                {   
                    for(int k = 0; k < maxsize;k++)
                    {
                        if( (i == mid-1) && (j>= mid - 1) ) 
                        {
                            A[i][j][k] = -1.0;    
                        }
                    }
                }
            } 
        }
        // loops to see if the boxes are not equal  
        do{
            for(int i =0; i < maxsize;i++)
            {
                for(int j = 0; j < maxsize;j++)
                {
                    for(int k =0; k<maxsize;k++)
                    {
                        if(A[i][j][k]!=-1.0)
                        {
                            if(i!=0 && A[i-1][j][k]!=-1.0)
                            {
                                change =(A[i][j][k] - A[i-1][j][k]) * Dterm; 
                                A[i][j][k] = A[i][j][k] - change; 
                                A[i-1][j][k] = A[i-1][j][k] + change; 
                            } 
                            if(j!=0 && A[i][j-1][k]!=-1.0 )
                            {
                                change =(A[i][j][k] - A[i][j-1][k]) * Dterm;
                                A[i][j][k] = A[i][j][k] - change;
                                A[i][j-1][k] = A[i][j-1][k] + change;
                            }
                            if(k!=0 && A[i][j][k-1]!=-1.0)
                            {
                                change =(A[i][j][k] - A[i][j][k-1]) * Dterm;
                                A[i][j][k] = A[i][j][k] - change;
                                A[i][j][k-1] = A[i][j][k-1] + change;
                            }
                            if(i!=maxsize-1 && A[i+1][j][k]!=-1.0)
                            {
                                change =(A[i][j][k] - A[i+1][j][k]) * Dterm;
                                A[i][j][k] = A[i][j][k] - change;
                                A[i+1][j][k] = A[i+1][j][k] + change;
                            }
                            if(j!=maxsize-1 && A[i][j+1][k]!=-1.0)
                            {
                                change =(A[i][j][k] - A[i][j+1][k]) * Dterm;
                                A[i][j][k] = A[i][j][k] - change;
                                A[i][j+1][k] = A[i][j+1][k] + change;
                            }
                            if(k!=maxsize-1 && A[i][j][k+1]!=-1.0)
                            {
                                change =(A[i][j][k] - A[i][j][k+1]) * Dterm;
                                A[i][j][k] = A[i][j][k] - change;
                                A[i][j][k+1] = A[i][j][k+1] + change;
                            }
                        }
                    }      }
            }
            time = time + timestep;
            // mass consistency 

            double sumval = 0.0; 
            double maxval = A[0][0][0];
            double minval = A[0][0][0]; 
            for(int i =0; i<maxsize;i++)
            {
                for(int j =0;j<maxsize;j++)
                {
                    for(int k =0;k<maxsize;k++)
                    {
                // get the maximum and minimum of each cube
                        if(A[i][j][k] != -1.0)
                        {
                            if ( A[i][j][k] > maxval) 
                            {
                                maxval = A[i][j][k]; 
                            }
                            if ( A[i][j][k] < minval) 
                            {
                                minval = A[i][j][k]; 
                            }
                            sumval+=A[i][j][k]; 
                        }
                    }      
                }
            }
            printf("sumval %f  ratio %f  maxval %f minval %f\n",sumval,ratio,maxval,minval); 
            ratio = minval / maxval;
        } while ( ratio <0.99);
        printf("Box equilibrated in %.2f seconds of simulated time\n",time);
        wall = walltime_() - wall;
        printf("wall time is %f\n",wall);
    } 

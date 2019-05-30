package main 
// Checked go on 10/20/17
// imports used in my program 
import "fmt"
import "math"
import "time"
const maxsize int = 10 
func main(){ 
    fmt.Printf("This is your current maxsize %d. If you want to change it, maxsize is the first line defined in the code.\n",maxsize) 
    fmt.Print("Do you want to add a partition?\n1:Yes\n2:No\n")
    var choice int
    // Zero out the 3D array  
    var A [maxsize][maxsize][maxsize] float64 
    for i:=0;i<maxsize;i++{
    for j:=0;j<maxsize;j++{
    for k:=0;k<maxsize;k++{
    A[i][j][k] = 0.0 
                           }
                           }
                           }
    var diffusion float64 = 0.175 
    var room float64 = 5
    var speed float64 = 250 
    var timestep float64 = ( room / speed) / float64(maxsize) 
    var distance = room / float64(maxsize) 
    var dC float64 = (diffusion * timestep) / (distance * distance)   
    A[0][0][0] = 1.0e21
    var tacc float64 = 0
    var ratio float64 = 0
    var mid int = int(maxsize) / 2
    fmt.Scanf("%d",&choice)
    // flag to check if the diffusion was turned on
    start:= time.Now()   
    if(choice==1){ 
    for i:=0; i < maxsize;i++{
    for j:=0; j < maxsize;j++{
    for k:=0; k < maxsize;k++{
       if(( i == mid -1) && (j>=mid -1)){
            A[i][j][k] = -1 
             }                          
                             }
                            }
                            }
                            } 
    // while the ratio is less than 99%, check to see each blocks are not adjacent to each other  
    for ratio <=0.99 { 
    for i:=0;i<maxsize;i++{
    for j:=0;j<maxsize;j++{
    for k:=0;k<maxsize;k++{
    // check to see if all the cubes are not the same 
    if(A[i][j][k]!=-1) {
    if(i!=0 && A[i-1][j][k]!=-1) {
    var change float64 = (A[i][j][k] - A[i-1][j][k] ) * dC  
    A[i][j][k] = A[i][j][k] - change
    A[i-1][j][k] = A[i-1][j][k] + change
                                    }
    if(j!=0 && A[i][j-1][k]!=-1) {
    var change float64 = (A[i][j][k] - A[i][j-1][k] ) * dC
    A[i][j][k] = A[i][j][k] - change
    A[i][j-1][k] = A[i][j-1][k] + change
                                        }
    if(k!=0 && A[i][j][k-1]!=-1) {
    var change float64 = (A[i][j][k] - A[i][j][k-1] ) * dC
    A[i][j][k] = A[i][j][k] - change
    A[i][j][k-1] = A[i][j][k-1] + change
                                        }
    if(i!=maxsize-1 && A[i+1][j][k]!=-1) {
    var change float64 = (A[i][j][k] - A[i+1][j][k] ) * dC
    A[i][j][k] = A[i][j][k] - change
    A[i+1][j][k] = A[i+1][j][k] + change
                                    }
    if(j!=maxsize-1 && A[i][j+1][k]!=-1) {
    var change float64 = (A[i][j][k] - A[i][j+1][k] ) * dC
    A[i][j][k] = A[i][j][k] - change
    A[i][j+1][k] = A[i][j+1][k] + change
                                    }
    if(k!=maxsize-1 && A[i][j][k+1]!=-1) {
    var change float64 = (A[i][j][k] - A[i][j][k+1] ) * dC
    A[i][j][k] = A[i][j][k] - change
    A[i][j][k+1] = A[i][j][k+1] + change
                                    }
                                   }
                                 }
              }      
                }
    tacc = tacc + timestep 
    
    // mass consistent 
    var sumval float64 = 0
    var min float64 = A[0][0][0] 
    var max float64 = A[0][0][0] 
    for i:=0;i<maxsize;i++{
    for j:=0;j<maxsize;j++{
    for k:=0;k<maxsize;k++{
     // get the maximum and minimum of each cube
     if(A[i][j][k]!=-1) {
     max = math.Max(A[i][j][k],max)
     min = math.Min(A[i][j][k],min)
     sumval = sumval + A[i][j][k] 
                        }
                        }
                     }
                }
    fmt.Printf("Sumval %.2f Ratio %.2f Maxval %.2f Minval %.2f\n",sumval,ratio,max,min)   
    ratio = min / max   
}  
elapsed:=time.Since(start) 
fmt.Printf("Box equilibrated in %.2f seconds\n",tacc) 
fmt.Print("wall time ")
fmt.Println(elapsed ) 
} 

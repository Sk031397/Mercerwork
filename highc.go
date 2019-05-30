package main
import "fmt"

func main(){
    var max int64 
    var min int64
    fmt.Println("Enter a initial number")
    fmt.Scanf("%d\n",&min)
    fmt.Println("Enter a final number")
    fmt.Scanf("%d\n",&max)
     fmt.Printf("Minimum value : %d\n",min)
        fmt.Printf("Maximum value : %d\n",max)

    count:=0 
    var listone[10] int64
    var listtwo [10] int64 
    for i:=0;i<7;i++{
        if( min % 2 ==0){
            min = min / 2
        }else{
            min = min * 3 + 1 
        }
        count = count + 1  
        listone[i]= min 
        }
       for i:=0; i<7;i++{
        if( max % 2 ==0){
            max = max / 2
        }else{
            max = max * 3 + 1
        }
        count = count + 1 
        listtwo[i] = max  
    }
     var largeone int64 = listone[0] 
     for i:=0;i<10;i++{
        if (largeone < listone[i]){
                largeone = listone[i]  
                                }            
}
        var largetwo int64 = listtwo[0] 
        for i:=0;i<10;i++{
        if (largetwo < listtwo[i]){
                largetwo = listtwo[i]
                                }
}
        var largest int64; 
        if(largeone > largetwo) {
            largest = largeone
        }else{
            largest = largetwo 
}
        
        fmt.Println(largest)         
}

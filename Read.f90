
program reader 
character(LEN=5000000)::long_string
    integer::filesize 
call read_file(long_string,filesize) 
    end program reader 
    !- opens the file and reads through it 
subroutine  read_file(string,counter)

    character(LEN=*)::string
    character(len=600)::filename; 
    integer::counter
    character(LEN=1)::input
    character(len=50)::args
    call getarg(1,args)
    if(iargc()== 0 ) then 
        print *, "Please enter a file"
        read*, filename;
       open(unit=20,status="old",access="direct",form="unformatted",recl=1,file=filename)
    counter = 1
    300 read(20,rec=counter,err=500) input
    string(counter:counter)=input
    counter=counter+1
    goto 300
    500 continue
    counter = counter -1
    close(20)
    call compute_Index(string,counter)
    call grade_Index(string,counter) 
    endif
    if(iargc() >0) then  
    open(unit=5,status="old",access="direct",form="unformatted",recl=1,file=args)
    counter = 1 
    100 read(5,rec=counter,err=200) input 
    string(counter:counter)=input 
    counter=counter+1
    goto 100
    200 continue 
    counter = counter -1 
    close(5)
    call compute_Index(string,counter) 
    call grade_Index(string,counter)
    end if  
    end subroutine read_file 

    ! count the number of words in the file  
subroutine count_words(string,nwords) 
    character(len=*) ::string  
    integer::nwords,pos,i 
    pos = 1 
    nwords = 0
    loop:do 
    i = verify(string(pos:),' ')
    if (i == 0) exit loop        !-- No word found.
    nwords = nwords + 1          !-- Found something.
    pos = pos + i - 1            !-- Move to start of the word.
    i = scan(string(pos:), ' ')    !-- Find next blank.
    if (i == 0) exit loop        !-- No blank found.
    pos = pos + i - 1            !-- Move to the blank.
    end do loop ! gives nwords 
    end subroutine count_words
    !- counts the number of sentences in the file 
subroutine count_sentences(string,nsentences)
    character(len=*)::string 
    integer::nsentences,pos,i
    pos = 1 
    nsentences = 0
    loop:do 
    i = verify(string(pos:),'?!:;.') !- verifies if one of the following exists
    if( i ==0) exit loop 
    nsentences = nsentences + 1 
    pos = pos + i-1
    i = scan(string(pos:),'?!:;.') !- scans the file to see if one the following
    if(i==0) exit loop 
    pos = pos + i -1
    end do loop  
    end subroutine count_sentences  
    !- counts the number of syllables in each word 
subroutine count_syllables(string,nsyllables)
    integer::nsyllables,i,pos
    character(len=*) :: string
    pos = 1 
    nsyllables = 0 
    loop: do 
        i = verify(string(pos:),"aeiouy") ! verifies if one the the following exists
        if(i==0) exit loop 
        nsyllables = nsyllables + 1 
        pos = pos + i -1 
        i = scan(string(pos:),"aeiouy") !scans the file to see if one the folowing exists
        if(i==0) exit loop 
        pos = pos + i - 1 
        end do loop 
    end subroutine count_syllables  
    ! calculate the flesch readabilty index 
subroutine compute_Index(string,counter) 
    character(len=*) ::string
    integer::counter
    real::nwords,nsentences,nsyllables,fleschIndex
call count_words(string,counter)   
    nwords = counter
call count_sentences(string,counter) 
    nsentences = counter 
call count_syllables(string,counter)
    nsyllables = counter  
fleschIndex = 206.835 - 1.015 * ( nwords / nsentences ) - 84.6 * (nsyllables/ nwords)
    !format the grade to one decimal place 
     15 format ("The Flesch Readability Grade Index is ",f5.1)
    print 15, fleschIndex
    end subroutine compute_Index
    ! calculate the flesch grade Index 
subroutine grade_Index(string,counter)
    character(len=*)::string
    integer::counter
    real :: gradeIndex,nsyllables,nsentences,nwords   
call count_words(string,counter)
    nwords = counter 
call count_sentences(string,counter)
    nsentences = counter 
call count_syllables(string,counter)
    nsyllables = counter       
    gradeIndex = 11.8 * (nsyllables / nwords) + 0.39* (nwords / nsentences ) -15.59; 
    !format the grade to one decimal place  
    5 format ("The Flesch Kincaid Grade Index is ",f5.1)   
    print 5, gradeIndex 
    end subroutine grade_Index   

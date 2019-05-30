Instructions:

1. Compile and run the code.  Create a new branch called "submission"
   and do all of you work on the submission branch.  You will be committing
   and pushing your code to be graded on the submission branch.
   
2. In this README.md file, add your name after the "Submitted by:" at the
   bottom of the file to signify that you have read this file and that you
   are bound by the Mercer Honor Code.  You may not talk to anyone about this
   code except Dr. Pounds and you are free to use the class notes, man pages, 
   and resources from the internet to help you write your code.  Once you 
   add your name, add the modified file to your repo and commit and push 
   the submission branch with the commit message "signing honor code pledge".

3. Enable the Depth Buffer so the boxes and shapes are displayed 
   properly.  When done part of the sphere and cone will be hidden inside
   the boxes.   Commit and push these changes. ( 15 pts )

5. Comment out the glFrustum command and write code to determine
   the aspect ratio and field of view and then use these values in a call
   to the gluPerspective command to give you the EXACT SAME view as the
   commented out glFrustum command. Commit and push these changes. (15 pts)
 
6. Instead of using either glFrustum or gluPerspective, define and implement
   your own perspective projection matrix that gives the the EXACT SAME
   projection as the original glFrustum.  (10 pts) In addition, set up your code
   and makefile so that the decision to use the matrix you create for the 
   projection can be selected at COMPILE TIME with a -DMATRIX compiler flag.
   In other words, if the code is compiled without the -DMATRIX flag it will
   use your gluPerspective command from part 5; if the flag is used the the 
   code will use you matrix from part 6. Commit and push these changes. 
   ( 10 pts )
   
X. Comment out the gluLookAt command and position the camera using 
   a series of glTranslate and glRotate commands to give the EXACT SAME
   view as the gluLookAt command.  (25 pts EXTRA CREDIT)
   
 
 Submitted by: Sahid Kebe 
   
   
   
   
   
   
   

#!/usr/bin/sbcl --script 
;I just set and declare the variable in the same line 
(defvar maxsize)
(defvar change) 
(defvar minval 0.d0)
(defvar maxval 0.d0)
(defvar sumval 0.d0) 
(defvar A) 
(defvar height)
(defvar timestep 0.d0)
(defvar dC)
(defvar tacc 0.d0)
(format t "How big is the cube? ~%")   
(setf maxsize(read))
; create the array as a list in order to use maxsize as a index 
(setf A (make-array(list maxsize maxsize maxsize))) 
; declaring the constant variables 
(defvar diffusion_coefficient 0.175)
(defvar room_dimension 5.0) 
(defvar speed_of_gas 250.0)
; other variables 
(setf timestep (/ room_dimension speed_of_gas maxsize ) )
(setf height (/ room_dimension maxsize) ) 
(setf dC (/ (* diffusion_coefficient timestep) (* height height)) ) 
; set 1 index to 1.0 * 10 e21 
(setf (aref A 0 0 0) (* 1( expt 10 21)))
(defvar tacc 0.d0)
(defvar r 0.d0)
(defvar choice )
(defvar mid)
(setf mid (/ maxsize 2) ) 
(format t "Do you want to add a partition?~%1:Yes~%2:No~%") 
(setf choice(read))
(let ((real1 (get-internal-real-time))
        (run1 (get-internal-run-time)))
;flag to see if the partiton was set on our not 
(if (= choice 1)
  (progn 
    (dotimes(i maxsize)
      (dotimes(j maxsize)
        (dotimes(k maxsize)

          (if(and (= i (- mid 1)) (>= j (- mid 1) ) )
            (progn 
              (setf (aref A i j k) -1.0) 
              )
            )
          )
        )
      )
    )
  )
; loop while ratio is less than 0.99   
(loop while(<= r 0.99) do  
      (setf tacc (+ timestep tacc ) )   
      ; loop through each cube checking to see if each cube is not equal to each other 
      (dotimes ( i maxsize) 
        (dotimes (j maxsize) 
          (dotimes ( k maxsize)
            (if (/= (aref A i j k)-1)
              (progn
                (if(and (/= k 0) (/= (aref A i j (- k 1) ) -1 ) )  
                  (progn 
                    (setf change (* dC (- (aref A i j k )(aref A i j (- k 1)))))
                    (setf (aref A i j k)(- (aref A i j k)change ))
                    (setf(aref A i j (- k 1) )(+(aref A i j (- k 1)) change))
                    )               
                  )
                (if(and (/= k (- maxsize 1)) (/= (aref A i j (+ k 1) ) -1) ) 
                  (progn
                    (setf change(* dC(-(aref A i j k)(aref A i j (+ k 1)))))
                    (setf (aref A i j k)(- (aref A i j k)change ))
                    (setf(aref A i j (+ k 1) )(+(aref A i j (+ k 1)) change))
                    )
                  )
                (if(and (/= j 0) (/= (aref A i (- j 1) k) -1) )
                  (progn
                    (setf change (* dC (- (aref A i j k )(aref A i (- j 1) k))))
                    (setf (aref A i j k)(- (aref A i j k)change ))
                    (setf(aref A i (- j 1) k )(+(aref A i (- j 1) k)change))
                    )
                  )
                (if(and (/= j (- maxsize 1))(/=(aref A i (+ j 1)k ) -1) )
                  (progn
                    (setf change(* dC(-(aref A i j k)(aref A i (+ j 1) k ))))
                    (setf (aref A i j k)(- (aref A i j k)change ))
                    (setf(aref A i (+ j 1) k )(+(aref A i (+ j 1) k)change))

                    )
                  )
                (if(and (/= i 0) (/= (aref A (- i 1) j k) -1) )
                  (progn
                    (setf change (* dC (- (aref A i j k )(aref A (- i 1) j k))))
                    (setf (aref A i j k)(- (aref A i j k)change ))
                    (setf(aref A (- i 1) j k )(+(aref A (- i 1) j k) change))
                    )
                  )

                (if(and (/= i (- maxsize 1 ))(/= (aref A (+ i 1) j k ) -1) ) 
                  (progn
                    (setf change(* dC(-(aref A i j k)(aref A (+ i 1) j k ))))
                    (setf (aref A i j k)(- (aref A i j k)change ))
                    (setf(aref A (+ i 1) j k )(+(aref A (+ i 1) j k) change)) 
                    ) 
                  )
                )  

              )
            )
          )
        )       
      ; mass consistentcy  
      (setf sumval 0)
      (setf maxval (aref A 0 0 0 ) )  
      (setf minval (aref A 0 0 0 ) ) 
      (dotimes (i maxsize) 
        (dotimes (j maxsize)
          (dotimes (k maxsize)
            ; get the maximum and minimum of each cube 
            (if (/= (aref A i j k) -1) 
              (progn
                (if (< (aref A i j k ) minval) 
                  (progn
                    (setf minval (aref A i j k ) ) 
                    ) 
                  )
                (if (> (aref A i j k ) maxval ) 
                  (progn 
                    (setf maxval (aref A i j k ) )
                    )
                  )
                (setf sumval (+ (aref A i j k )sumval) )  
                )
              )
            )
          )
        )
      (setf r ( / minval maxval ) )  
      (format t "~% Sumval ~,2f Ratio ~,2f Maxval ~,2f Minval ~,2f ~%" sumval r maxval minval)
      )
(format t "~% Box equilibrated in ~,2f ~%" tacc)    
; calculates the time after the diffusion code is completed  
 (let ((run2 (get-internal-run-time))
        (real2 (get-internal-real-time)))
    (format t "Computation took:~%")
    (format t "  ~f seconds of real time (Wall Time) ~%"
        (/ (- real2 real1) internal-time-units-per-second))
    (format t "  ~f seconds of run time~%"
        (/ (- run2 run1) internal-time-units-per-second))))

#!/usr/bin/sbcl --script
; recursive function calculates collatz conjecture
(defun numSteps(N)
    (if (= 1 N) 0 
        (if (evenp N)
            (1+ (numSteps (/ N 2) ))
            (1+ (numSteps (+ 1 (* 3 N) ) ) ) ) ) ) 
  

(defvar maximum)
(defvar control)
(defvar steps)
(defvar dup)
(defvar temp)
(defvar dupIndex)
(defvar smallIndex)
(defvar small)
(defvar stepArray)
(defvar numArray)
(setf stepArray (make-array'(10)))
(setf numArray (make-array'(10)))

(format t "Enter a positive number ~%")
(setf maximum(read))
(setf control maximum)
(defvar size 10)
(dotimes (i size)
    (setf(aref stepArray i) 0)
    (setf (aref numArray i) 0)
)
; while the collatz conjecture is still calculating
(loop while (> control 1) do
      (setf maximum control)
       ; calculate collatz conjecture 
      (setf steps  (numSteps maximum)) 
      (setf maximum control)
      (setf dup 0)
      (setf dupIndex 0)
      (setf smallIndex 0)
      (setf small (aref stepArray 0) )
      ; while the index in the array is less than the first element, update it
      (dotimes(i size)
        (if(< (aref stepArray i) small)
          (progn
            (setf small (aref stepArray i))
            (setf smallIndex i)
            )
          )
        ; if the duplicates are found, delete the duplicae
        (if(= (aref stepArray i) steps)
          (progn
            (setf dup 1)
            (setf dupIndex i)
            )
          )
        )
      ; if a duplicate is not found, add it to the arrays
      (if(and (> steps (aref stepArray smallIndex) ) (= dup 0) )
        (progn
          (setf (aref stepArray smallIndex) steps)
          (setf (aref numArray smallIndex) maximum)
          )
        )
      ; if a duplicate is found, just add the number to the numArray not the seqArray
      (if(and (< maximum (aref numArray dupIndex) ) (= dup 1) )
        (progn
          (setf (aref numArray dupIndex) maximum)
          )
        )
      (setf control (- control 1) )
      )
; bubble sort 
(dotimes (j size)
(dotimes (k (- size 1 ) )
    (if(> (aref stepArray k) (aref stepArray (+ k 1) ) )
    (progn
        (setf temp (aref stepArray k) )
        (setf (aref stepArray k) (aref stepArray (+ k 1) ) )
        (setf (aref stepArray (+ k 1) ) temp)

        (setf temp (aref numArray k) )
        (setf (aref numArray k) (aref numArray (+ k 1) ) )
        (setf (aref numArray (+ k 1) ) temp)
    )
    )
)
)
(format t "~% Sorted based on sequence length  ~%" )
(loop for i from (- size 1) downto 0 do
    (format t "~% ~,d     ~,d ~%" (aref numArray i) (aref stepArray i))
)
(format t "~% Sorted based on integer length  ~%" )
(dotimes (j size)
; bubble sort 
(dotimes (k (- size 1 ) )
    (if(> (aref numArray k) (aref numArray (+ k 1) ) )
    (progn
        (setf temp (aref numArray k) )
        (setf (aref numArray k) (aref numArray (+ k 1) ) )
        (setf (aref numArray (+ k 1) ) temp)

        (setf temp (aref stepArray k) )
        (setf (aref stepArray k) (aref stepArray (+ k 1) ) )
        (setf (aref stepArray (+ k 1) ) temp)
    )
    )
)
)


(loop for i from (- size 1) downto 0 do
  (format t "~% ~,d     ~,d ~%" (aref numArray i) (aref stepArray i) ) 
) 

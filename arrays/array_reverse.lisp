(defun array-reverse (arr)
  (do* ((right 0 (1+ right))
        (left (1- (length arr)) (1- left)))
       ((>= left right))
    (rotatef (aref arr left) (aref arr right)))
  arr)

(defun array-reverse (arr)
  (let* ((len (length arr))
         (newarr (make-array len)))
    (dotimes (i len)
      (setf (aref newarr i) (aref arr (- len i 1))))
    newarr))

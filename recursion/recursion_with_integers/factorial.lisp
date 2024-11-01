(defun factorial (n)
  (cond ((< n 0) nil)
        ((or (= n 0) (= n 1)) 1)
        (t (* n (factorial (- n 1))))))


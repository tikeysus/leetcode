(defun choose (n k)
  (cond ((or (< n 0) (< k 0)) nil)
        ((= k 0) 1)
        ((= n k) 1)
        (t (+ (choose (- n 1) k)
              (choose (- n 1) (- k 1))))))


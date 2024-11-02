(defun sum-up-to-n (n)
  (cond
    ((< n 0) nil)
    ((= n 0) 0)
    ((= n 1) 1)
    (t (+ n (sum-up-to-n (- n 1))))))

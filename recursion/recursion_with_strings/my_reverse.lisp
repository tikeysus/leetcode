;; This buffer is for text that is not saved, and for Lisp evaluation.
;; To create a file, visit it with C-x C-f and enter text in its buffer.

(defun my_reverse (s)
  (cond
   ((= (length s) 0) "")
   ((= (length s) 1) s)
   ((= (length s) 2) return (
                             concatenate 'string (string (aref s 1))
                                         (string (aref s 0))))
   (t (concatenate 'string
                   (my_reverse (subseq s 1))
                   (string (aref s 0))))))

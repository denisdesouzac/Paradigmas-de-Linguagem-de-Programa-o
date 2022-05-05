maior::(Ord t)=>[t]->t
maior [e]	= e
maior (c:r) = maiordedois c(maior r)


maiordedois a b
	| a>b	    = a
	| otherwise = b

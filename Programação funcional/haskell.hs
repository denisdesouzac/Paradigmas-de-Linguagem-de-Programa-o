fat::Integer->Integer
fat n = fat' 1 n
	where
	fat' result 0 = result
	fat' result n = fat' (result*n)(n-1)


fibonacci::Integer->Integer
fibonacci 1 	= 1
fibonacci 2 	= 1
fibonacci n 	= fibonacci(n-1)+fibonacci(n-2)


elemento::Int->[t]->t
elemento 1 (c:_) = c
elemento i (_:r) = elemento(i-1)r


pertence::(Eq t)=>t->[t]->Bool
pertence _ [] = False
pertence elem (c:r)
	| elem == c = True
	| Otherwise = pertence elem r


nelementos::[t]->Int
nelementos (_:r) = (nelementos r)+1
nelementos []	 = 0


maior::(Ord t)=>[t]->t
maior [e]	= e
maior (c:r) = maiordedois c(maior r)


maiordedois a b
	| a>b	    = a
	| Otherwise = b


nocorrencias::(Eq t)=>t->[t]->Int
nocorrencias _ [] = 0
nocorrencias e (c:r)
	| e == c    = 1+(nocorrencias e r)
	| Otherwise = nocorrencias e r


unicaocorrencia::(Eq t)=>t->[t]->Bool
unicaocorrenia _ [] = False
unicaocorrenia e (c:r)
	| e == c    = not(pertence e r)
	| Otherwise = unicaocorrenia e r


maioresque::(Ord t)=>t->[t]->[t]
maioresque _ [] = []
maioresque e (c:r)
	| c>e   	= c:(maioresque e r)
	| Otherwise = maioresque e rs



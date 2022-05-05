-- Questão 1
menorDeDois :: (Ord t) => t -> t -> t
menorDeDois a b
	| a < b     = a
	| otherwise = b
	
-- Questão 2
menorDeTres :: (Ord t) => t -> t -> t -> t
menorDeTres a b c = menorDeDois c (menorDeDois a b)

-- Questão 3
fat :: Integer -> Integer
fat n = fat' 1 n
	where
	fat' result 0 = result
	fat' result n = fat' (result*n)(n-1)
	
-- Questão 4
fibonacci :: Integer -> Integer
fibonacci 1 = 1
fibonacci 2 = 1
fibonacci n = fibonacci(n-1) + fibonacci(n-2)

-- Questão 5
elemento :: Int -> [t] -> t
elemento 1 (c:_) = c
elemento e (c:r) = elemento (e-1) r

-- Questão 6
pertence :: (Eq t) => t -> [t] -> Bool
pertence e [] = False
pertence e (c:r)
	| e == c    = True
	| otherwise = pertence e r;
	
-- Questão 7
nroElementos :: [t] -> Int
nroElementos (_:r) = (nroElementos r) + 1
nroElementos []    = 0

-- Questão 8
maior :: [Int] -> Int
maior [e]   = e
maior (c:r) = maiorDeDois c (maior r)

maiorDeDois a b
	| a > b     = a
	| otherwise = b
	
-- Questão 9
nroOcorrencias :: (Eq t) => t -> [t] -> Int
nroOcorrencias _ [] = 0
nroOcorrencias e (c:r)
	| e == c    = (nroOcorrencias e r) + 1
	| otherwise = nroOcorrencias e r
	
-- Questão 10
unica_ocorrencia :: (Eq t)=> t -> [t] -> Bool
unica_ocorrencia _ [] = False
unica_ocorrencia e (c:r)
	|e == c = not(pertence e r)
	|otherwise = unica_ocorrencia e r

-- Questão 11
maioresQue :: (Ord t) => t -> [t] -> [t]
maioresQue _ [] = []
maioresQue e (c:r)
	| c > e = c:(maioresQue e r)
	|otherwise = maioresQue e r
	
-- Questão 11


rm::(Ord t)=>[t]->[t]
rm [] = []
rm [e,f] = [maiorDeDois e f]
rm (c:r) = c:maiorDeDois r (rm r)

---------------------------------

removePenultimo :: (Eq t) => [t] -> [t]
removePenultimo [] = [] 
removePenultimo [e,f] = [f] 
removePenultimo (c:r) = c:(removePenultimo r)

insere::(Ord t) => [t] -> t -> [t]
insere [] e     = [e]
insere (c:r) e  = c:(insere r e)

soma:: [Int] -> Int
soma [] = 0
soma (c:r) = c + soma r

nroElementos :: [t] -> Int
nroElementos (_:r) = (nroElementos r) + 1
nroElementos []    = 0

media :: [Int] -> Int
media [] = 0
media l = quot (soma l)(nroElementos l)

rm::(Ord t)=>[t]->[t]
rm [] = []
rm [e,f] = [maiorDeDois e f]
rm (c:r) = c:maiorDeDois r (rm r)
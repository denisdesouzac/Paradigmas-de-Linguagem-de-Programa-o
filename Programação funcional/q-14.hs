-- Questão 14
removeult::[t]->[t]
removeult [e] = []
removeult (c:r) = c:(removeult r)
-- Questão 15
removerRepetidos :: (Eq t) => [t] -> [t]
removerRepetidos (c:r) = c:(removerRepetidos (removerTodos c r))
removerRepetidos []    = []

removerTodos :: (Eq t) => t -> [t] -> [t]
removerTodos _ [] = []
removerTodos e (c:r)
	| e == c    = removerTodos e r
	| otherwise = c:(removerTodos e r)
-- Questão 16
maiores :: (Ord t) => Int -> [t] -> [t]
maiores n l@(c:r)
	| n >= (nroElementos l) = l
	| otherwise =
		let cComNMaiores = c:(maiores n r)
		in removeUltOc (menor cComNMaiores) cComNMaiores
		
menor :: (Ord t) => [t] -> t
menor [e] = e
menor (c:r) = menorDeDois c (menor r)

menorDeDois :: (Ord t)=> t -> t -> t
menorDeDois a b
	| a < b = a
	|otherwise = b
	
removeUltOc :: (Eq t) => t -> [t] -> [t]
removeUltOc e l = reverse (remove e (reverse l))


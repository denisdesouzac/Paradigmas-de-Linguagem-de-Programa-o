remove:: (Eq t) => t -> [t] -> [t]
remove e (c:r)
	| e == c    = r
	| otherwise = c:remove e r
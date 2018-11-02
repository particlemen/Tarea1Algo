
total = 0
SUCC = 0

with open("output.txt") as our, open("TestFiles/out.txt") as manu: 
	for x, y in zip(our, manu):
		total += 1
		x = x.strip()
		y = y.strip()
		print(x)

		if x == y:
			SUCC += 1

por = (SUCC/total) * 100

print("Un",por, "% de las palabras fueron decodificadas con exito\n")
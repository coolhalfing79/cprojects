from random import randint
with open("randomnumbers.txt", "w") as file:
	for x in range(100):
		a = randint(0, 100)
		file.write(f"{a}\n")

from itertools import permutations

def perms(alphabet: list, length: int, type: list[float]):
	counts = [int(t * length) for t in type]
	string = "".join(str(alphabet[i]) * counts[i] for i in range(len(counts)))
	perms = list(set("".join(p) for p in permutations(string)))
	return sorted(perms)

class Encoder:
	alphabet: list
	index: int
	length: int
	string: str
	type: list[float]

	def __init__(self, string: str):
		self.string = string
		self.length = len(self.string)
		self.alphabet = list(set(string))
		self.type = self.getType()
		self.index = perms(self.alphabet, self.length, self.type).index(string)

	def getType(self):
		type: list[float] = []
		for char in self.alphabet:
			type.append(self.string.count(f"{char}") / self.length)
		return type

	def encode(self):
		return self.alphabet, self.index, self.length, self.type

class Decoder:
	alphabet: list[int]
	index: int
	length: int
	type: list[float]

	def __init__(self, alphabet: list[int],index: int,length: int, type: list[float]):
		self.alphabet = alphabet
		self.length = length
		self.index = index
		self.type = type

	def decode(self):
		type_class = perms(self.alphabet, self.length, self.type)
		return type_class[self.index]

string = "the quick brown fox jumps over the lazy dog"

encoder = Encoder(string)
alphabet, index, length, type = encoder.encode()

decoder = Decoder(alphabet, index, length, type)
print(decoder.decode())

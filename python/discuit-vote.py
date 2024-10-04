def points(up: int, down: int):
	return up - down

def percentage(up: int, down: int):
	return round(up/(up+down) * 100)

for up in range(6001):
	for down in range(6001):
		if points(up, down) == 4 and percentage(up, down) == 84:
			print(f"upvotes: {up}, downvotes: {down}")

// You start at the beginning of an array (index=0). The value of the array at
// that index is the jump distance. Determine if you can reach the end of the
// array.

let myArray = [2, 3, 1, 1, 4]
var i = 0

while true {
	i += myArray[i]

	if i > myArray.count || myArray[i] == 0 {
		print(false)
		break
	} else if i == myArray.count - 1 {
		print(true)
		break
	}
}

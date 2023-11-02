const myArray = Array.from({ length: 1e4 }, (_, i) => i + 1) as (string | number)[];

for (let i = 2; i < 1e4; i += 3) { myArray[i] = "Fizz"; }
for (let i = 4; i < 1e4; i += 5) { myArray[i] = "Buzz"; }
for (let i = 14; i < 1e4; i += 15) { myArray[i] = "FizzBuzz"; }

console.log(myArray);

export { };

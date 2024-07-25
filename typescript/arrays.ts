const arr = new Array(1000).fill(0);
const lights = new Array(1000).fill(arr);

lights[0][1] = 1;
console.log(lights);

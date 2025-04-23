/**
 * This is a fast implentation of the Fibonacci sequence that uses repeated
 * multiplication with the golden ratio to achieve higher performance.
 * @param n Index of Fibonacci sequence to return
 * @returns nth Fibonacci number
 */
function fib(n: number): number {
  if (n < 2) return n;

  let num = 1;
  const PHI = (1 + Math.sqrt(5)) / 2;

  for (let i = 2; i < n; i++) {
    num = Math.round(num * PHI);
  }

  return num;
}

const n = 50;
console.log(fib(n));

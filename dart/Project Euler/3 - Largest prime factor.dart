// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

List factorise(int n) {
  var factors = [];
  
  for (var i = 2; i < (n+1); i++) {
    if (n == 1) {
      break;
    } else {
      while (n % i == 0) {
        for (var x in factors) {
          if (i % x == 0) {
            continue;
          }
        }
        n ~/= i;
        factors.add(i);
      }
    }
  }

  return factors;
}

void main() {
  var factors = factorise(600851475143);
  print(factors[factors.length-1]);
}

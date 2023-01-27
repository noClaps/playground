// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

void main() {
    int rng = 20;
    num ans = 0;

    for (int i = 2; i < (prodOfList(rng)~/rng); i++) {
        if (divisibilityTester(rng, i) != null) {
            ans = divisibilityTester(rng, i);
            break;
        }
    }

    print(ans);
}

int prodOfList(int rng) {
    int product = 1;
    for (int n = 2; n <= rng; n++) {
        product *= n;
    }

    return product;
}

divisibilityTester(int rng, int testVal) {
    List results = [];

    for (int n=2; n<=rng; n++) {
        if (testVal % n == 0) {
            results.add(true);
        } else {
            results.add(false);
        }
    }

    if (results.contains(false) == false) {
        return testVal;
    }
}

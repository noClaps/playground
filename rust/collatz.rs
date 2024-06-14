fn collatz_length(mut n: i32) -> u32 {
    let mut count = 1;
    while n != 1 {
        count += 1;

        if n % 2 == 0 {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }

    count
}

fn main() {
    let n = 11;
    println!("{}", collatz_length(n));
}

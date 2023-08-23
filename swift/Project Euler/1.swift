func sum3Or5(lim: Int) -> Int {
    var n = 0
    var sum = 0
    
    while n < lim {
        if n % 3 == 0 || n % 5 == 0 {
            sum += n
        }

        n += 1
    }

    return sum
}

let sumTo10 = sum3Or5(lim: 10)
print("Sum to 10: \(sumTo10)")

let sumTo1000 = sum3Or5(lim: 1000)
print("Sum to 1000: \(sumTo1000)")

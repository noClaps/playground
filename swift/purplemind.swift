// https://www.youtube.com/watch?v=w6xl0IWrZYc

func problem() -> Double {
    var x = Double.random(in: 0...1)

    while x != 0 && x != 1 {
        let coin = Double.random(in: 0...1)
        if 1 - x > x {
            // closer to 0
            if coin < 0.5 {
                // left
                x = 0
            } else {
                // right
                x += x
            }
        } else {
            // closer to 1
            if coin < 0.5 {
                // left
                x -= 1 - x
            } else {
                // right
                x = 1
            }
        }
    }

    return x
}

var num0 = 0
var num1 = 0

let ATTEMPTS = 100000

for _ in 1...ATTEMPTS {
    if problem() == 0 {
        num0 += 1
    } else {
        num1 += 1
    }
}

print(
    """
    0: \(num0)
    1: \(num1)
    """)

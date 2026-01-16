func switchNumsMod(_ a: Int, _ b: Int) -> (Int, Int) {
    // Switch with a*(a+b-1) mod (a+b)
    // This works because in the field F_(a+b) numbers will wrap around.
    let newA = a * (a + b - 1) % (a + b)
    let newB = b * (a + b - 1) % (a + b)

    return (newA, newB)
}

func switchNumsXor(_ a: Int, _ b: Int) -> (Int, Int) {
    var a = a ^ b
    let b = b ^ a
    a = a ^ b

    return (a, b)
}

func switchNumsSimple(_ a: Int, _ b: Int) -> (Int, Int) {
    var a = a + b
    let b = a - b
    a = a - b

    return (a, b)
}

let a = Int(CommandLine.arguments[1])!
let b = Int(CommandLine.arguments[2])!

print("Switching with mod:", switchNumsMod(a, b))
print("Switching with XOR:", switchNumsXor(a, b))
print("Switching with + and -:", switchNumsSimple(a, b))

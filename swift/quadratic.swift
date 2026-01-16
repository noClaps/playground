let ITERATIONS = 1000

func quadratic_c(_ cm1: Double, _ count: Int = ITERATIONS) -> Double {
    if count == 0 {
        return cm1 / 2
    }
    return cm1 / (2 + quadratic_c(cm1, count - 1))
}

func quadratic_bc(_ b: Double, _ c: Double, _ count: Int = ITERATIONS) -> Double {
    if count == 0 {
        return b
    }
    return b + c / quadratic_bc(b, c, count - 1)
}

func quadratic(_ a: Double, _ b: Double, _ c: Double) -> Double {
    if a == 0 {
        return b / c
    }

    var b = b
    var c = c
    if a != 1 {
        b /= a
        c /= a
    }
    if b == 0 {
        c = -c
        // x^2 = c
        // x^2 - 1 = c - 1
        // (x+1)(x-1) = c-1
        // x-1 = (c-1)/(x+1)
        // x = 1 + (c-1)/(2+x)
        return 1 + quadratic_c(c - 1)
    }

    // x^2 = bx + c
    b = -b
    c = -c
    // x = b + c/x
    //   = b + c/(b + c/x)...
    return quadratic_bc(b, c)
}

let a = Double(CommandLine.arguments[1])!
let b = Double(CommandLine.arguments[2])!
let c = Double(CommandLine.arguments[3])!

print("a = \(a), b = \(b), c = \(c)")
print("x = \(quadratic(a, b, c))")

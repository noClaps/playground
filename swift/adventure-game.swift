import Foundation

let game = [
    ("Welcome to the game! Press 1 to start or 2 to quit", ["1": 1, "2": -1]),
    ("No game here unfortunately. Press 1 to return to main menu or 2 to quit", ["1": 0, "2": -1]),
]

func gameLoop(_ idx: Int) {
    print("\(game[idx].0)\n> ", terminator: "")
    var opt = readLine()!
    while game[idx].1[opt] == nil {
        print("Invalid input, please try again\n> ", terminator: "")
        opt = readLine()!
    }
    let optIdx = game[idx].1[opt]!
    if optIdx == -1 {
        print("Thanks for playing!")
        exit(0)
    }
    gameLoop(optIdx)
}

gameLoop(0)

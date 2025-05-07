import sys

game = [
    ["Welcome to the game! Press 1 to start or 2 to quit", {"1": 1, "2": -1}],
    ["No game here unfortunately. Press 1 to return to main menu or 2 to quit", {"1": 0, "2": -1}]
]

def game_loop(idx):
    opt = input(f"{game[idx][0]}\n> ")
    while opt not in game[idx][1]:
        opt = input("Invalid input, please try again\n> ")
    optIdx = game[idx][1][opt]
    if optIdx == -1:
        print("Thanks for playing!")
        sys.exit()
    game_loop(optIdx)

game_loop(0)

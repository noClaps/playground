# random

A command line tool to generate random numbers.

## Build instructions

```sh
git clone https://github.com/noClaps/playground.git && cd c/random/
cc random.c -o random # replace `cc` with your C compiler, like `gcc` or `clang`
```

## Usage

```
USAGE: random [-i] [--coin] [<min>] [<max>]

ARGUMENTS:
  <min>          The minimum value for the random number generator. (default: 0.0)
  <max>          The maximum value for the random number generator. (default: 1.0)

OPTIONS:
  -i             Should the output be an integer?
  -c, --coin     Flip a coin instead of generating a number.
  -h, --help     Display this help and exit.
```

You can use the tool simply by running:

```sh
random # generates a random number between 0 and 1
```

You can also pass in limits. The defaults are 0 and 1.

```sh
random 10 # generates a random number between 0 and 10
```

If you want to generate integers, you can enable the `-i` flag.

```sh
random -i 5 10 # generates a random integer between 5 and 10
```

If you want to flip a coin, you can use the `-c` or `--coin` flag.

```sh
random -c # returns either Heads or Tails
random --coin
```

You can view the help by using `-h` or `--help`:

```sh
random -h # shows the help menu for the command
random --help
```

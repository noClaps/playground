# psc

A command line tool to check the strength of a password.

**DISCLAIMER**: This is simply a research project, and not a secure password strength checker. If you'd like to really check whether your password is secure, use a proper tool for it.

## Build instructions

```sh
git clone https://github.com/noClaps/playground.git && cd c/psc/
cc psc.c -o psc # replace `cc` with your C compiler, like `gcc` or `clang`
```

## Usage

```
USAGE: psc <password>

ARGUMENTS:
  <password>     The password to check strength of.

OPTIONS:
  -h, --help     Display this help and exit.
```

You can use the tool simply by running:

```sh
psc password123 # Replace "password123" with your password
```

You can view the help by using `-h` or `--help`:

```sh
psc -h
psc --help
```

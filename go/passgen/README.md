# passgen

A command line tool to generate passwords of a given length.

**DISCLAIMER**: This is simply a research project, and not a cryptographically secure password generator. If you'd like to generate truly secure passwords, use a password manager or some other proper tool.

## Build instructions

```sh
git clone https://github.com/noClaps/playground.git && cd go/passgen/
go build
```

## Usage

```
USAGE: passgen <length> [-s <s>]

ARGUMENTS:
  <length>                The length of the password to generate

OPTIONS:
  -s <s>                  The separator for blocks in the password (default: -)
  -h, --help              Show help information.
```

You can use the tool simply by running:

```sh
passgen 24 # Or any other positive whole number
```

You can also pass in a custom separator:

```sh
passgen 24 -s "_"
```

or remove the separator entirely:

```sh
passgen 24 -s ""
```

You can view the help by using `-h` or `--help`:

```sh
passgen -h
passgen --help
```

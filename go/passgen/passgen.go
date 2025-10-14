package main

import (
	"crypto/sha512"
	"encoding/hex"
	"flag"
	"fmt"
	"math/rand"
	"os"
	"slices"
	"strconv"
	"strings"
	"time"
)

func replaceAtIndex(str string, pos int, char byte) string {
	return str[:pos] + string(char) + str[pos+1:]
}

func toggleCase(char byte) byte {
	if strings.ToUpper(string(char)) == string(char) {
		return byte(strings.ToLower(string(char))[0])
	}

	return byte(strings.ToUpper(string(char))[0])
}

func generatePassword(length int, separator string) string {
	password := ""

	for i := 1; i <= length; i++ {
		if separator != "" && length > 6 && i%6 == 0 && i != length {
			password += separator
			continue
		}

		randInt := rand.Intn(length)
		now := time.Now().Unix() * int64(randInt)

		hash := sha512.New()
		hashText := hex.EncodeToString(hash.Sum([]byte(strconv.FormatInt(now, 10))))

		randIndex := rand.Intn(len(hashText))
		password += string(hashText[randIndex])
	}

	for range password {
		randIndex := rand.Intn(max(len(password)-1, 1))
		password = replaceAtIndex(password, randIndex, toggleCase(password[randIndex]))
	}

	return password
}

func findArg(argv []string) (string, []string) {
	for i := range argv {
		if (i == 0 && argv[i][0] != '-') || (i-1 >= 0 && argv[i-1][0] != '-') {
			return argv[i], slices.Concat(argv[:i], argv[i+1:])
		}
	}

	return "", argv
}

func main() {
	var separator string
	flag.StringVar(&separator, "s", "-", "The separator for blocks in the password.")

	arg, remainingArgs := findArg(os.Args[1:])

	flag.CommandLine.Parse(remainingArgs)

	if arg == "" {
		fmt.Println("USAGE: passgen <length> [-s <s>]")
		os.Exit(1)
	}

	length, err := strconv.Atoi(arg)
	if err != nil {
		fmt.Println("\033[31mError parsing arguments: not an integer:\033[0m", arg)
		os.Exit(1)
	}

	password := generatePassword(length, separator)
	fmt.Println(password)
}

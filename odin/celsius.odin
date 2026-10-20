package main

import "core:fmt"
import "core:os"
import "core:strconv"
import "core:strings"

FREEZING_PT :: 32.0
SCALE_FACTOR :: 5.0 / 9.0

main :: proc() {
	buf: [256]byte
	fmt.print("Enter Fahrenheit temperature: ")
	n, read_err := os.read(os.stdin, buf[:])
	if read_err != nil {fmt.eprintfln("Error reading from stdin: %v", read_err); return}

	str := strings.trim_space(string(buf[:n]))

	input, ok := strconv.parse_f64(str)
	if !ok {fmt.eprintfln("Error parsing int from '%s'", str); return}

	celsius := (input - FREEZING_PT) * SCALE_FACTOR
	fmt.printfln("Celsius equivalent: %.1f", celsius)
}

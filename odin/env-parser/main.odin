#+feature dynamic-literals
package main

import "core:fmt"
import "core:os"
import "core:strings"
import "core:testing"

Error :: union #shared_nil {
	os.Error,
}

main :: proc() {}

parse_env :: proc(path: string) -> (map[string]string, Error) {
	f, read_err := os.read_entire_file(path, context.allocator)
	if read_err != nil {return nil, read_err}
	defer delete(f)

	file := string(f)
	defer delete(file)

	lines, lines_err := strings.split_lines(file)
	if lines_err != nil {return nil, lines_err}
	defer delete(lines)

	builder, builder_err := strings.builder_make()
	if builder_err != nil {return nil, builder_err}
	defer strings.builder_destroy(&builder)

	env := make(map[string]string)
	for line in lines {
		// skip comments
		if strings.starts_with(line, "#") {continue}

		parts, parts_err := strings.split_n(line, "=", 2)
		if parts_err != nil {return nil, parts_err}
		defer delete(parts)

		if len(parts) < 1 {continue}
		k := strings.trim_space(parts[0])
		if k == "" {continue} 	// empty keys are not valid

		v := ""
		if len(parts) > 1 {
			v = strings.trim_space(parts[1])
		}

		if strings.starts_with(v, `"`) {
			strings.builder_reset(&builder)
			// remove quotes from quoted value
			for i := 1; v[i] != '"'; i += 1 {
				strings.write_byte(&builder, v[i])
			}
			v = strings.to_string(builder)
		} else if idx := strings.index_proc(v, strings.is_space); idx != -1 {
			// if not quoted, dont capture anything after first whitespace
			v = v[:idx]
		}

		env[k] = v
	}

	return env, nil
}

@(test)
parser_env_test :: proc(t: ^testing.T) {
	env, err := parse_env("testdata/.env")
	testing.expect_value(t, err, nil)
	defer delete(env)

	expected := map[string]string {
		"DB_HOST"   = "localhost",
		"DB_PORT"   = "5432",
		"API_KEY"   = "my_api_key",
		"LOG_FILE"  = "app.log",
		"KEY"       = "VALUE",
		"empty"     = "",
		"another"   = "value=more",
		"quoted"    = "value",
		"newlines"  = "value\\nwith\\nnewlines",
		"comment"   = "value#notacomment",
		"nonascii"  = "value🍪",
		"duplicate" = "2",
	}
	defer delete(expected)

	builder := strings.builder_make()
	defer strings.builder_destroy(&builder)

	for k, v in expected {
		testing.expect(t, k in env)
		testing.expect(
			t,
			env[k] == v,
			fmt.sbprintfln(&builder, "expected env['%s'] to be '%s', got '%s'", k, v, env[k]),
		)
	}
}

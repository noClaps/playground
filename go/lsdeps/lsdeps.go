package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"log"
	"maps"
	"net/http"
	"slices"
)

type npmPackage struct {
	Dependencies         map[string]string `json:"dependencies"`
	OptionalDependencies map[string]string `json:"optionalDependencies"`
	PeerDependencies     map[string]string `json:"peerDependencies"`
}

func main() {
	var skipOptional bool
	flag.BoolVar(&skipOptional, "skipopt", false, "Skip counting optional dependencies.")
	var skipPeer bool
	flag.BoolVar(&skipPeer, "skippeer", false, "Skip counting peer dependencies.")

	flag.Parse()

	name := flag.Arg(0)
	if name == "" {
		log.Fatalln("A package name is required")
	}

	toFetch := []string{name}
	deps := []string{}

	fmt.Print("Fetching dependencies...")

	for len(toFetch) > 0 {
		name := toFetch[0]
		toFetch = toFetch[1:]

		fmt.Printf("\033[2K\rFetching %s...", name)

		url := "https://registry.npmjs.com/" + name + "/latest"
		res, err := http.Get(url)
		if err != nil {
			log.Printf("%v %s\n", err, url)
			continue
		}
		defer res.Body.Close()
		if res.StatusCode != http.StatusOK {
			log.Printf("HTTP %d: %s %s", res.StatusCode, res.Status, url)
			continue
		}

		pkg := new(npmPackage)
		if err := json.NewDecoder(res.Body).Decode(pkg); err != nil {
			log.Printf("%v %s", err, url)
		}

		pkgDeps := slices.Collect(maps.Keys(pkg.Dependencies))
		if !skipOptional {
			pkgDeps = slices.Concat(pkgDeps, slices.Collect(maps.Keys(pkg.OptionalDependencies)))
		}
		if !skipPeer {
			pkgDeps = slices.Concat(pkgDeps, slices.Collect(maps.Keys(pkg.PeerDependencies)))
		}

		for _, dep := range pkgDeps {
			if slices.Contains(deps, dep) {
				continue
			}
			deps = append(deps, dep)
			toFetch = append(toFetch, dep)
		}
	}

	fmt.Print("\033[2K\r")
	fmt.Printf(`Name: %s
URL: https://npmjs.com/package/%s
Dependency count: %d
`, name, name, len(deps))
}

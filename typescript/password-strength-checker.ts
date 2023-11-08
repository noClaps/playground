function charSet(password: string): number {
    let totalCharSet = 0;

    if (password.match(/[A-Z]/)) {
        console.log("✓ Has uppercase");
        totalCharSet += 26;
    } else {
        console.log("✕ does not have uppercase");
    }

    if (password.match(/[a-z]/)) {
        console.log("✓ Has lowercase");
        totalCharSet += 26;
    } else {
        console.log("✕ does not have lowercase");
    }

    if (password.match(/[0-9]/)) {
        console.log("✓ Has numbers");
        totalCharSet += 10;
    } else {
        console.log("✕ does not have numbers");
    }

    if (password.match(/[^A-Za-z0-9]/)) {
        console.log("✓ Has special characters");
        totalCharSet += 33;
    } else {
        console.log("✕ does not have special characters");
    }

    return totalCharSet;
}

function rating(entropy: number): string {
    if (entropy < 20) { return "Very weak"; }
    if (entropy < 40) { return "Weak"; }
    if (entropy < 60) { return "Okay"; }
    if (entropy < 80) { return "Strong"; }
    return "Very strong";
}

console.log("\nWelcome to the noClaps password strength checker\n");

const passwd = prompt("Input your password:") ?? "";
const totalCharSet = charSet(passwd);

const entropy = Math.log2(totalCharSet ** passwd.length);
const pwdRating = rating(entropy);

console.log(`Password entropy: ${ entropy }`);
console.log(`Password rating: ${ pwdRating }\n`);

export { };

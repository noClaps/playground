import 'dart:io';
import 'dart:math';

void main() {
  // Initialise variables
  var numOfCombinations, entropy, numOfGuesses, pwdRating;

  print("\nWelcome to the noClaps password strength checker\n");

  /*
  * Diceware passphrase strength depends on the number of words, not
  * necessarily the words themselves. Password strength depends on the
  * characters in them.
  */
  print("What type of password will you be testing?\n");
  print("[1] Password\n[2] Diceware passphrase\n");
  stdout.write("Type of password: ");
  var pwdType = int.parse(stdin.readLineSync()!);

  switch (pwdType) {
    // Password case
    case 1:
      stdout.write("\nEnter your password: ");
      var password = stdin.readLineSync();

      var totalCharSet = charSet(password);
      var length = password!.length;

      numOfCombinations = BigInt.from(totalCharSet).pow(length).toDouble();
      entropy = log(numOfCombinations) / log(2);
      numOfGuesses = BigInt.from(pow(2, entropy - 1));
      pwdRating = rating(entropy);
      break;

    // Diceware passphrase case
    case 2:
      stdout.write("\nNumber of words: ");
      var wordCount = int.parse(stdin.readLineSync()!);

      /*
      * A die has 6 sides, and to generate 1 word of a diceware password,
      * 5 rolls are needed. Hence, the total number of possibilities for words
      * is 6^5 = 7776
      */
      var totalWordsSet = 7776;
      numOfCombinations = BigInt.from(totalWordsSet).pow(wordCount).toDouble();
      entropy = log(numOfCombinations) / log(2);
      numOfGuesses = BigInt.from(pow(2, entropy - 1));
      pwdRating = rating(entropy);
      break;
  }

  print("\nTotal number of combinations: $numOfCombinations");

  /*
  * "It is important to note that statistically, a brute force attack will not
  * require guessing ALL of the possible combinations to eventually hit the
  * right permutation. We therefore tend to look at the expected number of
  * guesses required which can be rephrased as how many guesses it takes to
  * have a 50% chance of guessing the password.""
  * 
  * Source: https://generatepasswords.org/how-to-calculate-entropy/
  */
  print("Password entropy: $entropy");
  print("Expected number of guesses: $numOfGuesses");
  print("\nPassword strength: $pwdRating");
}

dynamic charSet(password) {
  var totalCharSet = 0;

  if (password!.contains(RegExp(r'[A-Z]'))) {
    print("\n✓ Has uppercase");
    totalCharSet += 26;
  } else {
    print("\n✕ does not have uppercase");
  }

  if (password.contains(RegExp(r'[a-z]'))) {
    print("✓ Has lowercase");
    totalCharSet += 26;
  } else {
    print("✕ does not have lowercase");
  }

  if (password.contains(RegExp(r'[0-9]'))) {
    print("✓ Has numbers");
    totalCharSet += 10;
  } else {
    print("✕ does not have numbers");
  }
  
  /*
  * The regex here checks if the password contains anything except for
  * uppercase letters, lowercase letters or numbers. While this can include a
  * far greater character set than 33, it's safe to assume most people aren't
  * gonna be using those characters.
  */
  if (password.contains(RegExp(r'[^A-Za-z0-9]'))) {
    print("✓ Has special characters");
    totalCharSet += 33;
  } else {
    print("✕ does not have special characters");
  }

  return totalCharSet;
}

dynamic rating(entropy) {
  /*
  * This isn't really based on any scientific criteria, just my own definition
  * of a weak or strong password. This could differ from person to person.
  */
  var pwdRating = "Very weak";

  if (entropy < 40) {
    pwdRating = "Weak";
  } else if (entropy < 60) {
    pwdRating = "Okay";
  } else if (entropy < 80) {
    pwdRating = "Strong";
  } else {
    pwdRating = "Very strong";
  }

  return pwdRating;
}

import "dart:convert";
import "dart:io";

void main() async {
  print("\nWelcome to the noClaps GitHub search\n");

  stdout.write("Search for a user: ");
  final username = stdin.readLineSync(); // Read user input
  print("Fetching data for ${username}...\n");

  final profileUri =
      Uri(scheme: "https", host: "api.github.com", path: "/users/$username");
  final repoUri = Uri(
      scheme: "https", host: "api.github.com", path: "/users/$username/repos");
  final followerUri = Uri(
      scheme: "https",
      host: "api.github.com",
      path: "/users/$username/followers");
  final followingUri = Uri(
      scheme: "https",
      host: "api.github.com",
      path: "/users/$username/following");
  final socialUri = Uri(
      scheme: "https",
      host: "api.github.com",
      path: "/users/$username/social_accounts");

  // Use fetchData() function to fetch data for each of the Uris
  final userData = await fetchData(profileUri);
  List userRepos = await fetchData(repoUri);
  List followers = await fetchData(followerUri);
  List following = await fetchData(followingUri);
  List socials = await fetchData(socialUri);

  if (userData['message'] == "Not Found") {
    // If user is not found, return error and exit
    print("Sorry, that user doesn't exist");
  } else {
    // Display results
    print("Link: ${userData['html_url']}");
    print("Username: ${userData['login']}");
    userData['bio'] != null ? print("Bio: ${userData['bio']}") : "";
    userData['blog'] != "" ? print("Website: ${userData['blog']}") : "";

    // Show followers list, if any
    if (followers.length != 0) {
      print("Followers:");
      for (var follower in followers) {
        print("- ${follower["login"]}: ${follower["html_url"]}");
      }
    }

    // Show following list, if any
    if (following.length != 0) {
      print("Following:");
      for (var user in following) {
        print("- ${user["login"]}: ${user["html_url"]}");
      }
    }

    // Show repos list, if any
    if (userRepos.length != 0) {
      print("Repos:");
      for (var repo in userRepos) {
        print("- ${repo["name"]}: ${repo["html_url"]}");
      }
    }

    // Show social links, if any
    if (socials.length != 0) {
      print("Social links:");
      for (var link in socials) {
        print("- ${link["url"]}");
      }
    }
  }
}

dynamic fetchData(Uri url) async {
  // Create an HTTP connection to the GitHub REST API
  var client = HttpClient();
  try {
    HttpClientRequest request =
        await client.getUrl(url); // Make request with URL
    HttpClientResponse response = await request.close(); // Get response
    final stringData = await response
        .transform(utf8.decoder)
        .join(); // Transform response into string
    final parsedData = json.decode(stringData); // Transform string into JSON

    return parsedData;
  } finally {
    client.close(); // Close connection
  }
}

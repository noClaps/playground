interface UserData {
	login: string;
	html_url: string;
	followers_url: string;
	following_url: string;
	repos_url: string;
	blog: string | null;
	bio: string | null;
}

interface Repos {
	name: string;
	html_url: string;
}

interface Follow {
	login: string;
	html_url: string;
}

console.log("\nWelcome to the noClaps GitHub search\n");
const username = prompt("Search for a user:");
console.log(`Fetching data for ${username}...`);

const userData: UserData | null = await fetch(
	`https://api.github.com/users/${username}`,
).then(async (r) => {
	const json = await r.json();
	if (json.message === "Not Found") {
		console.log("Sorry, that user doesn't exist.");
		return null;
	}
	return json;
});

if (userData) {
	console.log(`
    Username: ${userData.login}
    Link: ${userData.html_url}
    ${userData.bio ? `Bio: ${userData.bio}` : ""}
    ${userData.blog ? `Blog: ${userData.blog}` : ""}
    `);

	let option: string | undefined = "";

	while (option !== "q") {
		option = prompt(
			`Select an option:
1) Show repositories
2) Show followers list
3) Show following list

Press Q to quit.
`,
		)?.toLowerCase();

		console.log();

		switch (option) {
			case "1":
				const repos: Repos[] = await fetch(userData.repos_url).then((r) =>
					r.json(),
				);
				repos.map((repo) => {
					console.log(`- ${repo.name}: ${repo.html_url}`);
				});
				break;
			case "2":
				const followers: Follow[] = await fetch(userData.followers_url).then(
					(r) => r.json(),
				);
				followers.map((follower) => {
					console.log(`- ${follower.login}: ${follower.html_url}`);
				});
				break;
			case "3":
				const following: Follow[] = await fetch(
					userData.following_url.replace("{/other_user}", ""),
				).then((r) => r.json());
				following.map((follower) => {
					console.log(`- ${follower.login}: ${follower.html_url}`);
				});
				break;
			default:
				break;
		}

		console.log();
	}
}

export {};

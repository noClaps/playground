use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();

    println!("Your channel's RSS feed is:");
    println!(
        "https://www.youtube.com/feeds/videos.xml?channel_id={}",
        &args[1]
    );
}

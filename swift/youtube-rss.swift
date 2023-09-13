import Foundation

print("Enter channel ID")
let channelId = readLine() ?? ""
print("Your channel's RSS feed is:")
print("https://www.youtube.com/feeds/videos.xml?channel_id=\(channelId)")

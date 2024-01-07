import Foundation

var count = 200
var argv = CommandLine.arguments

// Repetitions flag (-r)
if try argv.contains(where: { $0.contains(try Regex("-r[0-9]+")) }) {
  let index = try argv.firstIndex(where: { $0.contains(try Regex("-r[0-9]+")) }) ?? 0
  if index != 0 {
    count = Int(argv[index].dropFirst(2)) ?? 200
    argv.remove(at: index)
  }
}

func shell(_ command: String) {
  // https://stackoverflow.com/a/50035059
  let task = Process()

  task.standardOutput = nil
  task.standardError = nil
  task.arguments = ["-c", command]
  task.executableURL = URL(filePath: "/bin/zsh")
  task.standardInput = nil
  do {
    try task.run()
  } catch {
    print(error)
  }
}

func format(_ time: Double) -> String {
  if time < 1 / 1000 {
    return "\((time * 1_000_000)) µs"
  }

  if time < 1 {
    return "\(time * 1000) ms"
  }

  return "\(time)"
}

for i in 1...argv.count - 1 {
  var avg = 0.0
  for _ in 1...count {
    let timeStart = Date()
    shell(argv[i])
    let time = -timeStart.timeIntervalSinceNow
    avg += time
  }
  print("Command: '\(argv[i])'\nTime: \(format(avg / Double(count)))\n")
}

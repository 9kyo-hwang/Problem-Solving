struct Queue<T> {
    private var enqueue: [T] = []
    private var dequeue: [T] = []
    
    var isEmpty: Bool {
        return enqueue.isEmpty && dequeue.isEmpty
    }
    
    mutating func push(_ input: T) {
        enqueue.append(input)
    }
    
    @discardableResult
    mutating func pop() -> T? {
        if dequeue.isEmpty {
            dequeue = enqueue.reversed()
            enqueue = []
        }
        return dequeue.popLast()
    }
}

let input = readLine()!.split(separator:" ").map{Int($0)!}

let n = input[0], m = input[1]
var graph : [[Int]] = Array(repeating: [], count: n + 1)
var visited : [Bool] = Array(repeating: false, count: n + 1)
var result : Int = 0

for _ in 0..<m {
    let tmp = readLine()!.split(separator: " ").map { Int($0)!}
    graph[tmp[0]].append(tmp[1])
    graph[tmp[1]].append(tmp[0])
}

func bfs(start: Int) {
    visited[start] = true
    
    var q = Queue<Int>()
    q.push(start)
    
    while !q.isEmpty {
        let current = q.pop()!
        for i in graph[current] {
            if visited[i] == false {
                q.push(i)
                visited[i] = true
            }
        }
    }
}

for i in 1...n {
    if visited[i] == false {
        bfs(start: i)
        result += 1
    }
}

print(result)
This repository provides a simple C++ implementation of a weighted undirected graph with support for shortest path calculation using a custom recursive approach inspired by Dijkstra's algorithm.

## Features

- Add bidirectional paths with associated costs
- Compute shortest path from a start to a finish vertex
- Print the path and cumulative costs
- Detect and update duplicate paths
- Simple and extensible design

## Usage

### Graph Construction

```cpp
Graph graph(/*start*/0, /*finish*/5);
graph.addPath(0, 1, 4);
graph.addPath(1, 2, 6);
graph.addPath(2, 5, 3);
graph.calculatePath();


### TODO
- [ ] Optimizations
- [ ] Add tests

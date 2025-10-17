#pragma once

#include <limits>
#include <unordered_map>

#include "path.h"
#include "types.h"

/*!
 * \brief The Graph class represents a weighted undirected graph and computes the shortest path
 * between two vertices.
 */
class Graph
{
public:
    explicit Graph(Id start, Id finish);

    void addPath(Id from, Id to, unsigned cost);
    void calculatePath();

private:
    Id findNextVertex(Id id);
    void calculateVertexCost(Id id);
    void printPath() const;

    static constexpr auto _maxCost{ std::numeric_limits<unsigned>::max() };

    Id _start;
    Id _finish;
    std::unordered_map<Path, unsigned> _pathCost;
    std::unordered_map<Id, unsigned> _vertexCost;
    std::vector<Id> _path;
};

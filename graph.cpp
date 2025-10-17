#include "graph.h"

#include <iostream>
/*!
 * \brief Graph::Graph constructs a Graph with a specified \p start and \p finish vertex
 */
Graph::Graph(Id start, Id finish) : _start{ start }, _finish{ finish }
{
}

/**
 * @brief Adds a path (edge) between two vertices with a given cost.
 *        If the path already exists, updates the cost and logs the change.
 * @param from The starting vertex of the path.
 * @param to The ending vertex of the path.
 * @param cost The cost associated with the path.
 */
void Graph::addPath(Id from, Id to, unsigned cost)
{
    const Path edge(from, to);
    if (_pathCost.contains(edge))
    {
        std::cout << "Path already exist. Old cost " << _pathCost[edge] << " new cost " << cost
                  << "\n";
    }

    _pathCost[edge] = cost;
    _vertexCost[to] = _maxCost;
    _vertexCost[from] = _maxCost;
}

/**
 * @brief Calculates the shortest path from the start to the finish vertex.
 *        Uses a recursive cost propagation and greedy vertex selection.
 */
void Graph::calculatePath()
{
    _vertexCost[_start] = 0;

    Id currentVertex{ _start };
    while (currentVertex != _finish)
    {
        for (const auto &[path, cost] : _pathCost)
        {
            if (currentVertex == path.from())
                calculateVertexCost(path.to());
        }
        currentVertex = findNextVertex(currentVertex);
        _path.push_back(currentVertex);
    }

    printPath();
}

/**
 * @brief Finds the next vertex to visit with the minimal cost from the current vertex.
 * @param id The current vertex ID.
 * @return The next vertex ID with the lowest cost.
 */
Id Graph::findNextVertex(Id id)
{
    std::pair<Id, unsigned> minimalCost{ _start, _maxCost };
    for (const auto &[path, cost] : _pathCost)
    {
        if (id != path.from())
            continue;

        if (_vertexCost[path.to()] < minimalCost.second)
            minimalCost = { path.to(), _vertexCost[path.to()] };
    }

    return minimalCost.first;
}

/**
 * @brief Updates the cost to reach a given vertex based on its neighbors.
 *        Recursively calculates costs if needed.
 * @param id The vertex ID to update.
 */
void Graph::calculateVertexCost(Id id)
{
    for (const auto &[path, cost] : _pathCost)
    {
        if (id != path.to())
            continue;

        if (_vertexCost[path.from()] == _maxCost)
            calculateVertexCost(path.from());

        _vertexCost[id] = std::min(_vertexCost[path.from()] + cost, _vertexCost[id]);
    }
}

/**
 * @brief Prints the computed shortest path and associated costs from start to finish.
 */
void Graph::printPath() const
{
    std::cout << "Shortest path from " << _start << " to " << _finish << "\n";
    for (const Id id : _path)
    {
        std::cout << id;
        if (id != _finish)
            std::cout << "->";
    }
    std::cout << ":";
    for (const Id id : _path)
    {
        std::cout << _vertexCost.at(id);
        if (id != _finish)
            std::cout << "->";
    }
    std::cout << "\n";
}

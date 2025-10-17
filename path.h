#pragma once

#include "types.h"

#include <cstddef>
#include <functional>

/*!
 * @brief provides a path between two vertices in the graph
 */
class Path
{
public:
    explicit Path(Id from, Id to);

    Id from() const;
    Id to() const;

    bool operator==(const Path &rv) const;

private:
    Id _from;
    Id _to;
};

namespace std
{
template <>
struct hash<Path>
{
    std::size_t operator()(const Path &p) const
    {
        auto a = std::min(p.from(), p.to());
        auto b = std::max(p.from(), p.to());
        return std::hash<Id>()(a) ^ (std::hash<Id>()(b) << 1);
    }
};
} // namespace std
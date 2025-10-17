#include "path.h"

Path::Path(Id from, Id to) : _from{ from }, _to{ to }
{
}
Id Path::from() const
{
    return _from;
}
Id Path::to() const
{
    return _to;
}
bool Path::operator==(const Path &rv) const
{
    return (rv._from == _from && rv._to == _to) || (rv._to == _from && rv._from == _to);
}

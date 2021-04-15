#include "Node.h"

namespace Pathfinding
{
    Connection::Connection(Node*& node, int cost)
    {
        _node = node;
        _cost = cost;
    }

    Node* Connection::GetNode()
    {
        return _node;
    }

    int Connection::GetCost()
    {
        return _cost;
    }
}

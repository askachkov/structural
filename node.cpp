#include "node.h"

using namespace std;

void Node::add(const NodePtr & node)
{
    m_Children.push_back(node);
}

void Node::draw()
{
    for ( int i = 0; i < m_Children.size(); ++i ){
        if ( i > 0 ){
            std::cout << ", ";
        }
        m_Children[i]->draw();
    }
}

KeyValueNode::KeyValueNode(const StringPtr & key, const NodePtr & value):
    m_Key(key),
    m_Value(value)
{
}

void KeyValueNode::draw()
{
    m_Key->draw();
    std::cout << ": ";
    m_Value->draw();
}
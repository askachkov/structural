#pragma once

#include "node.h"

std::shared_ptr<INode> createNum(double value);
std::shared_ptr<StringNode> createString(const std::string & s);
std::shared_ptr<INode> createPair(const std::string & key, const std::shared_ptr<INode> & value);
std::shared_ptr<Node> createGroup();
std::shared_ptr<INode> createArr(const std::shared_ptr<Node> & inner);
std::shared_ptr<INode> createObj(const std::shared_ptr<Node> & inner);
void log(const std::string & msg);
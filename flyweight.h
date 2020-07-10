#pragma once

#include "factory.h"

std::shared_ptr<StringNode> createFlyweightString(const std::string & s);
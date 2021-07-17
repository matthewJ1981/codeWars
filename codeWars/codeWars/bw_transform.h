#pragma once

#include <string>
#include <utility>

std::pair<std::string, int> encode(const std::string& s);

std::string decode(const std::string& s, int n);
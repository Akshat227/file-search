#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;

int main(int argc, char const *argv[])
{
    std::string path = "/home/akshat";
    std::ofstream outFile("pathdata.txt"); // Opens file for writing (overwrites if exists)
    std::vector<std::string> files;
    for (const auto &entry : fs::recursive_directory_iterator(path))
    {
        std::string filepath = entry.path().string();
        files.push_back(filepath);
        outFile << filepath << "\n";
    }
    std::string target = "cmake";
    outFile.close();
    auto it = std::find(files.begin(), files.end(), target);

    if (it != files.end())
    {
        std::cout << "✅ Found: " << *it << "\n";
    }
    else
    {
        std::cout << "❌ Not found: " << target << "\n";
    }

    return 0;
}

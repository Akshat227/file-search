#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

int main(int argc, char const *argv[])
{
    std::string path = "/home/akshat";
    std::ofstream outFile("pathdata.txt"); // Opens file for writing (overwrites if exists)

    for (const auto &entry : fs::recursive_directory_iterator(path))
    {
        outFile << entry.path() << "\n";
    }
    outFile.close();
    std::cout << "Data written to my_output.txt successfully." << std::endl;
    return 0;
}

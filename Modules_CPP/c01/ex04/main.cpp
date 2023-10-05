#include <iostream>
#include <fstream>
#include <string>

void replace_in_file(const std::string& file_name, const std::string& s1, const std::string& s2)
{
    std::ifstream input_file(file_name);
    if (!input_file.is_open())
    {
        std::cerr << "Error: Unable to open file '" << file_name << "' for reading." << std::endl;
        return;
    }
    std::string output_file_name = file_name + ".replace";
    std::ofstream output_file(output_file_name);
    if (!output_file.is_open())
    {
        std::cerr << "Error: Unable to open file '" << output_file_name << "' for writing." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(input_file, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            std::string new_line = line.substr(0, pos);
            new_line += s2;
            new_line += line.substr(pos + s1.length());
            line = new_line;
            pos += s2.length();
        }
        output_file << line << std::endl;
    }
    input_file.close();
    output_file.close();
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Error: Invalid number of arguments. Expecting 3 arguments: <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    replace_in_file(argv[1], argv[2], argv[3]);
    return 0;
}

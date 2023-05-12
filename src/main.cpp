#include <iostream>
#include <string>
#include <stdexcept>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main(int argc, char *argv[])
{
    try
    {
        int indent = argc > 1 ? std::stoi(argv[1]) : 4;
        std::string buffer(std::istreambuf_iterator<char>(std::cin), {});
        json result = json::parse(buffer);
        std::cout << result.dump(indent) << std::endl;
        return 0;
    }
    catch (std::invalid_argument)
    {
        std::cout << "Invalid indentation. It must be a positive number. :(\n";
        return 1;
    }
    catch (...)
    {
        std::cout << "Bad Input. :(\n";
        return 1;
    }
}
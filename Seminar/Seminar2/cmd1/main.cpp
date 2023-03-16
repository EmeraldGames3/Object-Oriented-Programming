#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input-file> <output-file>" << std::endl;
        return 1;
    }
    std::string inputFileName = argv[1];
    std::string outputFileName = argv[2];
    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Error: Cannot open input file '" << inputFileName << "'." << std::endl;
        return 1;
    }
    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "Error: Cannot open output file '" << outputFileName << "'." << std::endl;
        return 1;
    }
    std::string line;
    int lineCount = 0;
    while (std::getline(inputFile, line) && lineCount < 5) {
        std::cout << line << std::endl;
        outputFile << line << std::endl;
        lineCount++;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
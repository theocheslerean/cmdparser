#include <iostream>
#include <CommandLineParser/cmdparser.h>

using namespace std;
using namespace CommandLineParser;

int main(int argc, char** argv) {

    CMDParser parser(argc,argv);
    auto arguments = parser.get_map();

    // parser.print_arguments();

    cout << arguments["A"].as<int>() << endl;
    cout << arguments["B"].as<int>() << endl;
    cout << arguments["C"].as<unsigned int>() << endl;
    cout << arguments["D"].as<float>() << endl;
    cout << arguments["E"].as<float>() << endl;
    cout << arguments["F"].as<float>() << endl;
    cout << arguments["G"].as<float>() << endl;
    cout << arguments["H"].as<double>() << endl;
    cout << arguments["I"].as<double>() << endl;
    cout << arguments["J"].as<double>() << endl;
    cout << arguments["K"].as<double>() << endl;

    cout << parser.get_map().size() << endl;
    return 0;
}


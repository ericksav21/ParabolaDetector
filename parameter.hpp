#ifndef PARAMETER_H
#define PARAMETER_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;

/**
 * Used for process all user parameters.
 * Returns map<string, string> with the stored parameters.
 */
class Parameter {
private:
	int argc;
	char **argv;
public:
	/**
	 * Receives the same function parameters as main.
	 * You may pass 'argc' and 'argv' as they are defined in main function.
	 */
	Parameter(int argc, char **argv);

	~Parameter();

	/**
	 * Prints info for every parameter that system can handle.
	 */
	void print_help();

	/**
	 * Parses every parameter from argv and creates a map<string, string>,
	 * when key represents the parameter name.
	 */
	map<string, string> process();
};

#endif
#include "parameter.hpp"

Parameter::Parameter(int argc, char **argv) {
	this->argc = argc;
	this->argv = new char*[argc + 1];
	for(int i = 0; i <= argc; i++) {
		this->argv[i] = argv[i];
	}
}

Parameter::~Parameter() {}

void Parameter::print_help() {
	cout << "Parabola detector, made by Erick Salvador Alvarez Valencia." << endl;
	cout << "System help:" << endl;
	cout << "--seed o -S\t" << "Seed for random number generation." << endl;
	cout << "--file o -F\t" << " Name of image, it must have a PGM format." << endl;
	cout << "--algo o -A\t" << " Algorithm to be used for processing: 'UMDA', 'Genetic' or 'Both'." << endl;
	cout << "--psize\t" << " Size of population (UMDA & Genetic A)." << endl;
	cout << "--ngenerations\t" << " Number of generations (UMDA & Genetic A)." << endl;
	cout << "--srate\t" << " Selection percentage (UMDA)." << endl;
	cout << "--urate\t" << " Crossover percentage (Genetic A)." << endl;
	cout << "--mrate\t" << " Mutation percentage (Genetic A)." << endl;
	cout << "--verbose o -V\t" << " Explicit mode (text)." << endl;
}

map<string, string> Parameter::process() {
	map<string, string> res;
	int i = 1;
	while(i < argc) {
		string p_act = string(argv[i]);
		if(p_act == "--seed" || p_act == "-S") {
			res["seed"] = string(argv[++i]);
		}
		else if(p_act == "--file" || p_act == "-F") {
			res["file"] = string(argv[++i]);
		}
		else if(p_act == "--algo" || p_act == "-A") {
			res["algo"] = string(argv[++i]);
		}
		else if(p_act == "--psize") {
			res["psize"] = string(argv[++i]);
		}
		else if(p_act == "--ngenerations") {
			res["ngenerations"] = string(argv[++i]);
		}
		else if(p_act == "--srate") {
			res["srate"] = string(argv[++i]);
		}
		else if(p_act == "--urate") {
			res["urate"] = string(argv[++i]);
		}
		else if(p_act == "--mrate") {
			res["mrate"] = string(argv[++i]);	
		}
		else if(p_act == "--verbose" || p_act == "-V") {
			res["verb"] = "1";	
		}
		else {
			cout << "Unrecognized parameter '" << p_act << endl;
		}
		i++;
	}

	return res;
}
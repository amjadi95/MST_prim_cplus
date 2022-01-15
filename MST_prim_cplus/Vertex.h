#pragma once
#include <vector>

using namespace std;
#define NOPARENT -1;
#define INFINITY  9999;


class Vertex
{

public:
	int Vnumber;
	vector<Vertex> VChildren;
	int Vparent;
	int Vkey;
	int EdgeValue;

	Vertex() {
		Vnumber = 0;		
		Vparent = NOPARENT;
		Vkey = INFINITY;
		EdgeValue = 0;
	}
	

};

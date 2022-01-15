#pragma once

#include "Vertex.h"


class MST_Prim
{
private:
	vector<Vertex> nodes;
	vector<Vertex>* MST;

public:

	

	MST_Prim(vector<Vertex> _nodes, int start)
	{
		nodes = _nodes;
		MST = calculation(start);
	}

	vector<Vertex> get_MST() {
		vector<Vertex> mst;
		for (int i = 0; i < MST->size();i++)
		{
			mst.push_back(MST->at(i));
		}
		return mst;
	}

	vector<Vertex> * calculation(int start)
	{
		vector<Vertex>* answer = new vector<Vertex>;

		vector<Vertex>* Q = new vector<Vertex>;

		for (int i = 0; i < nodes.size();i++)
		{
			Q->push_back(nodes.at(i));
		}


		for (int i = 0; i < Q->size();i++)
		{
			if (Q->at(i).Vnumber == start)
			{
				Q->at(i).Vkey = 0;
				break;
			}
		}

		while (Q->size() > 0)
		{
			Vertex v = minEdge(Q, answer);
			for (int i = 0; i < v.VChildren.size();i++)
			{
				if (v.VChildren.at(i).Vnumber != v.Vparent)
				{
					for (int j = 0; j < Q->size(); j++)
					{
						if (Q->at(j).Vnumber == v.VChildren.at(i).Vnumber)
						{
							if (Q->at(j).Vkey > v.VChildren.at(i).EdgeValue)
							{
								Q->at(j).Vkey = v.VChildren.at(i).EdgeValue;
								Q->at(j).Vparent = v.Vnumber;
								break;
							}

						}
					}
				}
			}
		}
		
		return answer;
	}
	Vertex minEdge(vector<Vertex>* list, vector<Vertex>* answer)
	{
		int min = INFINITY;
		int index = -1;

		for (int i = 0; i < list->size();i++)
		{
			if(list->at(i).Vkey < min)
			{
				min = list->at(i).Vkey;
				index = i;
			}
		}
		
		answer->push_back(list->at(index));
		Vertex temp = list->at(index);
		list->erase(list->begin()+(index));
		return temp;
	}	

};
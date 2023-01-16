#pragma once
#include "ObjectBase.h"
class Game
{
public:
	std::vector<std::vector<Object*>> ColliosionVector;

	Game(int SizeX = 1024, int SizeY = 1024, int CellSize = 2)
	{
		for (int y = 0; y < SizeY; y++)
		{
			std::vector<Object*> Row;
			for (int x = 0; x < SizeX; x++) 
			{
				
					Row.push_back(new Object(y, x, e_NOTHING));
				
			
			}
			ColliosionVector.push_back(Row);
			Row.clear();
		}
		this->m_CellSize = CellSize;
		this->m_SizeX = SizeX;
		this->m_SizeY = SizeY;
		ColliosionVector[100][100]->CellData.CellType = e_WATER;
		ColliosionVector[100][101]->CellData.CellType = e_WATER;
		ColliosionVector[100][102]->CellData.CellType = e_WATER;
		ColliosionVector[100][103]->CellData.CellType = e_WATER;
		ColliosionVector[100][104]->CellData.CellType = e_WATER;
		ColliosionVector[100][105]->CellData.CellType = e_WATER;
	}

	void Loop(int LoopX, int LoopY);
	friend class Object;
	int m_CellSize, m_SizeX, m_SizeY;
private:
};

void Renderer(int LoopX, int LoopY, std::vector<std::vector<Object*>>& ColliosionVector);
void PhysicsUpdate(int LoopX, int LoopY, std::vector<std::vector<Object*>>& ColliosionVector);

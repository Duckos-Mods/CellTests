#pragma once
#include "InForm.hpp"
#include <vector>
#include <raylib.h>

class Object
{
public:
	void Update(std::vector<std::vector<Object*>>& ColliosionVector, int YMax, int XMax);
	Object(int x, int y, Type type)
	{
		this->CellData.x = x;
		this->CellData.y = y;
		this->CellData.CellType = type;
		this->CellData.JustMovedLeft = false;
		this->CellData.JustSetOne = false;
		this->CellData.JustSetTwo = false;

	}
	friend class Game;
	struct {
		Type CellType;
		int x, y;
		double Temp;
		bool JustMovedLeft;
		bool JustSetTwo;
		bool JustSetOne;
		bool JustUpdated;
		bool JustUpdatedTwo;
	} CellData;
private:
};
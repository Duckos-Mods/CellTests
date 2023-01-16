#include "ObjectBase.h"
#include <iostream>

void Object::Update(std::vector<std::vector<Object*>>& ColliosionVector, int YMax, int XMax) {
	YMax += 1;
	if (!ColliosionVector[CellData.x][CellData.y]->CellData.JustSetOne) {
		if (!ColliosionVector[CellData.x][CellData.y]->CellData.JustSetTwo) {
			ColliosionVector[CellData.x][CellData.y]->CellData.JustMovedLeft = false;
		}
		else {
			ColliosionVector[CellData.x][CellData.y]->CellData.JustSetTwo = false;
		}
	}
	else {
		ColliosionVector[CellData.x][CellData.y]->CellData.JustSetOne = false;
	}
	if (!ColliosionVector[CellData.x][CellData.y]->CellData.JustUpdatedTwo) {
		ColliosionVector[CellData.x][CellData.y]->CellData.JustUpdated = false;
	}
	else {
		ColliosionVector[CellData.x][CellData.y]->CellData.JustUpdatedTwo = false;

	}
	switch (CellData.CellType)
	{
		case e_NOTHING: {
			break;
		}
		case e_SAND: {
			if (CellData.y != YMax && ColliosionVector[CellData.x][CellData.y + 1]->CellData.CellType == e_NOTHING)
			{
				ColliosionVector[CellData.x][CellData.y + 1]->CellData.CellType = e_SAND;
				ColliosionVector[CellData.x][CellData.y]->CellData.CellType = e_NOTHING;
				break;
			}
			else if (CellData.y != YMax && CellData.x != 0 && ColliosionVector[CellData.x - 1][CellData.y + 1]->CellData.CellType == e_NOTHING)
			{
				
				if (CellData.y != YMax && ColliosionVector[CellData.x][CellData.y + 1]->CellData.CellType == e_NOTHING || CellData.y != YMax && ColliosionVector[CellData.x - 1][CellData.y]->CellData.CellType == e_NOTHING)
				{	
					ColliosionVector[CellData.x - 1][CellData.y + 1]->CellData.CellType = e_SAND;
					ColliosionVector[CellData.x][CellData.y]->CellData.CellType = e_NOTHING;
				}
				break;
			}
			else if (CellData.y != YMax && CellData.x != 0 && CellData.x != XMax && ColliosionVector[CellData.x + 1][CellData.y + 1]->CellData.CellType == e_NOTHING)
			{
				if (CellData.y != YMax && ColliosionVector[CellData.x][CellData.y + 1]->CellData.CellType == e_NOTHING || CellData.y != YMax && ColliosionVector[CellData.x + 1][CellData.y]->CellData.CellType == e_NOTHING)
				{
					ColliosionVector[CellData.x + 1][CellData.y + 1]->CellData.CellType = e_SAND;
					ColliosionVector[CellData.x][CellData.y]->CellData.CellType = e_NOTHING;
				}
				break;
			}
			else if (CellData.y != YMax && ColliosionVector[CellData.x][CellData.y + 1]->CellData.CellType == e_WATER)
			{
				ColliosionVector[CellData.x][CellData.y + 1]->CellData.CellType = e_SAND;
				ColliosionVector[CellData.x][CellData.y]->CellData.CellType = e_WATER;
				break;
			}
			else if (CellData.y != YMax && CellData.x != 0 && ColliosionVector[CellData.x - 1][CellData.y + 1]->CellData.CellType == e_WATER)
			{
				ColliosionVector[CellData.x - 1][CellData.y + 1]->CellData.CellType = e_SAND;
				ColliosionVector[CellData.x][CellData.y]->CellData.CellType = e_WATER;
				break;
			}
			else if (CellData.y != YMax && CellData.x != XMax && CellData.x != 0 && ColliosionVector[CellData.x + 1][CellData.y + 1]->CellData.CellType == e_WATER)
			{
				ColliosionVector[CellData.x + 1][CellData.y + 1]->CellData.CellType = e_SAND;
				ColliosionVector[CellData.x][CellData.y]->CellData.CellType = e_WATER;
				break;
			}
			break;
		}
		case e_WATER: {
			if (CellData.y != YMax && ColliosionVector[CellData.x][CellData.y + 1]->CellData.CellType == e_NOTHING)
			{
				ColliosionVector[CellData.x][CellData.y + 1]->CellData.CellType = e_WATER;
				ColliosionVector[CellData.x][CellData.y]->CellData.CellType = e_NOTHING;
				break;
			}
			else if (CellData.y != YMax && CellData.x != XMax && CellData.x != 0 && ColliosionVector[CellData.x - 1][CellData.y + 1]->CellData.CellType == e_NOTHING)
			{
				if (CellData.y != YMax && ColliosionVector[CellData.x][CellData.y + 1]->CellData.CellType == e_NOTHING || CellData.y != YMax && ColliosionVector[CellData.x - 1][CellData.y]->CellData.CellType == e_NOTHING) {
					ColliosionVector[CellData.x - 1][CellData.y + 1]->CellData.CellType = e_WATER;
					ColliosionVector[CellData.x][CellData.y]->CellData.CellType = e_NOTHING;
				}
			}
			else if (CellData.y != YMax && CellData.x != XMax && ColliosionVector[CellData.x + 1][CellData.y + 1]->CellData.CellType == e_NOTHING)
			{
				if (CellData.y != YMax && ColliosionVector[CellData.x][CellData.y + 1]->CellData.CellType == e_NOTHING || CellData.y != YMax && ColliosionVector[CellData.x + 1][CellData.y]->CellData.CellType == e_NOTHING)
				{

					ColliosionVector[CellData.x + 1][CellData.y + 1]->CellData.CellType = e_WATER;
					ColliosionVector[CellData.x][CellData.y]->CellData.CellType = e_NOTHING;
				}
			}
			else if (!ColliosionVector[CellData.x][CellData.y]->CellData.JustMovedLeft && CellData.x != XMax && ColliosionVector[CellData.x + 1][CellData.y]->CellData.CellType == e_NOTHING)
			{
				ColliosionVector[CellData.x + 1][CellData.y]->CellData.CellType = e_WATER;
				ColliosionVector[CellData.x][CellData.y]->CellData.CellType = e_NOTHING;
				break;
			}
			else if (!ColliosionVector[CellData.x][CellData.y]->CellData.JustUpdated && CellData.x != 0 && CellData.x != XMax && ColliosionVector[CellData.x - 1][CellData.y]->CellData.CellType == e_NOTHING)
			{
				ColliosionVector[CellData.x - 1][CellData.y]->CellData.CellType = e_WATER;
				ColliosionVector[CellData.x][CellData.y]->CellData.CellType = e_NOTHING;
				ColliosionVector[CellData.x - 1][CellData.y]->CellData.JustMovedLeft = true;
				ColliosionVector[CellData.x - 1][CellData.y]->CellData.JustSetOne = true;
				ColliosionVector[CellData.x - 1][CellData.y]->CellData.JustSetTwo = true;
				ColliosionVector[CellData.x - 1][CellData.y]->CellData.JustUpdated = true;
				ColliosionVector[CellData.x - 1][CellData.y]->CellData.JustUpdatedTwo = true;
				break;
			}
			break;
		}
		default: {
			break;
		}
	}
}
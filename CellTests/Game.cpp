#include "Game.h"
#include "raylib.h"
#include <thread>

int mx = 100;
int my = 100;

void PhysicsUpdate(int LoopX, int LoopY, std::vector<std::vector<Object*>>& ColliosionVector)
{
	while (!WindowShouldClose())
	{
		if (mx > LoopX - 1) {
			mx = LoopX - 1;
		}
		if (mx <= 0) {
			mx = 0;
		}
		if (my > LoopY - 1) {
			my = LoopY - 1;
		}
		if (my < 0) {
			my = 0;
		}
		if (IsKeyDown('K') == true) {
			while (mx <= 0) {
				mx++;
			}
			while (mx >= LoopX - 1) {
				mx--;
			}
			while (my <= 0) {
				my++;
			}
			while (my >= LoopY - 1) {
				my--;
			}

			ColliosionVector[mx][my]->CellData.CellType = e_SAND;
			ColliosionVector[mx + 1][my]->CellData.CellType = e_SAND;
			ColliosionVector[mx - 1][my]->CellData.CellType = e_SAND;
			ColliosionVector[mx][my + 1]->CellData.CellType = e_SAND;
			ColliosionVector[mx][my - 1]->CellData.CellType = e_SAND;
			ColliosionVector[mx + 1][my + 1]->CellData.CellType = e_SAND;
			ColliosionVector[mx - 1][my + 1]->CellData.CellType = e_SAND;
			ColliosionVector[mx + 1][my - 1]->CellData.CellType = e_SAND;
			ColliosionVector[mx + 1][my - 1]->CellData.CellType = e_SAND;
		}
		if (IsKeyDown('E') == true) {
			while (mx <= 0) {
				mx++;
			}
			while (mx >= LoopX - 1) {
				mx--;
			}
			while (my <= 0) {
				my++;
			}
			while (my >= LoopY - 1) {
				my--;
			}

			ColliosionVector[mx][my]->CellData.CellType = e_NOTHING;
			ColliosionVector[mx + 1][my]->CellData.CellType = e_NOTHING;
			ColliosionVector[mx - 1][my]->CellData.CellType = e_NOTHING;
			ColliosionVector[mx][my + 1]->CellData.CellType = e_NOTHING;
			ColliosionVector[mx][my - 1]->CellData.CellType = e_NOTHING;
			ColliosionVector[mx + 1][my + 1]->CellData.CellType = e_NOTHING;
			ColliosionVector[mx - 1][my + 1]->CellData.CellType = e_NOTHING;
			ColliosionVector[mx + 1][my - 1]->CellData.CellType = e_NOTHING;
			ColliosionVector[mx + 1][my - 1]->CellData.CellType = e_NOTHING;
		}
		if (IsKeyDown('F') == true) {
			ColliosionVector[mx][my]->CellData.CellType = e_WATER;
		}
		if (IsKeyDown('B') == true) {
			ColliosionVector[mx][my]->CellData.CellType = e_WOOD;
		}
		if (IsKeyDown('A') == true) {
			mx -= 1;
		}
		if (IsKeyDown('D') == true) {
			mx++;
		}
		if (IsKeyDown('W') == true) {
			my -= 1;
		}
		if (IsKeyDown('S') == true) {
			my++;
		}
		if (IsKeyPressed('U') == true) {

			for (int y = LoopY - 1; y > 0; y--)
			{
				for (int x = LoopX - 1; x > 0; x--)
				{
					ColliosionVector[y][x]->CellData.CellType = e_NOTHING;
				}
			}
		}
		if (IsKeyPressed('X') == true) {

			for (int y = LoopY - 1; y > 0; y--)
			{
				for (int x = LoopX - 1; x > 0; x--)
				{
					ColliosionVector[y][x]->CellData.CellType = e_SAND;
				}
			}
		}
		if (IsKeyPressed('V') == true) {

			for (int y = LoopY - 1; y > 0; y--)
			{
				for (int x = LoopX - 1; x > 0; x--)
				{
					ColliosionVector[y][x]->CellData.CellType = e_WOOD;
				}
			}
		}
		if (IsKeyPressed('Z') == true) {

			for (int y = LoopY - 1; y > 0; y--)
			{
				for (int x = LoopX - 1; x > 0; x--)
				{
					ColliosionVector[y][x]->CellData.CellType = e_WATER;
				}
			}
		}
		for (int y = LoopY - 1; y > 0; y--)
		{
			for (int x = LoopX - 1; x > 0; x--)
			{
				ColliosionVector[y][x]->Update(ColliosionVector, LoopX - 2, LoopY - 1);
			}
		}
	}
}

void Game::Loop(int LoopX, int LoopY)
{
	InitWindow((LoopX * m_CellSize) - m_CellSize, (LoopY * m_CellSize) - m_CellSize, "Tests");
	//SetWindowState(FLAG_VSYNC_HINT);
	std::thread t1(&PhysicsUpdate, LoopX, LoopY, std::ref(ColliosionVector));
	t1.detach();

	while (!WindowShouldClose())
	{
		
		BeginDrawing();
		ClearBackground(BLACK);
		for (int y = LoopY - 1; y > 0 ; y--)
		{
			for (int x = LoopX - 1; x > 0; x--)
			{
				switch (ColliosionVector[y][x]->CellData.CellType)
				{
				case e_NOTHING: {
					break;
				}
				case e_SAND: {
					DrawRectangle((ColliosionVector[y][x]->CellData.x* m_CellSize) - m_CellSize, (ColliosionVector[y][x]->CellData.y* m_CellSize) - m_CellSize, m_CellSize, m_CellSize, YELLOW);
					break;
				}
				case e_WATER: {
					DrawRectangle((ColliosionVector[y][x]->CellData.x* m_CellSize) - m_CellSize, (ColliosionVector[y][x]->CellData.y* m_CellSize) - m_CellSize, m_CellSize, m_CellSize, BLUE);
					break;
				}
				case e_WOOD: {
					DrawRectangle((ColliosionVector[y][x]->CellData.x* m_CellSize) - m_CellSize, (ColliosionVector[y][x]->CellData.y* m_CellSize) - m_CellSize, m_CellSize, m_CellSize, BROWN);
					break;
				}
				default:
					break;
				}
			}
		}

		DrawRectangle((mx* m_CellSize) - m_CellSize, (my* m_CellSize) - m_CellSize, 5, 5, { 255, 0, 0, 150 });
		DrawFPS(05, 5);
		EndDrawing();
	}
				
}//
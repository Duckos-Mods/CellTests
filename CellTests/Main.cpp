
#include "Game.h"

int main() {
	int i = 512;
	Game* game = new Game(i, i, 2);
	game->Loop(i, i);

	return 0;
}
#include "Board.h"

Board::Board()
{
	this->textures.reserve(this->maxRangeOfBlocks);
	this->blocks.reserve(this->countOfBlocks);

	//for (auto countOfBlocks = 0; countOfBlocks < blocks.size(); countOfBlocks++)
	//	this->blocks.push_back(Block());
		
	std::filesystem::path buildPath = std::filesystem::current_path() / "res";

	if (!textures[0].loadFromFile((buildPath / "empty.png").string()) ||
		!textures[1].loadFromFile((buildPath / "circle.png").string()) ||
		!textures[2].loadFromFile((buildPath / "x.png").string())) {
		std::cout << "Failed to load textures." << std::endl;

	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int x = i * 150;
			int y = j * 150;
			this->blocks.push_back(Block(x, y));
		}
	}
	for (auto block : blocks) {
		block.SetSprite(textures[0]);
	}

}
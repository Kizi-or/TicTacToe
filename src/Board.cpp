#include "Board.h"

Board::Board()
{
	this->blocks.reserve(this->countOfBlocks);
		
	std::filesystem::path buildPath = std::filesystem::current_path() / "res";

	if (!textureEmpty.loadFromFile((buildPath / "empty.png").string()) ||
		!textureCircle.loadFromFile((buildPath / "circle.png").string()) ||
		!textureX.loadFromFile((buildPath / "x.png").string())) {
		std::cout << "Failed to load textures." << std::endl;

	}

	for (int rangeOfX = 0; rangeOfX < maxRangeOfBlocks; ++rangeOfX)
		for (int rangeOfY = 0; rangeOfY < maxRangeOfBlocks; ++rangeOfY) {
			int x = rangeOfX * blockShift;
			int y = rangeOfY * blockShift;
			this->blocks.push_back(Block(x, y));
		}

	for (auto& block : blocks)
		block.SetSprite(textureEmpty);

	player = TypeOfPlayer::PlayerX;

}

void Board::DrawBlocksOnScreen(const std::unique_ptr<sf::RenderWindow>& window)
{
	for (const auto& block : blocks)
		window->draw(block.GetSprite());
}

void Board::CheckClick(const sf::Vector2f& clickPosition)
{
	for (auto& block : blocks)
		if (block.GetSprite().getGlobalBounds().contains(clickPosition) && block.GetStateOfBlock())
		{
			player == TypeOfPlayer::PlayerX ? block.SetTypeOfBlock(textureX, TypeOfBlock::X) : block.SetTypeOfBlock(textureCircle, TypeOfBlock::O);
			player == TypeOfPlayer::PlayerX ? player = TypeOfPlayer::PlayerO : player = TypeOfPlayer::PlayerX;
		}
}

const bool Board::IsGameOver() const { return isGameOver; }

void Board::CheckWin(TypeOfBlock typeOfBlock, const  std::string& finalInscription)
{
	//check rows
	for (int shiftOfBlockToCheck = 0; shiftOfBlockToCheck < this->maxRangeOfBlocks; shiftOfBlockToCheck++)
		if (blocks[shiftOfBlockToCheck].GetTypeOfBlock() == typeOfBlock &&
			blocks[shiftOfBlockToCheck + maxRangeOfBlocks].GetTypeOfBlock() == typeOfBlock &&
			blocks[shiftOfBlockToCheck + 2 * maxRangeOfBlocks].GetTypeOfBlock() == typeOfBlock)
		{
			std::cout << finalInscription << std::endl;
		}
	//check columns
	for (int shiftOfBlockToCheck = 0; shiftOfBlockToCheck < this->maxRangeOfBlocks; ++shiftOfBlockToCheck) {
		if (blocks[shiftOfBlockToCheck * maxRangeOfBlocks].GetTypeOfBlock() == typeOfBlock &&
			blocks[shiftOfBlockToCheck * maxRangeOfBlocks + 1].GetTypeOfBlock() == typeOfBlock &&
			blocks[shiftOfBlockToCheck * maxRangeOfBlocks + 2].GetTypeOfBlock() == typeOfBlock)
		{
			std::cout << finalInscription << std::endl;
		}
	}
	if (blocks[0].GetTypeOfBlock() == typeOfBlock &&
		blocks[4].GetTypeOfBlock() == typeOfBlock &&
		blocks[8].GetTypeOfBlock() == typeOfBlock) {
		std::cout << finalInscription << std::endl;
	}

	if (blocks[2].GetTypeOfBlock() == typeOfBlock &&
		blocks[4].GetTypeOfBlock() == typeOfBlock &&
		blocks[6].GetTypeOfBlock() == typeOfBlock) {
		std::cout << finalInscription << std::endl;
	}
}
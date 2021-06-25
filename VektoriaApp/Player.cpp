#include "Player.h"
#include "JobController.h"

Player::Player()
{
}

void Player::initPlayer(int startConcrete, int startSteel, int startWood)
{
	concrete = startConcrete;
	steel = startSteel;
	wood = startWood;
}

void Player::setZufriedenheit1(int)
{
}

void Player::setZufriedenheit2(int)
{
}

void Player::setZufriedenheit3(int)
{
}

int Player::getZufriedenheit1()
{
	return 0;
}

int Player::getZufriedenheit2()
{
	return 0;
}

int Player::getZufriedenheit3()
{
	return 0;
}

void Player::AddFarmingRobot(int count)
{
	_farmingRobots += count;
	JobSystem::JobController::Instance().ActivateFarmingRobot(count);
}

void Player::AddMiningRobot(int count)
{
	_miningRobots += count;
	JobSystem::JobController::Instance().ActivateMiningRobot(count);
}

int Player::GetFarmingRobot()
{
	return _farmingRobots;
}

int Player::GetMiningRobot()
{
	return _miningRobots;
}

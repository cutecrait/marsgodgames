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

void Player::AddConcreteRobot(int count)
{
	_concreteRobots += count;
	robots += count;
	JobSystem::JobController::Instance().ActivateConcreteRobot(count);
}

void Player::AddStoneRobot(int count)
{
	_stoneRobots += count;
	robots += count;
	JobSystem::JobController::Instance().ActivateStoneRobot(count);
}

void Player::AddSteelRobot(int count)
{
	_steelRobots += count;
	robots += count;
	JobSystem::JobController::Instance().ActivateSteelRobot(count);
}

int Player::GetConcreteRobot()
{
	return 0;
}

int Player::GetStoneRobot()
{
	return _stoneRobots;
}

int Player::GetSteelRobot()
{
	return _steelRobots;
}

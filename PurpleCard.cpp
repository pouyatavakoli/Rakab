#include "PurpleCard.hpp"

PurpleCard::PurpleCard(int numberOnTheCardVal, std::string nameVal) : Card(numberOnTheCardVal, "Purple", nameVal) {}

void PurpleCard::startEffect() {}

void PurpleCard::endEffect() {}

void PurpleCard::refresh() {}

void PurpleCard::startEffect(Player &) {}

void PurpleCard::endEffect(Player &) {}


std::string PurpleCard::getName() const {}
std::string PurpleCard::getType() const {}
int PurpleCard::getNumerOnTheCard() const {}
int PurpleCard::getPoints() const {}
void PurpleCard::setPoints(int) {}
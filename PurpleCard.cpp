#include "PurpleCard.hpp"

PurpleCard::PurpleCard(int numberOnTheCardVal, std::string nameVal) : Card(numberOnTheCardVal, "Purple", nameVal) {}

void PurpleCard::startEffect() {}

void PurpleCard::endEffect() {}

void PurpleCard::refresh() {}

void PurpleCard::startEffect(Player &) {}

void PurpleCard::endEffect(Player &) {}

void PurpleCard::startEffect(Game &) {}

void PurpleCard::endEffect(Game &) {}

void PurpleCard::refresh(Game &) {}

void PurpleCard::startEffect(std::vector<Player> &) {}

void PurpleCard::endEffect(std::vector<Player> &) {}

void PurpleCard::refresh(std::vector<Player> &) {}
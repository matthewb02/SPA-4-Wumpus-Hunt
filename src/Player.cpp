//
// Created by benderm on 3/26/2025.
//

#include "Map.h"

#include <iostream>

Player::Player() {
    lives = 3;
    gold = 0;
    torches = 1;
    torchDuration = 6;
    rations = 40;
    arrows = 0;
    keys = 0;
    goldMultiplier = 1.0;
}

Player::~Player() {
    delete map;
}


Map* Player::getMap() {
    return map;
}

void Player::changeMap(Map* map) {
    this -> map = map;
}

int Player::getLives() const {
    return lives;
}

void Player::changeLives(const int dLives) {
    lives += dLives;
}

int Player::getGold() const {
    return gold;
}

void Player::changeGold(const int dGold) {
    gold += dGold;
}

int Player::getTorches() const {
    return torches;
}

void Player::changeTorches(const int dTorches) {
    torches += dTorches;
}

int Player::getTorchDuration() const {
    return torchDuration;
}

void Player::setTorchDuration(const int newTorchDuration) {
    torchDuration = newTorchDuration;
}

void Player::decrementTorchDuration() {
    if (torchDuration > 0) {
        torchDuration--;
        if (torchDuration == 0)
            std::cout << "Your torch burns out!" << std::endl;
    }
}

int Player::getRations() const {
    return rations;
}

void Player::changeRations(const int dRations) {
    rations += dRations;
}

int Player::getArrows() const {
    return arrows;
}

void Player::changeArrows(const int dArrows) {
    arrows += dArrows;
}

int Player::getKeys() const {
    return keys;
}

void Player::changeKeys(const int dKeys) {
    keys += dKeys;
}

double Player::getGoldMultiplier() const {
    return goldMultiplier;
}

void Player::multiplyGoldMultiplier(double multiplier) {
    goldMultiplier *= multiplier;
}

//
// Created by benderm on 3/26/2025.
//

#include "Player.h"

Player::Player() {
    lives = 3;
    gold = 0;
    torches = 1;
    torchDuration = 5;
    rations = 100;
    arrows = 1;
    keys = 0;
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
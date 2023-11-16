// Copyright (c) 2021 Remy Skelton All rights reserved.
//
// Created by: Remy Skelton
// Date: Nov, 15, 2023
// This program will ask the user
// for a number between 0 and 9 and it will tell them if
// they correctly guessed my number with try catch

#include <cmath>
#include <iostream>
#include <random>
#include <string>

int main() {
    // Declare userNumStr
    std::string userGuessStr;
    int userGuessInt;  // Move the declaration outside the try block

    // create a random seed value
    std::random_device rd;
    // create the sequence for number generator
    std::mt19937 gen(rd());

    // declare correct guess
    int correctGuess;

    // declare constants
    const int MIN_NUMBER = 1;
    const int MAX_NUMBER = 10;

    // Create a distribution between 1 and 10
    std::uniform_int_distribution<int> distribution(MIN_NUMBER, MAX_NUMBER);

    // generate correctGuess
    correctGuess = distribution(gen);

    do {
        // Get the userNumStr and display a message about the program
        std::cout << "This program will ask the user";
        std::cout << " for a number between 0 and 9 and it will tell them if";
        std::cout << " they guessed my number correctly.";
        std::cout << "\nEnter your whole number: ";
        std::cin >> userGuessStr;

        try {
            // Convert userGuessStr to int
            userGuessInt = std::stoi(userGuessStr);

            // Convert userGuessStr to float
            float userGuessFloat = std::stof(userGuessStr);

            // check if user number is negative
            if (userGuessInt != userGuessFloat) {
                // display that user number is not positive
                std::cout << userGuessFloat << " is not a positive int."
                        << userGuessInt << std::endl;
            } else if (userGuessInt < 0) {
                // display that user number is not positive
                std::cout << userGuessInt << " is not a positive int."
                        << std::endl;
            } else if (userGuessInt > 9) {
                // display that user number is greater than 9
                std::cout << userGuessInt << " is greater than 9." << std::endl;
            } else {
                // display is not the correct guess
                std::cout << userGuessInt << " is not correct." << std::endl;
            }
        } catch (std::invalid_argument) {
            // Display that the user number was not valid
            std::cout << userGuessStr << " is not a valid int." << std::endl;
        }
    } while (userGuessInt != correctGuess);
    // Display the guess was correct
    std::cout << userGuessInt << " is correct." << std::endl;
}

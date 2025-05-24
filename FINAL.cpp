#include <iostream>

using namespace std;

int main() {
    char words[15][10] = {
        "apple", "house", "water", "paper", "phone",
        "chair", "table", "light", "music", "happy",
        "color", "plant", "money", "world", "peace"
    };
    
    char playAgain = 'y';
    
    while (playAgain == 'y' || playAgain == 'Y') {
        int score = 0;
        int totalQuestions = 5;
        
        int seed = 0;
        cout << "Enter a number to randomize: ";
        cin >> seed;
        if (seed == 0) seed = 12345;
    
    cout << "=== WORD SCRAMBLE GAME ===" << endl;
    cout << "Unscramble the words! You have " << totalQuestions << " questions." << endl;
    cout << "Type your answer and press Enter." << endl << endl;
    
    for (int i = 0; i < totalQuestions; i++) {
        seed = (seed * 1103515245 + 12345) % 2147483647;
        int wordIndex = (seed % 15);
        if (wordIndex < 0) wordIndex = -wordIndex;
        
        char originalWord[10];
        char scrambledWord[10];
        int wordLen = 0;
        
        for (int j = 0; words[wordIndex][j] != '\0'; j++) {
            originalWord[j] = words[wordIndex][j];
            scrambledWord[j] = words[wordIndex][j];
            wordLen++;
        }
        originalWord[wordLen] = '\0';
        scrambledWord[wordLen] = '\0';
        
        if (wordLen > 2) {
            char temp = scrambledWord[0];
            scrambledWord[0] = scrambledWord[2];
            scrambledWord[2] = temp;
        }
        if (wordLen > 1) {
            char temp = scrambledWord[1];
            scrambledWord[1] = scrambledWord[wordLen-1];
            scrambledWord[wordLen-1] = temp;
        }
        if (wordLen > 4) {
            char temp = scrambledWord[wordLen/2];
            scrambledWord[wordLen/2] = scrambledWord[wordLen-2];
            scrambledWord[wordLen-2] = temp;
        }
        
        cout << "Question " << (i + 1) << ": " << scrambledWord << endl;
        cout << "Your answer: ";
        
        char userAnswer[10];
        cin >> userAnswer;
        
        bool isCorrect = true;
        int answerLen = 0;
        
        for (int k = 0; userAnswer[k] != '\0'; k++) {
            answerLen++;
        }
        
        if (answerLen != wordLen) {
            isCorrect = false;
        } else {
            for (int k = 0; k < wordLen; k++) {
                char origChar = originalWord[k];
                char userChar = userAnswer[k];
                
                if (origChar >= 'A' && origChar <= 'Z') {
                    origChar = origChar + 32;
                }
                if (userChar >= 'A' && userChar <= 'Z') {
                    userChar = userChar + 32;
                }
                
                if (origChar != userChar) {
                    isCorrect = false;
                    break;
                }
            }
        }
        
        if (isCorrect) {
            cout << "Correct! Well done!" << endl;
            score++;
        } else {
            cout << "Wrong! The correct answer was: " << originalWord << endl;
        }
        
        cout << endl;
    }
    
    cout << "=== GAME OVER ===" << endl;
    cout << "Your final score: " << score << " out of " << totalQuestions << endl;
    
    if (score == totalQuestions) {
        cout << "Perfect score! You're amazing!" << endl;
    } else if (score >= totalQuestions / 2) {
        cout << "Good job! Keep practicing!" << endl;
    } else {
        cout << "Better luck next time!" << endl;
    }
    
    cout << "\nDo you want to play again? (y/n): ";
    cin >> playAgain;
    cout << endl;
    }
    
    cout << "Thanks for playing!" << endl;
    
    return 0;
}

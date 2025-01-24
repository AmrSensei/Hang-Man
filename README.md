### Hangman Game (Console-Based)

This is a **Hangman Game** developed in **C++**, where the user tries to guess a word by guessing individual letters. The player has a limited number of incorrect guesses before losing the game. The game displays a drawing of a stick figure as the player misses guesses.

#### Features:
- **Random Word Selection**: The game selects a random word from a file (`words.txt`) containing a list of words.
- **Visual Hangman Drawing**: A drawing is shown with each incorrect guess, representing a "hangman" figure. The player starts with an empty figure and gradually adds parts with each incorrect guess.
- **Letter Tracking**: Tracks correctly guessed letters and displays the remaining available letters for the player to choose from.
- **Win/Loss Condition**: The game ends when the player either guesses the word correctly or runs out of attempts (10 wrong guesses).

#### Controls:
- The player is prompted to enter a letter at each step.
- The game continues until either the player wins by guessing the word correctly or loses by reaching the maximum number of incorrect guesses.

#### How to Play:
1. The game will randomly choose a word from a file named `words.txt`.
2. Guess the letters by entering them one by one.
3. Track the correct letters and keep an eye on the hangman drawing to avoid making too many wrong guesses.
4. You lose if the drawing is fully completed (after 10 incorrect guesses), and you win if you guess all the letters of the word correctly before that.

#### Installation:
To run the game, simply compile the source code and ensure that you have a text file named `words.txt` with words you want to guess from. 

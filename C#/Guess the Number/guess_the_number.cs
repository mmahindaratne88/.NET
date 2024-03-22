using System;

class Program {
    static void Main(string[] args) {
        Random random = new Random();
        int randomNumber = random.Next(1, 101);
        int guess, attempts = 0;

        Console.WriteLine("Welcome to the Number Guessing Game!");
        Console.WriteLine("I have selected a number between 1 and 100. You have 5 attempts to guess it.");

        do {
            Console.Write("Enter your guess: ");
            guess = Convert.ToInt32(Console.ReadLine());
            attempts++;

            if (guess > randomNumber) {
                Console.WriteLine("Too high!");
            } else if (guess < randomNumber) {
                Console.WriteLine("Too low!");
            } else {
                Console.WriteLine($"Congratulations! You guessed it right in {attempts} attempts.");
                break;
            }
        } while (attempts < 5);

        if (attempts == 5) {
            Console.WriteLine($"Sorry, you've used all your attempts. The number was: {randomNumber}");
        }
    }
}

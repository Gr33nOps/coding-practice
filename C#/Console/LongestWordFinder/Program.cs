using System;
using System.IO; // This helps us read files
class Program
{
    static void Main()
    {
        // Step 1: Set the name of the text file to read
        string fileName = "moved_example.txt";
        // Step 2: Read all the text from the file
        string text = File.ReadAllText(fileName);
        // Step 3: Split the text into words (using spaces to separate)
        string[] words = text.Split(' ', StringSplitOptions.RemoveEmptyEntries);
        // Step 4: Find the longest word
        string longestWord = ""; // Start with an empty word
        foreach (string word in words)
        {
            if (word.Length > longestWord.Length)
            {
                longestWord = word; // Update if the current word is longer
            }
        }
        // Step 5: Display the longest word
        Console.WriteLine("Longest word: " + longestWord);
    }
}

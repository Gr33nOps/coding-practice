using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {

        Console.WriteLine(" Conditional Logic Example ");
        int score = 78;

        if (score >= 90)
            Console.WriteLine($"Excellent! Your score of {score} is outstanding.");
        else if (score >= 70)
            Console.WriteLine($"Good job! Your score of {score} shows solid performance.");
        else
            Console.WriteLine($"Keep trying! Your score of {score} needs improvement.");

        Console.WriteLine("\n Switch Case Example ");
        char grade = 'B';

        switch (grade)
        {
            case 'A':
                Console.WriteLine("Outstanding Achievement!");
                break;
            case 'B':
                Console.WriteLine("Great Work!");
                break;
            case 'C':
                Console.WriteLine("Satisfactory Performance!");
                break;
            default:
                Console.WriteLine("Keep Working Hard!");
                break;
        }

        Console.WriteLine("\n For Loop Demonstration ");
        for (int counter = 5; counter <= 7; counter++)
            Console.WriteLine($"Count value: {counter}");

        Console.WriteLine("\n While Loop Demonstration ");
        int index = 10;
        while (index <= 12)
        {
            Console.WriteLine($"Index position: {index}");
            index++;
        }

        Console.WriteLine("\n Do-While Loop Demonstration ");
        int value = 20;
        do
        {
            Console.WriteLine($"Current value: {value}");
            value++;
        } while (value <= 22);

        Console.WriteLine("\nForeach Loop Demonstration");
        List<string> colors = new List<string> { "Red", "Blue", "Green", "Yellow" };
        foreach (string color in colors)
            Console.WriteLine($"Color name: {color}");
    }
}
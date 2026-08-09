/*
using System;

class Program1
{
    static void Main()
    {
        Console.WriteLine("Hello World!");
    }
}
*/

/*
using System;

class Program2
{
    static void Main()
    {
        int myNumber = 25;
        double myDecimal = 3.14;
        char myLetter = 'A';
        bool myTruth = true;
        string myText = "Learning C#";

        Console.WriteLine(myNumber);
        Console.WriteLine(myDecimal);
        Console.WriteLine(myLetter);
        Console.WriteLine(myTruth);
        Console.WriteLine(myText);
    }
}
*/

/*
using System;

class Program3
{
    static void Main()
    {
        const int myConstant = 10;
        Console.WriteLine(myConstant);

        myConstant = 20; // This line will cause an error!
        // When you try to change a constant, the compiler gives an error
        // because constants cannot be changed after they are set.
    }
}
*/
/*
using System;

class Program4
{
    static void Main()
    {
        string userName = "Alice";
        Console.WriteLine("Hello " + userName);
    }
}
*/

/*
using System;

class Program5
{
    static void Main()
    {
        int firstNumber = 10;
        int secondNumber = 20;
        int thirdNumber = 30;
        int sum = firstNumber + secondNumber + thirdNumber;

        Console.WriteLine("The sum is: " + sum);
    }
}
*/

//using System;

//class Program6
//{
//    static void Main()
//    {
//        int myInteger = 42;
//        double myDouble = myInteger;

//        Console.WriteLine("Integer: " + myInteger);
//        Console.WriteLine("Double: " + myDouble);
//    }
//}

//using System;

//class Program7
//{
//    static void Main()
//    {
//        double originalNumber = 9.87;
//        int convertedNumber = (int)originalNumber;

//        Console.WriteLine("Original double: " + originalNumber);
//        Console.WriteLine("Converted to int: " + convertedNumber);
//    }
//}

//using System;

//class Program8
//{
//    static void Main()
//    {
//        string textNumber = "123";
//        bool textBool = true;

//        int convertedInt = Convert.ToInt32(textNumber);
//        double convertedDouble = Convert.ToDouble(textNumber);
//        bool convertedBool = Convert.ToBoolean(textBool);
//        string convertedString = Convert.ToString(convertedInt);

//        Console.WriteLine("String to int: " + convertedInt);
//        Console.WriteLine("String to double: " + convertedDouble);
//        Console.WriteLine("String to bool: " + convertedBool);
//        Console.WriteLine("Int to string: " + convertedString);
//    }
//}

//using System;

//class Program9
//{
//    static void Main()
//    {
//        Console.Write("Please enter your name: ");
//        string userInput = Console.ReadLine();
//        Console.WriteLine("Hello " + userInput + "! Nice to meet you!");
//    }
//}

//using System;

//class Program10
//{
//    static void Main()
//    {
//        int myScore = 100;
//        Console.WriteLine("Starting score: " + myScore);

//        myScore += 50;
//        Console.WriteLine("After adding 50: " + myScore);

//        int anotherScore = 25;
//        anotherScore = myScore;
//        Console.WriteLine("Another score assigned: " + anotherScore);
//    }
//}

//using System;

//class Program11
//{
//    static void Main()
//    {
//        Console.Write("What is your favorite color? ");
//        string favoriteColor = Console.ReadLine() ?? "";
//        Console.WriteLine("Your favorite color is " + favoriteColor + "!");
//    }
//}

//using System;

//class Program12
//{
//    static void Main()
//    {
//        Console.Write("Enter first decimal number: ");
//        double firstNumber = Convert.ToDouble(Console.ReadLine());

//        Console.Write("Enter second decimal number: ");
//        double secondNumber = Convert.ToDouble(Console.ReadLine());

//        double result = firstNumber + secondNumber;
//        Console.WriteLine("The sum is: " + result);
//    }
//}

//using System;

//class Program13
//{
//    static void Main()
//    {
//        int firstValue = 5;
//        int secondValue = 10;

//        Console.WriteLine("Before swapping:");
//        Console.WriteLine("First: " + firstValue);
//        Console.WriteLine("Second: " + secondValue);

//        int temporary = firstValue;
//        firstValue = secondValue;
//        secondValue = temporary;

//        Console.WriteLine("After swapping:");
//        Console.WriteLine("First: " + firstValue);
//        Console.WriteLine("Second: " + secondValue);
//    }
//}

//using System;

//class Program14
//{
//    static void Main()
//    {
//        Console.Write("Enter a number: ");
//        int userNumber = Convert.ToInt32(Console.ReadLine());

//        if (userNumber > 0)
//        {
//            Console.WriteLine("The number is positive");
//        }
//        else if (userNumber < 0)
//        {
//            Console.WriteLine("The number is negative");
//        }
//        else
//        {
//            Console.WriteLine("The number is zero");
//        }
//    }
//}

//using System;

//class Program15
//{
//    static void Main()
//    {
//        Console.Write("Enter a number: ");
//        int userNumber = Convert.ToInt32(Console.ReadLine());

//        if (userNumber % 2 == 0)
//        {
//            Console.WriteLine("The number is even");
//        }
//        else
//        {
//            Console.WriteLine("The number is odd");
//        }
//    }
//}


//using System;

//class Program16
//{
//    static void Main()
//    {
//        Console.Write("Enter your age: ");
//        int userAge = Convert.ToInt32(Console.ReadLine());

//        if (userAge >= 18)
//        {
//            Console.WriteLine("You are eligible to vote!");
//        }
//        else
//        {
//            Console.WriteLine("You are not old enough to vote yet");
//        }
//    }
//}

//using System;

//class Program17
//{
//    static void Main()
//    {
//        Console.Write("Enter your exam marks: ");
//        int marks = Convert.ToInt32(Console.ReadLine());

//        if (marks < 0 || marks > 100)
//        {
//            Console.WriteLine("Invalid");
//        }
//        else if (marks >= 90)
//        {
//            Console.WriteLine("Grade: A");
//        }
//        else if (marks >= 75)
//        {
//            Console.WriteLine("Grade: B");
//        }
//        else if (marks >= 60)
//        {
//            Console.WriteLine("Grade: C");
//        }
//        else
//        {
//            Console.WriteLine("Grade: F");
//        }
//    }
//}

//using System;

//class Program18
//{
//    static void Main()
//    {
//        Console.Write("Enter the current hour (0-23): ");
//        int hour = Convert.ToInt32(Console.ReadLine());

//        if (hour >= 0 && hour < 6)
//        {
//            Console.WriteLine("Good night");
//        }
//        else if (hour >= 6 && hour < 12)
//        {
//            Console.WriteLine("Good morning");
//        }
//        else if (hour >= 12 && hour < 18)
//        {
//            Console.WriteLine("Good afternoon");
//        }
//        else if (hour >= 18 && hour < 22)
//        {
//            Console.WriteLine("Good evening");
//        }
//        else if (hour >= 22 && hour <= 23)
//        {
//            Console.WriteLine("Good night");
//        }
//        else
//        {
//            Console.WriteLine("Invalid hour");
//        }
//    }
//}

//using System;

//class Program19
//{
//    static void Main()
//    {
//        Console.Write("Enter a number: ");
//        int number = Convert.ToInt32(Console.ReadLine());

//        if (number % 3 == 0 && number % 5 == 0)
//        {
//            Console.WriteLine("The number is divisible by both 3 and 5");
//        }
//        else
//        {
//            Console.WriteLine("The number is not divisible by both 3 and 5");
//        }
//    }
//}

//using System;

//class Program20
//{
//    static void Main()
//    {
//        Console.Write("Enter first number: ");
//        int first = Convert.ToInt32(Console.ReadLine());

//        Console.Write("Enter second number: ");
//        int second = Convert.ToInt32(Console.ReadLine());

//        Console.Write("Enter third number: ");
//        int third = Convert.ToInt32(Console.ReadLine());

//        int largest = first;

//        if (second > largest)
//        {
//            largest = second;
//        }

//        if (third > largest)
//        {
//            largest = third;
//        }

//        Console.WriteLine("The largest number is: " + largest);
//    }
//}

//using System;

//class Program21
//{
//    static void Main()
//    {
//        Console.Write("Enter a character: ");
//        char letter = Convert.ToChar(Console.ReadLine());

//        char lowerLetter = char.ToLower(letter);

//        if (lowerLetter == 'a' || lowerLetter == 'e' || lowerLetter == 'i' || lowerLetter == 'o' || lowerLetter == 'u')
//        {
//            Console.WriteLine("The character is a vowel");
//        }
//        else
//        {
//            Console.WriteLine("The character is a consonant");
//        }
//    }
//}

//using System;

//class Program22
//{
//    static void Main()
//    {
//        Console.Write("Enter a year: ");
//        int year = Convert.ToInt32(Console.ReadLine());

//        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//        {
//            Console.WriteLine(year + " is a leap year");
//        }
//        else
//        {
//            Console.WriteLine(year + " is not a leap year");
//        }
//    }
//}

//using System;

//class Program23
//{
//    static void Main()
//    {
//        Console.Write("Enter your annual income: ");
//        double income = Convert.ToDouble(Console.ReadLine());

//        double tax = 0;

//        if (income <= 250000)
//        {
//            tax = 0;
//        }
//        else if (income <= 500000)
//        {
//            tax = income * 0.05;
//        }
//        else if (income <= 1000000)
//        {
//            tax = income * 0.10;
//        }
//        else
//        {
//            tax = income * 0.15;
//        }

//        Console.WriteLine("Your income tax is: " + tax);
//        Console.WriteLine("Your net income after tax is: " + (income - tax));
//    }
//}

//using System;

//class Program24
//{
//    static void Main()
//    {
//        Console.Write("Enter a number (1-7): ");
//        int dayNumber = Convert.ToInt32(Console.ReadLine());

//        switch (dayNumber)
//        {
//            case 1:
//                Console.WriteLine("Monday");
//                break;
//            case 2:
//                Console.WriteLine("Tuesday");
//                break;
//            case 3:
//                Console.WriteLine("Wednesday");
//                break;
//            case 4:
//                Console.WriteLine("Thursday");
//                break;
//            case 5:
//                Console.WriteLine("Friday");
//                break;
//            case 6:
//                Console.WriteLine("Saturday");
//                break;
//            case 7:
//                Console.WriteLine("Sunday");
//                break;
//            default:
//                Console.WriteLine("Invalid number! Please enter 1-7");
//                break;
//        }
//    }
//}

//using System;

//class Program25
//{
//    static void Main()
//    {
//        Console.Write("Enter first number: ");
//        double num1 = Convert.ToDouble(Console.ReadLine());

//        Console.Write("Enter second number: ");
//        double num2 = Convert.ToDouble(Console.ReadLine());

//        Console.Write("Enter operation (+, -, *, /): ");
//        char operation = Convert.ToChar(Console.ReadLine() ?? "");

//        double result = 0;

//        switch (operation)
//        {
//            case '+':
//                result = num1 + num2;
//                Console.WriteLine("Result: " + result);
//                break;
//            case '-':
//                result = num1 - num2;
//                Console.WriteLine("Result: " + result);
//                break;
//            case '*':
//                result = num1 * num2;
//                Console.WriteLine("Result: " + result);
//                break;
//            case '/':
//                if (num2 != 0)
//                {
//                    result = num1 / num2;
//                    Console.WriteLine("Result: " + result);
//                }
//                else
//                {
//                    Console.WriteLine("Cannot divide by zero!");
//                }
//                break;
//            default:
//                Console.WriteLine("Invalid operation!");
//                break;
//        }
//    }
//}

//using System;

//class Program26
//{
//    static void Main()
//    {
//        Console.Write("Enter month number (1-12): ");
//        int month = Convert.ToInt32(Console.ReadLine());

//        switch (month)
//        {
//            case 1:
//            case 3:
//            case 5:
//            case 7:
//            case 8:
//            case 10:
//            case 12:
//                Console.WriteLine("This month has 31 days");
//                break;
//            case 4:
//            case 6:
//            case 9:
//            case 11:
//                Console.WriteLine("This month has 30 days");
//                break;
//            case 2:
//                Console.WriteLine("This month has 28 or 29 days");
//                break;
//            default:
//                Console.WriteLine("Invalid month number!");
//                break;
//        }
//    }
//}

//using System;

//class Program27
//{
//    static void Main()
//    {
//        Console.Write("Enter your grade (A, B, C, F): ");
//        char grade = Convert.ToChar(Console.ReadLine() ?? "".ToUpper());

//        switch (grade)
//        {
//            case 'A':
//                Console.WriteLine("Excellent! You did great!");
//                break;
//            case 'B':
//                Console.WriteLine("Good job! Keep it up!");
//                break;
//            case 'C':
//                Console.WriteLine("You passed, but try harder next time!");
//                break;
//            case 'F':
//                Console.WriteLine("Sorry, you failed. Study more!");
//                break;
//            default:
//                Console.WriteLine("Invalid grade entered!");
//                break;
//        }
//    }
//}

//using System;

//class Program28
//{
//    static void Main()
//    {
//        Console.Write("Enter fuel type (Petrol, Diesel, Electric): ");
//        string fuelType = Console.ReadLine() ?? "".ToLower();

//        switch (fuelType)
//        {
//            case "petrol":
//                Console.WriteLine("Petrol engines are common and affordable");
//                break;
//            case "diesel":
//                Console.WriteLine("Diesel engines are fuel efficient and powerful");
//                break;
//            case "electric":
//                Console.WriteLine("Electric vehicles are eco-friendly and quiet");
//                break;
//            default:
//                Console.WriteLine("Unknown fuel type!");
//                break;
//        }
//    }
//}

// WHILE LOOP PROGRAMS

//// 5. Print Numbers 1 to 10
//using System;

//class Program29
//{
//    static void Main()
//    {
//        int number = 1;

//        while (number <= 10)
//        {
//            Console.Write(number + " ");
//            number++;
//        }
//    }
//}

//// 6. Odd Numbers Between 1 and 50
//using System;

//class Program30
//{
//    static void Main()
//    {
//        int number = 1;

//        Console.WriteLine("Odd numbers between 1 and 50:");
//        while (number <= 50)
//        {
//            if (number % 2 != 0)
//            {
//                Console.Write(number + " ");
//            }
//            number++;
//        }
//    }
//}

//// 7. Sum of First 10 Natural Numbers
//using System;

//class Program31
//{
//    static void Main()
//    {
//        int number = 1;
//        int sum = 0;

//        while (number <= 10)
//        {
//            sum = sum + number;
//            number++;
//        }

//        Console.WriteLine("Sum of first 10 natural numbers: " + sum);
//    }
//}

//// 8. Digit Counter
//using System;

//class Program32
//{
//    static void Main()
//    {
//        Console.Write("Enter an integer: ");
//        int number = Convert.ToInt32(Console.ReadLine());

//        int originalNumber = number;
//        int digitCount = 0;

//        if (number == 0)
//        {
//            digitCount = 1;
//        }
//        else
//        {
//            if (number < 0)
//            {
//                number = -number;
//            }

//            while (number > 0)
//            {
//                number = number / 10;
//                digitCount++;
//            }
//        }

//        Console.WriteLine("Number of digits in " + originalNumber + " is: " + digitCount);
//    }
//}

// DO-WHILE LOOP PROGRAMS

//// 9. Multiplication Table Generator
//using System;

//class Program33
//{
//    static void Main()
//    {
//        Console.Write("Enter a number for multiplication table: ");
//        int number = Convert.ToInt32(Console.ReadLine());

//        int multiplier = 1;

//        Console.WriteLine("Multiplication table of " + number + ":");
//        do
//        {
//            int result = number * multiplier;
//            Console.WriteLine(number + " x " + multiplier + " = " + result);
//            multiplier++;
//        }
//        while (multiplier <= 10);
//    }
//}

//// 10. Password Prompt Loop
//using System;

//class Program34
//{
//    static void Main()
//    {
//        string correctPassword = "secret123";
//        string enteredPassword;

//        do
//        {
//            Console.Write("Enter the password: ");
//            enteredPassword = Console.ReadLine() ?? "";

//            if (enteredPassword != correctPassword)
//            {
//                Console.WriteLine("Wrong password! Try again.");
//            }
//        }
//        while (enteredPassword != correctPassword);

//        Console.WriteLine("Password correct! Access granted.");
//    }
//}

//// 11. Countdown from 10 to 1
//using System;

//class Program35
//{
//    static void Main()
//    {
//        int number = 10;

//        Console.Write("Countdown: ");
//        do
//        {
//            Console.Write(number + " ");
//            number--;
//        }
//        while (number >= 1);

//        Console.WriteLine("Blast off!");
//    }
//}

//// FOR LOOP PROGRAMS

//// 12. Even Numbers from 1 to 20
//using System;

//class Program36
//{
//    static void Main()
//    {
//        Console.Write("Even numbers from 1 to 20: ");
//        for (int number = 1; number <= 20; number++)
//        {
//            if (number % 2 == 0)
//            {
//                Console.Write(number + " ");
//            }
//        }
//    }
//}

//// 13. Factorial Calculation
//using System;

//class Program37
//{
//    static void Main()
//    {
//        Console.Write("Enter a number to find its factorial: ");
//        int number = Convert.ToInt32(Console.ReadLine());

//        int factorial = 1;

//        for (int i = 1; i <= number; i++)
//        {
//            factorial = factorial * i;
//        }

//        Console.WriteLine("Factorial of " + number + " is: " + factorial);
//    }
//}

//// 14. Squares of Numbers 1 to 10
//using System;

//class Program38
//{
//    static void Main()
//    {
//        Console.WriteLine("Squares of numbers 1 to 10:");
//        for (int number = 1; number <= 10; number++)
//        {
//            int square = number * number;
//            Console.WriteLine(number + " squared is: " + square);
//        }
//    }
//}

//// PATTERN AND NESTED LOOPS

//// 1. Right-Angled Triangle Pattern
//using System;

//class Program39
//{
//    static void Main()
//    {
//        Console.Write("Enter number of rows: ");
//        int rows = Convert.ToInt32(Console.ReadLine());

//        for (int i = 1; i <= rows; i++)
//        {
//            for (int j = 1; j <= i; j++)
//            {
//                Console.Write("* ");
//            }
//            Console.WriteLine();
//        }
//    }
//}

//// 2. Multiplication Tables (2 to 5)
//using System;

//class Program40
//{
//    static void Main()
//    {
//        for (int table = 2; table <= 5; table++)
//        {
//            Console.WriteLine("Multiplication table of " + table + ":");
//            for (int multiplier = 1; multiplier <= 10; multiplier++)
//            {
//                int result = table * multiplier;
//                Console.Write(table + " x " + multiplier + " = " + result + "\t");
//            }
//            Console.WriteLine();
//        }
//    }
//}

//// 3. Dice Combinations (1-6)
//using System;

//class Program41
//{
//    static void Main()
//    {
//        Console.WriteLine("All possible combinations of two dice:");
//        for (int dice1 = 1; dice1 <= 6; dice1++)
//        {
//            for (int dice2 = 1; dice2 <= 6; dice2++)
//            {
//                Console.Write("Dice 1: " + dice1 + ", Dice 2: " + dice2 + "\t");
//            }
//            Console.WriteLine();
//        }
//    }
//}

//// CONTROL FLOW WITH BREAK AND CONTINUE

//// 4. Break on Number 6
//using System;

//class Program42
//{
//    static void Main()
//    {
//        for (int number = 1; number <= 10; number++)
//        {
//            if (number == 6)
//            {
//                break;
//            }
//            Console.Write(number + " ");
//        }
//        Console.WriteLine("Stopped at number 6");
//    }
//}

//// 5. Break on Sentinel Value
//using System;

//class Program43
//{
//    static void Main()
//    {
//        Console.WriteLine("Enter up to 5 numbers (enter -1 to stop):");

//        for (int i = 1; i <= 5; i++)
//        {
//            Console.Write("Enter number " + i + ": ");
//            int userInput = Convert.ToInt32(Console.ReadLine());

//            if (userInput == -1)
//            {
//                Console.WriteLine("You entered -1. Stopping input.");
//                break;
//            }

//            Console.WriteLine("You entered: " + userInput);
//        }

//        Console.WriteLine("Input session ended.");
//    }
//}

//// 6. Skip Number 5
//using System;

//class Program44
//{
//    static void Main()
//    {
//        for (int number = 1; number <= 10; number++)
//        {
//            if (number == 5)
//            {
//                continue;
//            }
//            Console.Write(number + " ");
//        }
//    }
//}

//// 7. Skip Negative Inputs
//using System;

//class Program45
//{
//    static void Main()
//    {
//        int[] positiveNumbers = new int[10];
//        int count = 0;

//        Console.WriteLine("Enter 10 numbers:");

//        for (int i = 1; i <= 10; i++)
//        {
//            Console.Write("Enter number " + i + ": ");
//            int userInput = Convert.ToInt32(Console.ReadLine());

//            if (userInput < 0)
//            {
//                Console.WriteLine("Negative number skipped.");
//                continue;
//            }

//            positiveNumbers[count] = userInput;
//            count++;
//        }

//        Console.WriteLine("Positive numbers you entered:");
//        for (int i = 0; i < count; i++)
//        {
//            Console.Write(positiveNumbers[i] + " ");
//        }
//    }
//}

//// ARRAY HANDLING AND DATA PROCESSING

// 8. Store and Display Student Marks
//using System;

//class Program46
//{
//    static void Main()
//    {
//        int[] marks = new int[10];

//        Console.WriteLine("Enter marks for 10 students:");

//        for (int i = 0; i < 10; i++)
//        {
//            Console.Write("Enter marks for student " + (i + 1) + ": ");
//            marks[i] = Convert.ToInt32(Console.ReadLine());
//        }

//        Console.WriteLine("All student marks:");
//        for (int i = 0; i < 10; i++)
//        {
//            Console.WriteLine("Student " + (i + 1) + ": " + marks[i]);
//        }
//    }
//}

//// 9. Find Highest, Lowest, and Average Marks
//using System;

//class Program47
//{
//    static void Main()
//    {
//        int[] marks = new int[10];

//        Console.WriteLine("Enter marks for 10 students:");

//        for (int i = 0; i < 10; i++)
//        {
//            Console.Write("Enter marks for student " + (i + 1) + ": ");
//            marks[i] = Convert.ToInt32(Console.ReadLine());
//        }

//        int highest = marks[0];
//        int lowest = marks[0];
//        int sum = 0;

//        for (int i = 0; i < 10; i++)
//        {
//            if (marks[i] > highest)
//            {
//                highest = marks[i];
//            }

//            if (marks[i] < lowest)
//            {
//                lowest = marks[i];
//            }

//            sum = sum + marks[i];
//        }

//        double average = (double)sum / 10;

//        Console.WriteLine("All student marks:");
//        for (int i = 0; i < 10; i++)
//        {
//            Console.WriteLine("Student " + (i + 1) + ": " + marks[i]);
//        }

//        Console.WriteLine("Highest mark: " + highest);
//        Console.WriteLine("Lowest mark: " + lowest);
//        Console.WriteLine("Average mark: " + average);
//    }
//}

// 10. Pass/Fail Count
using System;

class Program48
{
    static void Main()
    {
        int[] marks = new int[10];

        Console.WriteLine("Enter marks for 10 students:");

        for (int i = 0; i < 10; i++)
        {
            Console.Write("Enter marks for student " + (i + 1) + ": ");
            marks[i] = Convert.ToInt32(Console.ReadLine());
        }

        int highest = marks[0];
        int lowest = marks[0];
        int sum = 0;
        int passCount = 0;
        int failCount = 0;

        for (int i = 0; i < 10; i++)
        {
            if (marks[i] > highest)
            {
                highest = marks[i];
            }

            if (marks[i] < lowest)
            {
                lowest = marks[i];
            }

            sum = sum + marks[i];

            if (marks[i] >= 40)
            {
                passCount++;
            }
            else
            {
                failCount++;
            }
        }

        double average = (double)sum / 10;

        Console.WriteLine("All student marks:");
        for (int i = 0; i < 10; i++)
        {
            Console.WriteLine("Student " + (i + 1) + ": " + marks[i]);
        }

        Console.WriteLine("Highest mark: " + highest);
        Console.WriteLine("Lowest mark: " + lowest);
        Console.WriteLine("Average mark: " + average);
        Console.WriteLine("Students who passed (marks >= 40): " + passCount);
        Console.WriteLine("Students who failed (marks < 40): " + failCount);
    }
}
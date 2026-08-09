using System;

namespace programOne
{
  class PROGRAM
  {
    public static void one()
    {
      Console.WriteLine("Prorgam one");    
    }
    }
}
namespace programTwo
{
    class PROGRAM
    {
        public static void two()
        {
            Console.WriteLine("Program two");
        }
    }
}
namespace main 
{
    class PROGRAM
    {
        static void Main()
        {
            programOne.PROGRAM.one();
            programTwo.PROGRAM.two();
        }
    }
}

using System;
namespace fact {
    class PROGRAM {
        static void Main()
        {
            Console.Write("Enter number:");
            int number = Convert.ToInt32(Console.ReadLine());
            int fact = 1;
            for (int i = 1; i <= number; i++) { 
                fact *= i; 
            }
            Console.Write(fact);
        }
    }
}

using System;
namespace linearSearch
{
    class PROGRAM
    {
        static void Main()
        {
            int[] arr = { 10, 20, 30, 40, 50 };
            Console.Write("Enter the number that you want to find: ");
            int number = Convert.ToInt32(Console.ReadLine());

            bool found = false;
            for (int i = 0; i < arr.Length; i++) {
                if (arr[i] == number)
                {
                    Console.WriteLine("Number is found at index " + i);
                    found = true;
                    break;
                }
            }
            if (!found) {
                Console.WriteLine("Number is not found");
            }
        }
    }
}


using System;
namespace bubleSort
{
    class BUBBLE_SORT
    {
        static void Main()
        {
            int[] arr = { 3, 2, 5, 1, 4 };
            int n = arr.Length;
            
            for (int i = 0; i<n-1; i++) {
                for (int j = 0; j<n-i-1; j++) {
                    if (arr[j] > arr[j+1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            Console.Write("Sorted array: ");
            foreach(int num in arr){
                Console.Write(num + " ");
            }
        }
    }
}

using System;
namespace SelcectionSort
{
    class SELECTION_SORT
    {
        static void Main()
        {
            int[] arr = { 3, 2, 5, 1, 4 };
            int n = arr.Length;

            for (int i = 0; i < n - 1; i++)
            {
                int minindex = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] < arr[minindex])
                    {
                        minindex = arr[j];
                    }
                }
                int temp = arr[minindex];
                arr[minindex] = arr[i];
                arr[i] = temp;
            }
            Console.Write("Sorted array: ");
            foreach (int num in arr)
            {
                Console.Write(num + " ");
            }
        }
    }
}
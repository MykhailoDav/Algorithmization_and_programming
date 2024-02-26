//Добрий день! Віктор Генадійович, в мене тут в останньому слові 4 букви а: кашааа
//Hello, here is 3 'a' sumbol: Hondaaa
namespace Lab_8_1
{
    public static class MyProgram
    {
        public static void Main()
        {
            string str;
            Console.WriteLine("Enter string");
            str = Console.ReadLine();

            int count_a_int_str = Count_a(str);

            if (count_a_int_str !=-1)         
                Console.WriteLine($"The number of 'a' in the last word is: {count_a_int_str}");
            else
                Console.WriteLine("No words in the input");

        }
        public static int Count_a(string input)
        {           
            string[] words = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                
            if (words.Length > 0)
            {               
                string lastWord = words[words.Length - 1];

                int countOfA = lastWord.Count(c => c == 'a' || c == 'а');

                return countOfA;
            }
            else           
                return -1;            
        }
    }
}
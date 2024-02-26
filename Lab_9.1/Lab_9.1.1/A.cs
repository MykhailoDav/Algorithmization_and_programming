using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba_9_1_1
{   
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;//Для виводу кирилиці

            int NumberOfStudent;
            Console.Write("Введіть кількість студентів: ");
            while (!int.TryParse(Console.ReadLine(), out NumberOfStudent) || NumberOfStudent < 0 )
            {
                Console.WriteLine("Некоректне значення. Введiть цiле число");
                Console.Write("Кiлькiсть студентiв: ");
            }

            StudentA.Student[] students = new StudentA.Student[NumberOfStudent];
            StudentA.GetStudentInfo(ref students);
            StudentA.PrintStudentInfo(students);

            double[] average = new double[NumberOfStudent];
            StudentA.AverageScore(students, ref average);
            StudentA.PrintAverageScore(students, in average);

            Console.WriteLine("Процент студентів, які отримали з фізики оцінки “5” або “4”: " + StudentA.percentageOf_A_Students(students) + "%");
        }
    }
    public class StudentA
    {
        public enum Specialties
        {
            ComputerScience = 1,
            Informatics,
            MathematicsAndEconomics,
            PhysicsAndInformatics,
            LaborTraining
        }


        public struct Student
        {
            public string LastName;
            public int Course;
            public Specialties Specialty;
            public int PhysicsGrade;
            public int MathGrade;
            public int ComputerScienceGrade;
        }
       public static void GetStudentInfo(ref Student[] students)
        {
            for (int i = 0; i < students.Length; i++)
            {
                Console.WriteLine($"Введiть iнформацiю для студента {i + 1}:");
                Console.Write("Прiзвище: ");
                students[i].LastName = Console.ReadLine();

                Console.Write("Курс: ");
                while (!int.TryParse(Console.ReadLine(), out students[i].Course) || students[i].Course < 1 || students[i].Course > 6)
                {
                    Console.WriteLine("Некоректне значення. Введiть цiле число від 1 до 6");
                    Console.Write("Курс: ");
                }

                Console.WriteLine("Виберiть спецiальнiсть зi списку: ");
                foreach (var specialty in Enum.GetValues(typeof(Specialties)))
                    Console.WriteLine($"{(int)specialty}: {specialty}");

                Console.Write("Введіть номер спеціальності: ");

                while (!Enum.TryParse(Console.ReadLine(), out students[i].Specialty) || students[i].Specialty < Specialties.ComputerScience || students[i].Specialty > Specialties.LaborTraining)
                {
                    Console.WriteLine("Некоректне значення. Введіть число від 1 до 28.");
                    Console.Write("Введіть номер спеціальності: ");
                }
                Console.Write("Оцiнка з фiзики: ");
                while (!int.TryParse(Console.ReadLine(), out students[i].PhysicsGrade) || students[i].PhysicsGrade < 1 || students[i].PhysicsGrade > 5)
                {
                    Console.WriteLine("Некоректне значення. Введiть число від 1 до 5.");
                    Console.Write("Оцiнка з фiзики: ");
                }
                Console.Write("Оцiнка з математики: ");
                while (!int.TryParse(Console.ReadLine(), out students[i].MathGrade) || students[i].MathGrade < 1 || students[i].MathGrade > 5)
                {
                    Console.WriteLine("Некоректне значення. Введіть число вiд 1 до 5.");
                    Console.Write("Оцiнка з математики: ");
                }
                Console.Write("Оцiнка з iнформатики: ");
                while (!int.TryParse(Console.ReadLine(), out students[i].ComputerScienceGrade) || students[i].ComputerScienceGrade < 1 || students[i].ComputerScienceGrade > 5)
                {
                    Console.WriteLine("Некоректне значення. Введiть число від 1 до 5.");
                    Console.Write("Оцiнка з iнформатики: ");
                }
                Console.WriteLine();
            }
        }
       public static void PrintStudentInfo(Student[] students)
        {
            Console.WriteLine("Список студентів: ");

            // Виведення верхньої частини таблиці
            Console.WriteLine("┌─────┬───────────────┬─────┬───────────────────────┬──────────┬──────────┬───────────────┐");
            // Виведення заголовка таблиці
            Console.WriteLine("│{0,-5}│{1,-15}│{2,-5}│{3,-23}│{4,-10}│{5,-10}│{6,-15}│",
                   "№", "Прiзвище", "Курс", "Спеціальність", "Фізика", "Математика", " Iнформатика");
            // Виведення роздільника між заголовком та даними
            Console.WriteLine("├─────┼───────────────┼─────┼───────────────────────┼──────────┼──────────┼───────────────┤");

            // Виведення інформації про кожного студента
            for (int i = 0; i < students.Length; i++)
            {
                PrintStudentRow(i + 1, students[i].LastName, students[i].Course, students[i].Specialty,
                                students[i].PhysicsGrade, students[i].MathGrade, students[i].ComputerScienceGrade);
                // Виведення роздільника між рядками
                if (i != students.Length - 1)
                    Console.WriteLine("├─────┼───────────────┼─────┼───────────────────────┼──────────┼──────────┼───────────────┤");
            }
            // Виведення нижньої частини таблиці
            Console.WriteLine("└─────┴───────────────┴─────┴───────────────────────┴──────────┴──────────┴───────────────┘");
            Console.WriteLine();
        }

        public static void PrintStudentRow(int number, string lastName, int course, Specialties specialty,
                                   int physicsGrade, int mathGrade, int computerScienceGrade)
        {
            string specialtyName = Enum.GetName(typeof(Specialties), specialty);
            // Виведення даних про студента з відповідними клітинками та відступами
            Console.WriteLine("│{0,-5}│{1,-15}│{2,-5}│{3,-23}│{4,-10}│{5,-10}│{6,-15}│",
                              number, lastName, course, specialtyName, physicsGrade, mathGrade, computerScienceGrade);
        }
        public static void AverageScore(Student[] students, ref double[] average)
        {
            for (int i = 0; i < students.Length; i++)
            {
                average[i] = Math.Round((students[i].PhysicsGrade + students[i].MathGrade + students[i].ComputerScienceGrade) * 1.0 / 3, 1);
            }
        }
        public static void PrintAverageScore(Student[] students, in double[] average)
        {
            Console.WriteLine("Середній бал студентів: ");
            for (int i = 0; i < students.Length; i++)
                Console.WriteLine("Середній бал студента " + students[i].LastName + " = " + average[i]);
        }
        public static double percentageOf_A_Students(in Student[] students)
        {
            int count = 0;
            for (int i = 0; i < students.Length; i++)
                if (students[i].PhysicsGrade == 5 || students[i].PhysicsGrade == 4)
                    count++;
            return Math.Round((count * 1.0 / students.Length) * 100, 2);
        }
    }
}
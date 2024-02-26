using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Laba_9_1_2
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;//Для виводу кирилиці

            int NumberOfStudent;
            Console.Write("Введіть кількість студентів: ");
            while (!int.TryParse(Console.ReadLine(), out NumberOfStudent) || NumberOfStudent < 0)
            {
                Console.WriteLine("Некоректне значення. Введiть цiле число більше нуля");
                Console.Write("Кiлькiсть студентiв: ");
            }

            StudentB.Student[] students = new StudentB.Student[NumberOfStudent];
            StudentB.GetStudentInfo(ref students);
            StudentB.PrintStudentInfo(students);

            double[] average = new double[NumberOfStudent];
            StudentB.AverageScore(students, ref average);
            StudentB.PrintAverageScore(students, in average);

            Console.WriteLine("Процент студентів, які отримали з фізики оцінки “5” або “4”: " + StudentB.percentageOf_A_Students(students) + "%");

        }
    }
    public class StudentB
    {
        public enum Specialties
        {
            ComputerScience = 1,
            Informatics,
            MathematicsAndEconomics,
            PhysicsAndInformatics,
            LaborTraining
        }

        [StructLayout(LayoutKind.Explicit)]
        public struct Student
        {
            [FieldOffset(0)] public string LastName;
            [FieldOffset(16)] public int Course;
            [FieldOffset(20)] public Specialties Specialty;
            [FieldOffset(24)] public int PhysicsGrade;
            [FieldOffset(28)] public int MathGrade;

            [FieldOffset(32)] public int ProgramingGrade;
            [FieldOffset(32)] public int NumericalMethodsGrade;
            [FieldOffset(32)] public int PedagogyGrade;

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

                if (students[i].Specialty == Specialties.ComputerScience)
                {
                    Console.Write("Оцiнка з програмування: ");
                    while (!int.TryParse(Console.ReadLine(), out students[i].ProgramingGrade) || students[i].ProgramingGrade < 1 || students[i].ProgramingGrade > 5)
                    {
                        Console.WriteLine("Некоректне значення. Введiть число від 1 до 5.");
                        Console.Write("Оцiнка з програмування: ");
                    }
                }
                else if (students[i].Specialty == Specialties.Informatics)
                {
                    Console.Write("Оцiнка з чисельних методів: ");
                    while (!int.TryParse(Console.ReadLine(), out students[i].NumericalMethodsGrade) || students[i].ProgramingGrade < 1 || students[i].ProgramingGrade > 5)
                    {
                        Console.WriteLine("Некоректне значення. Введiть число від 1 до 5.");
                        Console.Write("Оцiнка з чисельних методів: ");
                    }
                }
                else
                {
                    Console.Write("Оцiнка з педагогіки: ");
                    while (!int.TryParse(Console.ReadLine(), out students[i].PedagogyGrade) || students[i].ProgramingGrade < 1 || students[i].ProgramingGrade > 5)
                    {
                        Console.WriteLine("Некоректне значення. Введiть число від 1 до 5.");
                        Console.Write("Оцiнка з педагогіки: ");
                    }
                }

                Console.WriteLine();

            }
        }
        public static void PrintStudentInfo(Student[] students)
        {
            Console.WriteLine("Список студентів: ");

            // Виведення верхньої частини таблиці
            Console.WriteLine("┌─────┬───────────────┬─────┬───────────────────────┬──────────┬──────────┬─────────────┬───────────────┬──────────┐");
            // Виведення заголовка таблиці
            Console.WriteLine("│{0,-5}│{1,-15}│{2,-5}│{3,-23}│{4,-10}│{5,-10}│{6,-13}|{7,-15}|{8,-10}|",
                   "№", "Прiзвище", "Курс", "Спеціальність", "Фізика", "Математика", "програмування", "чисельні методи", "педагогіка");
            // Виведення роздільника між заголовком та даними
            Console.WriteLine("├─────┼───────────────┼─────┼───────────────────────┼──────────┼──────────┼─────────────┼───────────────┼──────────┤");

            // Виведення інформації про кожного студента
            for (int i = 0; i < students.Length; i++)
            {
                PrintStudentRow(i + 1, students[i].Specialty, students[i].LastName, students[i].Course, students[i].Specialty,
                                students[i].PhysicsGrade, students[i].MathGrade, students[i].ProgramingGrade, students[i].NumericalMethodsGrade, students[i].PedagogyGrade);
                // Виведення роздільника між рядками
                if (i != students.Length - 1)
                    Console.WriteLine("├─────┼───────────────┼─────┼───────────────────────┼──────────┼──────────┼─────────────┼───────────────┼──────────┤");
            }

            // Виведення нижньої частини таблиці
            Console.WriteLine("└─────┴───────────────┴─────┴───────────────────────┴──────────┴──────────┴─────────────┴───────────────┴──────────┘");
            Console.WriteLine();
        }
        public static void PrintStudentRow(int number, Specialties Specialty, string lastName, int course, Specialties specialty,
                                   double physicsGrade, double mathGrade, double ProgramingGrade, double NumericalMethodsGrade, double PedagogyGrade)
        {
            string specialtyName = Enum.GetName(typeof(Specialties), specialty);
            // Виведення даних про студента з відповідними клітинками та відступами
            if (Specialty == Specialties.ComputerScience)
                Console.WriteLine("│{0,-5}│{1,-15}│{2,-5}│{3,-23}│{4,-10}│{5,-10}│{6,-13}|{7,-15}|{8,-10}|",
                              number, lastName, course, specialtyName, physicsGrade, mathGrade, ProgramingGrade, "", "");
            else if (Specialty == Specialties.Informatics)
                Console.WriteLine("│{0,-5}│{1,-15}│{2,-5}│{3,-23}│{4,-10}│{5,-10}│{6,-13}|{7,-15}|{8,-10}|",
                              number, lastName, course, specialtyName, physicsGrade, mathGrade, "", NumericalMethodsGrade, "");
            else
                Console.WriteLine("│{0,-5}│{1,-15}│{2,-5}│{3,-23}│{4,-10}│{5,-10}│{6,-13}|{7,-15}|{8,-10}|",
                              number, lastName, course, specialtyName, physicsGrade, mathGrade, "", "", PedagogyGrade);

        }

        public static void AverageScore(Student[] students, ref double[] average)
        {
            for (int i = 0; i < students.Length; i++)
            {
                average[i] = Math.Round((students[i].PhysicsGrade + students[i].MathGrade + students[i].ProgramingGrade) * 1.0 / 3, 1);
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
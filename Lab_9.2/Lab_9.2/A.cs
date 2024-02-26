using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static Laba_9_2_1.StudentA;

namespace Laba_9_2_1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;//Для виводу кирилиці
            Console.InputEncoding = Encoding.UTF8;////Для вводу кирилиці

            int NumberOfStudent;
            Console.Write("Введіть кількість студентів: ");
            while (!int.TryParse(Console.ReadLine(), out NumberOfStudent) || NumberOfStudent < 0)
            {
                Console.WriteLine("Некоректне значення. Введiть цiле число");
                Console.Write("Кiлькiсть студентiв: ");
            }
            StudentA.Student[] students = new StudentA.Student[NumberOfStudent];

            Console.WriteLine("\nВас вітає база даних студентів)");
            int menuItem;
            do
            {

                Console.WriteLine("\n");
                Console.WriteLine("Виберіть дію:\n");
                Console.WriteLine("\t[1] - введення даних з клавіатури");
                Console.WriteLine("\t[2] - заповнення тестовими(рандомними) даними");
                Console.WriteLine("\t[3] - вивід даних на екран");
                Console.WriteLine("\t[4] - фізичне сортування");
                Console.WriteLine("\t[5] - індексне сортування");
                Console.WriteLine("\t[6] - пошук студента");
                Console.WriteLine("\t[7] - для кожного студента вивести: прізвище і середній бал");
                Console.WriteLine("\t[8] - обчислити та вивести процент студентів, які отримали з фізики оцінки “5” або “4”.");
                Console.WriteLine("\t[0] - вихід та завершення роботи програми");
                Console.WriteLine("\nВведіть значення: ");

                while (!int.TryParse(Console.ReadLine(), out menuItem) || menuItem < 0 || menuItem > 8)
                {
                    Console.WriteLine("Некоректне значення. Введiть цiле число");
                    Console.Write("Введіть значення: ");
                }
                Console.WriteLine("\n\n");
                switch (menuItem)
                {
                    case 1:
                        StudentA.GetStudentInfo(ref students);
                        Console.WriteLine("Ви успішнее ввдели дані, тепер можете обрати наступну дію)");
                        break;
                    case 2:
                        StudentA.GetStudentInfo(ref students, true);
                        StudentA.PrintStudentInfo(students);
                        break;
                    case 3:
                        StudentA.PrintStudentInfo(students);
                        break;
                    case 4:
                        StudentA.physicalSort(ref students, NumberOfStudent);
                        Console.WriteLine("Фізичне сортування пройшло успішно)");
                        StudentA.PrintStudentInfo(students);

                        break;
                    case 5:
                        int[] indexArray = new int[NumberOfStudent];
                        indexArray = StudentA.IndexSort(students, NumberOfStudent);
                        Console.WriteLine("Індексне сортування пройшло успішно)");
                        StudentA.PrintIndexSorted(ref students, ref indexArray, NumberOfStudent);

                        break;
                    case 6:
                        StudentA.physicalSort(ref students, NumberOfStudent);
                        Console.WriteLine("Для пошуку введіть наступні дані");
                        int m;
                        {
                            string LastName;
                            Console.WriteLine("Прізвище: ");
                            LastName = Console.ReadLine();

                            Console.WriteLine("\nВиберiть спецiальнiсть зi списку: ");
                            foreach (var specialty in Enum.GetValues(typeof(Specialties)))
                                Console.WriteLine($"{(int)specialty}: {specialty}");
                            Specialties EnterSpecialty;
                            Console.Write("Введіть номер спеціальності: ");
                            while (!Enum.TryParse(Console.ReadLine(), out EnterSpecialty) || EnterSpecialty < Specialties.ComputerScience || EnterSpecialty > Specialties.LaborTraining)
                            {
                                Console.WriteLine("Некоректне значення. Введіть число від 1 до 5.");
                                Console.Write("Введіть номер спеціальності: ");
                            }

                            int ComputerScienceGrade;
                            Console.Write("Оцiнка з iнформатики: ");
                            while (!int.TryParse(Console.ReadLine(), out ComputerScienceGrade) || ComputerScienceGrade < 1 || ComputerScienceGrade > 5)
                            {
                                Console.WriteLine("Некоректне значення. Введiть число від 1 до 5.");
                                Console.Write("Оцiнка з iнформатики: ");
                            }

                            m = BinSearch(ref students, NumberOfStudent, LastName, EnterSpecialty, ComputerScienceGrade);
                        }
                        if (m >= 0)
                        {
                            Console.WriteLine("┌─────┬───────────────┬─────┬───────────────────────┬──────────┬──────────┬───────────────┐");
                            PrintStudentRow(m + 1, students[m].LastName, students[m].Course, students[m].Specialty,
                                students[m].PhysicsGrade, students[m].MathGrade, students[m].ComputerScienceGrade);
                            Console.WriteLine("└─────┴───────────────┴─────┴───────────────────────┴──────────┴──────────┴───────────────┘");
                        }
                        else
                            Console.WriteLine("\nНа жаль студента з такими даними не знайдено");
                        break;
                    case 7:
                        double[] average = new double[NumberOfStudent];
                        StudentA.AverageScore(ref students, average);
                        StudentA.PrintAverageScore(in students, average);
                        break;
                    case 8:
                        Console.WriteLine("Процент студентів, які отримали з фізики оцінки “5” або “4”: " + StudentA.percentageOf_A_Students(students) + "%");
                        break;
                    default:
                        break;
                }

            } while (menuItem != 0);
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

        public static void GetStudentInfo(ref Student[] students, bool automaticFill = false)
        {
            Random random = new Random();
            for (int i = 0; i < students.Length; i++)
            {

                if (automaticFill)
                {
                    // Автоматичне заповнення даними для налагодження
                    students[i].LastName = GenerateRandomName();
                    students[i].Course = random.Next(1, 7); // Генерація випадкового числа від 1 до 6
                    students[i].Specialty = (Specialties)random.Next((int)Specialties.ComputerScience, (int)Specialties.LaborTraining + 1);
                    students[i].PhysicsGrade = random.Next(1, 6);
                    students[i].MathGrade = random.Next(1, 6);
                    students[i].ComputerScienceGrade = random.Next(1, 6);
                }
                else//ввід з клави
                {
                    Console.WriteLine($"Введiть iнформацiю для студента {i + 1}:\n");
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
                        Console.WriteLine("Некоректне значення. Введіть число від 1 до 5.");
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
                }

                Console.WriteLine();
            }
        }
        private static string GenerateRandomName()
        {
            Random random = new Random();
            const string chars = "АБВГДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯабвгдеєжзиіїйклмнопрстуфхцчшщьюя";

            // Генерація рандомної довжини прізвища від 5 до 10 символів
            int length = random.Next(5, 11);

            // Вибір рандомних букв для прізвища
            return new string(Enumerable.Repeat(chars, length)
                .Select(s => s[random.Next(s.Length)]).ToArray());
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
        public static void AverageScore(ref Student[] students, double[] average)
        {
            for (int i = 0; i < students.Length; i++)
            {
                average[i] = Math.Round((students[i].PhysicsGrade + students[i].MathGrade + students[i].ComputerScienceGrade) * 1.0 / 3, 2);
            }
        }
        public static void PrintAverageScore(in Student[] students, double[] average)
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
        public static void physicalSort(ref Student[] students, int n)
        {
            Student temp = new Student();
            for (int i = 0; i < n - 1; i++) // метод "бульбашки"
                for (int j = 0; j < n - i - 1; j++)

                    if (students[j].Specialty > students[j + 1].Specialty
                        ||
                       (students[j].Specialty == students[j + 1].Specialty &&
                        students[j].ComputerScienceGrade > students[j + 1].ComputerScienceGrade)
                        ||
                       (students[j].Specialty == students[j + 1].Specialty &&
                        students[j].ComputerScienceGrade == students[j + 1].ComputerScienceGrade &&
                       string.Compare(students[j].LastName, students[j + 1].LastName) > 0))
                    {
                        temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                    }
        }
        public static int[] IndexSort(Student[] students, int n)
        {
            int[] indices = new int[n];

            for (int k = 0; k < n; k++)
                indices[k] = k;

            int i, j, value;

            for (i = 1; i < n; i++)
            {
                value = indices[i];

                for (j = i - 1; j >= 0 && (
                        students[indices[j]].Specialty > students[value].Specialty ||
                        (students[indices[j]].Specialty == students[value].Specialty &&
                         students[indices[j]].ComputerScienceGrade > students[value].ComputerScienceGrade) ||
                        (students[indices[j]].Specialty == students[value].Specialty &&
                         students[indices[j]].ComputerScienceGrade == students[value].ComputerScienceGrade &&
                         string.Compare(students[indices[j]].LastName, students[value].LastName) > 0))

                    ; j--)
                {
                    indices[j + 1] = indices[j];
                }

                indices[j + 1] = value;
            }

            return indices;
        }
        public static void PrintIndexSorted(ref Student[] students, ref int[] I, int n)
        {
            Console.WriteLine("Відсортованй список студентів: ");

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
                PrintStudentRow(i + 1, students[I[i]].LastName, students[I[i]].Course, students[I[i]].Specialty,
                                students[I[i]].PhysicsGrade, students[I[i]].MathGrade, students[I[i]].ComputerScienceGrade);
                // Виведення роздільника між рядками
                if (i != students.Length - 1)
                    Console.WriteLine("├─────┼───────────────┼─────┼───────────────────────┼──────────┼──────────┼───────────────┤");
            }
            // Виведення нижньої частини таблиці
            Console.WriteLine("└─────┴───────────────┴─────┴───────────────────────┴──────────┴──────────┴───────────────┘");
            Console.WriteLine();
        }
        public static int BinSearch(ref Student[] students, int N, string prizv, Specialties specialty, int ComputerScienceGrade)
        {
            int L = 0, R = N - 1, m;
            do
            {
                m = (L + R) / 2;

                if (string.Equals(students[m].LastName, prizv, StringComparison.OrdinalIgnoreCase) && students[m].Specialty == specialty && students[m].ComputerScienceGrade == ComputerScienceGrade)
                    return m;

                
                if (students[m].Specialty < specialty
                    ||
                    students[m].Specialty == specialty&&
                    students[m].ComputerScienceGrade < ComputerScienceGrade
                    ||
                    students[m].Specialty == specialty &&
                    students[m].ComputerScienceGrade == ComputerScienceGrade&&
                    string.Compare(students[m].LastName, prizv) < 0
                    )
                
                {
                    L = m + 1;
                }
                else
                {
                    R = m - 1;
                }

            } while (L <= R);

            return -1;
        }
    }
}
/*if ((string.Compare(students[m].LastName, prizv) < 0)
                    ||
                    (string.Equals(students[m].LastName, prizv, StringComparison.OrdinalIgnoreCase) &&
                     students[m].Specialty < specialty)
                     ||
                     (string.Equals(students[m].LastName, prizv, StringComparison.OrdinalIgnoreCase) &&
                     students[m].Specialty == specialty &&
                     students[m].ComputerScienceGrade < ComputerScienceGrade))*/
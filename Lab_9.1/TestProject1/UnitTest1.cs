using System.Net.Security;
using System;
using System.Threading.Tasks;
using Laba_9_1_1;
namespace TestProject1
{
    public class Tests
    {
        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void Test1()
        {
            StudentA.Student[] students = new StudentA.Student[3];

            students[0].PhysicsGrade = 3;
            students[0].MathGrade = 3;
            students[0].ComputerScienceGrade = 3;

            students[1].PhysicsGrade = 1;
            students[1].MathGrade = 2;
            students[1].ComputerScienceGrade = 3;

            students[2].PhysicsGrade = 4;
            students[2].MathGrade = 5;
            students[2].ComputerScienceGrade = 2;

            double[] average = new double[3];
            StudentA.AverageScore(students, ref average);

            Assert.AreEqual(3, average[0]);

            Assert.AreEqual(2, average[1]);

            Assert.AreEqual(3.7000000000000002d, average[2]);
        }
    }
}
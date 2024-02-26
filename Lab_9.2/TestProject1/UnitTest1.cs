using Laba_9_2_1;
using Microsoft.VisualStudio.TestPlatform.TestHost;
using System;

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
            StudentA.Student[] students = new StudentA.Student[2];

            students[0].PhysicsGrade = 3;
            students[0].MathGrade = 3;
            students[0].ComputerScienceGrade = 3;

            students[1].PhysicsGrade = 1;
            students[1].MathGrade = 2;
            students[1].ComputerScienceGrade = 3;


            double[] average = new double[2];
            StudentA.AverageScore(ref students, average);

            Assert.AreEqual(3, average[0]);

            Assert.AreEqual(2, average[1]);

            
        }
    }
}
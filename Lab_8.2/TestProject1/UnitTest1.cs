using System.Net.Security;
using System;
using System.Threading.Tasks;
using Lab_8_1;

namespace Lab_8_1_tests
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
            string str = "nvselrijrgl vjqwejlr vwkjwerjiaaa";
            int expected = 3;
            int actual = MyProgram.Count_a(str);
            Assert.AreEqual(expected, actual);
        }
        public void Test2()
        {
            string str = "vwblin;won a";
            int expected = 1;
            int actual = MyProgram.Count_a(str);
            Assert.AreEqual(expected, actual);
        }
        public void Test3()
        {
            string str = "      ";
            int expected = 0;
            int actual = MyProgram.Count_a(str);
            Assert.AreEqual(expected, actual);
        }
        public void Test4()
        {
            string str = "";
            int expected = -1;
            int actual = MyProgram.Count_a(str);
            Assert.AreEqual(expected, actual);
        }
    }
}
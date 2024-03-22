using System;

class Program {
    static void Main(string[] args) {
        char op;
        double num1, num2;

        Console.Write("Enter an operator (+, -, *, /): ");
        op = Convert.ToChar(Console.ReadLine());

        Console.Write("Enter two operands: ");
        num1 = Convert.ToDouble(Console.ReadLine());
        num2 = Convert.ToDouble(Console.ReadLine());

        switch (op) {
            case '+':
                Console.WriteLine("{0} + {1} = {2}", num1, num2, num1 + num2);
                break;
            case '-':
                Console.WriteLine("{0} - {1} = {2}", num1, num2, num1 - num2);
                break;
            case '*':
                Console.WriteLine("{0} * {1} = {2}", num1, num2, num1 * num2);
                break;
            case '/':
                if (num2 != 0)
                    Console.WriteLine("{0} / {1} = {2}", num1, num2, num1 / num2);
                else
                    Console.WriteLine("Error! Division by zero.");
                break;
            default:
                Console.WriteLine("Error! Invalid operator.");
                break;
        }
    }
}

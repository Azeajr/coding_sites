using System;

public static class Kata
{
    public static string ReverseWords(string str)
    {
        // Original solution
        // string?[] temp = str.Split();
        // for (var i = 0; i < temp.Length; i++)
        // {
        //     temp[i] = new string(temp[i]?.ToCharArray().Reverse().ToArray());
        // }
        //
        // return String.Join(" ", temp);
        
        // Improved solution using select and lambda
        // Originally wanted to do something like JS foreach with a lambda so maybe JS forEach == c# Select?
        // return String.Join(" ", str.Split().Select(s => new string(s.ToCharArray().Reverse().ToArray())));
        
        // Best practice
        return String.Join(" ", str.Split().Select(s => new string(s.Reverse().ToArray())));

    }

    public static void Main(string[] args)
    {
        var testString = "This is an example!";
        Console.WriteLine(testString);
        Console.WriteLine(ReverseWords(testString));
    }
}
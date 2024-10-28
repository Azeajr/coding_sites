using System;

public class Kata
{
  public static int CountBits(int n)
  {
    string binary = Convert.ToString(n, 2);

    int count = 0;
    foreach (char c in binary)
    {
      if (c == '1')
      {
        count++;
      }
    }

    return count;
  }

  public static void Main(string[] args)
  {
    Console.WriteLine(CountBits(9));
  }
}
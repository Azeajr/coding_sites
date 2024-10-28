using System;

public class Kata
{
  public static int Opposite(int number)
  {
    return -number;
  }

  public static void Main(string[] args)
  {
    Console.WriteLine(Opposite(2));
    Console.WriteLine(Opposite(-22));
  }
}
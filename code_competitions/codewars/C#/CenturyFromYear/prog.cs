using System;


public static class Kata
{
  public static int CenturyFromYear(int year)
  {
    return (int)Math.Ceiling(year / 100.0);
  }

  public static void Main(string[] args)
  {
    Console.WriteLine(CenturyFromYear(1705));
    Console.WriteLine(CenturyFromYear(1900));
    Console.WriteLine(CenturyFromYear(1601));
    Console.WriteLine(CenturyFromYear(2000));
  }
}
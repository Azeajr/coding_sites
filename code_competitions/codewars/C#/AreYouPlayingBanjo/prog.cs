using System;
using System.Globalization;

public class Kata
{
  public static string AreYouPlayingBanjo(string name)
  {
    return name.StartsWith("R", true, new CultureInfo("en-US")) ? name + " plays banjo" : name + " does not play banjo";
  }

  public static void Main(string[] args)
  {
    Console.WriteLine(AreYouPlayingBanjo("Ricardo"));
    Console.WriteLine(AreYouPlayingBanjo("ricardo"));
    Console.WriteLine(AreYouPlayingBanjo("Antonio"));
  }
}
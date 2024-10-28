// In this kata you are required to, given a string, replace every letter with its position in the alphabet.

// If anything in the text isn't a letter, ignore it and don't return it.

// "a" = 1, "b" = 2, etc.
using System;
public static class Kata
{
  public static string AlphabetPosition(string text)
  {
    string temp = "";
    foreach (char c in text)
    {
      if(char.IsLetter(c)){
        temp += ((int)(char.ToLower(c)) - 96) + " ";
      }
    }

    return temp.TrimEnd();
  }

  public static void Main(string[] args)
  {
    Console.WriteLine("THis is a Test");
    Console.WriteLine(AlphabetPosition("THis is a Test"));
  }
}
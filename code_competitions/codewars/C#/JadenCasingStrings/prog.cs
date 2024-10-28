using System;
public static class JadenCase
{
  public static string ToJadenCase(this string phrase)
  {
    string[] words = phrase.Split(' ');
    // foreach (var word in words)
    // {
    //   word[0] = word[0].ToString().ToUpper();
    // }

    // for (int i = 0; i < words.Length; i++)
    // {
    //   words[i][0] = words[i][0].ToString().ToUpper();
    // }

    foreach (var word in words)
    {
      Console.WriteLine(word);
    }
    return String.Empty;
  }

  public static void Main(string[] args)
  {
    ToJadenCase("How can mirrors be real if our eyes aren't real");
  }
}
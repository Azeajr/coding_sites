import unittest
import logging
from collections import Counter

logging.basicConfig(level=logging.DEBUG, format="%(levelname)s: %(message)s")


def equalFrequency(word: str):
    """
    Return True if by removing exactly one character from 'word',
    we can make all remaining characters occur the same number of times.
    Otherwise, return False.
    """
    freq = Counter(word)  # Character -> Frequency
    freq_counts = Counter(
        freq.values()
    )  # Frequency -> How many characters have that frequency
    logging.debug(f"Word: {word}, freq_counts: {freq_counts}")

    # CASE 1: Only one distinct frequency
    #   e.g. 'aaa' -> freq_counts={3:1}, or 'abc' -> freq_counts={1:3}
    #   Removing one character can succeed if either:
    #    (a) The frequency is 1 (so removing any one char still leaves all at freq=1),
    #    (b) OR there is only one character type (freq_counts.value == 1),
    #        so removing one occurrence keeps the same frequency for that single character type.
    if len(freq_counts) == 1:
        (f, how_many) = next(iter(freq_counts.items()))
        if f == 1 or how_many == 1:
            logging.debug("Single frequency: valid removal possible.")
            return True
        logging.debug("Single frequency: no valid removal possible.")
        return False

    # CASE 2: More than two distinct frequencies -> cannot fix in a single removal
    if len(freq_counts) > 2:
        logging.debug("More than two distinct frequencies: return False.")
        return False

    # CASE 3: Exactly two distinct frequencies
    #   Let them be f1 and f2, with c1 and c2 characters at each frequency
    (f1, c1), (f2, c2) = freq_counts.items()
    logging.debug(f"Two frequencies: f1={f1}, c1={c1}, f2={f2}, c2={c2}")

    # Option A: One of the frequencies is 1 and exactly one character has that frequency
    #           -> remove that single occurrence, and all others match.
    if (f1 == 1 and c1 == 1) or (f2 == 1 and c2 == 1):
        logging.debug("A single char has frequency=1: valid removal.")
        return True

    # Option B: The difference between f1 and f2 is 1, and exactly one character has the higher frequency
    #           -> remove one occurrence from that higher-frequency character to match the lower frequency.
    if abs(f1 - f2) == 1:
        if (f1 > f2 and c1 == 1) or (f2 > f1 and c2 == 1):
            logging.debug(
                "Frequencies differ by 1 and the higher freq is used by exactly one char: valid removal."
            )
            return True

    logging.debug("No valid single-removal scenario.")
    return False


# -------------- TESTS --------------

param_list = [
    ("abcc", True),  # remove one 'c' -> 'abc' all freq=1
    (
        "aazz",
        False,
    ),  # 'aazz' -> freq_counts={2:2}; removing 1 char leads to freq={2,1}, mismatch
    ("bac", True),  # remove 'b' -> 'ac' all freq=1
    ("abbcc", True),  # remove one 'a' -> 'bbcc' all freq=2
    ("babbdd", False),
    ("zz", True),  # remove 1 'z' -> single 'z' freq=1
    (
        "a",
        True,
    ),  # removing 'a' leaves empty string (consistent with the logic that c == 1)
    ("ab", True),  # remove 1 char -> single char remains
    ("aaabb", True),  # remove 1 'a' -> 'aabb' each freq=2
    ("ddaccb", False),
]


class TestEqualFrequency(unittest.TestCase):
    def test_equalFrequency(self):
        for word, expected in param_list:
            with self.subTest(word=word, expected=expected):
                result = equalFrequency(word)
                logging.debug(f"Tested '{word}': expected={expected}, got={result}")
                self.assertEqual(result, expected)


if __name__ == "__main__":
    unittest.main(verbosity=2)

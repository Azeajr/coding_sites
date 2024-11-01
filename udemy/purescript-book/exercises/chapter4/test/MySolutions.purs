module Test.MySolutions where

import Prelude

import Data.Array (null, tail, head)
import Data.Maybe (fromMaybe)

-- Note to reader: Add your solutions to this file
-- My solution only works due to overflow, I think.
isEven :: Int -> Boolean
isEven num =
  if num - 2 == 0 then
    true
  else if num - 2 == 1 then
    false
  else
    isEven (num - 2)

isEven' :: Int -> Boolean
isEven' n =
  if n < 0
    then isEven'(-n)
  else if n == 0
    then true
  else not(isEven'(n-1))

countEven ∷ Array Int → Int
countEven arr =
  if null arr then
    0
  else if (isEven(fromMaybe 1 (head arr))) then
    1 + countEven(fromMaybe [] (tail arr))
  else
    countEven(fromMaybe [] (tail arr))
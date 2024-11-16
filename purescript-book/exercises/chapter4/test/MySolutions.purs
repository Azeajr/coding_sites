module Test.MySolutions where

import Prelude

import Control.Alternative (guard)
import Data.Array (any, filter, head, null, tail, last, (..), catMaybes, cons)
import Data.Array.NonEmpty
import Data.Foldable (product)
import Data.Int (floor, toNumber)
import Data.Int as Int
import Data.Maybe (fromMaybe, Maybe(..))
import Data.NonEmpty (NonEmpty)
import Data.Number (sqrt)
import Data.Number.Format (toString)
import Effect.Class.Console (log)
import Effect.Exception (throwException)
import Test.QuickCheck.Gen (sample)
import Test.Unit.Console (print)

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
  if n < 0 then isEven' (-n)
  else if n == 0 then true
  else not (isEven' (n - 1))

countEven ∷ Array Int → Int
countEven arr =
  if null arr then
    0
  else if (isEven (fromMaybe 1 (head arr))) then
    1 + countEven (fromMaybe [] (tail arr))
  else
    countEven (fromMaybe [] (tail arr))

squared :: Array Number -> Array Number
squared arr =
  -- map (\n -> n * n) arr
  -- (\n-> n * n ) `map` arr
  (\n -> n * n) <$> arr

keepNonNegative ∷ Array Number → Array Number
keepNonNegative arr =
  filter (\n -> n >= 0.0) arr

infix 8 filter as <$?>

keepNonNegativeRewrite :: Array Number -> Array Number
keepNonNegativeRewrite arr =
  -- (<$?>) (\n -> n >= 0.0) arr
  (\n -> n >= 0.0) <$?> arr

isPrime :: Int -> Boolean
isPrime n = do
  if n <= 3 then
    n > 1
  else if n `mod` 2 == 0 || n `mod` 3 == 0 then
    false
  else do
    let limit = floor (sqrt (Int.toNumber n))
    not (any (\i -> n `mod` i == 0 || n `mod` (i + 2) == 0) (5 .. (limit + 1)))

cartesianProduct ∷ ∀ a. Array a -> Array a -> Array (Array a)
cartesianProduct arr1 arr2 = do
  i <- arr1
  j <- arr2
  pure [ i, j ]

triples ∷ Int → Array (Array Int)
triples n = do
  i <- 1 .. n
  let r = 2 * i
  st <- findAllFactorPairs ((r * r) / 2)
  let s = fromMaybe 0 (head st)
  let t = fromMaybe 0 (last st)

  let x = r + s
  let y = r + t
  let z = r + s + t
  if x <= n && y <= n && z <= n then
    pure [ x, y, z ]
  else
    []

findAllFactorPairs ∷ Int → Array (Array Int)
findAllFactorPairs n = do
  i <- 1 .. floor (sqrt (toNumber n))
  if n `mod` i == 0 then
    pure [ i, n `div` i ]
  else
    []

triples' :: Int -> Array (Array Int)
triples' n = do
  a <- 1 .. n
  b <- a .. n
  c <- b .. n
  guard $ a * a + b * b == c * c
  pure [ a, b, c ]



findFirstFactor ∷ Int → Maybe Int
findFirstFactor n = go 2
  where
    limit = floor (sqrt (toNumber n))

    go::Int -> Maybe Int
    go i 
      | i > limit = Just 1
      | n `mod` i == 0 = Just i
      | otherwise = go (i + 1)



primeFactors :: Int -> Array Int
primeFactors n = catMaybes $ go n 2
  where
    limit = floor (sqrt (toNumber n))

    go :: Int -> Int -> Array (Maybe Int)
    go num i
      | i > limit = if num == 1 then [Just 1] else [ Just num ]
      | num `mod` i == 0 = cons (Just i) (go (num `div` i) i)
      | otherwise = go num (i + 1)
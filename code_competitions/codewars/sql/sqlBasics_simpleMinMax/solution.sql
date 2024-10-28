-- people table schema
-- id
-- name
-- age
-- select table schema
-- age_min (minimum of ages)
-- age_max (maximum of ages)
SELECT MIN(age) AS age_min,
  MAX(age) AS age_max
FROM people
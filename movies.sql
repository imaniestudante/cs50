SELECT DISTINCT name FROM people
JOIN stars ON star.person_id = people.id
JOIN movies ON movies.id = star_movie.id
WHERE
(SELECT movies.id FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.movies_id
WHERE people.name = "Kevin Bacon" AND people.birth = 1958)
AND people.name != "Kevin Bacon"
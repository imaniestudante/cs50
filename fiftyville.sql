SELECT description FROM crime_scene_report WHERE month = 7 AND day = 28 AND street = "Chamberlim Street";
SELECT name, transcript FROM interviews WHERE month = 7 AND day = 28;
SELECT activity, minute FROM courthouse_security_logs WHERE month 7 AND day = 28 AND hour = 10;
SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = "exit";
SELECT name, phone_number FROM people WHERE license_place IN (SELECT license_place FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = "exit");
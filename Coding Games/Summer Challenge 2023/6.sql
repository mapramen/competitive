SELECT
	ChatId
FROM
	(
		SELECT
			studentsChatsMap.ChatId,
			studentsChatsMap.StudentId
		FROM
			(
				SELECT
					studentsChatsMap.ChatId AS ChatId,
					studentsChatsMap.StudentId AS StudentId
				FROM
					studentsChatsMap
					JOIN (
						SELECT
							TOP 50 PERCENT *
						FROM
							student
						ORDER BY
							AvgGrade DESC
					) AS student ON studentsChatsMap.StudentId = student.StudentId
			) AS studentsChatsMap
			JOIN (
				SELECT
					*
				FROM
					onlineChat
				WHERE
					CreatedAt >= '3961-05-05'
			) AS onlineChat ON studentsChatsMap.ChatId = onlineChat.ChatId
	)
GROUP BY
	ChatId
HAVING
	COUNT(*) = 7;

WITH good_student AS (
	SELECT
		TOP 50 PERCENT *
	FROM
		student
	ORDER BY
		AvgGrade DESC
)
SELECT
	*
FROM
	good_student;
# Write your MySQL query statement below
select s.student_id,s.student_name,
sub.subject_name,
COUNT(e.student_id) as attended_exams
FROM Students  s
CROSS JOIN Subjects sub
left join Examinations  e
ON  sub.subject_name= e.subject_name
AND s.student_id=e.student_id 
Group BY 
s.student_id,
s.student_name,
sub.subject_name
order by
s.student_id,sub.subject_name


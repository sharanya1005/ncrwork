use NCR;
UPDATE emp
SET job = 'SALESPERSON'
WHERE job = 'SALESMAN' and deptno = 30;
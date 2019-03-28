use NCR;
select empname, job, sal, deptname, grade from emp, dept, salgrade where emp.deptno = dept.deptno and sal between losal and hisal and job!='CLERK' order by sal desc;
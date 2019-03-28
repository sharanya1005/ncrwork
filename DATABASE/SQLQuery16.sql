use NCR;
select deptno,count(*)"no. of employees in dept" from emp group by deptno having count(*)>3 order by deptno;
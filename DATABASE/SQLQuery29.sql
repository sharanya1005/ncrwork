use NCR;


select count(*), sum(sal) "Total salary", avg(sal)"average salary",deptno from emp where deptno in (select deptno from emp) group by deptno;
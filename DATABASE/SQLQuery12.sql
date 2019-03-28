use NCR;
select job,min(sal)"MINIMUM SALARY", max(sal) "MAXIMUM SALARY" from emp group by job;
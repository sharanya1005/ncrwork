use NCR;
select job,avg(sal)"AVERAGE SALARY",sum( sal + isnull(comm,0))"REMUNERATION" from emp group by job;